#ifndef PDF_H
#define PDF_H

#include <QString>



class PDF
{
public:
    PDF();

    void Pdf(QString filename, QString html);
private:
    QString currDate();
};

#endif // PDF_H
