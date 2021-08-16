#include <jsonokuyucu.h>
#include <QApplication>
#include "QVariant"

QEventLoop loop;
QNetworkReply *reply;


JSONOkuyucu::JSONOkuyucu()
{
    /*
    for(int i = 0;i < veri.count();i++)
    {
        QMap<QString, QVariant> map = veri[i].toMap();
        qDebug() << map["id"].toString() << "--" << map["ad"].toString();
    }*/


}



QList<QVariant> JSONOkuyucu::Oku(QString yol,QList<QString> Basliklar, QList<QVariant> Veriler)
{

    QNetworkAccessManager *naManager = new QNetworkAccessManager(this);
    QUrl url = QUrl(yol);

    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");



    QJsonObject obj;
    for(int i =0;i<Veriler.length();i++)
    {
        if (Veriler[i].type() == QVariant::Int)
        {
            obj[Basliklar[i]] = Veriler[i].toInt();
        }
        else if (Veriler[i].type() == QVariant::Double)
        {
            obj[Basliklar[i]] = Veriler[i].toFloat();
        }
        else
        {
            obj[Basliklar[i]] = Veriler[i].toString();
        }

    }
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();

    if (naManager)
    {

        QObject::connect(naManager, &QNetworkAccessManager::finished, this, &JSONOkuyucu::onFinish);

        reply = naManager->post(request, data);


    }

    loop.exec();


    return veri;
}



void JSONOkuyucu::onFinish(QNetworkReply *reply)
{



    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
        qDebug() << "status code=" << statusCode.toInt();

    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if(reason.isValid())
        qDebug() << "reason=" << reason.toString();

    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
    }
    else {


        QString data = reply->readAll().simplified();


        if(data == "false")
        {
            IslemBasarili = false;
        }
        else
        {
            IslemBasarili = true;
        }

        QJsonParseError jsonError;
        QJsonDocument flowerJson = QJsonDocument::fromJson(data.toUtf8(),&jsonError);
        if (jsonError.error != QJsonParseError::NoError){
            qDebug() << jsonError.errorString();
        }

        QVariant v = flowerJson.toVariant();
        veri= v.toList();

    }

    loop.exit();


    reply->deleteLater();

}




int JSONOkuyucu::GetAl(QString yol)
{

    QNetworkAccessManager *naManager = new QNetworkAccessManager(this);
    QUrl url = QUrl(yol);

    QNetworkRequest request;
    request.setUrl(url);

    if (naManager)
    {

        QObject::connect(naManager, &QNetworkAccessManager::finished, this, &JSONOkuyucu::onFinishGet);

        reply = naManager->get(request);

    }

    loop.exec();


    return data.toInt();
}



void JSONOkuyucu::onFinishGet(QNetworkReply *reply)
{



    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
        qDebug() << "status code=" << statusCode.toInt();

    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if(reason.isValid())
        qDebug() << "reason=" << reason.toString();

    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
    }
    else {


        data = reply->readAll().simplified();


    }

    reply->deleteLater();

    loop.exit();
}
