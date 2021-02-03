#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    int Id = 0;
    std::string Name;
    std::string Surname;
    std::string Pesel;
    std::string Place;
    std::string HouseFlatNo;
    std::string Street;
};

#endif
