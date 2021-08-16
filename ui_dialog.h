/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnYukariSaat;
    QLCDNumber *lcdsaat;
    QPushButton *btnAsagiSaat;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnYukariDk;
    QLCDNumber *lcdDk;
    QPushButton *btnAsagiDk;
    QPushButton *btnTamam;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1280, 675);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 761, 661));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(gridLayoutWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout->addWidget(calendarWidget, 0, 1, 1, 1);

        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(840, 10, 211, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnYukariSaat = new QPushButton(verticalLayoutWidget);
        btnYukariSaat->setObjectName(QString::fromUtf8("btnYukariSaat"));
        btnYukariSaat->setMinimumSize(QSize(0, 100));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/yukari.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnYukariSaat->setIcon(icon);
        btnYukariSaat->setIconSize(QSize(60, 60));

        verticalLayout->addWidget(btnYukariSaat);

        lcdsaat = new QLCDNumber(verticalLayoutWidget);
        lcdsaat->setObjectName(QString::fromUtf8("lcdsaat"));
        lcdsaat->setDigitCount(2);
        lcdsaat->setProperty("intValue", QVariant(12));

        verticalLayout->addWidget(lcdsaat);

        btnAsagiSaat = new QPushButton(verticalLayoutWidget);
        btnAsagiSaat->setObjectName(QString::fromUtf8("btnAsagiSaat"));
        btnAsagiSaat->setMinimumSize(QSize(0, 100));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/asagi.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAsagiSaat->setIcon(icon1);
        btnAsagiSaat->setIconSize(QSize(60, 60));

        verticalLayout->addWidget(btnAsagiSaat);

        verticalLayoutWidget_2 = new QWidget(Dialog);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1050, 10, 211, 471));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnYukariDk = new QPushButton(verticalLayoutWidget_2);
        btnYukariDk->setObjectName(QString::fromUtf8("btnYukariDk"));
        btnYukariDk->setMinimumSize(QSize(0, 100));
        btnYukariDk->setIcon(icon);
        btnYukariDk->setIconSize(QSize(60, 60));

        verticalLayout_2->addWidget(btnYukariDk);

        lcdDk = new QLCDNumber(verticalLayoutWidget_2);
        lcdDk->setObjectName(QString::fromUtf8("lcdDk"));
        lcdDk->setSmallDecimalPoint(false);
        lcdDk->setDigitCount(2);
        lcdDk->setSegmentStyle(QLCDNumber::Filled);
        lcdDk->setProperty("value", QVariant(0.000000000000000));
        lcdDk->setProperty("intValue", QVariant(0));

        verticalLayout_2->addWidget(lcdDk);

        btnAsagiDk = new QPushButton(verticalLayoutWidget_2);
        btnAsagiDk->setObjectName(QString::fromUtf8("btnAsagiDk"));
        btnAsagiDk->setMinimumSize(QSize(0, 100));
        btnAsagiDk->setIcon(icon1);
        btnAsagiDk->setIconSize(QSize(60, 60));

        verticalLayout_2->addWidget(btnAsagiDk);

        btnTamam = new QPushButton(Dialog);
        btnTamam->setObjectName(QString::fromUtf8("btnTamam"));
        btnTamam->setGeometry(QRect(840, 570, 421, 91));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        btnYukariSaat->setText(QString());
        btnAsagiSaat->setText(QString());
        btnYukariDk->setText(QString());
        btnAsagiDk->setText(QString());
        btnTamam->setText(QCoreApplication::translate("Dialog", "TAMAM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
