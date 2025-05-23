#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <Qstring>


class LibraryItem {

public:
    LibraryItem(const QString& title, const QString& author, int id, bool isBorrowed);

    int getId() const;
    bool getIsBorrowed() const;
    void setBorrowedItem();
    void setReturnedItem();

    virtual QString displayInfo() const = 0;
    virtual QString toFileString() const = 0;
    virtual QString getType() const = 0;
    virtual QString serialInfo() const = 0;

    virtual ~LibraryItem() = default;

protected:
    QString title;
    QString author;
    int id;
    bool isBorrowed;

};
#endif // LIBRARYITEM_H
