/********************************************************************************
** Form generated from reading UI file 'anaform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANAFORM_H
#define UI_ANAFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnaForm
{
public:
    QPushButton *btnUrunKayit;
    QPushButton *btnMusteriKayit;
    QToolButton *btnClose;
    QPushButton *btnMalzemeGiris;
    QTableWidget *tblListe;
    QLineEdit *txtID;
    QLineEdit *txtAd;
    QLineEdit *txtMalzeme;
    QLineEdit *txtBirimFiyat;
    QLineEdit *txtBorc;
    QLineEdit *txtNet;
    QLineEdit *txtOdenen;
    QLineEdit *txtToplam;
    QLineEdit *txtFire;
    QLineEdit *txtMiktar;
    QPushButton *btnFiltreler;
    QLineEdit *tMiktar;
    QLineEdit *tFire;
    QLineEdit *tnet;
    QLineEdit *tToplam;
    QLineEdit *tOdenen;
    QLineEdit *tBorc;
    QLabel *lblToplam;
    QPushButton *btnPDFCikar;
    QPushButton *ebtnSil;
    QPushButton *btnBaslangic;
    QPushButton *btnBitis;
    QPushButton *pushButton;

    void setupUi(QWidget *AnaForm)
    {
        if (AnaForm->objectName().isEmpty())
            AnaForm->setObjectName(QString::fromUtf8("AnaForm"));
        AnaForm->resize(919, 507);
        btnUrunKayit = new QPushButton(AnaForm);
        btnUrunKayit->setObjectName(QString::fromUtf8("btnUrunKayit"));
        btnUrunKayit->setGeometry(QRect(750, 90, 131, 25));
        btnMusteriKayit = new QPushButton(AnaForm);
        btnMusteriKayit->setObjectName(QString::fromUtf8("btnMusteriKayit"));
        btnMusteriKayit->setGeometry(QRect(750, 130, 131, 25));
        btnClose = new QToolButton(AnaForm);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(850, 10, 31, 31));
        btnMalzemeGiris = new QPushButton(AnaForm);
        btnMalzemeGiris->setObjectName(QString::fromUtf8("btnMalzemeGiris"));
        btnMalzemeGiris->setGeometry(QRect(750, 170, 131, 25));
        tblListe = new QTableWidget(AnaForm);
        tblListe->setObjectName(QString::fromUtf8("tblListe"));
        tblListe->setGeometry(QRect(10, 90, 731, 341));
        txtID = new QLineEdit(AnaForm);
        txtID->setObjectName(QString::fromUtf8("txtID"));
        txtID->setGeometry(QRect(10, 40, 113, 25));
        txtAd = new QLineEdit(AnaForm);
        txtAd->setObjectName(QString::fromUtf8("txtAd"));
        txtAd->setGeometry(QRect(140, 40, 113, 25));
        txtMalzeme = new QLineEdit(AnaForm);
        txtMalzeme->setObjectName(QString::fromUtf8("txtMalzeme"));
        txtMalzeme->setGeometry(QRect(270, 40, 113, 25));
        txtBirimFiyat = new QLineEdit(AnaForm);
        txtBirimFiyat->setObjectName(QString::fromUtf8("txtBirimFiyat"));
        txtBirimFiyat->setGeometry(QRect(510, 40, 113, 25));
        txtBorc = new QLineEdit(AnaForm);
        txtBorc->setObjectName(QString::fromUtf8("txtBorc"));
        txtBorc->setGeometry(QRect(510, 70, 113, 25));
        txtNet = new QLineEdit(AnaForm);
        txtNet->setObjectName(QString::fromUtf8("txtNet"));
        txtNet->setGeometry(QRect(140, 70, 113, 25));
        txtOdenen = new QLineEdit(AnaForm);
        txtOdenen->setObjectName(QString::fromUtf8("txtOdenen"));
        txtOdenen->setGeometry(QRect(390, 70, 113, 25));
        txtToplam = new QLineEdit(AnaForm);
        txtToplam->setObjectName(QString::fromUtf8("txtToplam"));
        txtToplam->setGeometry(QRect(270, 70, 113, 25));
        txtFire = new QLineEdit(AnaForm);
        txtFire->setObjectName(QString::fromUtf8("txtFire"));
        txtFire->setGeometry(QRect(10, 70, 113, 25));
        txtMiktar = new QLineEdit(AnaForm);
        txtMiktar->setObjectName(QString::fromUtf8("txtMiktar"));
        txtMiktar->setGeometry(QRect(630, 40, 113, 25));
        btnFiltreler = new QPushButton(AnaForm);
        btnFiltreler->setObjectName(QString::fromUtf8("btnFiltreler"));
        btnFiltreler->setGeometry(QRect(770, 250, 83, 25));
        tMiktar = new QLineEdit(AnaForm);
        tMiktar->setObjectName(QString::fromUtf8("tMiktar"));
        tMiktar->setGeometry(QRect(40, 470, 113, 25));
        tFire = new QLineEdit(AnaForm);
        tFire->setObjectName(QString::fromUtf8("tFire"));
        tFire->setGeometry(QRect(170, 470, 113, 25));
        tnet = new QLineEdit(AnaForm);
        tnet->setObjectName(QString::fromUtf8("tnet"));
        tnet->setGeometry(QRect(300, 470, 113, 25));
        tToplam = new QLineEdit(AnaForm);
        tToplam->setObjectName(QString::fromUtf8("tToplam"));
        tToplam->setGeometry(QRect(430, 470, 113, 25));
        tOdenen = new QLineEdit(AnaForm);
        tOdenen->setObjectName(QString::fromUtf8("tOdenen"));
        tOdenen->setGeometry(QRect(560, 470, 113, 25));
        tBorc = new QLineEdit(AnaForm);
        tBorc->setObjectName(QString::fromUtf8("tBorc"));
        tBorc->setGeometry(QRect(700, 470, 113, 25));
        lblToplam = new QLabel(AnaForm);
        lblToplam->setObjectName(QString::fromUtf8("lblToplam"));
        lblToplam->setGeometry(QRect(751, 369, 161, 61));
        QFont font;
        font.setPointSize(20);
        lblToplam->setFont(font);
        btnPDFCikar = new QPushButton(AnaForm);
        btnPDFCikar->setObjectName(QString::fromUtf8("btnPDFCikar"));
        btnPDFCikar->setGeometry(QRect(770, 210, 83, 25));
        ebtnSil = new QPushButton(AnaForm);
        ebtnSil->setObjectName(QString::fromUtf8("ebtnSil"));
        ebtnSil->setGeometry(QRect(770, 310, 89, 25));
        btnBaslangic = new QPushButton(AnaForm);
        btnBaslangic->setObjectName(QString::fromUtf8("btnBaslangic"));
        btnBaslangic->setGeometry(QRect(120, 10, 89, 25));
        btnBitis = new QPushButton(AnaForm);
        btnBitis->setObjectName(QString::fromUtf8("btnBitis"));
        btnBitis->setGeometry(QRect(240, 10, 89, 25));
        pushButton = new QPushButton(AnaForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(860, 450, 41, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Info.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        retranslateUi(AnaForm);

        QMetaObject::connectSlotsByName(AnaForm);
    } // setupUi

    void retranslateUi(QWidget *AnaForm)
    {
        AnaForm->setWindowTitle(QCoreApplication::translate("AnaForm", "Form", nullptr));
        btnUrunKayit->setText(QCoreApplication::translate("AnaForm", "\303\234r\303\274nler", nullptr));
        btnMusteriKayit->setText(QCoreApplication::translate("AnaForm", "M\303\274\305\237teriler", nullptr));
        btnClose->setText(QCoreApplication::translate("AnaForm", "X", nullptr));
        btnMalzemeGiris->setText(QCoreApplication::translate("AnaForm", "Malzeme Giri\305\237", nullptr));
        btnFiltreler->setText(QCoreApplication::translate("AnaForm", "Filtrele", nullptr));
        lblToplam->setText(QCoreApplication::translate("AnaForm", "TOPLAM =", nullptr));
        btnPDFCikar->setText(QCoreApplication::translate("AnaForm", "PDF \303\207\304\261kar", nullptr));
        ebtnSil->setText(QCoreApplication::translate("AnaForm", "Sil", nullptr));
        btnBaslangic->setText(QString());
        btnBitis->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AnaForm: public Ui_AnaForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANAFORM_H
