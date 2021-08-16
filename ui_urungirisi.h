/********************************************************************************
** Form generated from reading UI file 'urungirisi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URUNGIRISI_H
#define UI_URUNGIRISI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_urunGirisi
{
public:
    QTableWidget *tbwUrun;
    QPushButton *btnEkle;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *txtUrun;
    QToolButton *btnClose;
    QPushButton *btnSil;

    void setupUi(QWidget *urunGirisi)
    {
        if (urunGirisi->objectName().isEmpty())
            urunGirisi->setObjectName(QString::fromUtf8("urunGirisi"));
        urunGirisi->resize(415, 581);
        tbwUrun = new QTableWidget(urunGirisi);
        tbwUrun->setObjectName(QString::fromUtf8("tbwUrun"));
        tbwUrun->setGeometry(QRect(20, 160, 271, 401));
        btnEkle = new QPushButton(urunGirisi);
        btnEkle->setObjectName(QString::fromUtf8("btnEkle"));
        btnEkle->setGeometry(QRect(320, 80, 83, 71));
        label = new QLabel(urunGirisi);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 62, 17));
        label_2 = new QLabel(urunGirisi);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 130, 161, 17));
        txtUrun = new QTextEdit(urunGirisi);
        txtUrun->setObjectName(QString::fromUtf8("txtUrun"));
        txtUrun->setGeometry(QRect(20, 80, 271, 31));
        btnClose = new QToolButton(urunGirisi);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(370, 10, 31, 31));
        btnSil = new QPushButton(urunGirisi);
        btnSil->setObjectName(QString::fromUtf8("btnSil"));
        btnSil->setGeometry(QRect(320, 160, 83, 71));

        retranslateUi(urunGirisi);

        QMetaObject::connectSlotsByName(urunGirisi);
    } // setupUi

    void retranslateUi(QWidget *urunGirisi)
    {
        urunGirisi->setWindowTitle(QCoreApplication::translate("urunGirisi", "Form", nullptr));
        btnEkle->setText(QCoreApplication::translate("urunGirisi", "EKLE", nullptr));
        label->setText(QCoreApplication::translate("urunGirisi", "\303\234r\303\274n", nullptr));
        label_2->setText(QCoreApplication::translate("urunGirisi", "\303\234r\303\274nler", nullptr));
        btnClose->setText(QCoreApplication::translate("urunGirisi", "X", nullptr));
        btnSil->setText(QCoreApplication::translate("urunGirisi", "S\304\260L", nullptr));
    } // retranslateUi

};

namespace Ui {
    class urunGirisi: public Ui_urunGirisi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URUNGIRISI_H
