#include "dialog.h"
#include "ui_dialog.h"
#include "QDebug"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
        setWindowFlags(Qt::FramelessWindowHint);

    ui->setupUi(this);
    this->dateTime = "";









}


Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_calendarWidget_clicked(const QDate &date)
{
    this->date = date.toString("yyyy-MM-dd");
}

void Dialog::on_pushButton_clicked()
{

}

void Dialog::on_btnYukariSaat_clicked()
{
    ui->lcdsaat->display(ui->lcdsaat->value()+1);

    if(ui->lcdsaat->value() == 24)
    {
        ui->lcdsaat->display(0);
    }
}


void Dialog::on_btnYukariDk_clicked()
{
    ui->lcdDk->display(ui->lcdDk->value()+1);

    if(ui->lcdDk->value() == 60)
    {
        ui->lcdDk->display(0);
    }
}


void Dialog::on_btnAsagiSaat_clicked()
{
    ui->lcdsaat->display(ui->lcdsaat->value()-1);

    if(ui->lcdsaat->value() == -1)
    {
        ui->lcdsaat->display(23);
    }
}


void Dialog::on_btnAsagiDk_clicked()
{
    ui->lcdDk->display(ui->lcdDk->value()-1);

    if(ui->lcdDk->value() == -1)
    {
        ui->lcdDk->display(59);
    }


}


void Dialog::on_btnTamam_clicked()
{
    QString tarih = ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");


    QString saat = QString::number(ui->lcdsaat->value());
    QString dk =  QString::number(ui->lcdDk->value());

    qDebug()<<tarih << " Saat : "<< saat <<":"<<dk;


    if(saat.size() == 1)
    {
        saat = "0" + saat;
    }
    if(dk.size() == 1)
    {
        dk = "0" + dk;
    }

    QString date = tarih + " " + saat +":" + dk+":" + "00";


    zaman = QDateTime::fromString(date, "yyyy-MM-dd hh:mm:ss");

    qDebug()<<zaman <<" sss";



    this->close();

}


void Dialog::showEvent(QShowEvent *ev)
{

    ui->calendarWidget->setSelectedDate(zaman.date());

    int saat = zaman.time().hour();
    int dk = zaman.time().minute();


    ui->lcdsaat->display(saat);
    ui->lcdDk->display(dk);


}
void Dialog::on_Dialog_accepted()
{

}

