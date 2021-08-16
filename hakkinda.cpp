#include "hakkinda.h"
#include "ui_hakkinda.h"

#include <QMessageBox>

Hakkinda::Hakkinda(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Hakkinda)
{
    ui->setupUi(this);

    this->setWindowTitle ("Hakkında");
}

Hakkinda::~Hakkinda()
{
    delete ui;
}

void Hakkinda::on_pushButton_clicked()
{
    QMessageBox::aboutQt(this,"Qt Hakkında");

}

