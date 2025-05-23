#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QString>
#include "libraryitem.h"

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(const QString& title, const QString& author, int id, int issueNumber, bool isBorrowed = false);
    QString getType() const override;
    QString serialInfo() const override;
    QString displayInfo() const override;


    QString toFileString() const override;

};

#endif // MAGAZINE_H
