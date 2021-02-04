#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    int Id = 0;
    QString sId(){return (QString)(Id);};
    QString Title;
    QString Author;
    QString PublishDate;
    QString PublishCountry;
    QString IsbnNumber;
};

#endif
