#include "urungirisi.h"
#include "ui_urungirisi.h"
#include "jsonokuyucu.h"

#include <QMessageBox>
#include "QDebug"
#include <QRegExp>


urunGirisi::urunGirisi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::urunGirisi)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);


    ui->tbwUrun->setColumnCount(3);
    ui->tbwUrun->verticalHeader()->setVisible(false);
    ui->tbwUrun->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbwUrun->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tbwUrun->setShowGrid(true);
    ui->tbwUrun->setStyleSheet("QTableView {selection-background-color: red;}");
    ui->tbwUrun->setHorizontalHeaderItem(0, new QTableWidgetItem(""));
    ui->tbwUrun->setHorizontalHeaderItem(1, new QTableWidgetItem("Ad"));
    ui->tbwUrun->setHorizontalHeaderItem(2, new QTableWidgetItem("ID"));
    ui->tbwUrun->setEditTriggers(QAbstractItemView::NoEditTriggers);






    ui->tbwUrun->setColumnWidth(0,0);
    ui->tbwUrun->setColumnWidth(1,250);
    ui->tbwUrun->setColumnWidth(2,0);



    UrunleriDoldur();






}

void urunGirisi::showEvent(QShowEvent *ev)
{
#ifdef Q_OS_ANDROID
    showEventHelperAndroid();
    qDebug()<<"Android";

#else
    showEventHelper();
    qDebug()<<"Linux";

#endif
}


void urunGirisi::showEventHelperAndroid()
{
    int kapatButonYukseklik = Dpi * 0.5;
    int kapatButonGenislik = Dpi * 0.5;


    ui->tbwUrun->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 32px; }");
    ui->tbwUrun->setStyleSheet("QTableView {selection-background-color: red;font-size: 32px;}");




    float bosluk = Dpi * 0.005;

    int butonYukseklik = (W - 3* kapatButonYukseklik - bosluk * 6) / 5;
    int butonGenislik = Dpi;







    ui->btnClose->setGeometry(H - bosluk - kapatButonGenislik, bosluk,kapatButonGenislik,kapatButonYukseklik);



    ui->btnEkle->setGeometry(H - bosluk - butonGenislik, kapatButonYukseklik * 2,butonGenislik,butonYukseklik);
    ui->btnSil->setGeometry( H - bosluk - butonGenislik, kapatButonYukseklik * 2.5 + butonYukseklik ,butonGenislik,butonYukseklik);


    ui->label->setGeometry(bosluk,bosluk,H - kapatButonYukseklik -butonGenislik,kapatButonYukseklik);

    ui->txtUrun->setGeometry(bosluk,ui->label->y() + ui->label->height() + bosluk,H - kapatButonYukseklik -butonGenislik,butonYukseklik / 2);

    ui->label_2->setGeometry(bosluk,ui->txtUrun->y() + ui->txtUrun->height() + bosluk,H - kapatButonYukseklik -butonGenislik,butonYukseklik / 2);

    ui->tbwUrun->setGeometry(bosluk,ui->label_2->y() + ui->label_2->height() + bosluk,H - kapatButonYukseklik -butonGenislik, W - ui->label_2->y() - ui->label_2->height() - bosluk);

    ui->tbwUrun->setColumnWidth(1,H - kapatButonYukseklik * 2 -butonGenislik);


    ui->btnEkle->setText("Ekle");
    ui->btnSil->setText("Sil");



    // setGeometry(desktopRect);
}


void urunGirisi::showEventHelper()
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


    ui->label->setGeometry(10,kapatButonYukseklik,genislik - 50 -butonGenislik,butonYukseklik);

    ui->txtUrun->setGeometry(10,butonYukseklik/2 + kapatButonYukseklik + 10,genislik - 50 -butonGenislik,butonYukseklik / 2);

    ui->label_2->setGeometry(10,butonYukseklik/2 + 2*kapatButonYukseklik + 10,genislik - 50 -butonGenislik,butonYukseklik / 2);

    ui->tbwUrun->setGeometry(10,butonYukseklik + 2*kapatButonYukseklik + 10,genislik - 50 -butonGenislik, yukseklik - butonYukseklik - 2*kapatButonYukseklik - 20);

    ui->tbwUrun->setColumnWidth(1,genislik - 50 -butonGenislik -50);




   // setGeometry(desktopRect);
}

void urunGirisi::UrunleriDoldur()
{

    this->VeriCek();

    int urunSayisi = urunler.count();

    ui->tbwUrun->setRowCount(urunSayisi);


    for(int i=0;i<urunSayisi;i++)
    {
        QTableWidgetItem * id = new QTableWidgetItem(urunler[i]);
        id->setTextAlignment(Qt::AlignCenter);
        ui->tbwUrun->setItem(i,1,id);
    }

    if(urunSayisi > 0)
    {
        ui->tbwUrun->selectRow(0);
    }


}

void urunGirisi::VeriCek()
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
        urunler.append(veri[i].toMap().values()[0].toString());
    }

}



urunGirisi::~urunGirisi()
{
    delete ui;
}

void urunGirisi::on_btnSil_clicked()
{
    if(ui->tbwUrun->rowCount() > 0)
    {
        Sil();
    }
}


void urunGirisi::on_btnEkle_clicked()
{





    if(QRegExp("\\s*").exactMatch(ui->txtUrun->toPlainText()))
    {
       UyariCikar("Lütfen bir karakter giriniz!");


        return;
    }
    else if(AyniUrunVarMi())
    {
        UyariCikar("Birden çok aynı isimde ürün var!");
        return;
    }
    else
    {
        Kaydet();

        ui->tbwUrun->selectRow(ui->tbwUrun->rowCount()-1);

    }
}

bool urunGirisi::AyniUrunVarMi()
{
    if(urunler.indexOf(ui->txtUrun->toPlainText()) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void urunGirisi::Kaydet()
{

    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;

    QString isim = ui->txtUrun->toPlainText();

    Basliklar.append("ad");
    Veriler.append(isim);


    veri = j.Oku("http://00.0.0.0:0/Urunler/ekle",Basliklar,Veriler);

    if(j.IslemBasarili)
    {
        urunler.append(isim);
        ui->tbwUrun->setRowCount(urunler.length());
        ui->tbwUrun->setItem(urunler.length() - 1,1,new QTableWidgetItem(isim));
    }
    else
    {
        HataCikar("Kaydetme İşlemi Başarısız!");
    }

}

void urunGirisi::Sil()
{
    QModelIndexList selection = ui->tbwUrun->selectionModel()->selectedRows();

    QString secim = urunler[selection.at(0).row()];



    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;


    Basliklar.append("Ad");
    Veriler.append(secim);


    veri = j.Oku("http://00.0.0.0:0/Urunler/sil",Basliklar,Veriler);

    if(j.IslemBasarili)
    {
        urunler.removeAt(selection.at(0).row());
        ui->tbwUrun->removeRow(selection.at(0).row());
    }
    else
    {
        HataCikar("Silme işlemi Başarısız!");
    }
}


void urunGirisi::on_btnClose_clicked()
{
    this->close();

}

void urunGirisi::UyariCikar(const QString &uyari)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "Uyarı", uyari);


}

void urunGirisi::BilgiCikar(const QString &uyari)
{
    QMessageBox::StandardButton reply;
    QMessageBox::information(this, "Bilgi", uyari);


}

void urunGirisi::HataCikar(const QString &hata)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, "Hata", hata);


}


