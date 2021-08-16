#ifndef URUNGIRISI_H
#define URUNGIRISI_H

#include <QWidget>
#include "Globaller.h"

namespace Ui {
class urunGirisi;
}

class urunGirisi : public QWidget
{
    Q_OBJECT

public:
    explicit urunGirisi(QWidget *parent = nullptr);
    ~urunGirisi();

private slots:
    void on_btnSil_clicked();

    void on_btnEkle_clicked();

    void on_btnClose_clicked();



protected:
    void showEvent(QShowEvent *ev);

private:
    void showEventHelper();
    Ui::urunGirisi *ui;
    void UrunleriDoldur();

    QList<QString> urunler;
    void UyariCikar(const QString &hata);
    void BilgiCikar(const QString &hata);
    void HataCikar(const QString &hata);
    bool AyniUrunVarMi();
    void Kaydet();
    void Sil();

    void showEventHelperAndroid();
    void VeriCek();
};

#endif // URUNGIRISI_H
