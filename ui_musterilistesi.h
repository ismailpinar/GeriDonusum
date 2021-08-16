/********************************************************************************
** Form generated from reading UI file 'musterilistesi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSTERILISTESI_H
#define UI_MUSTERILISTESI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusteriListesi
{
public:
    QPushButton *btnMLGuncelle;
    QPushButton *btnMLSil;
    QLabel *lblMusteriListesi;
    QTableWidget *tblMusteriListesi;
    QPushButton *btnEkle;
    QToolButton *btnClose;
    QLabel *lblToplam;
    QLineEdit *txtToplam;

    void setupUi(QWidget *MusteriListesi)
    {
        if (MusteriListesi->objectName().isEmpty())
            MusteriListesi->setObjectName(QString::fromUtf8("MusteriListesi"));
        MusteriListesi->resize(466, 900);
        btnMLGuncelle = new QPushButton(MusteriListesi);
        btnMLGuncelle->setObjectName(QString::fromUtf8("btnMLGuncelle"));
        btnMLGuncelle->setGeometry(QRect(360, 320, 83, 81));
        btnMLSil = new QPushButton(MusteriListesi);
        btnMLSil->setObjectName(QString::fromUtf8("btnMLSil"));
        btnMLSil->setGeometry(QRect(360, 230, 83, 81));
        lblMusteriListesi = new QLabel(MusteriListesi);
        lblMusteriListesi->setObjectName(QString::fromUtf8("lblMusteriListesi"));
        lblMusteriListesi->setGeometry(QRect(20, 20, 161, 17));
        tblMusteriListesi = new QTableWidget(MusteriListesi);
        tblMusteriListesi->setObjectName(QString::fromUtf8("tblMusteriListesi"));
        tblMusteriListesi->setGeometry(QRect(20, 50, 321, 831));
        btnEkle = new QPushButton(MusteriListesi);
        btnEkle->setObjectName(QString::fromUtf8("btnEkle"));
        btnEkle->setGeometry(QRect(360, 140, 83, 81));
        btnClose = new QToolButton(MusteriListesi);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(410, 10, 31, 31));
        lblToplam = new QLabel(MusteriListesi);
        lblToplam->setObjectName(QString::fromUtf8("lblToplam"));
        lblToplam->setGeometry(QRect(260, 770, 181, 17));
        txtToplam = new QLineEdit(MusteriListesi);
        txtToplam->setObjectName(QString::fromUtf8("txtToplam"));
        txtToplam->setGeometry(QRect(260, 800, 113, 25));

        retranslateUi(MusteriListesi);

        QMetaObject::connectSlotsByName(MusteriListesi);
    } // setupUi

    void retranslateUi(QWidget *MusteriListesi)
    {
        MusteriListesi->setWindowTitle(QCoreApplication::translate("MusteriListesi", "Form", nullptr));
        btnMLGuncelle->setText(QCoreApplication::translate("MusteriListesi", "G\303\234NCELLE", nullptr));
        btnMLSil->setText(QCoreApplication::translate("MusteriListesi", "S\304\260L", nullptr));
        lblMusteriListesi->setText(QCoreApplication::translate("MusteriListesi", "M\303\274\305\237teri Listesi", nullptr));
        btnEkle->setText(QCoreApplication::translate("MusteriListesi", "EKLE", nullptr));
        btnClose->setText(QCoreApplication::translate("MusteriListesi", "X", nullptr));
        lblToplam->setText(QCoreApplication::translate("MusteriListesi", "Toplam Bor\303\247 (YTL)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusteriListesi: public Ui_MusteriListesi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSTERILISTESI_H
