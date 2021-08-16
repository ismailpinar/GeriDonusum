#include "musterilistesi.h"
#include "ui_musterilistesi.h"

#include <QMessageBox>
#include <QRegExp>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <anaform.h>
#include <jsonokuyucu.h>
#include "QDebug"
#include "QScreen"

#include "Globaller.h"

QList<Musteri> Musteriler;
QList<QString> Urunler;


MusteriListesi::MusteriListesi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusteriListesi)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);










    ui->tblMusteriListesi->setColumnCount(4);
    ui->tblMusteriListesi->verticalHeader()->setVisible(false);
    ui->tblMusteriListesi->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblMusteriListesi->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblMusteriListesi->setShowGrid(true);
    ui->tblMusteriListesi->setStyleSheet("QTableView {selection-background-color: red;}");
    ui->tblMusteriListesi->setHorizontalHeaderItem(0, new QTableWidgetItem(""));
    ui->tblMusteriListesi->setHorizontalHeaderItem(1, new QTableWidgetItem("İsim Soyisim"));
    ui->tblMusteriListesi->setHorizontalHeaderItem(2, new QTableWidgetItem("ID"));
    ui->tblMusteriListesi->setHorizontalHeaderItem(3, new QTableWidgetItem("Borç (YTL)"));

    ui->tblMusteriListesi->setEditTriggers(QAbstractItemView::NoEditTriggers);








    ui->tblMusteriListesi->setColumnWidth(0,50);
    ui->tblMusteriListesi->setColumnWidth(1,0);
    ui->tblMusteriListesi->setColumnWidth(2,0);
    ui->tblMusteriListesi->setColumnWidth(3,100);






    VerileriOku();
    ListeDoldur();
    UrunTipleriOku();

    if(Musteriler.length() > 0)
    {
        ui->tblMusteriListesi->selectRow(0);
    }



}

MusteriListesi::~MusteriListesi()
{
    delete ui;
}

void MusteriListesi::showEvent(QShowEvent *ev)
{
#ifdef Q_OS_ANDROID
    showEventHelperAndroid();
    qDebug()<<"Android";

#else
    showEventHelper();
    qDebug()<<"Linux";

#endif
}


void MusteriListesi::showEventHelperAndroid()
{
    int kapatButonYukseklik = Dpi * 0.5;
    int kapatButonGenislik = Dpi * 0.5;

    ui->tblMusteriListesi->setColumnWidth(0,kapatButonGenislik);
    ui->tblMusteriListesi->setColumnWidth(1,0);
    ui->tblMusteriListesi->setColumnWidth(2,0);
    ui->tblMusteriListesi->setColumnWidth(3,kapatButonGenislik * 3);

    ui->tblMusteriListesi->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 32px; }");
    ui->tblMusteriListesi->setStyleSheet("QTableView {selection-background-color: red;font-size: 32px;}");




    float bosluk = Dpi * 0.005;

    int butonYukseklik = (W - 3* kapatButonYukseklik - bosluk * 6) / 5;
    int butonGenislik = Dpi;


    ui->tblMusteriListesi->horizontalHeader()->setMinimumHeight(kapatButonYukseklik);





    ui->btnClose->setGeometry(H - bosluk - kapatButonGenislik, bosluk,kapatButonGenislik,kapatButonYukseklik);
    ui->btnEkle->setGeometry(H - bosluk - butonGenislik, kapatButonYukseklik * 2,butonGenislik,butonYukseklik);
    ui->btnMLSil->setGeometry( H - bosluk - butonGenislik, kapatButonYukseklik * 2.5 + butonYukseklik ,butonGenislik,butonYukseklik);
    ui->btnMLGuncelle->setGeometry(H - bosluk - butonGenislik, kapatButonYukseklik * 5 + butonYukseklik ,butonGenislik,butonYukseklik);



    ui->lblMusteriListesi->setGeometry(bosluk,bosluk,H - kapatButonYukseklik -butonGenislik,butonYukseklik/2);
    ui->tblMusteriListesi->setGeometry(bosluk,butonYukseklik/2+bosluk,H - kapatButonYukseklik -butonGenislik,W - 3*butonYukseklik);

    ui->lblToplam->setGeometry(bosluk,ui->tblMusteriListesi->height() + ui->tblMusteriListesi->y() ,H - kapatButonYukseklik -butonGenislik,butonYukseklik/2);
    ui->txtToplam->setGeometry(bosluk,ui->lblToplam->height() + ui->lblToplam->y() ,H - kapatButonYukseklik -butonGenislik,butonYukseklik/2);



    ui->tblMusteriListesi->setColumnWidth(1,ui->tblMusteriListesi->width() - kapatButonGenislik * 5);


    ui->txtToplam->setEnabled(false);
    ui->txtToplam->setObjectName("txtToplam");
    ui->txtToplam->setAccessibleName("txtToplam");
    QString styleSheet = "#txtToplam { color: rgb(0, 0, 0); ;font:18px}";
    ui->txtToplam->setStyleSheet(styleSheet);
    ui->txtToplam->setAlignment(Qt::AlignHCenter);


    ui->btnEkle->setStyleSheet("font-size: 32px;");
    ui->btnMLSil->setStyleSheet("font-size: 32px;");
    ui->btnMLGuncelle->setStyleSheet("font-size: 32px;");

    ui->btnEkle->setText("Ekle");
    ui->btnMLSil->setText("Sil");
    ui->btnMLGuncelle->setText("Güncelle");


    ui->lblToplam->setStyleSheet("font-size: 32px;");
    ui->lblMusteriListesi->setStyleSheet("font-size: 32px;");

}


void MusteriListesi::showEventHelper()
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
    ui->btnMLSil->setGeometry( genislik - 10 - butonGenislik, kapatButonYukseklik * 2.5 + butonYukseklik ,butonGenislik,butonYukseklik);
    ui->btnMLGuncelle->setGeometry(genislik - 10 - butonGenislik, kapatButonYukseklik * 5 + butonYukseklik ,butonGenislik,butonYukseklik);



    ui->lblMusteriListesi->setGeometry(10,10,genislik - 50 -butonGenislik,butonYukseklik/2);
    ui->tblMusteriListesi->setGeometry(10,butonYukseklik/2+10,genislik - 50 -butonGenislik,yukseklik - 2*butonYukseklik);

    ui->lblToplam->setGeometry(10,ui->tblMusteriListesi->height() + ui->tblMusteriListesi->y() ,genislik - 50 -butonGenislik,butonYukseklik/2);
    ui->txtToplam->setGeometry(10,ui->lblToplam->height() + ui->lblToplam->y() ,genislik - 50 -butonGenislik,butonYukseklik/2);



    ui->tblMusteriListesi->setColumnWidth(1,ui->tblMusteriListesi->width() - kapatButonGenislik -butonGenislik - 50);
    ui->tblMusteriListesi->setColumnWidth(3,butonGenislik);

    ui->tblMusteriListesi->setColumnWidth(0,kapatButonGenislik);

    ui->txtToplam->setEnabled(false);
    ui->txtToplam->setObjectName("txtToplam");
    ui->txtToplam->setAccessibleName("txtToplam");
    QString styleSheet = "#txtToplam { color: rgb(0, 0, 0); ;font:18px}";
    ui->txtToplam->setStyleSheet(styleSheet);
    ui->txtToplam->setAlignment(Qt::AlignHCenter);




}

void MusteriListesi::VerileriOku()
{
    VeriCek();


}

void MusteriListesi::VeriCek()
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


    float toplamBorc=0;


    for(int i = 0;i < veri.count();i++)
    {
        QMap<QString, QVariant> map = veri[i].toMap();

        Musteri musteri;

        musteri.Ad = (map.values()[0].toString());
        musteri.Soyad = (map.values()[4].toString());
        musteri.ID = (map.values()[2].toInt());
        musteri.KullaniciUrunID = (map.values()[3].toInt());
        musteri.Borc = (map.values()[1].toFloat());


        toplamBorc +=musteri.Borc;

        Musteriler.append(musteri);
    }

    ui->txtToplam->setText(QString::number(toplamBorc,'f',2).replace(".",","));

}

void MusteriListesi::ListeDoldur()
{
    int musteriSayisi = Musteriler.length();


    int kapatButonYukseklik = 50;

    ui->tblMusteriListesi->setRowCount(musteriSayisi);

    for(int i = 0;i<musteriSayisi ;i++)
    {
        QTableWidgetItem * id = new QTableWidgetItem(QString::number(i+1));
        id->setTextAlignment(Qt::AlignCenter);
        ui->tblMusteriListesi->setItem(i,0,id);

        QTableWidgetItem * ad = new QTableWidgetItem(Musteriler[i].Ad + " " + Musteriler[i].Soyad);
        ad->setTextAlignment(Qt::AlignCenter);
        ui->tblMusteriListesi->setItem(i,1,ad);

        QTableWidgetItem * borc = new QTableWidgetItem(QString::number(Musteriler[i].Borc,'f', 2).replace(".",","));
        borc->setTextAlignment(Qt::AlignCenter);
        ui->tblMusteriListesi->setItem(i,3,borc);


        ui->tblMusteriListesi->setItem(i,2,new QTableWidgetItem(QString::number(Musteriler[i].ID)));

        ui->tblMusteriListesi->setRowHeight(i,kapatButonYukseklik);



        GridFontGuncelle(i);

    }



}








void MusteriListesi::on_btnMLSil_clicked()
{
    if(ui->tblMusteriListesi->rowCount() <= 0)
    {
        UyariCikar("Silinecek müşteri mevcut değil lütfen müşteri ekleyin!");
        return;

    }

    bool basari = Sil(Musteriler[seciliMusteriSira].ID);

    if(basari)
    {
        Musteriler.removeAt(seciliMusteriSira);


        ui->tblMusteriListesi->removeRow(ui->tblMusteriListesi->currentRow());

        seciliMusteriSira = Musteriler.length() - 1;
        seciliGridSira = seciliMusteriSira;

        BilgiCikar("Silme işlemi başarılı");

    }
    else
    {
        HataCikar("Silme işlemi başarısız!");

    }


}



bool MusteriListesi::Sil(int silinecekNo)
{

    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;


    Basliklar.append("Ad");
    Veriler.append("**");


    Basliklar.append("Soyad");
    Veriler.append("");


    Basliklar.append("ID");
    Veriler.append(silinecekNo);


    Basliklar.append("KullaniciUrunID");
    Veriler.append(-1);

    Basliklar.append("Borc");
    Veriler.append(-1);



    veri = j.Oku("http://00.0.0.0:0/Musteriler/sil",Basliklar,Veriler);

    if(j.IslemBasarili)
    {

        if(MusteriUrunleriSil(Musteriler[seciliMusteriSira].KullaniciUrunID))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }


}

bool MusteriListesi::MusteriUrunleriSil(int silinecekNo)
{
    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;




    Basliklar.append("ID");
    Veriler.append(1);

    Basliklar.append("Malzeme");
    Veriler.append(0);


    Basliklar.append("KullaniciUrunID");
    Veriler.append(silinecekNo);

    Basliklar.append("BiimFiyat");
    Veriler.append(0);



    veri = j.Oku("http://00.0.0.0:0/MusteriUrunler/sil",Basliklar,Veriler);

    if(j.IslemBasarili)
    {
        return true;
    }
    else
    {
        return false;
    }


}

int MusteriListesi::SilinecekDiziElemaniBul(int id)
{

    int sira = -1;

    for(int i=0;i<Musteriler.count();i++)
    {
        if(Musteriler[i].ID == id)
        {
            sira = i;

            break;
        }
    }



    return sira;

}

void MusteriListesi::UrunTipleriOku()
{
    Urunler.clear();

    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;


    Basliklar.append("ad");
    Veriler.append("*#*");


    veri = j.Oku("http://00.0.0.0:0/Urunler/getir",Basliklar,Veriler);


    for(int i = 0;i < veri.count();i++)
    {
        Urunler.append(veri[i].toMap().values()[0].toString());
    }

}


void MusteriListesi::on_btnEkle_clicked()
{


    if(Urunler.length() > 0)
    {
        wdg = new MusteriGirisi;

        eklemeIcinAc = true;


        wdg->SonUrunIDAl();
        wdg->show();

    }
    else
    {
        BilgiCikar("Müşteriye eklenecek ürün mevcut değil lütfen ürün ekleyin!");
    }


}


void MusteriListesi::on_btnClose_clicked()
{
    close();
}


void MusteriListesi::on_btnMLGuncelle_clicked()
{
    if(ui->tblMusteriListesi->rowCount() <= 0)
    {
         UyariCikar("Güncellenecek müşteri mevcut değil lütfen müşteri ekleyin!");
         return;

    }


    Guncelle();

}

void MusteriListesi::Guncelle()
{


    if(Urunler.length() > 0)
    {
        wdg = new MusteriGirisi;


        eklemeIcinAc = false;

        wdg->musteri = Musteriler[seciliMusteriSira];
        wdg->VerileriDoldur(Musteriler[seciliMusteriSira]);

        wdg->show();

    }
    else
    {
        HataCikar("Müşteriye eklenecek ürün mevcut değil lütfen ürün ekleyin!");
    }

}


void MusteriListesi::on_tblMusteriListesi_itemSelectionChanged()
{



}


void MusteriListesi::on_tblMusteriListesi_cellClicked(int row, int column)
{
    seciliGridSira = ui->tblMusteriListesi->currentRow();

    int sira = ui->tblMusteriListesi->item(ui->tblMusteriListesi->currentRow(),2)->text().toInt();


    int no = SilinecekDiziElemaniBul(sira);






    if(seciliMusteriSira == no )
    {
        Guncelle();
    }
    else
    {      
        seciliMusteriSira = no;
    }


}


void MusteriListesi::on_tblMusteriListesi_cellDoubleClicked(int row, int column)
{
    seciliGridSira = ui->tblMusteriListesi->currentRow();

    int sira = ui->tblMusteriListesi->item(ui->tblMusteriListesi->currentRow(),2)->text().toInt();

    int no = SilinecekDiziElemaniBul(sira);

     seciliMusteriSira = no;

     //Guncelle();





}


bool  MusteriListesi::event(QEvent *e)
{

    if (e->type() == QEvent::WindowActivate) {

        onActivated();
    }


    return QWidget::event(e);
}


void MusteriListesi::onActivated()
{
    if(bilgiGoster)
    {
        bilgiGoster = false;
        return;
    }




    if(acildi)
    {

        VeriGuncelle();
    }
    else
    {
        acildi = true;
    }
}

void MusteriListesi::VeriGuncelle()
{
    int kapatButonYukseklik = 50;

    if(eklemeIcinAc)
    {
        if(QRegExp("\\s*").exactMatch(wdg->musteri.Ad))
        {
            return;
        }
        Musteriler.append(wdg->musteri);
        ui->tblMusteriListesi->setRowCount(Musteriler.length());
        seciliMusteriSira = Musteriler.length() - 1;

        QString kullanici;

        kullanici.append(Musteriler[seciliMusteriSira].Ad);
        kullanici.append(" ");
        kullanici.append(Musteriler[seciliMusteriSira].Soyad);



        ui->tblMusteriListesi->setItem(Musteriler.length() - 1,2,new QTableWidgetItem(QString::number(Musteriler[seciliMusteriSira].KullaniciUrunID)));




        QTableWidgetItem * user = new QTableWidgetItem(kullanici);
        user->setTextAlignment(Qt::AlignCenter);
        ui->tblMusteriListesi->setItem(Musteriler.length() - 1,1,user);

        QTableWidgetItem * userid = new QTableWidgetItem(QString::number(Musteriler.length()));
        userid->setTextAlignment(Qt::AlignCenter);
        ui->tblMusteriListesi->setItem(Musteriler.length() - 1,0,userid);

        QTableWidgetItem * borc = new QTableWidgetItem("0");
        borc->setTextAlignment(Qt::AlignCenter);
        ui->tblMusteriListesi->setItem(Musteriler.length() - 1,3,borc);


        ui->tblMusteriListesi->setRowHeight(Musteriler.length() - 1,kapatButonYukseklik);

        ui->tblMusteriListesi->selectRow(Musteriler.length() - 1);


        GridFontGuncelle(Musteriler.length() - 1);






    }
    else
    {
        Musteriler[seciliMusteriSira].Ad = wdg->musteri.Ad;
        Musteriler[seciliMusteriSira].Soyad = wdg->musteri.Soyad;

        QString kullanici;

        kullanici.append(Musteriler[seciliMusteriSira].Ad);
        kullanici.append(" ");
        kullanici.append(Musteriler[seciliMusteriSira].Soyad);





        QTableWidgetItem * user = new QTableWidgetItem(kullanici);
        user->setTextAlignment(Qt::AlignCenter);
        ui->tblMusteriListesi->setItem(seciliGridSira,1,user);

        GridFontGuncelle(seciliGridSira);
    }

    Musteriler[seciliMusteriSira].Urunler.clear();





}


void MusteriListesi::UyariCikar(const QString &uyari)
{
    bilgiGoster = true;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "Uyarı", uyari);


}

void MusteriListesi::BilgiCikar(const QString &uyari)
{
    bilgiGoster = true;

    QMessageBox::StandardButton reply;
    QMessageBox::information(this, "Bilgi", uyari);


}

void MusteriListesi::HataCikar(const QString &hata)
{
    bilgiGoster = true;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, "Hata", hata);


}




void MusteriListesi::GridFontGuncelle(int i)
{
    QFont fnt;
    fnt.setPointSize(12);
    fnt.setBold(false);
    fnt.setFamily("Biolinum");




    QTableWidgetItem* selectedItem = ui->tblMusteriListesi->item(i, 0);
    selectedItem->setFont(fnt);
    selectedItem = ui->tblMusteriListesi->item(i, 1);
    selectedItem->setFont(fnt);
    selectedItem = ui->tblMusteriListesi->item(i, 3);
    selectedItem->setFont(fnt);


}





