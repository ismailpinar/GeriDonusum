#include "musterigirisi.h"
#include "QDebug"
#include <QApplication>
#include <musterilistesi.h>
#include <anaform.h>
#include <QMessageBox>
#include <QScreen>
#include "Globaller.h"
#include "QDesktopWidget"
#include "jsonokuyucu.h"

QPoint desktopRect;
QRect AnaFormRect;
qreal refDpi;
qreal refH;
qreal refW;
qreal H;
qreal W;
qreal Dpi;
qreal Oran;
qreal OranFont;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    desktopRect = QApplication::desktop()->screen()->rect().center();


    refDpi = 216.;
    refH = 1776.;
    refW = 1080.;

    QRect rect = QGuiApplication::primaryScreen()->geometry();
    H = qMax(rect.width(), rect.height());
    W = qMin(rect.width(), rect.height());
    Dpi = QGuiApplication::primaryScreen()->logicalDotsPerInch();


    Oran = qMin(H/refH, W/refW);
    OranFont = qMin(H*refDpi/(Dpi*W), W*refDpi/(Dpi*W));


    AnaForm widget;

    widget.adjustSize();
    //widget.move(desktopRect);
    widget.show();





    return a.exec();
}
