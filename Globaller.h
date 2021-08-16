#ifndef GLOBALLER_H
#define GLOBALLER_H


#include <QDateTime>
#include <QList>
#include <QRect>
#include <QString>





class Globaller
{

public:
    Globaller();

    QString NoktaVirgulAl(QString deger);


};



struct MusteriUrun
{
public:

    int Malzeme;
    double BirimFiyat;

    bool operator==(const MusteriUrun& dInfo) const
    {
        if(Malzeme == dInfo.Malzeme && BirimFiyat == dInfo.BirimFiyat)
            return true;

        return false;
    }

};

struct Musteri
{
public:

    QList<MusteriUrun> Urunler;
    QString Ad;
    QString Soyad;
    double Borc;
    int ID;
    int KullaniciUrunID;

    bool operator==(const Musteri& dInfo) const
    {
        if(Ad == dInfo.Ad && Soyad == dInfo.Soyad && Urunler == dInfo.Urunler &&  dInfo.Borc)
            return true;

        return false;
    }


};


struct ListeBilgileri
{
public:
    int ID;
    int MusteriID;
    QString MusteriAdi;
    QString MalzemeAdi;
    QDateTime Tarih;
    double BirimFiyat;
    double Miktar;
    double Fire;
    double Odenen;
    double Borc;
};

//QDateTime b = QDateTime::fromString(as,time_format);


static QString VeriTabaniIP = "94.73.150.29";
static QString VeriTabaniAdi = "u0160014_maliyet";
static QString VeriTabaniKullaniciID = "u0160014_sistem";
static QString VeriTabaniSifre = "AfnPM2AbX-@W";
extern QList<Musteri> Musteriler;
extern QList<QString> Urunler;
extern QPoint desktopRect;
extern QRect AnaFormRect;
extern QList<ListeBilgileri> Liste;


extern qreal refDpi;
extern qreal refH;
extern qreal refW;

extern qreal H;
extern qreal W;
extern qreal Dpi;


extern qreal Oran;
extern qreal OranFont;


#endif // GLOBALLER_H
