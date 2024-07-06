#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QString>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include <QSerialPortInfo>

//绘制画图
#include <QtSerialPort/QSerialPort>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QValueAxis>

//正则匹配
#include <QRegExp>

QT_CHARTS_USE_NAMESPACE

#define MAX_X   50
#define MAX_Y_1   200000    //AD量程       -200 - 2000000
#define MAX_Y_2   700    //实际压力量程  0    - 700Kpa
#define TRUE    1
#define FALSE   0

#define aa 3.428
#define bb 611.8

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer *timerDrawLine;
    QChart *chart;
    QSplineSeries *lineSeries;
    QSplineSeries *lineSeries_Flitter;
    QSplineSeries *lineSeries_Fitting;
    QSerialPort *serialPort;
    QTimer *timer;
    QTimer *timersend;
    QString     SendTextStr;
    QByteArray  SendTextByte;
    quint32     dataRxNumber = 0 ;      // 记录Rx数据量
    quint8      Serial_State = 0 ;      // 串口状态
    quint8      average_Flag = 0 ;      // 平均值状态
    quint8      Range_Flag   = 0 ;      // 范围状态 0 Pa 1 百pa 2 kPa
    double     Press_Value = 0;
    double     Press_Value_Flitter_temp = 0;
    double     Press_Value_Flitter = 0;
    double      Press_Value_Fitting = 0.0;
    double      Show_Value_Fitting = 0.0;

private slots:
    //void SaveFileButton();
    void on_OpenUart_clicked();
    void on_CloseUart_clicked();
    void serialPortReadyRead_Slot();
    void ClearRecvButton();
    void TimeSendReady(int state);
    void SendDataHex(int state);
    void SaveRecvDataFile();
    void find_port();
    void TimerOut();
    void on_SendDataFile_clicked();
    void on_RefreshUart_clicked();
    void Chart_Init();
    void DrawLine();
    void on_ChangeRange_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
