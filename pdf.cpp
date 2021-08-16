#include "pdf.h"
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QTextCharFormat>
#include <QTextDocument>
#include <QTextCursor>
#include <pdf.h>

PDF::PDF()
{
}


QString PDF::currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}




void PDF::Pdf(QString filename,QString html)
{





    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::ScreenResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);
    printer.setPageMargins(QMarginsF(5, 15, 5, 15));
    printer.setOrientation(QPrinter::Landscape);

    document.print(&printer);
}


