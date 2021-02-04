#ifndef BORROWING_H
#define BORROWING_H

#include <string>
#include <QDateTime>

class Borrowing
{
public:
    int Id_borow = 0;
    int Id_book;
    QDateTime borrowDate;
    QDateTime returnDate;
    int Id_user;
};

#endif
