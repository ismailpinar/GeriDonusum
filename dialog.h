#ifndef DIALOG_H
#define DIALOG_H

#include <QDateTime>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString dateTime;
    QString date;

    QDateTime zaman;
protected:
    void showEvent(QShowEvent *ev);

private slots:

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_clicked();

    void on_btnYukariSaat_clicked();

    void on_btnYukariDk_clicked();

    void on_btnAsagiSaat_clicked();

    void on_btnAsagiDk_clicked();

    void on_btnTamam_clicked();

    void on_Dialog_accepted();



private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
