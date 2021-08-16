#ifndef ANAFORM_H
#define ANAFORM_H

#include <QNetworkReply>
#include <QWidget>
#include <musterilistesi.h>
#include <urungirisi.h>
#include "malzemegiris.h"
#include "Globaller.h"
#include <QFileDialog>
#include <QList>
#include "dialog.h"


namespace Ui {
class AnaForm;
}

class AnaForm : public QWidget
{
    Q_OBJECT

public:
    explicit AnaForm(QWidget *parent = nullptr);
    ~AnaForm();

 bool event(QEvent *e);
private slots:
    void on_btnUrunKayit_clicked();

    void on_btnMusteriKayit_clicked();

    void on_btnClose_clicked();


    void on_btnMalzemeGiris_clicked();

    void on_btnFiltreler_clicked();

    void on_btnPDFCikar_clicked();



    void on_ebtnSil_clicked(bool checked);

    void on_btnBaslangic_clicked();

    void on_btnBitis_clicked();

    void on_pushButton_clicked();

protected:
    void showEvent(QShowEvent *ev);

private:
    void showEventHelper();
    Ui::AnaForm *ui;

     MusteriListesi *wdg ;
     urunGirisi *urg;
     MalzemeGiris *mlz;

     void HataCikar(const QString &uyari);

     void BilgiCikar(const QString &uyari);

     void UyariCikar(const QString &uyari);
     void Filtrele();
     void onActivated();
     void PDFCikar();
     void onFinish(QNetworkReply *rep);

     void showEventHelperAndroid();

     QList<QVariant> GirisAl();
     void VerileriOku(QList<QVariant> veriler);
     bool BorcGuncelle();

     QList<ListeBilgileri> liste;

     QDateTime baslangicZaman;
     QDateTime bitisZaman;

     QDateTime SaatAc(QDateTime zaman);
};

#endif // ANAFORM_H


