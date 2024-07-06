#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList serialNamePort;
    Chart_Init();
    serialPort = new QSerialPort(this);

    //新建一个QTimer对象
    timer = new QTimer();
    //信号和槽
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerOut()));

    /*定时发送定时器*/
    timersend = new QTimer();
    /*定时器超时信号槽*/
    connect(timersend, SIGNAL(timeout()), this, SLOT(on_SendDataFile_clicked()));

    /*固定命令定时器100ms,发送传感器数据请求命令*/
    QTimer *timer_measure =  new QTimer(this);
    connect(timer_measure, &QTimer::timeout, this, [=]()
    {
        if(this->serialPort->isOpen())//判断串口是否打开
        {
            const char *qryCmd = "1:R:MRMD\r\n";//请求命令
            this->serialPort->write(qryCmd,strlen(qryCmd));
            ui->SendTextEdit->append(qryCmd);//每次发送的数据也进行回显
            serialPort->waitForBytesWritten();//等待数据返回
        }
    });
    timer_measure->start(200);

    connect(ui->timesendcheckBox,SIGNAL(stateChanged(int)),this,SLOT(TimeSendReady(int)));
    connect(ui->HexsendcheckBox,SIGNAL(stateChanged(int)),this,SLOT(SendDataHex(int)));// 绑定HEX发送chexkBox信号与对应的槽函数

    foreach(const QSerialPortInfo &info , QSerialPortInfo::availablePorts()){
        serialNamePort<<info.portName();
    }
    QFont font("Microsoft YaHei",10,QFont::Normal);//微软雅黑。字体大小16，Normal：正常，Bold 粗体，Black：黑体，Light：高亮
    setWindowTitle(" 压力测试 V1.0 ");
    ui->uartbox->addItems(serialNamePort);      // 引入当前串口
    setFixedSize(930,560); // 固定窗口的大小
    ui->CloseUart->setEnabled(false);       // 断开按键关使能
    ui->RecvTextEdit->setFont(font);
    ui->SendTextEdit->setFont(font);
    connect(ui->ClearRecvButton, SIGNAL(clicked()), this, SLOT(ClearRecvButton()));         // 清空接收按钮
    connect(ui->SaveRecvDataFile, SIGNAL(clicked()), this, SLOT(SaveRecvDataFile()));       // 保存数据按钮
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerOut()
{
    QString     stringdata;
    QString extractedString;

    timer->stop();              //关闭定时器
    ui->RecvTextEdit->setTextColor(QColor(Qt::black));
    // 读取串口接收的数据
    QByteArray  RecvBuff = serialPort->readAll();
    if(ui->recvcheckBox->isChecked())
    {
        stringdata = RecvBuff.toHex(' ').trimmed().toUpper();/*hex显示*/
    }
    else
    {
       stringdata = QString(RecvBuff);   /*ascii显示*/
    }

    QRegularExpression pattern("(?<=^.{9}).*");
    QRegularExpressionMatch match = pattern.match(stringdata);

    if (match.hasMatch())
    {
        //原始数据 正则表达式匹配
        extractedString = match.captured(0);
        Press_Value = extractedString.toInt();
        qDebug("原始数据：%f",Press_Value);

        //平均值滤波
        if(average_Flag < 8)
        {
            Press_Value_Flitter_temp += Press_Value;
            average_Flag ++;
        }
        else
        {
            Press_Value_Flitter = Press_Value_Flitter_temp / 8.0;
            Press_Value_Flitter_temp = 0.0;
            average_Flag = 0;
        }
        qDebug("\r\r滤波数据：%f",Press_Value_Flitter);

        //一阶拟合数据 单位KPa
        Press_Value_Fitting = ((aa * Press_Value_Flitter) + bb)/ 1000.0;
        Show_Value_Fitting = Press_Value_Fitting;//显示值
        qDebug("\r\r拟合数据：%f\r\n",Press_Value_Fitting);

        if(Range_Flag == 0)
        {
            Show_Value_Fitting *= 1000.0;
        }
        else if (Range_Flag == 1)
        {
            Show_Value_Fitting *= 10.0;
        }
        else
        {
            Show_Value_Fitting *= 1.0;
        }

        QString string_temp = QString::number(Show_Value_Fitting,10.0);//单位：帕
        ui->textBrowser_ShowValue->setText(string_temp);
        //qDebug() << string_temp;
    }

    DrawLine(); //绘制曲线

    /*时间戳按钮*/
    if (ui->timecheckBox->isChecked())
    {
       extractedString = QString("[%1]:RX -> %2").arg(QTime::currentTime().toString("HH:mm:ss:zzz")).arg(extractedString);
       ui->RecvTextEdit->append(extractedString);
    }
    else
    {
        ui->RecvTextEdit->insertPlainText(extractedString);
    }
    ui->RecvTextEdit->moveCursor(QTextCursor::End);  // 自动滚屏到最后一行 有BUG 不可用光标点击文本框
    dataRxNumber += RecvBuff.length();
    ui->RxNumlabel->setText(QString::number(dataRxNumber));
    RecvBuff.clear();
}

void MainWindow::serialPortReadyRead_Slot()
{
    //启动定时器
    timer->start(100);
}

void MainWindow::on_OpenUart_clicked()
{

    serialPort->setPortName(ui->uartbox->currentText());
    serialPort->setBaudRate(ui->baudbox->currentText().toInt());            //设置波特率
    serialPort->setDataBits(QSerialPort::Data8);                            //设置数据位数  默认8位
    serialPort->setParity(QSerialPort::NoParity);                           //设置奇偶校验  默认无奇偶
    serialPort->setStopBits(QSerialPort::TwoStop);                          //设置停止位    默认2停止
    serialPort->setFlowControl(QSerialPort::NoFlowControl);                 //设置流控制    默认无

    connect(serialPort,SIGNAL(readyRead()),this,SLOT(serialPortReadyRead_Slot()));

    if(serialPort->open(QIODevice::ReadWrite))              //打开串口成功
    {
        ui->OpenUart->setEnabled(false);
        ui->CloseUart->setEnabled(true);
        Serial_State = TRUE;
        QMessageBox::warning(this,tr("提示"),tr("串口连接成功"));
    }
    else
    {
        QMessageBox::warning(this,tr("错误"),tr("串口连接失败"));
    }
}

void MainWindow::on_CloseUart_clicked()
{
    serialPort->close();
    Serial_State = 0;
    ui->OpenUart->setEnabled(true);     // 连接串口按键使能
    ui->CloseUart->setEnabled(false);   // 断开按键关使能
}

//查找串口列表
void MainWindow::find_port()
{
    ui->uartbox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);   //设置串口
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->uartbox->addItem(serial.portName());        //显示串口名称
            serial.close();
        }
    }
}

void MainWindow::ClearRecvButton()
{
    ui->RecvTextEdit->clear();
    dataRxNumber = 0 ;
    ui->RxNumlabel->setText(QString::number(dataRxNumber));
}

void MainWindow::SaveRecvDataFile()
{
    QString data;

    data = ui->RecvTextEdit->toPlainText();

    if (data.isEmpty())
    {
        QMessageBox::information(this, "提示", "数据内容空");
        return;
    }
    QString curPath = QDir::currentPath();            //获取系统当前目录
    QString dlgTitle = "保存文件";                     //对话框标题
    QString filter = "文本文件(*.txt);;所有文件(*.*)";  //文件过滤器
    QString filename = QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);
    if (filename.isEmpty())
    {
        return;
    }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    /*保存文件*/
    QTextStream stream(&file);
    stream << data;
    file.close();
}

void MainWindow::on_SendDataFile_clicked()
{
    if (Serial_State == TRUE)
    {
        //获取发送框字符
        SendTextStr = ui->SendTextEdit->document()->toPlainText();
        SendTextByte = SendTextStr.toUtf8();
        if (SendTextByte.isEmpty() != true)
        {

            if (ui->HexsendcheckBox->isChecked())
            {
                SendTextByte = SendTextByte.fromHex(SendTextByte);
                serialPort->write(SendTextByte); // 发送hex数据
                QString strdata = SendTextByte.toHex(' ').trimmed().toUpper();
                if (ui->timecheckBox->isChecked()) // 时间戳发送
                {
                    ui->RecvTextEdit->setTextColor(QColor(Qt::blue));  // 时间戳颜色
                    ui->RecvTextEdit->append(QString("[%1]TX -> ").arg(QTime::currentTime().toString("HH:mm:ss:zzz")));
                }
                else
                {
                  strdata = strdata.append("\r\n");
                }
                ui->RecvTextEdit->setTextColor(QColor(Qt::black));
                ui->RecvTextEdit->insertPlainText(strdata);
            }
            else
            {
                // 发送ascii数据
                serialPort->write(SendTextByte);
                QString strdata = QString(SendTextByte);
                if (ui->timecheckBox->isChecked()) // 时间戳发送
                {
                    ui->RecvTextEdit->setTextColor(QColor(Qt::red)); // 时间戳颜色
                    ui->RecvTextEdit->append(QString("[%1]TX -> ").arg(QTime::currentTime().toString("HH:mm:ss:zzz")));
                }
                else
                {
                   strdata = strdata.append("\r\n");
                }
                ui->RecvTextEdit->setTextColor(QColor(Qt::black));
                ui->RecvTextEdit->insertPlainText(strdata);
            }
            //移动光标到末尾
            ui->RecvTextEdit->moveCursor(QTextCursor::End);
        }
        else
        {
            QMessageBox::warning(this, "警告", "您需要在发送编辑框中输入要发送的数据");
        }
    }
    else
    {
        QMessageBox::information(this, "警告", "串口未打开");
    }
}

/*
    函   数：TimeSendReady
    描   述：定时发送信号槽函数
    输   入：无
    输   出：无
*/
void MainWindow::TimeSendReady(int state)
{
    int settime;

    if (FALSE == Serial_State)
    {
        QMessageBox::information(this, "提示", "串口未打开");
        return;
    }
    /*判断是否有数据*/
    if (ui->SendTextEdit->document()->isEmpty() == true)
    {
        if (ui->timesendcheckBox->isChecked())
        {
            QMessageBox::warning(this, "警告", "您需要在发送编辑框中输入要发送的数据");
        }
        return;
    }
    /*判断勾选状态*/
    if (state == Qt::Checked)
    {
        /*获取设定时间*/
        settime = ui->timelineEdit->text().toInt();
        if (settime > 0) {
            timersend->start(settime);
        } else {
            QMessageBox::warning(this, "警告", "时间必须大于0");
        }
        ui->timelineEdit->setEnabled(false);
    }
    else
    {
        /*停止发送*/
        timersend->stop();
        ui->timelineEdit->setEnabled(true);
    }
}

void MainWindow::SendDataHex(int state)
{
    //获取发送框字符
    SendTextStr = ui->SendTextEdit->document()->toPlainText();
    SendTextByte = SendTextStr.toUtf8();
    if (SendTextStr.isEmpty())
    {
        return;
    }
    //asccii与hex转换
    if (state == Qt::Checked)
    {
        //转换成16进制数并转换为大写
        SendTextByte = SendTextByte.toHex(' ').toUpper();
        ui->SendTextEdit->document()->setPlainText(SendTextByte);
    }
    else
    {
        //从QByteArray转换为QString
        SendTextStr = SendTextByte.fromHex(SendTextByte);
        ui->SendTextEdit->document()->setPlainText(SendTextStr);
    }
}

void MainWindow::on_RefreshUart_clicked()
{
    ui->uartbox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);   //设置串口
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->uartbox->addItem(serial.portName());        //显示串口名称
            serial.close();
        }
    }
}

void MainWindow::Chart_Init()
{
    chart = new QChart();//初始化QChart的实例
    lineSeries = new QSplineSeries(); //初始AD值曲线
    lineSeries_Flitter = new QSplineSeries();//滤波后的曲线
    lineSeries_Fitting = new QSplineSeries();//二项式拟合的曲线
    lineSeries->setName("原始压力AD值");//设置曲线的名称
    lineSeries_Flitter->setName("滤波后数值曲线");
    lineSeries_Fitting->setName("拟合后数值曲线");
    chart->addSeries(lineSeries);//把曲线添加到QChart的实例chart中
    chart->addSeries(lineSeries_Flitter);
    chart->addSeries(lineSeries_Fitting);

    QValueAxis *axisX = new QValueAxis();//声明并初始化X轴、Y轴
    QValueAxis *axisY = new QValueAxis();
    QValueAxis *axisY_Fitting = new QValueAxis();
    axisX->setMin(0); //设置坐标轴显示的范围
    axisX->setMax(MAX_X);
    axisY->setMin(-200);
    axisY->setMax(MAX_Y_1);
    axisY_Fitting->setMin(0);
    axisY_Fitting->setMax(MAX_Y_2);
    axisX->setTickCount(10);//设置坐标轴上的格点
    axisY->setTickCount(5);
    axisY_Fitting->setTickCount(7);
    QFont font("Microsoft YaHei",8,QFont::Normal);//设置坐标轴显示的名称 微软雅黑。字体大小8
    axisX->setTitleFont(font);
    axisY->setTitleFont(font);
    axisY_Fitting->setTitleFont(font);
    axisX->setTitleText("t");
    axisY->setTitleText("Press-AD-Value");
    axisY_Fitting->setTitleText("Press-Fit-Value(KPa)");
    axisY->setGridLineVisible(false);//设置网格不显示
    axisY_Fitting->setGridLineVisible(false);

    chart->addAxis(axisX, Qt::AlignBottom);//下方：Qt::AlignBottom，左边：Qt::AlignLeft
    chart->addAxis(axisY, Qt::AlignLeft);//右边：Qt::AlignRight，上方：Qt::AlignTop
    chart->addAxis(axisY_Fitting, Qt::AlignRight);//右边：Qt::AlignRight，上方：Qt::AlignTop

    lineSeries->attachAxis(axisX);//把曲线关联到坐标轴
    lineSeries->attachAxis(axisY);  
    lineSeries_Flitter->attachAxis(axisX);
    lineSeries_Flitter->attachAxis(axisY);
    lineSeries_Fitting->attachAxis(axisX);
    lineSeries_Fitting->attachAxis(axisY_Fitting);

    ui->graphicsView->setChart(chart); //把chart显示到窗口上
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);      // 设置渲染：抗锯齿，使曲线更平滑
}

void MainWindow::DrawLine()
{
    static int count = 0;
    if(count > MAX_X)
    {
        //当曲线上最早的点超出X轴的范围时，剔除最早的点，
        lineSeries->removePoints(0,lineSeries->count() - MAX_X);
        // 更新X轴的范围
        chart->axisX()->setMin(count - MAX_X);
        chart->axisX()->setMax(count);
    }

    //增加新的点到曲线末端
    lineSeries->append(count, Press_Value);//在图表上显示初始压力值
    lineSeries_Flitter->append(count,Press_Value_Flitter);//在图表上显示滤波后压力值
    lineSeries_Fitting->append(count,Press_Value_Fitting);//在图表上显示拟合后压力值
    count ++;
}


void MainWindow::on_ChangeRange_clicked()
{
    Range_Flag++;
    if(Range_Flag > 2)
    {
        Range_Flag = 0;
    }
    switch (Range_Flag)
    {
    case 0:
        ui->label_range->setText("Pa");
        break;
    case 1:
        ui->label_range->setText("BPa");
        break;
    case 2:
        ui->label_range->setText("KPa");
        break;
    default:
        break;
    }
}

