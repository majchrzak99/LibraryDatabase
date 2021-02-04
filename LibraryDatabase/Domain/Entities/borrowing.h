#ifndef BORROWING_H
#define BORROWING_H

#include <QString>
#include <QDateTime>

class Borrowing
{
public:
    int Id_borrow = 0;
    int Id_book;
    QString borrowDate;
    QString returnDate;
    int Id_user;
};

#endif
