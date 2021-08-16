#include "musterigirisi.h"
#include "ui_musterigirisi.h"

#include "QMessageBox"
#include "QDebug"
#include "jsonokuyucu.h"

#include <QTableWidgetItem>
#include <QTableWidget>
#include <QLineEdit>
#include <anaform.h>
#include <QRegExp>
#include <QListView>
#include <QVBoxLayout>
#include <QDateTimeEdit>

#include "Globaller.h"




MusteriGirisi::MusteriGirisi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MusteriGirisi)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);

    ui->tbwMusteriUrun->setColumnCount(2);
    ui->tbwMusteriUrun->verticalHeader()->setVisible(false);
    ui->tbwMusteriUrun->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbwMusteriUrun->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tbwMusteriUrun->setShowGrid(true);
    ui->tbwMusteriUrun->setStyleSheet("QTableView {selection-background-color: red;}");
    ui->tbwMusteriUrun->setHorizontalHeaderItem(0, new QTableWidgetItem("Malzeme"));
    ui->tbwMusteriUrun->setHorizontalHeaderItem(1, new QTableWidgetItem("Birim Fiyat(TL)"));




    ui->tbwMusteriUrun->setColumnWidth(0,130);
    ui->tbwMusteriUrun->setColumnWidth(1,120);





}


MusteriGirisi::~MusteriGirisi()
{
    delete ui;
}

void MusteriGirisi::showEvent(QShowEvent *ev)
{
#ifdef Q_OS_ANDROID
    showEventHelperAndroid();
    qDebug()<<"Android";

#else
    showEventHelper();
    qDebug()<<"Linux";

#endif
}
void MusteriGirisi::showEventHelperAndroid()
{
    ui->tbwMusteriUrun->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 32px; }");
    ui->tbwMusteriUrun->setStyleSheet("QTableView {selection-background-color: red;font-size: 32px;}");

    int kapatButonYukseklik = Dpi * 0.5;
    int kapatButonGenislik = Dpi * 0.5;



    float bosluk = Dpi * 0.005;


    int butonYukseklik = (W - 3* kapatButonYukseklik - bosluk * 6) / 5;
    int butonGenislik = Dpi;




    ui->tbwMusteriUrun->horizontalHeader()->setMinimumHeight(kapatButonYukseklik);

    double grid = H - bosluk * 3 - butonGenislik;



    int gridSutunToplam = grid;




    ui->btnClose->setGeometry(H - bosluk - kapatButonGenislik, bosluk,kapatButonGenislik,kapatButonYukseklik);



    ui->btnEkle->setGeometry(H - bosluk - butonGenislik, kapatButonYukseklik * 2,butonGenislik,butonYukseklik);
    ui->btnSil->setGeometry( H - bosluk - butonGenislik, kapatButonYukseklik * 2.5 + butonYukseklik ,butonGenislik,butonYukseklik);



    ui->btnKaydet->setGeometry(H - bosluk - butonGenislik, W  - 3 * bosluk - 2*butonYukseklik ,butonGenislik,butonYukseklik);

    ui->label->setGeometry(bosluk,bosluk,H - kapatButonGenislik -butonGenislik,butonYukseklik / 2);

    ui->txtAdi->setGeometry(bosluk,ui->label->y()+bosluk + butonYukseklik/2,H - kapatButonGenislik -butonGenislik,butonYukseklik / 2);

    ui->label_4->setGeometry(bosluk,ui->txtAdi->y()+bosluk+ butonYukseklik/2,H - kapatButonGenislik -butonGenislik,butonYukseklik / 2);

    ui->txtSoyad->setGeometry(bosluk,ui->label_4->y()+bosluk + butonYukseklik/2 ,H - kapatButonGenislik -butonGenislik,butonYukseklik / 2);

    ui->lblBirimFiyat->setGeometry(bosluk,ui->txtSoyad->y()+bosluk + butonYukseklik/2,H - kapatButonGenislik -butonGenislik,butonYukseklik / 2);

    ui->txtBorc->setGeometry(bosluk,ui->lblBirimFiyat->y()+bosluk + butonYukseklik/2,H - kapatButonGenislik -butonGenislik,butonYukseklik / 2);


    ui->label_2->setGeometry(bosluk,ui->txtBorc->y()+bosluk + butonYukseklik/2,H - kapatButonGenislik -butonGenislik,butonYukseklik / 2);


    ui->tbwMusteriUrun->setGeometry(bosluk,ui->label_2->y() + bosluk + butonYukseklik/2,H - 2* butonGenislik, W - (ui->label_2->y()) - bosluk * 2- butonYukseklik / 2);


    ui->tbwMusteriUrun->setColumnWidth(0,(int)(130.0 * (gridSutunToplam/250.0)));
    ui->tbwMusteriUrun->setColumnWidth(1,(int)(120.0 * (gridSutunToplam/250.0)));


    ui->txtSoyad->setObjectName("txtSoyad");
    ui->txtSoyad->setAccessibleName("txtSoyad");
    QString styleSheet = "#txtSoyad { color: rgb(0, 0, 0); ;font:32px}";

    ui->txtSoyad->setStyleSheet(styleSheet);

    ui->txtSoyad->setAlignment(Qt::AlignHCenter);

    ui->txtAdi->setObjectName("txtAdi");
    ui->txtAdi->setAccessibleName("txtAdi");
    styleSheet = "#txtAdi { color: rgb(0, 0, 0); ;font:32px}";

    ui->txtAdi->setStyleSheet(styleSheet);

    ui->txtAdi->setAlignment(Qt::AlignHCenter);


    ui->txtBorc->setObjectName("txtBorc");
    ui->txtBorc->setAccessibleName("txtBorc");
    styleSheet = "#txtBorc { color: rgb(125, 0, 0); ;font:32px}";

    ui->txtBorc->setStyleSheet(styleSheet);

    ui->txtBorc->setAlignment(Qt::AlignHCenter);



    ui->btnEkle->setStyleSheet("font-size: 32px;");
    ui->btnSil->setStyleSheet("font-size: 32px;");
    ui->btnKaydet->setStyleSheet("font-size: 32px;");

    ui->btnEkle->setText("Ekle");
    ui->btnSil->setText("Sil");


    ui->txtBorc->setEnabled(false);
}
void MusteriGirisi::showEventHelper()
{
    int yukseklik = 750;
    int genislik = 1280;

    int kapatButonYukseklik = 50;
    int kapatButonGenislik = 50;

    setGeometry(AnaFormRect.x(),AnaFormRect.y(),genislik,yukseklik);

    ui->btnClose->setGeometry(genislik - 10 - kapatButonGenislik, 10,kapatButonGenislik,kapatButonYukseklik);


    int butonYukseklik = 100;
    int butonGenislik = 200;

    ui->btnEkle->setGeometry(genislik - 10 - butonGenislik, kapatButonYukseklik * 2,butonGenislik,butonYukseklik);
    ui->btnSil->setGeometry( genislik - 10 - butonGenislik, kapatButonYukseklik * 2.5 + butonYukseklik ,butonGenislik,butonYukseklik);



    ui->btnKaydet->setGeometry(genislik - 10 - butonGenislik, yukseklik  - 25 - butonYukseklik ,butonGenislik,butonYukseklik);

    ui->label->setGeometry(10,10,genislik - 50 -butonGenislik,butonYukseklik);

    ui->txtAdi->setGeometry(10,butonYukseklik/2 + 10 + 10,genislik - 50 -butonGenislik,butonYukseklik / 2);

    ui->label_4->setGeometry(10,butonYukseklik/2 + 10+kapatButonYukseklik + 10,genislik - 50 -butonGenislik,butonYukseklik / 2);

    ui->txtSoyad->setGeometry(10,butonYukseklik + 10 +kapatButonYukseklik + 10,genislik - 50 -butonGenislik,butonYukseklik / 2);

    ui->lblBirimFiyat->setGeometry(10,butonYukseklik/2 + 10+3*kapatButonYukseklik + 10,genislik - 50 -butonGenislik,butonYukseklik / 2);

    ui->txtBorc->setGeometry(10,butonYukseklik + 10 +3*kapatButonYukseklik + 10,genislik - 50 -butonGenislik,butonYukseklik / 2);


    ui->label_2->setGeometry(10,butonYukseklik/2 + 10+5*kapatButonYukseklik + 10,genislik - 50 -butonGenislik,butonYukseklik / 2);


    ui->tbwMusteriUrun->setGeometry(10,ui->label_2->geometry().y() + butonYukseklik/2,genislik - 50 -butonGenislik, yukseklik - (ui->label_2->geometry().y() + butonYukseklik/2) - 20);

    ui->txtSoyad->setObjectName("txtSoyad");
    ui->txtSoyad->setAccessibleName("txtSoyad");
    QString styleSheet = "#txtSoyad { color: rgb(0, 0, 0); ;font:18px}";

    ui->txtSoyad->setStyleSheet(styleSheet);

    ui->txtSoyad->setAlignment(Qt::AlignHCenter);

    ui->txtAdi->setObjectName("txtAdi");
    ui->txtAdi->setAccessibleName("txtAdi");
    styleSheet = "#txtAdi { color: rgb(0, 0, 0); ;font:18px}";

    ui->txtAdi->setStyleSheet(styleSheet);

    ui->txtAdi->setAlignment(Qt::AlignHCenter);


    ui->txtBorc->setObjectName("txtBorc");
    ui->txtBorc->setAccessibleName("txtBorc");
    styleSheet = "#txtBorc { color: rgb(125, 0, 0); ;font:18px}";

    ui->txtBorc->setStyleSheet(styleSheet);

    ui->txtBorc->setAlignment(Qt::AlignHCenter);


    ui->txtBorc->setEnabled(false);



}


void MusteriGirisi::VerileriDoldur(Musteri musteriGelen)
{



    guncelleme = true;

    ui->btnKaydet->setText("Güncelle");

    musteri = musteriGelen;



    ui->txtAdi->setText(musteri.Ad);
    ui->txtSoyad->setText(musteri.Soyad);
    ui->txtBorc->setText(QString::number(musteri.Borc,'f', 2).replace(".",","));




    UrunleriDoldur();

    musteriGecici = musteri;



}


void MusteriGirisi::VeriCek()
{


    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;




    Basliklar.append("ID");
    Veriler.append(-1);


    Basliklar.append("KullaniciUrunID");
    Veriler.append(musteri.KullaniciUrunID);

    Basliklar.append("Malzeme");
    Veriler.append(0.0);

    Basliklar.append("BirimFiyat");
    Veriler.append(0.0);



    veri = j.Oku("http://00.0.0.0:0/MusteriUrunler/getir",Basliklar,Veriler);




    for(int i = 0;i < veri.count();i++)
    {
        QMap<QString, QVariant> map = veri[i].toMap();

        MusteriUrun urun;
        urun.Malzeme = map.values()[3].toInt();
        urun.BirimFiyat = (map.values()[0]).toFloat();

        musteri.Urunler.append(urun);
    }


    int urunSayisi = musteri.Urunler.count();

    ui->tbwMusteriUrun->setRowCount(urunSayisi);

    int yukseklilk = 0;

#ifdef Q_OS_ANDROID
    yukseklilk= 100;
#else
    yukseklilk = 50;
#endif


    for(int i=0;i<urunSayisi;i++)
    {
        this->ComboBoxDoldur(i,musteri.Urunler[i].Malzeme);

        ui->tbwMusteriUrun->setItem(i,1,new QTableWidgetItem(QString::number(musteri.Urunler[i].BirimFiyat)));
        ui->tbwMusteriUrun->item(i,1)->setTextAlignment(Qt::AlignCenter);



        ui->tbwMusteriUrun->setRowHeight(i,yukseklilk);
        //ui->tbwMusteriUrun->setCellWidget(i, 0, combo);
    }

    if(urunSayisi > 0)
    {
        ui->tbwMusteriUrun->selectRow(0);
    }
}




void MusteriGirisi::UrunleriDoldur()
{
    VeriCek();
}



void MusteriGirisi::SonUrunIDAl()
{

    JSONOkuyucu j;

    int veri =j.GetAl("http://00.0.0.0:0/Musteriler");

    musteri.Ad = "";
    musteri.Soyad = "";
    musteri.ID = veri + 1;
    musteri.KullaniciUrunID = musteri.ID;

}




void MusteriGirisi::on_btnKaydet_clicked()
{



    musteri.Ad = ui->txtAdi->toPlainText();
    musteri.Soyad =ui->txtSoyad->toPlainText();


    if(AyniIsimVarMi(musteri.Ad, musteri.Soyad))
    {
        UyariCikar("Aynı isimde müşteri var. Lütfen farklı isim giriniz!");
        return;
    }
    else if(AyniUrunVarMi())
    {
        UyariCikar("Birden çok aynı isimde ürün var!");
        return;
    }


    if(guncelleme)
    {
        Guncelle();
    }
    else
    {
        Kaydet();
        guncelleme = true;
        ui->btnKaydet->setText("Güncelle");

    }

}


void MusteriGirisi::on_btnEkle_clicked()
{
    ui->tbwMusteriUrun->setRowCount(ui->tbwMusteriUrun->rowCount() + 1);


    ui->tbwMusteriUrun->setItem(ui->tbwMusteriUrun->rowCount()-1,1,new QTableWidgetItem("0.00"));


    ui->tbwMusteriUrun->item(ui->tbwMusteriUrun->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);




    ComboBoxDoldur(ui->tbwMusteriUrun->rowCount()-1,0);



    ui->tbwMusteriUrun->selectRow(ui->tbwMusteriUrun->rowCount()-1);



    int yukseklilk = 0;

#ifdef Q_OS_ANDROID
    yukseklilk= 100;
#else
    yukseklilk = 50;
#endif
    ui->tbwMusteriUrun->setRowHeight(ui->tbwMusteriUrun->rowCount() -1, yukseklilk);



    MusteriUrun urun;
    urun.Malzeme = 0;
    urun.BirimFiyat= 0;

    musteri.Urunler.append(urun);

}


void MusteriGirisi::ComboBoxDoldur(int satirNo,int secim)
{
    QComboBox* combo =  new QComboBox();

    for(int i = 0;i<Urunler.length();i++)
    {
        combo->addItem(Urunler[i]);

        qDebug()<<"www"<<Urunler.length();

    }


    combo->setCurrentIndex(secim);

    ui->tbwMusteriUrun->setCellWidget(satirNo, 0, combo);
}



void MusteriGirisi::on_btnSil_clicked()
{


    QModelIndexList selection = ui->tbwMusteriUrun->selectionModel()->selectedRows();

    musteri.Urunler.removeAt(selection.at(0).row());


    ui->tbwMusteriUrun->removeRow(selection.at(0).row());





}


void MusteriGirisi::on_btnGuncelle_clicked()
{


}

void MusteriGirisi::Kaydet()
{


    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;




    Basliklar.append("Ad");
    Veriler.append(musteri.Ad);

    Basliklar.append("ID");
    Veriler.append(-1);


    Basliklar.append("SoyAd");
    Veriler.append(musteri.Soyad);

    Basliklar.append("KullaniciUrunID");
    Veriler.append(musteri.KullaniciUrunID);

    Basliklar.append("Borc");
    Veriler.append(0);



    veri = j.Oku("http://00.0.0.0:0/Musteriler/ekle",Basliklar,Veriler);

    if(j.IslemBasarili)
    {
        UrunSil();
        UrunKaydet();

        musteriGecici = musteri;

        BilgiCikar("Kaydetme İşlemi Başarılı");
    }
    else
    {
        HataCikar("Kaydetme İşlemi Başarısız!");

    }

   
}



void MusteriGirisi::Sil(int silinecekNo)
{

    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;




    Basliklar.append("Ad");
    Veriler.append("**");

    Basliklar.append("ID");
    Veriler.append(silinecekNo);


    Basliklar.append("SoyAd");
    Veriler.append("");

    Basliklar.append("KullaniciUrunID");
    Veriler.append(-1);

    Basliklar.append("Borc");
    Veriler.append(-1);



    veri = j.Oku("http://00.0.0.0:0/Musteriler/sil",Basliklar,Veriler);

    if(j.IslemBasarili)
    {
        musteri.Urunler.removeAt(silinecekNo);

        BilgiCikar("Silme işlemi Başarılı");
    }
    else
    {
        HataCikar("Silme işlemi Başarısız!");

    }

}

void MusteriGirisi::Guncelle()
{

    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;


    Basliklar.append("Ad");
    Veriler.append(musteri.Ad);

    Basliklar.append("ID");
    Veriler.append(musteri.ID);


    Basliklar.append("SoyAd");
    Veriler.append(musteri.Soyad);

    Basliklar.append("KullaniciUrunID");
    Veriler.append(musteri.KullaniciUrunID);

    Basliklar.append("Borc");
    Veriler.append(musteri.Borc);

    veri = j.Oku("http://00.0.0.0:0/Musteriler/guncelle",Basliklar,Veriler);

    if(j.IslemBasarili)
    {
        UrunSil();
        UrunKaydet();

        musteriGecici = musteri;

        BilgiCikar("Güncelleme başarılı.");
    }
    else
    {
        HataCikar("Güncelleme işlemi başarısız!");

    }



}




bool MusteriGirisi::DegisiklikVarMi()
{


    if(musteri==musteriGecici)
    {
        return false;
    }
    else
    {
        return true;
    }


}

void MusteriGirisi::on_btnClose_clicked()
{
    musteri.Ad = ui->txtAdi->toPlainText();
    musteri.Soyad =ui->txtSoyad->toPlainText();

    DiziyiDegiskenlereAta();

    if(DegisiklikVarMi())
    {

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Değişiklik Sorusu", "Yapılan Değişikler Kaydedilsin mi?",
                                      QMessageBox::Cancel|QMessageBox::No| QMessageBox::Yes);

        switch (reply) {
        case QMessageBox::Yes:

            if(AyniIsimVarMi(musteri.Ad, musteri.Soyad))
            {
                UyariCikar("Aynı isimde müşteri var. Lütfen farklı isim giriniz!");
                break;
            }

            if(guncelleme)
            {
                Guncelle();
            }
            else
            {
                Kaydet();
            }



            this->close();

            break;
        case QMessageBox::No:

            this->close();


            break;
        case QMessageBox::Cancel:

            break;

        }
    }
    else
    {
        this->close();
    }

}





void MusteriGirisi::UrunKaydet()
{
    DiziyiDegiskenlereAta();




    QList<QVariant> veri;
    JSONOkuyucu j;





    for(int i =0;i<musteri.Urunler.length();i++)
    {
        QList<QVariant> Veriler;
        QList<QString> Basliklar;

        Basliklar.append("ID");
        Veriler.append(1);

        Basliklar.append("KullaniciUrunID");
        Veriler.append(musteri.KullaniciUrunID);

        Basliklar.append("Malzeme");
        Veriler.append(musteri.Urunler[i].Malzeme);

        Basliklar.append("BirimFiyat");
        Veriler.append(musteri.Urunler[i].BirimFiyat);



        veri = j.Oku("http://00.0.0.0:0/MusteriUrunler/ekle",Basliklar,Veriler);

        qDebug()<<j.IslemBasarili;
    }





}

void MusteriGirisi::UrunSil()
{


    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;




    Basliklar.append("ID");
    Veriler.append(-1);

    Basliklar.append("KullaniciUrunID");
    Veriler.append(musteri.KullaniciUrunID);

    Basliklar.append("Malzeme");
    Veriler.append(0);

    Basliklar.append("BirimFiyat");
    Veriler.append(0);



    veri = j.Oku("http://00.0.0.0:0/MusteriUrunler/sil",Basliklar,Veriler);



}

void MusteriGirisi::DiziyiDegiskenlereAta()
{
    for(int i=0;i<ui->tbwMusteriUrun->rowCount();i++)
    {
        MusteriUrun urun;

        QComboBox *myCB = qobject_cast<QComboBox*>(ui->tbwMusteriUrun->cellWidget(i,0));
        if(myCB)
        {
            urun.Malzeme =  myCB->currentIndex();
        }

        urun.BirimFiyat = ui->tbwMusteriUrun->item(i,1)->text().toFloat();

        musteri.Urunler[i] = urun;


    }


}


bool MusteriGirisi::AyniIsimVarMi(QString ad, QString soyaAdi)
{


    for(int i = 0; i<Musteriler.length();i++)
    {
        if(Musteriler[i].Ad == ad && Musteriler[i].Soyad == soyaAdi && Musteriler[i].ID != musteri.ID)
        {
            return true;
        }

    }

    return false;
}


bool MusteriGirisi::AyniUrunVarMi()
{

    QList<int> veriler;



    for(int i = 0;i< ui->tbwMusteriUrun->rowCount();i++)
    {
        QComboBox *myCB = qobject_cast<QComboBox*>(ui->tbwMusteriUrun->cellWidget(i,0));
        if(myCB)
        {
        if(veriler.size() > 0)
        {

            if(veriler.indexOf(myCB->currentIndex()) != -1)
            {
                return true;
            }
            else
            {
                veriler.append(myCB->currentIndex());
            }
        }
        else
        {
            veriler.append(myCB->currentIndex());
        }
        }


    }



    return false;
}


void MusteriGirisi::UyariCikar(const QString &uyari)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "Uyarı", uyari);


}

void MusteriGirisi::BilgiCikar(const QString &uyari)
{
    QMessageBox::StandardButton reply;
    QMessageBox::information(this, "Bilgi", uyari);


}

void MusteriGirisi::HataCikar(const QString &hata)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, "Hata", hata);


}






void MusteriGirisi::on_tbwMusteriUrun_cellChanged(int row, int column)
{

    if(column == 1)
    {



        ui->tbwMusteriUrun->item(row,1)->setText(ui->tbwMusteriUrun->item(row,1)->text().remove(QRegularExpression("[^\\d\\s\\'.'\\',']")));

        ui->tbwMusteriUrun->item(row,1)->setText(ui->tbwMusteriUrun->item(row,1)->text().replace(',','.'));
    }



}

