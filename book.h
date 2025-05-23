#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    QString genre;

public:
    Book(const QString& title, const QString& author, int id, const QString& genre, bool isBorrowed = false);

    QString getType() const override;
    QString serialInfo() const override;
    QString displayInfo() const override;

    // ✅ Add this to override the pure virtual function in LibraryItem
    QString toFileString() const override;
};

#endif // BOOK_H
