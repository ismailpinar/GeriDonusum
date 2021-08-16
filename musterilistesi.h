#ifndef MUSTERILISTESI_H
#define MUSTERILISTESI_H

#include <QWidget>
#include <musterigirisi.h>
#include "Globaller.h"

namespace Ui {
class MusteriListesi;
}

class MusteriListesi : public QWidget
{
    Q_OBJECT

public:
    explicit MusteriListesi(QWidget *parent = nullptr);
    ~MusteriListesi();

    bool event(QEvent *e);
private slots:


    void on_btnMLSil_clicked();

    void on_btnEkle_clicked();

    void on_btnClose_clicked();

    void on_btnMLGuncelle_clicked();

    void on_tblMusteriListesi_itemSelectionChanged();

    void on_tblMusteriListesi_cellClicked(int row, int column);

    void on_tblMusteriListesi_cellDoubleClicked(int row, int column);

protected:
    void showEvent(QShowEvent *ev);

private:
    void showEventHelper();
    Ui::MusteriListesi *ui;
    void VerileriOku();
    void ListeDoldur();
    bool Sil(int silinecekNo);
    int seciliMusteriSira = 0;
    int seciliGridSira = 0;
    int SilinecekDiziElemaniBul(int id);
    void Guncelle();
    void onActivated();
    bool acildi = false;
    void VeriGuncelle();
    MusteriGirisi *wdg;
    bool eklemeIcinAc = false;
    void UyariCikar(const QString &uyari);
    void BilgiCikar(const QString &uyari);
    void HataCikar(const QString &hata);
    bool bilgiGoster = false;



    void UrunTipleriOku();
    bool MusteriUrunleriSil(int silinecekNo);
    void GridFontGuncelle(int i);
    void showEventHelperAndroid();
    void VeriCek();

};

#endif // MUSTERILISTESI_H
