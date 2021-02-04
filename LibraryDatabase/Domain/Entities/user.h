#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    int Id = 0;
    QString sId(){return (QString)(Id);};
    QString Name;
    QString Surname;
    QString Pesel;
    QString Place;
    QString HouseFlatNo;
    QString Street;
};

#endif
