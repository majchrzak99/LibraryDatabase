#ifndef BORROWING_H
#define BORROWING_H

#include <string>
#include <QDateTime>

class Borrowing
{
public:
    int Id_borrow = 0;
    int Id_book;
    std::string borrowDate;
    std::string returnDate;
    int Id_user;
};

#endif
