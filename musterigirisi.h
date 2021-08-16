#ifndef MUSTERIGIRISI_H
#define MUSTERIGIRISI_H

#include <QMainWindow>
#include <QTableWidget>
#include <Globaller.h>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MusteriGirisi; }
QT_END_NAMESPACE

class MusteriGirisi : public QMainWindow
{
    Q_OBJECT

public:
    MusteriGirisi(QWidget *parent = nullptr);
    ~MusteriGirisi();

    Musteri musteri;
    void VerileriDoldur(Musteri mus);

    void SonUrunIDAl();


private slots:
    void on_btnKaydet_clicked();

    void on_btnEkle_clicked();

    void on_btnSil_clicked();

    void on_btnGuncelle_clicked();


    void on_btnClose_clicked();



    void on_tbwMusteriUrun_cellChanged(int row, int column);

protected:
    void showEvent(QShowEvent *ev);

private:
    void showEventHelper();
    Ui::MusteriGirisi *ui;
    QComboBox *combo = new QComboBox();


    Musteri musteriGecici;

    bool guncelleme = false;



    void VeriTabaniBaglanti();
    void Sil(int silinecekNo);
    void Kaydet();
    void DiziyiDegiskenlereAta();
    void UrunKaydet();
    void UrunSil();
    void Guncelle();
    void UrunleriDoldur();
    void ComboBoxDoldur(int satirNo, int secim);
    bool DegisiklikVarMi();
    void UyariCikar(const QString &uyari);
    void BilgiCikar(const QString &uyari);
    void HataCikar(const QString &hata);
    bool AyniIsimVarMi(QString ad, QString soyaAdi);




    bool AyniUrunVarMi();
    void UrunTipleriOku();
    void showEventHelperAndroid();
    void VeriCek();
};


#endif // MUSTERIGIRISI_H
