#include "book.h"

Book::Book(const QString& title, const QString& author, int id, const QString& genre, bool isBorrowed)
    : LibraryItem(title, author, id, isBorrowed), genre(genre) {}

QString Book::getType() const {
    return "Book";
}

QString Book::serialInfo() const {
    return QString("Book|%1|%2|%3|%4|%5")
    .arg(id)
        .arg(title)
        .arg(author)
        .arg(genre)
        .arg(isBorrowed);
}

QString Book::displayInfo() const {
    return QString("Book ID: %1 | Title: %2 | Author: %3 | Genre: %4 | Availability: %5")
    .arg(id)
        .arg(title)
        .arg(author)
        .arg(genre)
        .arg(isBorrowed ? "Borrowed" : "Available");
}

// ✅ Add this function to fulfill the pure virtual function from base class
QString Book::toFileString() const {
    return QString("%1|%2|%3|%4|%5|%6")
    .arg(getType())
        .arg(id)
        .arg(title)
        .arg(author)
        .arg(genre)
        .arg(isBorrowed);
}
