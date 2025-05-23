#ifndef LIBRARY_H
#define LIBRARY_H

#include <QVector>
#include <QString>
#include <memory>
#include <QStringList>
#include "libraryitem.h"

class Library{
private:
    int nextId;
    const QString filename;
    QVector<std::shared_ptr<LibraryItem>> items;
    QStringList split(const QString& string, const QChar& character) const;

public:
    Library(const QString& filename = "library_data.txt");

    bool getBorrowedItem(int id);
    bool getReturnedItem(int id);
    void getDisplayedItems() const;
    void saveData() const;
    void loadData();
    void searchItem(const QString& keyword) const;
    void addMagazine(const QString& author, const QString& title, int issueNumber);
    void addBook(const QString& author, const QString& title, const QString& genre);


};

#endif // LIBRARY_H
