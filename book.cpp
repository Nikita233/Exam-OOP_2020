#include "book.h"

Book::Book()
{

}

Book::Book(QString _genre, QString _author, unsigned int _year, QString _name) {
    genre = _genre;
    author = _author;
    year = _year;
    name = _name;
}

QString Book::getGenre() {
    return genre;
}

void Book::setGenre(QString _genre) {
    genre = _genre;
}

QString Book::getAuthor() {
    return author;
}

void Book::setAuthor(QString _author) {
    author = _author;
}

unsigned int Book::getYear() {
    return year;
}

void Book::setYear(unsigned int _year) {
    year = _year;
}

QString Book::getName() {
    return name;
}

void Book::setName(QString _name) {
    name = _name;
}
