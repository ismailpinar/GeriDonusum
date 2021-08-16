#ifndef JSONOKUYUCU_H
#define JSONOKUYUCU_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>



class JSONOkuyucu:public QObject
{
    Q_OBJECT

private slots:
     void onFinish(QNetworkReply *);
     void onFinishGet(QNetworkReply *);

public:

    JSONOkuyucu();

    QList<QVariant> Oku(QString yol,QList<QString> Basliklar, QList<QVariant> Veriler);

    bool IslemBasarili = false;


    int GetAl(QString yol);
private:


    QList<QVariant> veri;
    QString data;


};

#endif // JSONOKUYUCU_H
