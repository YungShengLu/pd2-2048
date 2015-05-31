/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *pn1;
    QLabel *lab1_1;
    QLabel *lab1_2;
    QPushButton *btn1;
    QWidget *pn1_1;
    QLabel *lab1_3;
    QLCDNumber *lcd1;
    QWidget *pn1_2;
    QLabel *lab1_4;
    QLCDNumber *lcd2;
    QWidget *pn2;
    QLabel *lab2_1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(701, 720);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../number/num2048.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pn1 = new QWidget(centralWidget);
        pn1->setObjectName(QStringLiteral("pn1"));
        pn1->setGeometry(QRect(40, 10, 621, 151));
        lab1_1 = new QLabel(pn1);
        lab1_1->setObjectName(QStringLiteral("lab1_1"));
        lab1_1->setGeometry(QRect(20, 20, 171, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setPointSize(60);
        font1.setBold(true);
        font1.setWeight(75);
        lab1_1->setFont(font1);
        lab1_1->setTextFormat(Qt::AutoText);
        lab1_2 = new QLabel(pn1);
        lab1_2->setObjectName(QStringLiteral("lab1_2"));
        lab1_2->setGeometry(QRect(30, 100, 411, 41));
        btn1 = new QPushButton(pn1);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setGeometry(QRect(470, 100, 131, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        btn1->setFont(font2);
        btn1->setMouseTracking(true);
        btn1->setAutoFillBackground(false);
        btn1->setStyleSheet(QStringLiteral(""));
        btn1->setAutoDefault(true);
        btn1->setDefault(false);
        btn1->setFlat(false);
        pn1_1 = new QWidget(pn1);
        pn1_1->setObjectName(QStringLiteral("pn1_1"));
        pn1_1->setGeometry(QRect(380, 10, 111, 80));
        lab1_3 = new QLabel(pn1_1);
        lab1_3->setObjectName(QStringLiteral("lab1_3"));
        lab1_3->setGeometry(QRect(10, 10, 91, 31));
        lcd1 = new QLCDNumber(pn1_1);
        lcd1->setObjectName(QStringLiteral("lcd1"));
        lcd1->setGeometry(QRect(20, 40, 71, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        lcd1->setFont(font3);
        pn1_2 = new QWidget(pn1);
        pn1_2->setObjectName(QStringLiteral("pn1_2"));
        pn1_2->setGeometry(QRect(500, 10, 111, 80));
        lab1_4 = new QLabel(pn1_2);
        lab1_4->setObjectName(QStringLiteral("lab1_4"));
        lab1_4->setGeometry(QRect(10, 10, 91, 31));
        lcd2 = new QLCDNumber(pn1_2);
        lcd2->setObjectName(QStringLiteral("lcd2"));
        lcd2->setGeometry(QRect(20, 40, 71, 31));
        lcd2->setFont(font3);
        pn2 = new QWidget(centralWidget);
        pn2->setObjectName(QStringLiteral("pn2"));
        pn2->setGeometry(QRect(39, 160, 621, 531));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(pn2->sizePolicy().hasHeightForWidth());
        pn2->setSizePolicy(sizePolicy);
        lab2_1 = new QLabel(pn2);
        lab2_1->setObjectName(QStringLiteral("lab2_1"));
        lab2_1->setGeometry(QRect(40, 10, 551, 521));
        lab2_1->setFrameShape(QFrame::StyledPanel);
        lab2_1->setPixmap(QPixmap(QString::fromUtf8("../table.png")));
        lab2_1->setScaledContents(true);
        lab2_1->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "2048", 0));
        lab1_1->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">2048</span></p></body></html>", 0));
        lab1_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:400;\">Join the numbers and get to the </span><span style=\" font-size:16pt;\">2048 </span><span style=\" font-size:16pt; font-weight:400;\">tile!</span></p></body></html>", 0));
        btn1->setText(QApplication::translate("MainWindow", "New Game", 0));
        lab1_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">SCORE</span></p></body></html>", 0));
        lab1_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">BEST</span></p></body></html>", 0));
        lab2_1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
