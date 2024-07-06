/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *RecvTextEdit;
    QTextEdit *SendTextEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *timecheckBox;
    QCheckBox *recvcheckBox;
    QCheckBox *HexsendcheckBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *timesendcheckBox;
    QLineEdit *timelineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *RxNumlabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QComboBox *uartbox;
    QLabel *label_2;
    QComboBox *baudbox;
    QLabel *label;
    QComboBox *databox;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *stopbox;
    QLabel *label_5;
    QComboBox *nonebox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *RefreshUart;
    QPushButton *OpenUart;
    QPushButton *CloseUart;
    QPushButton *SendDataFile;
    QPushButton *SaveRecvDataFile;
    QPushButton *ClearRecvButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(930, 560);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RecvTextEdit = new QTextEdit(centralWidget);
        RecvTextEdit->setObjectName(QStringLiteral("RecvTextEdit"));
        RecvTextEdit->setGeometry(QRect(230, 10, 691, 311));
        RecvTextEdit->setReadOnly(true);
        SendTextEdit = new QTextEdit(centralWidget);
        SendTextEdit->setObjectName(QStringLiteral("SendTextEdit"));
        SendTextEdit->setGeometry(QRect(230, 360, 691, 121));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 330, 681, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        timecheckBox = new QCheckBox(layoutWidget);
        timecheckBox->setObjectName(QStringLiteral("timecheckBox"));
        QFont font;
        font.setPointSize(10);
        timecheckBox->setFont(font);

        horizontalLayout_3->addWidget(timecheckBox);

        recvcheckBox = new QCheckBox(layoutWidget);
        recvcheckBox->setObjectName(QStringLiteral("recvcheckBox"));
        recvcheckBox->setFont(font);

        horizontalLayout_3->addWidget(recvcheckBox);

        HexsendcheckBox = new QCheckBox(layoutWidget);
        HexsendcheckBox->setObjectName(QStringLiteral("HexsendcheckBox"));
        HexsendcheckBox->setFont(font);

        horizontalLayout_3->addWidget(HexsendcheckBox);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        timesendcheckBox = new QCheckBox(layoutWidget);
        timesendcheckBox->setObjectName(QStringLiteral("timesendcheckBox"));
        timesendcheckBox->setFont(font);

        horizontalLayout_2->addWidget(timesendcheckBox);

        timelineEdit = new QLineEdit(layoutWidget);
        timelineEdit->setObjectName(QStringLiteral("timelineEdit"));
        timelineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(timelineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout->addWidget(label_8);

        RxNumlabel = new QLabel(layoutWidget);
        RxNumlabel->setObjectName(QStringLiteral("RxNumlabel"));

        horizontalLayout->addWidget(RxNumlabel);


        horizontalLayout_4->addLayout(horizontalLayout);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 211, 481));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        uartbox = new QComboBox(widget);
        uartbox->setObjectName(QStringLiteral("uartbox"));

        gridLayout->addWidget(uartbox, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        baudbox = new QComboBox(widget);
        baudbox->addItem(QString());
        baudbox->addItem(QString());
        baudbox->addItem(QString());
        baudbox->addItem(QString());
        baudbox->addItem(QString());
        baudbox->setObjectName(QStringLiteral("baudbox"));

        gridLayout->addWidget(baudbox, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        databox = new QComboBox(widget);
        databox->addItem(QString());
        databox->addItem(QString());
        databox->addItem(QString());
        databox->addItem(QString());
        databox->setObjectName(QStringLiteral("databox"));

        gridLayout->addWidget(databox, 2, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        stopbox = new QComboBox(widget);
        stopbox->addItem(QString());
        stopbox->addItem(QString());
        stopbox->addItem(QString());
        stopbox->setObjectName(QStringLiteral("stopbox"));

        gridLayout->addWidget(stopbox, 3, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        nonebox = new QComboBox(widget);
        nonebox->addItem(QString());
        nonebox->setObjectName(QStringLiteral("nonebox"));

        gridLayout->addWidget(nonebox, 4, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        RefreshUart = new QPushButton(widget);
        RefreshUart->setObjectName(QStringLiteral("RefreshUart"));
        RefreshUart->setMinimumSize(QSize(20, 31));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        RefreshUart->setFont(font3);

        verticalLayout_2->addWidget(RefreshUart);

        OpenUart = new QPushButton(widget);
        OpenUart->setObjectName(QStringLiteral("OpenUart"));
        OpenUart->setMinimumSize(QSize(20, 31));
        OpenUart->setFont(font3);

        verticalLayout_2->addWidget(OpenUart);

        CloseUart = new QPushButton(widget);
        CloseUart->setObjectName(QStringLiteral("CloseUart"));
        CloseUart->setMinimumSize(QSize(0, 31));
        CloseUart->setFont(font3);

        verticalLayout_2->addWidget(CloseUart);

        SendDataFile = new QPushButton(widget);
        SendDataFile->setObjectName(QStringLiteral("SendDataFile"));
        SendDataFile->setMinimumSize(QSize(0, 31));
        SendDataFile->setFont(font3);

        verticalLayout_2->addWidget(SendDataFile);

        SaveRecvDataFile = new QPushButton(widget);
        SaveRecvDataFile->setObjectName(QStringLiteral("SaveRecvDataFile"));
        SaveRecvDataFile->setMinimumSize(QSize(0, 31));
        SaveRecvDataFile->setFont(font3);

        verticalLayout_2->addWidget(SaveRecvDataFile);

        ClearRecvButton = new QPushButton(widget);
        ClearRecvButton->setObjectName(QStringLiteral("ClearRecvButton"));
        ClearRecvButton->setMinimumSize(QSize(0, 31));
        ClearRecvButton->setFont(font3);

        verticalLayout_2->addWidget(ClearRecvButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 930, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        timecheckBox->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\227\266\351\227\264\346\210\263", nullptr));
        recvcheckBox->setText(QApplication::translate("MainWindow", "HEX\346\216\245\346\224\266", nullptr));
        HexsendcheckBox->setText(QApplication::translate("MainWindow", "HEX\345\217\221\351\200\201", nullptr));
        timesendcheckBox->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201(ms)", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Rx\357\274\232", nullptr));
        RxNumlabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\344\270\262 \345\217\243 \345\212\251 \346\211\213", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        baudbox->setItemText(0, QApplication::translate("MainWindow", "460800", nullptr));
        baudbox->setItemText(1, QApplication::translate("MainWindow", "230400", nullptr));
        baudbox->setItemText(2, QApplication::translate("MainWindow", "115200", nullptr));
        baudbox->setItemText(3, QApplication::translate("MainWindow", "9600", nullptr));
        baudbox->setItemText(4, QApplication::translate("MainWindow", "4800", nullptr));

        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        databox->setItemText(0, QApplication::translate("MainWindow", "8", nullptr));
        databox->setItemText(1, QApplication::translate("MainWindow", "7", nullptr));
        databox->setItemText(2, QApplication::translate("MainWindow", "6", nullptr));
        databox->setItemText(3, QApplication::translate("MainWindow", "5", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        stopbox->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        stopbox->setItemText(1, QApplication::translate("MainWindow", "1.5", nullptr));
        stopbox->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        nonebox->setItemText(0, QApplication::translate("MainWindow", "None", nullptr));

        RefreshUart->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        OpenUart->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\344\270\262\345\217\243", nullptr));
        CloseUart->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        SendDataFile->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        SaveRecvDataFile->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        ClearRecvButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
