#include "magazine.h"

Magazine::Magazine(const QString& title, const QString& author, int id, int issueNumber, bool isBorrowed)
    : LibraryItem(title, author, id, isBorrowed), issueNumber(issueNumber) {}

QString Magazine::getType() const {
    return "Magazine";
}

QString Magazine::serialInfo() const {
    return QString("Magazine|%1|%2|%3|%4|%5")
    .arg(id)
        .arg(title)
        .arg(author)
        .arg(issueNumber)
        .arg(isBorrowed);
}

QString Magazine::displayInfo() const {
    return QString("Magazine ID: %1 | Title: %2 | Author: %3 | Issue: %4 | Status: %5")
    .arg(id)
        .arg(title)
        .arg(author)
        .arg(issueNumber)
        .arg(isBorrowed ? "Borrowed" : "Available");
}

QString Magazine::toFileString() const {
    return QString("Magazine|%1|%2|%3|%4|%5")
    .arg(id)
        .arg(title)
        .arg(author)
        .arg(issueNumber)
        .arg(isBorrowed);
}

