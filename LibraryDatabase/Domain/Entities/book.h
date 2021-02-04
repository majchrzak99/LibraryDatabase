#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    int Id = 0;
    std::string sId(){return std::to_string(Id);};
    std::string Title;
    std::string Author;
    std::string PublishDate;
    std::string PublishCountry;
    std::string IsbnNumber;
};

#endif
