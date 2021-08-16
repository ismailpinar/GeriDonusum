/********************************************************************************
** Form generated from reading UI file 'musterigirisi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSTERIGIRISI_H
#define UI_MUSTERIGIRISI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusteriGirisi
{
public:
    QWidget *centralwidget;
    QPushButton *btnEkle;
    QPushButton *btnSil;
    QTextEdit *txtSoyad;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QTableWidget *tbwMusteriUrun;
    QPushButton *btnKaydet;
    QToolButton *btnClose;
    QTextEdit *txtAdi;
    QLineEdit *txtBorc;
    QLabel *lblBirimFiyat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MusteriGirisi)
    {
        if (MusteriGirisi->objectName().isEmpty())
            MusteriGirisi->setObjectName(QString::fromUtf8("MusteriGirisi"));
        MusteriGirisi->resize(428, 850);
        centralwidget = new QWidget(MusteriGirisi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnEkle = new QPushButton(centralwidget);
        btnEkle->setObjectName(QString::fromUtf8("btnEkle"));
        btnEkle->setGeometry(QRect(330, 650, 83, 71));
        btnSil = new QPushButton(centralwidget);
        btnSil->setObjectName(QString::fromUtf8("btnSil"));
        btnSil->setGeometry(QRect(330, 730, 83, 71));
        txtSoyad = new QTextEdit(centralwidget);
        txtSoyad->setObjectName(QString::fromUtf8("txtSoyad"));
        txtSoyad->setGeometry(QRect(30, 140, 271, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 60, 62, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 200, 161, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 120, 62, 17));
        tbwMusteriUrun = new QTableWidget(centralwidget);
        tbwMusteriUrun->setObjectName(QString::fromUtf8("tbwMusteriUrun"));
        tbwMusteriUrun->setGeometry(QRect(30, 230, 271, 591));
        btnKaydet = new QPushButton(centralwidget);
        btnKaydet->setObjectName(QString::fromUtf8("btnKaydet"));
        btnKaydet->setGeometry(QRect(330, 90, 83, 71));
        btnClose = new QToolButton(centralwidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(380, 10, 31, 31));
        txtAdi = new QTextEdit(centralwidget);
        txtAdi->setObjectName(QString::fromUtf8("txtAdi"));
        txtAdi->setGeometry(QRect(90, 50, 104, 70));
        txtBorc = new QLineEdit(centralwidget);
        txtBorc->setObjectName(QString::fromUtf8("txtBorc"));
        txtBorc->setGeometry(QRect(250, 200, 113, 25));
        lblBirimFiyat = new QLabel(centralwidget);
        lblBirimFiyat->setObjectName(QString::fromUtf8("lblBirimFiyat"));
        lblBirimFiyat->setGeometry(QRect(250, 170, 181, 17));
        MusteriGirisi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MusteriGirisi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 428, 24));
        MusteriGirisi->setMenuBar(menubar);
        statusbar = new QStatusBar(MusteriGirisi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MusteriGirisi->setStatusBar(statusbar);

        retranslateUi(MusteriGirisi);

        QMetaObject::connectSlotsByName(MusteriGirisi);
    } // setupUi

    void retranslateUi(QMainWindow *MusteriGirisi)
    {
        MusteriGirisi->setWindowTitle(QCoreApplication::translate("MusteriGirisi", "AnaForm", nullptr));
        btnEkle->setText(QCoreApplication::translate("MusteriGirisi", "EKLE", nullptr));
        btnSil->setText(QCoreApplication::translate("MusteriGirisi", "S\304\260L", nullptr));
        label->setText(QCoreApplication::translate("MusteriGirisi", "Ad\304\261", nullptr));
        label_2->setText(QCoreApplication::translate("MusteriGirisi", "\303\234r\303\274n Bilgileri", nullptr));
        label_4->setText(QCoreApplication::translate("MusteriGirisi", "SoyAd\304\261", nullptr));
        btnKaydet->setText(QCoreApplication::translate("MusteriGirisi", "Kaydet", nullptr));
        btnClose->setText(QCoreApplication::translate("MusteriGirisi", "X", nullptr));
        lblBirimFiyat->setText(QCoreApplication::translate("MusteriGirisi", "Bor\303\247 (YTL)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusteriGirisi: public Ui_MusteriGirisi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSTERIGIRISI_H
