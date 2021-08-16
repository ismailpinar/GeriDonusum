/********************************************************************************
** Form generated from reading UI file 'hakkinda.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAKKINDA_H
#define UI_HAKKINDA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hakkinda
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Hakkinda)
    {
        if (Hakkinda->objectName().isEmpty())
            Hakkinda->setObjectName(QString::fromUtf8("Hakkinda"));
        Hakkinda->resize(287, 193);
        label = new QLabel(Hakkinda);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 211, 121));
        pushButton = new QPushButton(Hakkinda);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 150, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Info.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        retranslateUi(Hakkinda);

        QMetaObject::connectSlotsByName(Hakkinda);
    } // setupUi

    void retranslateUi(QWidget *Hakkinda)
    {
        Hakkinda->setWindowTitle(QCoreApplication::translate("Hakkinda", "Form", nullptr));
        label->setText(QCoreApplication::translate("Hakkinda", "<html><head/><body><p>	by P\304\261nar Soft</p><p><br/></p><p>        pinarsoftware@gmail.com</p></body></html>", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Hakkinda: public Ui_Hakkinda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAKKINDA_H
