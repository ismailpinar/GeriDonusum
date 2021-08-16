#include "anaform.h"
#include "anaform.h"
#include "ui_anaform.h"

#include <QMessageBox>
#include <musterigirisi.h>
#include <musterilistesi.h>

#include <QDesktopServices>
#include "QDebug"
#include <QStandardPaths>
#include <QDateTimeEdit>
#include <QHostAddress>
#include <qapplication.h>
#include <QNetworkInterface>
#include <QHostInfo>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <pdf.h>
#include <QUrlQuery>
#include <QString>
#include <QHttpPart>
#include <jsonokuyucu.h>
#include <hakkinda.h>
#ifdef Q_OS_ANDROID
#include <QtAndroid>
#endif





AnaForm::AnaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnaForm)
{

    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);




#ifdef Q_OS_ANDROID
    const QVector<QString> permissions({
        "android.permission.WRITE_EXTERNAL_STORAGE",
        "android.permission.READ_EXTERNAL_STORAGE"});

    for(const QString &permission : permissions){
        auto result = QtAndroid::checkPermission(permission);
        if(result == QtAndroid::PermissionResult::Denied){
            auto resultHash = QtAndroid::requestPermissionsSync(QStringList({permission}));
            if(resultHash[permission] == QtAndroid::PermissionResult::Denied)
            {

            }

        }
    }

#endif



    ui->tblListe->setColumnCount(11);
    ui->tblListe->verticalHeader()->setVisible(false);
    ui->tblListe->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblListe->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblListe->setShowGrid(true);
    ui->tblListe->setStyleSheet("QTableView {selection-background-color: red;}");
    ui->tblListe->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->tblListe->setHorizontalHeaderItem(1, new QTableWidgetItem("Müşteri Adı"));
    ui->tblListe->setHorizontalHeaderItem(2, new QTableWidgetItem("Malzeme"));
    ui->tblListe->setHorizontalHeaderItem(3, new QTableWidgetItem("Tarih"));
    ui->tblListe->setHorizontalHeaderItem(4, new QTableWidgetItem("Birim \n Fiyat (YTL)"));
    ui->tblListe->setHorizontalHeaderItem(5, new QTableWidgetItem("Miktar"));
    ui->tblListe->setHorizontalHeaderItem(6, new QTableWidgetItem("Fire \n (br)"));
    ui->tblListe->setHorizontalHeaderItem(7, new QTableWidgetItem("Net"));
    ui->tblListe->setHorizontalHeaderItem(8, new QTableWidgetItem("Toplam \n Ücret (YTL)"));
    ui->tblListe->setHorizontalHeaderItem(9, new QTableWidgetItem("Ödenen \n Ücret (YTL)"));
    ui->tblListe->setHorizontalHeaderItem(10, new QTableWidgetItem("Borç \n (YTL)"));






    ui->tblListe->horizontalHeader()->setMinimumHeight(50);


    ui->tblListe->setColumnWidth(0,50);
    ui->tblListe->setColumnWidth(1,220);
    ui->tblListe->setColumnWidth(2,100);
    ui->tblListe->setColumnWidth(3,150);
    ui->tblListe->setColumnWidth(4,80);
    ui->tblListe->setColumnWidth(5,80);

    ui->tblListe->setColumnWidth(6,60);
    ui->tblListe->setColumnWidth(7,80);
    ui->tblListe->setColumnWidth(8,100);
    ui->tblListe->setColumnWidth(9,100);
    ui->tblListe->setColumnWidth(10,100);


}






void AnaForm::showEvent(QShowEvent *ev)
{


#ifdef Q_OS_ANDROID
        showEventHelperAndroid();
        qDebug()<<"Android";

#else
    showEventHelper();
    qDebug()<<"Linux";

#endif

}

void AnaForm::showEventHelperAndroid()
{
    ui->tblListe->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 32px; }");
    ui->tblListe->setStyleSheet("QTableView {selection-background-color: red;font-size: 32px;}");

    int kapatButonYukseklik = Dpi * 0.5;
    int kapatButonGenislik = Dpi * 0.5;

    int sonNokta = 10;
    int baslangicY = kapatButonYukseklik * 1;

    float bosluk = Dpi * 0.005;


    int butonYukseklik = (W - 3* kapatButonYukseklik - bosluk * 6) / 6;
    int butonGenislik = Dpi;




    ui->tblListe->horizontalHeader()->setMinimumHeight(kapatButonYukseklik);

    double grid = H - bosluk * 3 - butonGenislik;



    int gridSutunToplam = grid;

    ui->pushButton->setGeometry(H - 80,W - 80 ,75,75);


    ui->tblListe->setColumnWidth(0,(int)(50.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(1,(int)(220.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(2,(int)(100.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(3,(int)(150.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(4,(int)(80.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(5,(int)(80.0 * (gridSutunToplam/1120.0)));

    ui->tblListe->setColumnWidth(6,(int)(60.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(7,(int)(80.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(8,(int)(100.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(9,(int)(100.0 * (gridSutunToplam/1120.0)));
    ui->tblListe->setColumnWidth(10,(int)(100.0 * (gridSutunToplam/1120.0)));


    ui->btnClose->setGeometry(H - bosluk - kapatButonGenislik, bosluk,kapatButonGenislik,kapatButonYukseklik);
    ui->btnFiltreler->setGeometry(H - bosluk - butonGenislik, ui->btnClose->y() + kapatButonYukseklik + bosluk,butonGenislik,butonYukseklik);
    ui->btnPDFCikar->setGeometry(H - bosluk - butonGenislik, ui->btnFiltreler->y() + bosluk + butonYukseklik,butonGenislik,butonYukseklik);



    ui->tblListe->setGeometry(bosluk,bosluk +2*baslangicY, grid,W - 4*kapatButonYukseklik -2*bosluk);

    ui->btnMalzemeGiris->setGeometry(H - bosluk - butonGenislik, ui->btnPDFCikar->y()+ butonYukseklik + bosluk ,butonGenislik,butonYukseklik);
    ui->btnMusteriKayit->setGeometry(H - bosluk - butonGenislik,ui->btnMalzemeGiris->y()+ butonYukseklik + bosluk,butonGenislik,butonYukseklik);
    ui->btnUrunKayit->setGeometry(H - bosluk - butonGenislik,ui->btnMusteriKayit->y()+ butonYukseklik + bosluk ,butonGenislik,butonYukseklik);




    ui->ebtnSil->setGeometry(H - bosluk - butonGenislik,ui->btnUrunKayit->y()+ butonYukseklik + bosluk ,butonGenislik,butonYukseklik);

    ui->ebtnSil->setStyleSheet("font-size: 32px;");
    ui->btnFiltreler->setStyleSheet("font-size: 32px;");
    ui->btnPDFCikar->setStyleSheet("font-size: 32px;");
    ui->btnMalzemeGiris->setStyleSheet("font-size: 32px;");
    ui->btnMusteriKayit->setStyleSheet("font-size: 32px;");
    ui->btnUrunKayit->setStyleSheet("font-size: 32px;");

    ui->btnFiltreler->setText("Filtrele");
    ui->btnMalzemeGiris->setText("Malzeme \n Girişi");
    ui->btnPDFCikar->setText("PDF\nÇıkar");
    ui->ebtnSil->setText("Sil");



    ui->btnUrunKayit->setStyleSheet("font-size: 32px;");
    ui->tMiktar->setStyleSheet("font-size: 32px;");
    ui->tFire->setStyleSheet("font-size: 32px;");
    ui->tOdenen->setStyleSheet("font-size: 32px;");
    ui->tToplam->setStyleSheet("font-size: 32px;");
    ui->tBorc->setStyleSheet("font-size: 32px;");
    ui->tnet->setStyleSheet("font-size: 32px;");





    ui->txtID->setGeometry(bosluk,bosluk +baslangicY,ui->tblListe->columnWidth(0),kapatButonYukseklik);
    ui->txtID->setAlignment(Qt::AlignCenter);
    ui->txtID->setStyleSheet("font-size: 32px;");


    sonNokta += ui->tblListe->columnWidth(0);
    ui->txtAd->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(1),kapatButonYukseklik);
    ui->txtAd->setAlignment(Qt::AlignCenter);
    ui->txtAd->setStyleSheet("font-size: 32px;");


    sonNokta+=ui->tblListe->columnWidth(1);
    ui->txtMalzeme->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(2),kapatButonYukseklik);
    ui->txtMalzeme->setAlignment(Qt::AlignCenter);
    ui->txtMalzeme->setStyleSheet("font-size: 32px;");



    sonNokta+=ui->tblListe->columnWidth(2);

    ui->btnBaslangic->setGeometry(sonNokta,bosluk,ui->tblListe->columnWidth(3),kapatButonYukseklik);
    ui->btnBitis->setGeometry(sonNokta, bosluk + kapatButonYukseklik ,ui->tblListe->columnWidth(3),kapatButonYukseklik);

    ui->btnBaslangic->setStyleSheet("font-size: 30px;");
    ui->btnBitis->setStyleSheet("font-size: 30px;");





    sonNokta+=ui->tblListe->columnWidth(3);
    ui->txtBirimFiyat->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(4),kapatButonYukseklik);
    ui->txtBirimFiyat->setAlignment(Qt::AlignCenter);
    ui->txtBirimFiyat->setStyleSheet("font-size: 32px;");


    sonNokta+=ui->tblListe->columnWidth(4);
    ui->txtMiktar->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(5),kapatButonYukseklik);
    ui->txtMiktar->setAlignment(Qt::AlignCenter);
    ui->txtMiktar->setStyleSheet("font-size: 32px;");


    sonNokta+=ui->tblListe->columnWidth(5);
    ui->txtFire->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(6),kapatButonYukseklik);
    ui->txtFire->setAlignment(Qt::AlignCenter);
    ui->txtFire->setStyleSheet("font-size: 32px;");


    sonNokta+=ui->tblListe->columnWidth(6);
    ui->txtNet->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(7),kapatButonYukseklik);
    ui->txtNet->setAlignment(Qt::AlignCenter);
    ui->txtNet->setStyleSheet("font-size: 32px;");


    sonNokta+=ui->tblListe->columnWidth(7);
    ui->txtToplam->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(8),kapatButonYukseklik);
    ui->txtToplam->setAlignment(Qt::AlignCenter);
    ui->txtToplam->setStyleSheet("font-size: 32px;");


    sonNokta+=ui->tblListe->columnWidth(8);
    ui->txtOdenen->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(9),kapatButonYukseklik);
    ui->txtOdenen->setAlignment(Qt::AlignCenter);
    ui->txtOdenen->setStyleSheet("font-size: 32px;");



    sonNokta+=ui->tblListe->columnWidth(9);
    ui->txtBorc->setGeometry(sonNokta,bosluk +baslangicY,ui->tblListe->columnWidth(10),kapatButonYukseklik);
    ui->txtBorc->setAlignment(Qt::AlignCenter);
    ui->txtBorc->setStyleSheet("font-size: 32px;");




    auto dv = new QDoubleValidator(-1000000.0, 100000.0, 0);
    ui->txtID->setValidator(dv);
    dv = new QDoubleValidator(-1000000.0, 100000.0, 2);
    ui->txtBirimFiyat->setValidator(dv);
    ui->txtMiktar->setValidator(dv);
    ui->txtOdenen->setValidator(dv);
    ui->txtBorc->setValidator(dv);
    ui->txtToplam->setValidator(dv);
    ui->txtFire->setValidator(dv);
    ui->txtNet->setValidator(dv);



    QDate d;
    d.setDate(d.currentDate().year(),d.currentDate().month(),1);
    QDateTime dateTime(d, QTime(0, 00, 0));

    baslangicZaman = dateTime;
    ui->btnBaslangic->setText(baslangicZaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));
    QDateTime dateTime2(d.currentDate(), QTime(23, 59, 59));

    bitisZaman = dateTime2;
    ui->btnBitis->setText(bitisZaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));




    ui->tMiktar->setGeometry(ui->txtMiktar->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtMiktar->width(),kapatButonYukseklik);
    ui->tMiktar->setAlignment(Qt::AlignCenter);

    ui->tFire->setGeometry(ui->txtFire->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtFire->width(),kapatButonYukseklik);
    ui->tFire->setAlignment(Qt::AlignCenter);

    ui->tOdenen->setGeometry(ui->txtOdenen->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtOdenen->width(),kapatButonYukseklik);
    ui->tOdenen->setAlignment(Qt::AlignCenter);

    ui->tToplam->setGeometry(ui->txtToplam->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtToplam->width(),kapatButonYukseklik);
    ui->tToplam->setAlignment(Qt::AlignCenter);

    ui->tBorc->setGeometry(ui->txtBorc->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtBorc->width(),kapatButonYukseklik);
    ui->tBorc->setAlignment(Qt::AlignCenter);

    ui->tnet->setGeometry(ui->txtNet->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtNet->width(),kapatButonYukseklik);
    ui->tnet->setAlignment(Qt::AlignCenter);

    ui->tFire->setVisible(false);



    ui->lblToplam->setGeometry(bosluk,ui->tnet->y()+2*bosluk,ui->tblListe->columnWidth(1),kapatButonYukseklik);
}

void AnaForm::showEventHelper()
{
    int yukseklik = 750;
    int genislik = 1280;

    int kapatButonYukseklik = 50;
    int kapatButonGenislik = 50;

    int sonNokta = 10;
    int baslangicY = kapatButonYukseklik * 2;


    int butonYukseklik = 80;
    int butonGenislik = 100;

    AnaFormRect = QRect(desktopRect.x()-genislik/2 - 0,desktopRect.y() - yukseklik/2,genislik,yukseklik);



    setGeometry(AnaFormRect);

    ui->btnClose->setGeometry(genislik - 10 - kapatButonGenislik, 10,kapatButonGenislik,kapatButonYukseklik);
    ui->btnFiltreler->setGeometry(genislik - 10 - butonGenislik, baslangicY,butonGenislik,butonYukseklik/2);
    ui->btnPDFCikar->setGeometry(genislik - 10 - butonGenislik, baslangicY+butonYukseklik/2 + 20,butonGenislik,butonYukseklik);





    ui->tblListe->setGeometry(10,5+1.5*baslangicY, genislik - 30 - butonGenislik,yukseklik - 2.5*butonYukseklik -10);


    ui->btnMalzemeGiris->setGeometry(genislik - 10 - butonGenislik,ui->tblListe->height() + ui->tblListe->y()-5*butonYukseklik -20 ,butonGenislik,butonYukseklik);
    ui->btnMusteriKayit->setGeometry(genislik - 10 - butonGenislik,ui->tblListe->height() + ui->tblListe->y()-4* butonYukseklik -10 ,butonGenislik,butonYukseklik);
    ui->btnUrunKayit->setGeometry(genislik - 10 - butonGenislik,ui->tblListe->height() + ui->tblListe->y()-3*butonYukseklik ,butonGenislik,butonYukseklik);



    ui->ebtnSil->setGeometry(genislik - 10 - butonGenislik,ui->tblListe->height() + ui->tblListe->y()-2*butonYukseklik +10 ,butonGenislik,butonYukseklik);


    ui->ebtnSil->setText("Sil");

    ui->pushButton->setGeometry(genislik - 40,yukseklik - 40 ,32,32);


    ui->txtID->setGeometry(10,baslangicY,ui->tblListe->columnWidth(0),kapatButonYukseklik);
    ui->txtID->setAlignment(Qt::AlignCenter);

    sonNokta += ui->tblListe->columnWidth(0);
    ui->txtAd->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(1),kapatButonYukseklik);
    ui->txtAd->setAlignment(Qt::AlignCenter);


    sonNokta+=ui->tblListe->columnWidth(1);
    ui->txtMalzeme->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(2),kapatButonYukseklik);
    ui->txtMalzeme->setAlignment(Qt::AlignCenter);


    sonNokta+=ui->tblListe->columnWidth(2);

    ui->btnBaslangic->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(3),kapatButonYukseklik/2);
    ui->btnBitis->setGeometry(sonNokta,baslangicY +kapatButonYukseklik/2 ,ui->tblListe->columnWidth(3),kapatButonYukseklik/2);




    sonNokta+=ui->tblListe->columnWidth(3);
    ui->txtBirimFiyat->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(4),kapatButonYukseklik);
    ui->txtBirimFiyat->setAlignment(Qt::AlignCenter);


    sonNokta+=ui->tblListe->columnWidth(4);
    ui->txtMiktar->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(5),kapatButonYukseklik);
    ui->txtMiktar->setAlignment(Qt::AlignCenter);


    sonNokta+=ui->tblListe->columnWidth(5);
    ui->txtFire->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(6),kapatButonYukseklik);
    ui->txtFire->setAlignment(Qt::AlignCenter);


    sonNokta+=ui->tblListe->columnWidth(6);
    ui->txtNet->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(7),kapatButonYukseklik);
    ui->txtNet->setAlignment(Qt::AlignCenter);


    sonNokta+=ui->tblListe->columnWidth(7);
    ui->txtToplam->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(8),kapatButonYukseklik);
    ui->txtToplam->setAlignment(Qt::AlignCenter);


    sonNokta+=ui->tblListe->columnWidth(8);
    ui->txtOdenen->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(9),kapatButonYukseklik);
    ui->txtOdenen->setAlignment(Qt::AlignCenter);


    sonNokta+=ui->tblListe->columnWidth(9);
    ui->txtBorc->setGeometry(sonNokta,baslangicY,ui->tblListe->columnWidth(10),kapatButonYukseklik);
    ui->txtBorc->setAlignment(Qt::AlignCenter);



    auto dv = new QDoubleValidator(-1000000.0, 100000.0, 0);
    ui->txtID->setValidator(dv);
    dv = new QDoubleValidator(-1000000.0, 100000.0, 2);
    ui->txtBirimFiyat->setValidator(dv);
    ui->txtMiktar->setValidator(dv);
    ui->txtOdenen->setValidator(dv);
    ui->txtBorc->setValidator(dv);
    ui->txtToplam->setValidator(dv);
    ui->txtFire->setValidator(dv);
    ui->txtNet->setValidator(dv);





    QDate d;
    d.setDate(d.currentDate().year(),d.currentDate().month(),1);
    QDateTime dateTime(d, QTime(0, 00, 0));

    baslangicZaman = dateTime;
    ui->btnBaslangic->setText(baslangicZaman.toUTC().toString());
    ui->btnBaslangic->setText(baslangicZaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));


    QDateTime dateTime2(d.currentDate(), QTime(23, 59, 59));

    bitisZaman = dateTime2;
    ui->btnBitis->setText(bitisZaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));



    ui->tMiktar->setGeometry(ui->txtMiktar->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtMiktar->width(),kapatButonYukseklik);
    ui->tMiktar->setAlignment(Qt::AlignCenter);

    ui->tFire->setGeometry(ui->txtFire->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtFire->width(),kapatButonYukseklik);
    ui->tFire->setAlignment(Qt::AlignCenter);

    ui->tOdenen->setGeometry(ui->txtOdenen->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtOdenen->width(),kapatButonYukseklik);
    ui->tOdenen->setAlignment(Qt::AlignCenter);

    ui->tToplam->setGeometry(ui->txtToplam->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtToplam->width(),kapatButonYukseklik);
    ui->tToplam->setAlignment(Qt::AlignCenter);

    ui->tBorc->setGeometry(ui->txtBorc->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtBorc->width(),kapatButonYukseklik);
    ui->tBorc->setAlignment(Qt::AlignCenter);

    ui->tnet->setGeometry(ui->txtNet->x(),ui->tblListe->height() + ui->tblListe->y(),ui->txtNet->width(),kapatButonYukseklik);
    ui->tnet->setAlignment(Qt::AlignCenter);

    ui->tFire->setVisible(false);



    ui->lblToplam->setGeometry(10,ui->tnet->y(),200,50);
}


void AnaForm::VerileriOku(QList<QVariant> veriler)
{

    ui->tblListe->setRowCount(0);

    float toplamMiktar = 0;
    float toplamNet = 0;
    float toplamOdenen=0;
    float toplamBorc =0;
    float toplamToplam =0 ;
    float toplamFire =0;


    ListeBilgileri list;

    liste.clear();



    int satirSayisi = ui->tblListe->rowCount();


    for(int i=0;i<veriler.length();i++)
    {

        list.ID = veriler[i].toMap().values()[5].toInt();
        list.MusteriAdi = veriler[i].toMap().values()[8].toString();
        list.MalzemeAdi = veriler[i].toMap().values()[6].toString();
        list.Tarih = veriler[i].toMap().values()[12].toDateTime();
        list.BirimFiyat = veriler[i].toMap().values()[1].toFloat();
        list.Miktar = veriler[i].toMap().values()[7].toFloat();
        list.Fire = veriler[i].toMap().values()[4].toFloat();
        list.Odenen = veriler[i].toMap().values()[11].toFloat();
        list.MusteriID = veriler[i].toMap().values()[9].toInt();



        ui->tblListe->setRowCount(satirSayisi +1);


        QTableWidgetItem * id = new QTableWidgetItem(QString::number(list.ID));
        id->setTextAlignment(Qt::AlignCenter);
        ui->tblListe->setItem(satirSayisi,0,id);

        id = new QTableWidgetItem(list.MusteriAdi);
        id->setTextAlignment(Qt::AlignCenter);
        ui->tblListe->setItem(satirSayisi,1,id);

        id = new QTableWidgetItem(list.MalzemeAdi);
        id->setTextAlignment(Qt::AlignCenter);
        ui->tblListe->setItem(satirSayisi,2,id);


        id = new QTableWidgetItem();
        id->setData(Qt::DisplayRole, list.Tarih);
        id->setTextAlignment(Qt::AlignCenter);
        ui->tblListe->setItem(satirSayisi,3,id);


        id = new QTableWidgetItem(QString::number(list.BirimFiyat,'f',2).replace(".",","));
        id->setTextAlignment(Qt::AlignCenter);
        ui->tblListe->setItem(satirSayisi,4,id);


        id = new QTableWidgetItem(QString::number(list.Miktar,'f',2).replace(".",","));
        id->setTextAlignment(Qt::AlignCenter);
        ui->tblListe->setItem(satirSayisi,5,id);

        toplamMiktar += list.Miktar;


        id = new QTableWidgetItem(QString::number(list.Fire,'f',2).replace(".",","));
        id->setTextAlignment(Qt::AlignCenter);
        id->setTextColor(QColor(222,0,0,255));
        ui->tblListe->setItem(satirSayisi,6,id);

        toplamFire += list.Fire;


        float net = list.Miktar  - list.Fire;

        id = new QTableWidgetItem(QString::number(net,'f',2).replace(".",","));
        id->setTextAlignment(Qt::AlignCenter);
        id->setTextColor(QColor(0,100,0,255));
        ui->tblListe->setItem(satirSayisi,7,id);

        toplamNet += net;

        float toplam = list.BirimFiyat * net;


        id = new QTableWidgetItem(QString::number(toplam,'f',2).replace(".",","));
        id->setTextAlignment(Qt::AlignCenter);
        ui->tblListe->setItem(satirSayisi,8,id);

        toplamToplam += toplam;


        id = new QTableWidgetItem(QString::number(list.Odenen,'f',2).replace(".",","));
        id->setTextAlignment(Qt::AlignCenter);
        id->setTextColor(QColor(0,100,0,255));
        ui->tblListe->setItem(satirSayisi,9,id);

        toplamOdenen += list.Odenen;


        id = new QTableWidgetItem(QString::number(list.Odenen - toplam,'f',2).replace(".",","));
        id->setTextAlignment(Qt::AlignCenter);
        id->setTextColor(QColor(0,0,100,255));
        ui->tblListe->setItem(satirSayisi,10,id);

        toplamBorc += list.Odenen- toplam;

        list.Borc =  list.Odenen - toplam;

        satirSayisi++;

        liste.append(list);

    }

    ui->tToplam->setText(QString::number(toplamToplam,'f',2).replace(".",","));
    ui->tnet->setText(QString::number(toplamNet,'f',2).replace(".",","));
    ui->tFire->setText(QString::number(toplamFire,'f',2).replace(".",","));
    ui->tBorc->setText(QString::number(toplamBorc,'f',2).replace(".",","));
    ui->tOdenen->setText(QString::number(toplamOdenen,'f',2).replace(".",","));
    ui->tMiktar->setText(QString::number(toplamMiktar,'f',2).replace(".",","));



}

void AnaForm::UyariCikar(const QString &uyari)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "Uyarı", uyari);


}

void AnaForm::BilgiCikar(const QString &uyari)
{
    QMessageBox::StandardButton reply;
    QMessageBox::information(this, "Bilgi", uyari);


}

void AnaForm::HataCikar(const QString &hata)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, "Hata", hata);


}






AnaForm::~AnaForm()
{
    delete ui;
}

void AnaForm::on_btnUrunKayit_clicked()
{
    urg = new urunGirisi;


    urg->adjustSize();

    urg->show();

}


void AnaForm::on_btnMusteriKayit_clicked()
{


    wdg = new MusteriListesi;

    wdg->adjustSize();

    wdg->show();
}


void AnaForm::on_btnClose_clicked()
{
    this->close();

}



void AnaForm::on_btnMalzemeGiris_clicked()
{
    mlz = new MalzemeGiris;

    mlz->adjustSize();

    mlz->show();
}


void AnaForm::on_btnFiltreler_clicked()
{
    Filtrele();
}

void AnaForm::Filtrele()
{
    ui->tblListe->model()->removeRows(0,ui->tblListe->rowCount());



    QList<QVariant> veriler= this->GirisAl();


    VerileriOku(veriler);



}

QList<QVariant> AnaForm::GirisAl()
{
    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;

    if(j.IslemBasarili)
    {
        return Veriler;
    }



    QString fid = ui->txtID->text();
    QString fuser = ui->txtAd->text();
    QString fmalzeme = ui->txtMalzeme->text();
    QString fBirimFiyat = ui->txtBirimFiyat->text();
    QString fMiktar = ui->txtMiktar->text();
    QString fFire = ui->txtFire->text();
    QString fOdenen = ui->txtOdenen->text();
    QString fBaslangic = QString::number(baslangicZaman.date().year());
    fBaslangic.append("/");
    fBaslangic.append(QString::number(baslangicZaman.date().month()));
    fBaslangic.append("/");
    fBaslangic.append(QString::number(baslangicZaman.date().day()));
    fBaslangic.append(" ");
    fBaslangic.append(QString::number(baslangicZaman.time().hour()));
    fBaslangic.append(":");
    fBaslangic.append(QString::number(baslangicZaman.time().minute()));
    fBaslangic.append(":");
    fBaslangic.append(QString::number(baslangicZaman.time().second()));


    QString fBitis = QString::number(bitisZaman.date().year());
    fBitis.append("/");
    fBitis.append(QString::number(bitisZaman.date().month()));
    fBitis.append("/");
    fBitis.append(QString::number(bitisZaman.date().day()));
    fBitis.append(" ");
    fBitis.append(QString::number(bitisZaman.time().hour()));
    fBitis.append(":");
    fBitis.append(QString::number(bitisZaman.time().minute()));
    fBitis.append(":");
    fBitis.append(QString::number(bitisZaman.time().second()));








    if(fid == NULL || fid == "")
    {
        Basliklar.append("ID");
        Veriler.append(-1);
    }
    else
    {
        Basliklar.append("ID");
        Veriler.append(fid.toInt());
    }

    if(fuser == NULL || fuser == "")
    {}
    else
    {
        Basliklar.append("MusteriAdi");
        Veriler.append(fuser);
    }
    if(fmalzeme == NULL || fmalzeme == "")
    {}
    else
    {
        Basliklar.append("MalzemeAdi");
        Veriler.append(fmalzeme);
    }

    Basliklar.append("BaslangicTarih");
    Veriler.append(fBaslangic);

    Basliklar.append("BitisTarih");
    Veriler.append(fBitis);

    if(fBirimFiyat == NULL || fBirimFiyat == "")
    {
        Basliklar.append("BirimFiyat");
        Veriler.append(-1);
    }
    else
    {
        Basliklar.append("BirimFiyat");
        Veriler.append(fBirimFiyat.toDouble());
    }

    if(fMiktar == NULL || fMiktar == "")
    {
        Basliklar.append("Miktar");
        Veriler.append(-1);
    }
    else
    {
        Basliklar.append("Miktar");
        Veriler.append(fMiktar.toDouble());
    }

    if(fFire == NULL || fFire == "")
    {
        Basliklar.append("Fire");
        Veriler.append(-1);
    }
    else
    {
        Basliklar.append("Fire");
        Veriler.append(fFire.toDouble());
    }

    if(fOdenen == NULL || fOdenen == "")
    {
        Basliklar.append("Odenen");
        Veriler.append(-1);
    }
    else
    {
        Basliklar.append("Odenen");
        Veriler.append(fOdenen.toDouble());
    }


   veri = j.Oku("http://37z.148.213.13:5001/AnaForm/getir",Basliklar,Veriler);



   return veri;
}



bool  AnaForm::event(QEvent *e)
{

    if (e->type() == QEvent::WindowActivate) {

        onActivated();
    }


    return QWidget::event(e);
}


void AnaForm::onActivated()
{
    Filtrele();

}


void AnaForm::PDFCikar()
{
    QString yol;




#ifdef Q_OS_ANDROID


    qDebug() <<"aaaaaaaaaaaaaa" <<QStandardPaths::displayName(QStandardPaths::DownloadLocation);

    yol = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);


    yol.append("/rapor.pdf");


#else
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::DontUseNativeDialog, true);
    dialog.setOption(QFileDialog::ShowDirsOnly, false);

    if (dialog.exec())
    {
        yol = dialog.selectedFiles().at(0);

        yol.append("/rapor.pdf");
    }
    else
    {
        return;
    }

#endif





    QDateTime day;

    QString tarih;
    QString saat;

    tarih.append(QString::number(day.currentDateTime().date().day()));
    tarih.append("-");
    tarih.append(QString::number(day.currentDateTime().date().month()));
    tarih.append("-");
    tarih.append(QString::number(day.currentDateTime().date().year()));
    tarih.append("");
    saat.append(QString::number(day.currentDateTime().time().hour()));
    saat.append(":");
    saat.append(QString::number(day.currentDateTime().time().minute()));


    QString tablo;



    for(int i=0;i<ui->tblListe->rowCount();i++)
    {
        QString zaman = ui->tblListe->item(i,3)->text();
        int tNo = zaman.indexOf("T");

        int leng = zaman.length();
        QString ssatx = zaman.right(leng - tNo - 1);
        int nokta = ssatx.lastIndexOf(":");
        ssatx = ssatx.left(nokta);

        QString tarihx = zaman.left(tNo);
        tarihx = tarihx.replace("T"," ");

        tablo += "</tr>"
                 "<tr>"
            "<td align=center valign=center halign=center> <p><font size=1 font color=black>"+ui->tblListe->item(i,1)->text()+"</font></p></td>"
                                                        "<td align=center valign=center halign=center> <p><font size=1 font color=black>"+ui->tblListe->item(i,2)->text()+"</font></p></td>"
                                                      "<td align=center valign=center halign=center> <p><font size=1 font color=black>"+tarihx +" <brb>" + ssatx + "</font></p></td>"
                                                 "<td align=center valign=center halign=center> <p><font size=1 font color=black>"+ui->tblListe->item(i,4)->text()+"</font></p></td>"
                                                 "<td align=center valign=center halign=center> <p><font size=1 font color=black>"+ui->tblListe->item(i,5)->text()+"</font></p></td>"
                                                 "<td align=center valign=center halign=center> <p><font size=1 font color=red>"+ui->tblListe->item(i,6)->text()+"</font></p></td>"
                                                 "<td align=center valign=center halign=center> <p><font size=1 font color=green>"+ui->tblListe->item(i,7)->text()+"</font></p></td>"
                                                 "<td align=center valign=center halign=center> <p><font size=1 font color=black>"+ui->tblListe->item(i,8)->text()+"</font></p></td>"
                                                 "<td align=center valign=center halign=center> <p><font size=1 font color=green>"+ui->tblListe->item(i,9)->text()+"</font></p></td>"
                                                 "<td align=center valign=center halign=center> <p><font size=1 font color=blue>"+ui->tblListe->item(i,10)->text()+"</font></p></td>";

    }


    tablo += "</tr>"
             "<tr>"
             "<td align=center valign=center halign=center>""</td>"
                                                  "<td align=center valign=center halign=center>""</td>"
                                                  "<td align=center valign=center halign=center>""</td>"
                                                  "<td align=center valign=center halign=center> <p><font size=1 font color=black><br><br><br>TOPLAM =</td>"
                                                  "<td align=center valign=center halign=center> <p><font size=1 font color=black><br><br><br>"+ui->tMiktar->text()+"</td>"
                                                  "<td align=center valign=center halign=center> <p><font size=1 font color=red> </font></p></td>"
                                                  "<td align=center valign=center halign=center> <p><font size=1 font color=green> <br><br><br>"+ui->tnet->text()+"</font></p></td>"
                                                  "<td align=center valign=center halign=center> <p><font size=1 font color=black><br><br><br>"+ui->tToplam->text()+"</td>"
                                                  "<td align=center valign=center halign=center> <p><font size=1 font color=green><br><br><br>"+ui->tOdenen->text()+"</font></p></td>"
                                                  "<td align=center valign=center halign=center> <p><font size=1 font color=blue> <br><br><br>"+ui->tBorc->text()+"</font></p></td>";


    QString baslangic = QString::number(baslangicZaman.date().day())  +"-" + QString::number(baslangicZaman.date().month()) +"-" + QString::number(baslangicZaman.date().year());
    QString bitis = QString::number(bitisZaman.date().day())  +"-" + QString::number(bitisZaman.date().month()) +"-" + QString::number(bitisZaman.date().year());


    QList<int> sutunGenislikleri;


#ifdef Q_OS_ANDROID
    sutunGenislikleri.append((200.0 * (H-50)) /1100.0 );
    sutunGenislikleri.append((100.0 * (H-50)) /1100.0 );
    sutunGenislikleri.append((90.0 *  (H-50)) /1100.0 );
    sutunGenislikleri.append((100.0 * (H-50)) /1100.0 );
    sutunGenislikleri.append((100.0 * (H-50)) /1100.0 );
    sutunGenislikleri.append((80.0 *  (H-50)) /1100.0 );
    sutunGenislikleri.append((100.0 * (H-50)) /1100.0 );
    sutunGenislikleri.append((110.0 * (H-50)) /1100.0 );
    sutunGenislikleri.append((110.0 * (H-50)) /1100.0 );
    sutunGenislikleri.append((110.0 * (H-50)) /1100.0 );

#else
    sutunGenislikleri.append((200.0 * (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((100.0 * (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((150.0 * (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((80.0 *  (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((80.0 *  (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((80.0 *  (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((80.0 *  (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((110.0 * (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((110.0 * (desktopRect.x()-100)) /1100.0 );
    sutunGenislikleri.append((110.0 * (desktopRect.x()-100)) /1100.0 );

#endif




    QString html =

        "<div align=right>"
        "Saat: "+
        saat+"   &nbsp;&nbsp;&nbsp;&nbsp;    Tarih: "+tarih+
        "</div>"
        "<div align=left>"
        "Pet Ka Geri Dönüşüm Ltd. Şti.<br>"
        "Küçükbalıklı mh.<br>"
        "1.Heybe sokak No:3<br>"
        "OSMANGAZİ<br>"
        "BURSA"
        "</div>"
        "<h1 align=center>PETKA GERİ GÖNÜŞÜM GİRDİ ÇIKTI RAPORU</h1>"
        "<p align=justify>"
        "Şirketimiz üzerinden "+baslangic+" tarihinden "+bitis+" tarihine kadar yapılmış alış veriş listesi aşağıdaki gibidir."
        "<div align=left>Saygılarımızla.</div>"
        "</p> <br>"
        "<table border=1 bordercolor=gray >"
        "<body>"
        "<tr>"
        "<td width="+QString::number(sutunGenislikleri[0])+" align=center valign=center halign=center>Müşteri Adı</td>"
        "<td width="+QString::number(sutunGenislikleri[1])+" align=center valign=center halign=center>Malzeme Adı</td>"
        "<td width="+QString::number(sutunGenislikleri[2])+" align=center valign=center halign=center>Tarih</td>"
        "<td width="+QString::number(sutunGenislikleri[3])+" align=center valign=center halign=center>Birim Fiyat (YTL)</td>"
        "<td width="+QString::number(sutunGenislikleri[4])+" align=center valign=center halign=center>Miktar</td>"
        "<td width="+QString::number(sutunGenislikleri[5])+" align=center valign=center halign=center>Fire<</td>"
        "<td width="+QString::number(sutunGenislikleri[6])+" align=center valign=center halign=center>Net</td>"
        "<td width="+QString::number(sutunGenislikleri[7])+" align=center valign=center halign=center>Toplam Ücret (YTL)</td>"
        "<td width="+QString::number(sutunGenislikleri[8])+" align=center valign=center halign=center>Ödenen Ücret (YTL)</td>"
        "<td width="+QString::number(sutunGenislikleri[9])+" align=center valign=center halign=center>Kalan (YTL)</td>"+
        tablo+
        "</tr>"
        "</body>"
        "</table></p>";





    PDF* p = new PDF();
    p->Pdf(yol,html);

    BilgiCikar("PDF Oluşturma işlemi Başarılı.");


}





void AnaForm::on_btnPDFCikar_clicked()
{

    PDFCikar();
}







void AnaForm::on_ebtnSil_clicked(bool checked)
{

    int secim = ui->tblListe->currentRow();

    int id = ui->tblListe->item(secim,0)->text().toInt();

    if(BorcGuncelle())
    {

    }
    else
    {
        BilgiCikar("Borç güncelleme hatası!");
    }

    QList<QVariant> veri;
    JSONOkuyucu j;
    QList<QVariant> Veriler;
    QList<QString> Basliklar;

    Basliklar.append("ID");
    Veriler.append(id);


    qDebug()<<"id = "<<id;

    veri = j.Oku("http://00.0.0.0:0/GirisA/sil",Basliklar,Veriler);


    if(j.IslemBasarili)
    {
        BilgiCikar("Başarı ile silindi!");
    }
    else
    {
        HataCikar("Silme işlemi başarısız! ");
    }

}


bool AnaForm::BorcGuncelle()
{
    int secim = ui->tblListe->currentRow();

    int id = liste[secim].MusteriID;



    double borc = liste[secim].Borc;





      QList<QVariant> veri;
      JSONOkuyucu j;
      QList<QVariant> Veriler;
      QList<QString> Basliklar;


      Basliklar.append("Ad");
      Veriler.append("");

      Basliklar.append("ID");
      Veriler.append(liste[secim].MusteriID);


      Basliklar.append("SoyAd");
      Veriler.append("");

      Basliklar.append("KullaniciUrunID");
      Veriler.append(0);

      Basliklar.append("Borc");
      Veriler.append(liste[secim].Borc);



      veri = j.Oku("http://00.0.0.0:0/Musteriler/guncelleBorc",Basliklar,Veriler);


      ui->tblListe->removeRow(secim);

      liste.removeAt(secim);


      return j.IslemBasarili;


}

QDateTime AnaForm::SaatAc(QDateTime zaman)
{
    Dialog *dialog = new Dialog();

    dialog->zaman.setDate(zaman.date());
    dialog->zaman.setTime(zaman.time());

    dialog->exec();
    qDebug()<<(dialog->dateTime);

    return dialog->zaman;

}

void AnaForm::on_btnBaslangic_clicked()
{
    baslangicZaman = SaatAc(baslangicZaman);

    ui->btnBaslangic->setText(baslangicZaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));

}


void AnaForm::on_btnBitis_clicked()
{
   bitisZaman = SaatAc(bitisZaman);

   ui->btnBitis->setText(bitisZaman.toLocalTime().toString("dd-MM-yyyy hh:mm:ss"));


}




void AnaForm::on_pushButton_clicked()
{
    //QMessageBox::about(this,"Yazılım Hakkında", "           by Pınar Soft \n pinarsoftware@gmail.com");
    Hakkinda *dialog = new Hakkinda();


    dialog->exec();

}

