#ifndef MALZEMEGIRIS_H
#define MALZEMEGIRIS_H

#include <QWidget>
#include "Globaller.h"

namespace Ui {
class MalzemeGiris;
}

class MalzemeGiris : public QWidget
{
    Q_OBJECT

public:
    explicit MalzemeGiris(QWidget *parent = nullptr);
    ~MalzemeGiris();

protected:
    void showEvent(QShowEvent *ev);

private slots:

    void on_btnClose_clicked();

    void on_cmbMalzemeAdi_currentIndexChanged(int index);

    void on_cmbMusteriAdi_currentIndexChanged(int index);

    void on_txtMiktar_textChanged();

    void on_txtFire_textChanged();

    void on_txtNet_textChanged();

    void on_txtOdenen_textChanged(const QString &arg1);

    void on_btnKaydet_clicked();

    void on_txtFireKg_textChanged(const QString &arg1);

    void on_btnZaman_clicked();

private:
    void showEventHelper();
    Ui::MalzemeGiris *ui;
    void MusterileriDoldur();
    void MalzemeleriDoldur();
    QList<Musteri> musteriler;
    void UrunTipleriOku();
    QList<QString> urunler;
    bool acilidi = false;
    void MalzemeComboDoldur(int f);
    void NetHesapla();
    void ToplamYaz();
    void ToplamYaz(float net);
    void KalanYaz();

    float toplam;
    float kalan;

    ListeBilgileri bilgiler;
    void VerileriKaydet();
    void HataCikar(const QString &hata);
    void BilgiCikar(const QString &uyari);
    void UyariCikar(const QString &uyari);
    void VerileriGuncelle();
    int SonUrunIDAl();
    bool kayitEdildi = false;
    void BorcYaz();
    void showEventHelperAndroid();
    bool BorcGuncelle();

    QDateTime zaman;
    bool kgDegisti = false;
    QDateTime SaatAc();
};

#endif // MALZEMEGIRIS_H
