#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
private:
    QString genre;
    QString author;
    unsigned int year;
    QString name;
public:
    Book();
    Book(QString, QString, unsigned int, QString);
    QString getGenre();
    void setGenre(QString);
    QString getAuthor();
    void setAuthor(QString);
    unsigned int getYear();
    void setYear(unsigned int);
    QString getName();
    void setName(QString);
};

#endif // BOOK_H
