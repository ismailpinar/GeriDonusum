#include "malzemegiris.h"
#include "ui_malzemegiris.h"

#include <QMessageBox>
#include <dialog.h>
#include <jsonokuyucu.h>
#include "QDebug"




MalzemeGiris::MalzemeGiris(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MalzemeGiris)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);

    MusterileriDoldur();



    zaman =  QDateTime::currentDateTime();

    ui->btnZaman->setText(zaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));


    UrunTipleriOku();

    acilidi = true;


    MalzemeComboDoldur(0);

    BorcYaz();




}

MalzemeGiris::~MalzemeGiris()
{
    delete ui;
}

void MalzemeGiris::showEvent(QShowEvent *ev)
{
#ifdef Q_OS_ANDROID
    showEventHelperAndroid();
    qDebug()<<"Android";

#else
    showEventHelper();
    qDebug()<<"Linux";

#endif


}
void MalzemeGiris::showEventHelperAndroid()
{
    int kapatButonYukseklik = Dpi * 0.5;
    int kapatButonGenislik = Dpi * 0.5;


    float bosluk = Dpi * 0.005;


    int butonYukseklik = (W - 3* kapatButonYukseklik - bosluk * 6) / 5;
    int butonGenislik = Dpi;

    int labelYukseklik = kapatButonYukseklik / 2;



    ui->btnClose->setGeometry(H - bosluk - kapatButonGenislik, 10,kapatButonGenislik,kapatButonYukseklik);

    ui->lblMusteriAdi->setGeometry(bosluk,kapatButonYukseklik ,butonGenislik,labelYukseklik);
    ui->cmbMusteriAdi->setGeometry(bosluk,ui->lblMusteriAdi->y() + ui->lblMusteriAdi->height(),(H - 50) /2,kapatButonYukseklik);

    ui->btnZaman->setGeometry((H - 50) /2 + 30,ui->cmbMusteriAdi->y(),(H - 50) /2,kapatButonYukseklik);


    ui->lblMalzemeAdi->setGeometry(bosluk,ui->cmbMusteriAdi->y() + ui->cmbMusteriAdi->height(),(H - 50) /2,kapatButonYukseklik);
    ui->cmbMalzemeAdi->setGeometry(bosluk,ui->lblMalzemeAdi->y() + ui->lblMalzemeAdi->height(),(H - 50) /2,kapatButonYukseklik);

    ui->lblMiktar->setGeometry(bosluk,ui->cmbMalzemeAdi->y() + ui->cmbMalzemeAdi->height(),(H - 150) /3,kapatButonYukseklik);
    ui->txtMiktar->setGeometry(bosluk,ui->lblMiktar->y() + ui->lblMiktar->height(),(H - 150) /3,kapatButonYukseklik);


    ui->lblBirimFiyat->setGeometry((H - 50) /2 + 30,ui->lblMalzemeAdi->y() ,(H - 50) /2,kapatButonYukseklik);
    ui->txtBirimFiyat->setGeometry((H - 50) /2 + 30,ui->cmbMalzemeAdi->y() ,(H - 50) /2,kapatButonYukseklik);

    ui->lblFire->setGeometry((H - 150) /3 + 30,ui->lblMiktar->y() ,(H - 150) /6,kapatButonYukseklik);
    ui->txtFire->setGeometry((H - 150) /3 + 30,ui->txtMiktar->y() ,(H - 150) /6,kapatButonYukseklik);

    ui->lblFireKg->setGeometry((H - 150) /3 + 30 + (H - 150) /6 ,ui->lblMiktar->y() ,(H - 150) /6,kapatButonYukseklik);
    ui->txtFireKg->setGeometry((H - 150) /3 + 30 + (H - 150) /6, ui->txtMiktar->y() ,(H - 150) /6,kapatButonYukseklik);


    ui->lblNet->setGeometry(2*(H - 150) /3 + 60,ui->lblMiktar->y() ,(H - 150) /3,kapatButonYukseklik);
    ui->txtNet->setGeometry(2*(H - 150) /3 + 60,ui->txtMiktar->y() ,(H - 150) /3,kapatButonYukseklik);

    ui->lblToplam->setGeometry(bosluk + (H) / 2,W - 2.5 * butonYukseklik - bosluk,(H) / 2 - 20,butonYukseklik/2);
    ui->lblBorc->setGeometry(bosluk + (H) / 2,W - 2 * butonYukseklik - bosluk,(H) / 2 - 20,butonYukseklik/2);
    ui->lblKalan->setGeometry(bosluk+ (H) / 2,W - 1.5 * butonYukseklik - bosluk,(H) / 2 - 20,butonYukseklik/2);




    ui->lblOdenen->setGeometry(bosluk,ui->txtMiktar->y() + ui->txtMiktar->height(),(H - 150) /3,kapatButonYukseklik);
    ui->txtOdenen->setGeometry(bosluk,ui->lblOdenen->y() + ui->lblOdenen->height(),(H - 150) /3,kapatButonYukseklik);


    ui->txtBirimFiyat->setEnabled(false);

    ui->btnKaydet->setGeometry(ui->txtOdenen->width() + 2 * bosluk, W - butonYukseklik * 2 - bosluk , H - (ui->txtOdenen->width() + 2 * bosluk) - ui->lblKalan->width(),butonYukseklik);


    auto dv = new QDoubleValidator(-1000000.0, 100000.0, 4);

    ui->txtFire->setValidator(dv);
    ui->txtMiktar->setValidator(dv);
    ui->txtNet->setValidator(dv);
    ui->txtOdenen->setValidator(dv);




    ui->txtBirimFiyat->setObjectName("txtBirimFiyat");
    ui->txtBirimFiyat->setAccessibleName("txtBirimFiyat");
    QString styleSheet = "#txtBirimFiyat { color: rgb(0, 0, 0); ;font:32px}";

    ui->txtBirimFiyat->setStyleSheet(styleSheet);

    ui->txtBirimFiyat->setAlignment(Qt::AlignHCenter);



    ui->txtFire->setObjectName("txtFire");
    ui->txtFire->setAccessibleName("txtFire");
    styleSheet = "#txtFire { color: rgb(250, 0, 0); ;font:32px}";

    ui->txtFire->setStyleSheet(styleSheet);

    ui->txtFire->setAlignment(Qt::AlignHCenter);

    ui->txtFireKg->setObjectName("txtFireKg");
    ui->txtFireKg->setAccessibleName("txtFireKg");
    styleSheet = "#txtFireKg { color: rgb(250, 0, 0); ;font:32px}";

    ui->txtFireKg->setStyleSheet(styleSheet);

    ui->txtFireKg->setAlignment(Qt::AlignHCenter);


    ui->txtMiktar->setObjectName("txtMiktar");
    ui->txtMiktar->setAccessibleName("txtMiktar");
    styleSheet = "#txtMiktar { color: rgb(0, 0, 0); ;font:32px}";

    ui->txtMiktar->setStyleSheet(styleSheet);

    ui->txtMiktar->setAlignment(Qt::AlignHCenter);


    ui->txtNet->setObjectName("txtNet");
    ui->txtNet->setAccessibleName("txtNet");
    styleSheet = "#txtNet { color: rgb(0, 120, 0); ;font:32px}";

    ui->txtNet->setStyleSheet(styleSheet);

    ui->txtNet->setAlignment(Qt::AlignHCenter);


    ui->txtOdenen->setObjectName("txtOdenen");
    ui->txtOdenen->setAccessibleName("txtOdenen");
    styleSheet = "#txtOdenen { color: rgb(0, 120, 0); ;font:32px}";

    ui->txtOdenen->setStyleSheet(styleSheet);

    ui->txtOdenen->setAlignment(Qt::AlignHCenter);

    styleSheet = "#dateTimeEdit { color: rgb(0, 120, 0); ;font:32px}";

    ui->btnZaman->setStyleSheet(styleSheet);


}


void MalzemeGiris::showEventHelper()
{
    ui->txtBirimFiyat->setObjectName("txtBirimFiyat");
    ui->txtBirimFiyat->setAccessibleName("txtBirimFiyat");
    QString styleSheet = "#txtBirimFiyat { color: rgb(0, 0, 0); ;font:18px}";

    ui->txtBirimFiyat->setStyleSheet(styleSheet);

    ui->txtBirimFiyat->setAlignment(Qt::AlignHCenter);



    ui->txtFire->setObjectName("txtFire");
    ui->txtFire->setAccessibleName("txtFire");
    styleSheet = "#txtFire { color: rgb(250, 0, 0); ;font:18px}";
    ui->txtFire->setStyleSheet(styleSheet);
    ui->txtFire->setAlignment(Qt::AlignHCenter);

    ui->txtFireKg->setObjectName("txtFireKg");
    ui->txtFireKg->setAccessibleName("txtFireKg");
    styleSheet = "#txtFireKg { color: rgb(250, 0, 0); ;font:18px}";



    ui->txtFireKg->setStyleSheet(styleSheet);

    ui->txtFireKg->setAlignment(Qt::AlignHCenter);


    ui->txtMiktar->setObjectName("txtMiktar");
    ui->txtMiktar->setAccessibleName("txtMiktar");
    styleSheet = "#txtMiktar { color: rgb(0, 0, 0); ;font:18px}";

    ui->txtMiktar->setStyleSheet(styleSheet);

    ui->txtMiktar->setAlignment(Qt::AlignHCenter);


    ui->txtNet->setObjectName("txtNet");
    ui->txtNet->setAccessibleName("txtNet");
    styleSheet = "#txtNet { color: rgb(0, 120, 0); ;font:18px}";

    ui->txtNet->setStyleSheet(styleSheet);

    ui->txtNet->setAlignment(Qt::AlignHCenter);


    ui->txtOdenen->setObjectName("txtOdenen");
    ui->txtOdenen->setAccessibleName("txtOdenen");
    styleSheet = "#txtOdenen { color: rgb(0, 120, 0); ;font:18px}";

    ui->txtOdenen->setStyleSheet(styleSheet);

    ui->txtOdenen->setAlignment(Qt::AlignHCenter);

    int yukseklik = 750;
    int genislik = 1280;

    int kapatButonYukseklik = 50;
    int kapatButonGenislik = 50;

    setGeometry(AnaFormRect.x(),AnaFormRect.y(),genislik,yukseklik);

    int butonYukseklik = 100;
    int butonGenislik = 200;

    int labelYukseklik = 50;

    ui->btnClose->setGeometry(genislik - 10 - kapatButonGenislik, 10,kapatButonGenislik,kapatButonYukseklik);

    ui->lblMusteriAdi->setGeometry(10,kapatButonYukseklik ,butonGenislik,labelYukseklik);
    ui->cmbMusteriAdi->setGeometry(10,ui->lblMusteriAdi->y() + ui->lblMusteriAdi->height(),(genislik - 50) /2,kapatButonYukseklik);

    ui->btnZaman->setGeometry((genislik - 50) /2 + 30,ui->cmbMusteriAdi->y(),(genislik - 50) /2,kapatButonYukseklik);


    ui->lblMalzemeAdi->setGeometry(10,ui->cmbMusteriAdi->y() + ui->cmbMusteriAdi->height(),(genislik - 50) /2,kapatButonYukseklik);
    ui->cmbMalzemeAdi->setGeometry(10,ui->lblMalzemeAdi->y() + ui->lblMalzemeAdi->height(),(genislik - 50) /2,kapatButonYukseklik);

    ui->lblMiktar->setGeometry(10,ui->cmbMalzemeAdi->y() + ui->cmbMalzemeAdi->height(),(genislik - 150) /3,kapatButonYukseklik);
    ui->txtMiktar->setGeometry(10,ui->lblMiktar->y() + ui->lblMiktar->height(),(genislik - 150) /3,kapatButonYukseklik);




    ui->lblBirimFiyat->setGeometry((genislik - 50) /2 + 30,ui->lblMalzemeAdi->y() ,(genislik - 50) /2,kapatButonYukseklik);
    ui->txtBirimFiyat->setGeometry((genislik - 50) /2 + 30,ui->cmbMalzemeAdi->y() ,(genislik - 50) /2,kapatButonYukseklik);

    ui->lblFire->setGeometry((genislik - 150) /3 + 30,ui->lblMiktar->y() ,(genislik - 150) /6,kapatButonYukseklik);
    ui->txtFire->setGeometry((genislik - 150) /3 + 30,ui->txtMiktar->y() ,(genislik - 150) /6,kapatButonYukseklik);

    ui->lblFireKg->setGeometry((genislik - 150) /3 + 30 + (genislik - 150) /6,ui->lblMiktar->y() ,(genislik - 150) /6,kapatButonYukseklik);
    ui->txtFireKg->setGeometry((genislik - 150) /3 + 30 + (genislik - 150) /6,ui->txtMiktar->y() ,(genislik - 150) /6,kapatButonYukseklik);


    ui->lblNet->setGeometry(2*(genislik - 150) /3 + 60,ui->lblMiktar->y() ,(genislik - 150) /3,kapatButonYukseklik);
    ui->txtNet->setGeometry(2*(genislik - 150) /3 + 60,ui->txtMiktar->y() ,(genislik - 150) /3,kapatButonYukseklik);

    ui->lblToplam->setGeometry(10 + (genislik) / 2,yukseklik - 2.5 * butonYukseklik - 10,(genislik) / 2 - 20,butonYukseklik/2);
    ui->lblBorc->setGeometry(10 + (genislik) / 2,yukseklik - 2 * butonYukseklik - 10,(genislik) / 2 - 20,butonYukseklik/2);
    ui->lblKalan->setGeometry(10+ (genislik) / 2,yukseklik - 1.5 * butonYukseklik - 10,(genislik) / 2 - 20,butonYukseklik/2);


    ui->btnKaydet->setGeometry(10,yukseklik - butonYukseklik - 10 ,genislik - 20,butonYukseklik);


    ui->lblOdenen->setGeometry(10,ui->txtMiktar->y() + ui->txtMiktar->height(),(genislik - 150) /3,kapatButonYukseklik);
    ui->txtOdenen->setGeometry(10,ui->lblOdenen->y() + ui->lblOdenen->height(),(genislik - 150) /3,kapatButonYukseklik);


    ui->txtBirimFiyat->setEnabled(false);


    auto dv = new QDoubleValidator(-1000000.0, 100000.0, 4);

    ui->txtFire->setValidator(dv);
    ui->txtMiktar->setValidator(dv);
    ui->txtNet->setValidator(dv);
    ui->txtOdenen->setValidator(dv);









}


void MalzemeGiris::on_btnClose_clicked()
{
    this->close();

}

void MalzemeGiris::MusterileriDoldur()
{
    Musteriler.clear();


    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;


    Basliklar.append("Ad");
    Veriler.append("*#*");


    Basliklar.append("Soyad");
    Veriler.append("");


    Basliklar.append("ID");
    Veriler.append(-1);


    Basliklar.append("KullaniciUrunID");
    Veriler.append(-1);

    Basliklar.append("Borc");
    Veriler.append(-1);



    veri = j.Oku("http://00.0.0.0:0/Musteriler/getir",Basliklar,Veriler);


    if(j.IslemBasarili)
    {

        for(int i = 0;i < veri.count();i++)
        {
            QMap<QString, QVariant> map = veri[i].toMap();

            Musteri musteri;

            musteri.Ad = (map.values()[0].toString());
            musteri.Soyad = (map.values()[4].toString());
            musteri.ID = (map.values()[2].toInt());
            musteri.KullaniciUrunID = (map.values()[3].toInt());
            musteri.Borc = (map.values()[1].toFloat());

            if(veri.count() == 1)
            {
                if(musteri.Ad == "" && musteri.Soyad == "" && musteri.ID == -1 && musteri.KullaniciUrunID == -1 && musteri.Borc == -1)
                {
                    HataCikar("Müşteriler Doldurulamadı sayfayı tekrar yenilemeyi deneyin! ");
                }
                else
                {
                    musteriler.append(musteri);

                    ui->cmbMusteriAdi->addItem(musteri.Ad + " " +musteri.Soyad);
                }
            }
            else
            {
                musteriler.append(musteri);

                ui->cmbMusteriAdi->addItem(musteri.Ad + " " +musteri.Soyad);
            }

        }
    }
    else
    {
        HataCikar("Müşteriler Doldurulamadı sayfayı tekrar yenilemeyi deneyin! ");
    }


}






void MalzemeGiris::MalzemeleriDoldur()
{
    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;

    int secim = ui->cmbMusteriAdi->currentIndex();

    if(secim != -1)
    {

        Basliklar.append("Ad");
        Veriler.append(musteriler[secim].Ad);


        Basliklar.append("Soyad");
        Veriler.append(musteriler[secim].Soyad);


        Basliklar.append("ID");
        Veriler.append(musteriler[secim].ID);



        Basliklar.append("KullaniciUrunID");
        Veriler.append(musteriler[secim].KullaniciUrunID);

        Basliklar.append("Borc");
        Veriler.append(musteriler[secim].Borc);

        Musteri urun;



        veri = j.Oku("http://00.0.0.0:0/MusteriUrunler/getir",Basliklar,Veriler);

        if(j.IslemBasarili)
        {

            for(int i = 0;i < veri.count();i++)
            {
                QMap<QString, QVariant> map = veri[i].toMap();

                MusteriUrun gecici;
                gecici.Malzeme = map.values()[3].toInt();
                gecici.BirimFiyat = (map.values()[0]).toFloat();

                urun.Urunler.append(gecici);


                if(veri.count() == 1)
                {
                    if(gecici.BirimFiyat == -1 && gecici.Malzeme == -1)
                    {
                        HataCikar("Malzemeler Doldurulamadı tekrar yenilemeyi deneyin! ");
                    }
                    else
                    {
                        musteriler[ui->cmbMusteriAdi->currentIndex()].Urunler = urun.Urunler;

                    }
                }
                else
                {
                    musteriler[ui->cmbMusteriAdi->currentIndex()].Urunler = urun.Urunler;

                }
            }

        }
        else
        {
            HataCikar("Malzemeler Doldurulamadı tekrar yenilemeyi deneyin! ");
        }

    }


}

void MalzemeGiris::UrunTipleriOku()
{


    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;


    Basliklar.append("ad");
    Veriler.append("*#*");


    veri = j.Oku("http://00.0.0.0:0/Urunler/getir",Basliklar,Veriler);


    for(int i = 0;i < veri.count();i++)
    {

        if(veri.count() == 1)
        {
            if(veri[i].toMap().values()[0] == "" && veri[i].toMap().values()[1] == -1)
            {
                HataCikar("Ürünler Doldurulamadı tekrar yenilemeyi deneyin! ");
            }
            else
            {

                urunler.append(veri[i].toMap().values()[0].toString());

            }
        }
        else
        {
            urunler.append(veri[i].toMap().values()[0].toString());

        }


    }

}




void MalzemeGiris::on_cmbMalzemeAdi_currentIndexChanged(int index)
{

    if(index > -1)
    {
        ui->txtBirimFiyat->setText(QString::number(musteriler[ui->cmbMusteriAdi->currentIndex()].Urunler[index].BirimFiyat).replace(".",","));

        ToplamYaz();

        KalanYaz();
    }
}


void MalzemeGiris::on_cmbMusteriAdi_currentIndexChanged(int index)
{
    if(acilidi)
    {
        MalzemeComboDoldur(ui->cmbMusteriAdi->currentIndex());

        BorcYaz();
    }
}

void MalzemeGiris::MalzemeComboDoldur(int seciliIndex)
{
    MalzemeleriDoldur();


    ui->cmbMalzemeAdi->clear();


    for(int i =0;i<musteriler[seciliIndex].Urunler.count();i++)
    {
        int index = ui->cmbMusteriAdi->currentIndex();

        if(musteriler[index].Urunler[i].Malzeme != -1)
        {
            ui->cmbMalzemeAdi->addItem((urunler[musteriler[index].Urunler[i].Malzeme]));
        }

    }
}


void MalzemeGiris::on_txtMiktar_textChanged()
{
    NetHesapla();
}





void MalzemeGiris::on_txtNet_textChanged()
{
    NetHesapla();
}

void MalzemeGiris::on_txtOdenen_textChanged(const QString &arg1)
{
    KalanYaz();
}


void MalzemeGiris::ToplamYaz(float net)
{
    QString nets = QString::number(net).replace(".",",");

    ui->txtNet->setText(nets);

    toplam = net*musteriler[ui->cmbMusteriAdi->currentIndex()].Urunler[ui->cmbMalzemeAdi->currentIndex()].BirimFiyat;

    QString toplams = "Toplam = ";
    toplams.append(QString::number(toplam));
    toplams.append(" YTL");

    ui->lblToplam->setText(toplams.replace(".",","));
}

void MalzemeGiris::ToplamYaz()
{
    float net = ui->txtNet->text().replace(",",".").toFloat();

    toplam = net*musteriler[ui->cmbMusteriAdi->currentIndex()].Urunler[ui->cmbMalzemeAdi->currentIndex()].BirimFiyat;

    QString toplams = "Toplam = ";
    toplams.append(QString::number(toplam));
    toplams.append(" YTL");

    ui->lblToplam->setText(toplams.replace(".",","));
}

void MalzemeGiris::KalanYaz()
{
    float odenen = ui->txtOdenen->text().replace(",",".").toFloat();

    float net = -toplam  +  odenen + musteriler[ui->cmbMusteriAdi->currentIndex()].Borc;

    QString toplams = "Kalan = ";
    toplams.append(QString::number(net));
    toplams.append(" YTL");

    ui->lblKalan->setText(toplams.replace(".",","));
}

void MalzemeGiris::BorcYaz()
{

    float net = musteriler[ui->cmbMusteriAdi->currentIndex()].Borc;

    QString toplams = "Mevcut Borç = ";
    toplams.append(QString::number(net).replace(".",","));
    toplams.append(" YTL");

    ui->lblBorc->setText(toplams);
}




void MalzemeGiris::on_btnKaydet_clicked()
{
    /*if(kayitEdildi)
    {
        VerileriGuncelle();
    }
    else*/
    {
        VerileriKaydet();
    }
}





void MalzemeGiris::VerileriKaydet()
{


    bilgiler.MusteriAdi = ui->cmbMusteriAdi->currentText();
    bilgiler.MalzemeAdi = ui->cmbMalzemeAdi->currentText();
    bilgiler.Tarih = zaman;
    bilgiler.BirimFiyat = ui->txtBirimFiyat->text().replace(",",".").toFloat();
    bilgiler.Miktar = ui->txtMiktar->text().replace(",",".").toFloat();
    bilgiler.Fire = ui->txtFireKg->text().replace(",",".").toFloat();
    bilgiler.Odenen = ui->txtOdenen->text().replace(",",".").toFloat();
    bilgiler.MusteriID = musteriler[ui->cmbMusteriAdi->currentIndex()].ID;

    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;



    Basliklar.append("MusteriAdi");
    Veriler.append(bilgiler.MusteriAdi);


    Basliklar.append("MalzemeAdi");
    Veriler.append(bilgiler.MalzemeAdi);

    Basliklar.append("Tarih");
    Veriler.append(bilgiler.Tarih.toString(Qt::ISODate));

    Basliklar.append("MusteriID");
    Veriler.append(bilgiler.MusteriID);


    Basliklar.append("BirimFiyat");
    Veriler.append(bilgiler.BirimFiyat );

    Basliklar.append("Miktar");
    Veriler.append(bilgiler.Miktar);

    Basliklar.append("Fire");
    Veriler.append(bilgiler.Fire);

    Basliklar.append("Odenen");
    Veriler.append(bilgiler.Odenen);











    veri = j.Oku("http://00.0.0.0:0/GirisA/ekle",Basliklar,Veriler);

    if(j.IslemBasarili)
    {

        if(BorcGuncelle())
        {
            BilgiCikar("Kaydetme İşlemi Başarılı");

            kayitEdildi = true;

            //ui->btnKaydet->setText("GÜNCELLE");
        }
        else
        {
            BilgiCikar("Kaydetme İşlemi Yarım Kaldı Borç Güncellenemedi!");
        }


    }
    else
    {
        HataCikar("Kaydetme İşlemi Başarısız!");

    }



}


bool MalzemeGiris::BorcGuncelle()
{
    bilgiler.MusteriID = musteriler[ui->cmbMusteriAdi->currentIndex()].ID;



    double net = ui->txtNet->text().replace(",",".").toFloat();
    double odenen = ui->txtOdenen->text().replace(",",".").toFloat();
    double toplam_ = net*musteriler[ui->cmbMusteriAdi->currentIndex()].Urunler[ui->cmbMalzemeAdi->currentIndex()].BirimFiyat;

    qDebug()<<"xxx"<<odenen;
    qDebug()<<"xxx"<<net;
    qDebug()<< "xxx"<< ui->cmbMusteriAdi->currentIndex()<< "  " <<ui->cmbMalzemeAdi->currentIndex()<< "  "<<musteriler[ui->cmbMusteriAdi->currentIndex()].Urunler[ui->cmbMalzemeAdi->currentIndex()].BirimFiyat;

    double borc= -toplam_+odenen + musteriler[ui->cmbMusteriAdi->currentIndex()].Borc;



    musteriler[ui->cmbMusteriAdi->currentIndex()].Borc = borc;


    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;


    Basliklar.append("Ad");
    Veriler.append(musteriler[ui->cmbMusteriAdi->currentIndex()].Ad);

    Basliklar.append("ID");
    Veriler.append(bilgiler.MusteriID);


    Basliklar.append("SoyAd");
    Veriler.append(musteriler[ui->cmbMusteriAdi->currentIndex()].Soyad);

    Basliklar.append("KullaniciUrunID");
    Veriler.append(musteriler[ui->cmbMusteriAdi->currentIndex()].KullaniciUrunID);

    Basliklar.append("Borc");
    Veriler.append(borc);



    veri = j.Oku("http://00.0.0.0:0/Musteriler/guncelle",Basliklar,Veriler);

    qDebug()<<"wwww"<<j.IslemBasarili << borc;

    return j.IslemBasarili;



}

void MalzemeGiris::VerileriGuncelle()
{

    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;

    int id = SonUrunIDAl();

    bilgiler.MusteriAdi = ui->cmbMusteriAdi->currentText();
    bilgiler.MalzemeAdi = ui->cmbMalzemeAdi->currentText();
    bilgiler.Tarih = zaman;
    bilgiler.BirimFiyat = ui->txtBirimFiyat->text().replace(",",".").toFloat();
    bilgiler.Miktar = ui->txtMiktar->text().replace(",",".").toFloat();
    bilgiler.Fire = ui->txtFire->text().replace(",",".").toFloat();
    bilgiler.Odenen = ui->txtOdenen->text().replace(",",".").toFloat();
    bilgiler.MusteriID = musteriler[ui->cmbMusteriAdi->currentIndex()].ID;

    double net = ui->txtNet->text().replace(",",".").toDouble();
    double odenen = ui->txtOdenen->text().replace(",",".").toDouble();
    double toplam_ = net*musteriler[ui->cmbMusteriAdi->currentIndex()].Urunler[ui->cmbMalzemeAdi->currentIndex()].BirimFiyat;

    double borc = toplam_ - odenen;

    Basliklar.append("ID");
    Veriler.append(id);

    Basliklar.append("MusteriAdi");
    Veriler.append(bilgiler.MusteriAdi);

    Basliklar.append("MalzemeAdi");
    Veriler.append(bilgiler.MalzemeAdi);

    Basliklar.append("BirimFiyat");
    Veriler.append(bilgiler.BirimFiyat );

    Basliklar.append("Miktar");
    Veriler.append(bilgiler.Miktar);

    Basliklar.append("Fire");
    Veriler.append(bilgiler.Fire);

    Basliklar.append("Odenen");
    Veriler.append(bilgiler.Odenen);

    Basliklar.append("MusteriID");
    Veriler.append(bilgiler.MusteriID );

    Basliklar.append("Tarih");
    Veriler.append(bilgiler.Tarih);


    veri = j.Oku("http://00.0.0.0:0/GirisA/guncelle",Basliklar,Veriler);

    if(j.IslemBasarili)
    {

        BilgiCikar("Güncelleme İşlemi Başarılı");

    }
    else
    {
        HataCikar("Güncelleme İşlemi Başarısız!");
    }

}

int MalzemeGiris::SonUrunIDAl()
{

    JSONOkuyucu j;

    int max =j.GetAl("http://00.0.0.0:0/AnaForm");

    return max;
}


void MalzemeGiris::UyariCikar(const QString &uyari)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "Uyarı", uyari);


}

void MalzemeGiris::BilgiCikar(const QString &uyari)
{
    QMessageBox::StandardButton reply;
    QMessageBox::information(this, "Bilgi", uyari);


}

void MalzemeGiris::HataCikar(const QString &hata)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, "Hata", hata);


}









void MalzemeGiris::on_txtFireKg_textChanged(const QString &arg1)
{
    kgDegisti = true;

    NetHesapla();
}

void MalzemeGiris::on_txtFire_textChanged()
{
    kgDegisti= false;

    NetHesapla();
}


void MalzemeGiris::NetHesapla()
{
    QString miktars = ui->txtMiktar->text().replace(".",",");
    float miktar = miktars.replace(",",".").toFloat();

    float net = 0;
    float fire = 0;
    QString fires ="";
    if(!kgDegisti)
    {
        fires = ui->txtFire->text().replace(".",",");
        fire = ui->txtFire->text().replace(",",".").toFloat();


        net=miktar -(miktar * fire / 100.0);

        float fi = miktar - net;

        ui->txtFireKg->setText(QString::number(fi));


    }
    else
    {
        fires = ui->txtFireKg->text().replace(".",",");
        fire = ui->txtFireKg->text().replace(",",".").toFloat();

        net =miktar -fire;


        float fi  = 100.0* (fire / miktar);



        ui->txtFire->setText(QString::number(fi));
    }



    ToplamYaz(net);

    KalanYaz();


}

QDateTime MalzemeGiris::SaatAc()
{
    Dialog *dialog = new Dialog();

    dialog->zaman.setDate(zaman.date());
    dialog->zaman.setTime(zaman.time());


    dialog->exec();



    return dialog->zaman;

}



void MalzemeGiris::on_btnZaman_clicked()
{
    zaman = SaatAc();

    ui->btnZaman->setText(zaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));

    qDebug()<<(zaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));

}

