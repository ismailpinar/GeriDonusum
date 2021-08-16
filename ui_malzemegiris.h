/********************************************************************************
** Form generated from reading UI file 'malzemegiris.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MALZEMEGIRIS_H
#define UI_MALZEMEGIRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MalzemeGiris
{
public:
    QToolButton *btnClose;
    QLabel *lblMusteriAdi;
    QLabel *lblMalzemeAdi;
    QComboBox *cmbMalzemeAdi;
    QComboBox *cmbMusteriAdi;
    QLabel *lblMiktar;
    QLabel *lblBirimFiyat;
    QLabel *lblFire;
    QLabel *lblToplam;
    QLabel *lblBorc;
    QLabel *lblKalan;
    QLabel *lblNet;
    QLineEdit *txtMiktar;
    QLineEdit *txtFire;
    QLineEdit *txtNet;
    QLineEdit *txtBirimFiyat;
    QPushButton *btnKaydet;
    QLineEdit *txtOdenen;
    QLabel *lblOdenen;
    QLineEdit *txtFireKg;
    QLabel *lblFireKg;
    QPushButton *btnZaman;

    void setupUi(QWidget *MalzemeGiris)
    {
        if (MalzemeGiris->objectName().isEmpty())
            MalzemeGiris->setObjectName(QString::fromUtf8("MalzemeGiris"));
        MalzemeGiris->resize(741, 621);
        btnClose = new QToolButton(MalzemeGiris);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(700, 20, 31, 31));
        lblMusteriAdi = new QLabel(MalzemeGiris);
        lblMusteriAdi->setObjectName(QString::fromUtf8("lblMusteriAdi"));
        lblMusteriAdi->setGeometry(QRect(20, 10, 181, 17));
        lblMalzemeAdi = new QLabel(MalzemeGiris);
        lblMalzemeAdi->setObjectName(QString::fromUtf8("lblMalzemeAdi"));
        lblMalzemeAdi->setGeometry(QRect(220, 230, 181, 17));
        cmbMalzemeAdi = new QComboBox(MalzemeGiris);
        cmbMalzemeAdi->setObjectName(QString::fromUtf8("cmbMalzemeAdi"));
        cmbMalzemeAdi->setGeometry(QRect(220, 250, 251, 31));
        cmbMusteriAdi = new QComboBox(MalzemeGiris);
        cmbMusteriAdi->setObjectName(QString::fromUtf8("cmbMusteriAdi"));
        cmbMusteriAdi->setGeometry(QRect(20, 30, 251, 31));
        lblMiktar = new QLabel(MalzemeGiris);
        lblMiktar->setObjectName(QString::fromUtf8("lblMiktar"));
        lblMiktar->setGeometry(QRect(220, 300, 181, 17));
        lblBirimFiyat = new QLabel(MalzemeGiris);
        lblBirimFiyat->setObjectName(QString::fromUtf8("lblBirimFiyat"));
        lblBirimFiyat->setGeometry(QRect(490, 230, 181, 17));
        lblFire = new QLabel(MalzemeGiris);
        lblFire->setObjectName(QString::fromUtf8("lblFire"));
        lblFire->setGeometry(QRect(490, 300, 181, 17));
        lblToplam = new QLabel(MalzemeGiris);
        lblToplam->setObjectName(QString::fromUtf8("lblToplam"));
        lblToplam->setGeometry(QRect(20, 340, 681, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        lblToplam->setFont(font);
        lblToplam->setAlignment(Qt::AlignCenter);
        lblBorc = new QLabel(MalzemeGiris);
        lblBorc->setObjectName(QString::fromUtf8("lblBorc"));
        lblBorc->setGeometry(QRect(20, 420, 721, 91));
        lblBorc->setFont(font);
        lblBorc->setAlignment(Qt::AlignCenter);
        lblKalan = new QLabel(MalzemeGiris);
        lblKalan->setObjectName(QString::fromUtf8("lblKalan"));
        lblKalan->setGeometry(QRect(20, 510, 691, 91));
        lblKalan->setFont(font);
        lblKalan->setAlignment(Qt::AlignCenter);
        lblNet = new QLabel(MalzemeGiris);
        lblNet->setObjectName(QString::fromUtf8("lblNet"));
        lblNet->setGeometry(QRect(0, 310, 181, 17));
        txtMiktar = new QLineEdit(MalzemeGiris);
        txtMiktar->setObjectName(QString::fromUtf8("txtMiktar"));
        txtMiktar->setGeometry(QRect(40, 440, 113, 25));
        txtFire = new QLineEdit(MalzemeGiris);
        txtFire->setObjectName(QString::fromUtf8("txtFire"));
        txtFire->setGeometry(QRect(40, 480, 113, 25));
        txtNet = new QLineEdit(MalzemeGiris);
        txtNet->setObjectName(QString::fromUtf8("txtNet"));
        txtNet->setGeometry(QRect(40, 400, 113, 25));
        txtBirimFiyat = new QLineEdit(MalzemeGiris);
        txtBirimFiyat->setObjectName(QString::fromUtf8("txtBirimFiyat"));
        txtBirimFiyat->setGeometry(QRect(490, 260, 113, 25));
        btnKaydet = new QPushButton(MalzemeGiris);
        btnKaydet->setObjectName(QString::fromUtf8("btnKaydet"));
        btnKaydet->setGeometry(QRect(330, 580, 83, 25));
        txtOdenen = new QLineEdit(MalzemeGiris);
        txtOdenen->setObjectName(QString::fromUtf8("txtOdenen"));
        txtOdenen->setGeometry(QRect(40, 520, 113, 25));
        lblOdenen = new QLabel(MalzemeGiris);
        lblOdenen->setObjectName(QString::fromUtf8("lblOdenen"));
        lblOdenen->setGeometry(QRect(20, 510, 181, 17));
        txtFireKg = new QLineEdit(MalzemeGiris);
        txtFireKg->setObjectName(QString::fromUtf8("txtFireKg"));
        txtFireKg->setGeometry(QRect(480, 130, 113, 25));
        lblFireKg = new QLabel(MalzemeGiris);
        lblFireKg->setObjectName(QString::fromUtf8("lblFireKg"));
        lblFireKg->setGeometry(QRect(610, 390, 181, 17));
        btnZaman = new QPushButton(MalzemeGiris);
        btnZaman->setObjectName(QString::fromUtf8("btnZaman"));
        btnZaman->setGeometry(QRect(340, 70, 191, 25));

        retranslateUi(MalzemeGiris);

        QMetaObject::connectSlotsByName(MalzemeGiris);
    } // setupUi

    void retranslateUi(QWidget *MalzemeGiris)
    {
        MalzemeGiris->setWindowTitle(QCoreApplication::translate("MalzemeGiris", "Form", nullptr));
        btnClose->setText(QCoreApplication::translate("MalzemeGiris", "X", nullptr));
        lblMusteriAdi->setText(QCoreApplication::translate("MalzemeGiris", "M\303\274\305\237teri Ad\304\261", nullptr));
        lblMalzemeAdi->setText(QCoreApplication::translate("MalzemeGiris", "Malzeme Ad\304\261", nullptr));
        lblMiktar->setText(QCoreApplication::translate("MalzemeGiris", "Miktar(Br)", nullptr));
        lblBirimFiyat->setText(QCoreApplication::translate("MalzemeGiris", "Birim Fiyat (YTL)", nullptr));
        lblFire->setText(QCoreApplication::translate("MalzemeGiris", "Fire (%)", nullptr));
        lblToplam->setText(QCoreApplication::translate("MalzemeGiris", "Toplam = 1 YTL", nullptr));
        lblBorc->setText(QCoreApplication::translate("MalzemeGiris", "Mevcut Bor\303\247 = 10 YTL", nullptr));
        lblKalan->setText(QCoreApplication::translate("MalzemeGiris", "Kalan = 11 YTL", nullptr));
        lblNet->setText(QCoreApplication::translate("MalzemeGiris", "Net(Br)", nullptr));
        btnKaydet->setText(QCoreApplication::translate("MalzemeGiris", "KAYDET", nullptr));
        lblOdenen->setText(QCoreApplication::translate("MalzemeGiris", "\303\226denen (YTL)", nullptr));
        lblFireKg->setText(QCoreApplication::translate("MalzemeGiris", "Fire(Br)", nullptr));
        btnZaman->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MalzemeGiris: public Ui_MalzemeGiris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MALZEMEGIRIS_H
