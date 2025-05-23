#include "library.h"
#include "book.h"
#include "magazine.h"
#include <QFile>
#include <QDebug>
#include <QSharedPointer>
#include <QTextStream>
#include <iostream>
#include <memory>

Library::Library(const QString& filename)
    : nextId(1), filename(filename){
    loadData();
}

void Library::addBook(const QString& title, const QString& author, const QString& genre) {
    static int nextId = 1;
    items.append(std::make_shared<Book>(title, author, nextId++, genre));
    std::cout << "Book added successfully.\n";
}

void Library::addMagazine(const QString& title, const QString& author, int issue) {
    static int nextId = 1;
    items.append(std::make_shared<Magazine>(title, author, nextId++, issue));
    std::cout << "Magazine added successfully.\n";
}

void Library::getDisplayedItems() const {
    for (const auto& item : items) {
        std::cout << item->displayInfo().toStdString() << std::endl;
    }
}


void Library::searchItem(const QString& keyword) const {
    bool found = false;
    for (const auto& item : items) {
        if (item->displayInfo().contains(keyword, Qt::CaseInsensitive)) {
            qDebug().noquote() << item->displayInfo();
            found = true;
        }
    }
    if (!found) qDebug() << "No matching items found.";
}

bool Library::getBorrowedItem(int id) {
    for (auto& item : items) {
        if (item->getId() == id && !item->getIsBorrowed()) {
            item->setBorrowedItem();
            return true;
        }
    }
    return false;
}

bool Library::getReturnedItem(int id) {
    for (auto& item : items) {
        if (item->getId() == id && item->getIsBorrowed()) {
            item->setBorrowedItem();  // just call it
            return true;
        }
    }
    return false;
}


void Library::saveData() const {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto& item : items) {
            out << item->serialInfo() << "\n";
        }
        file.close();
    }
}

void Library::loadData(){
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            auto tokens = split(line, '|');
            if (tokens[0] == "Book" && tokens.size() == 6) {
                items.append(std::make_shared<Book>(tokens[2], tokens[3], tokens[1].toInt(), tokens[4], tokens[5].toInt()));
                nextId = qMax(nextId, tokens[1].toInt() + 1);
            } else if (tokens[0] == "Magazine" && tokens.size() == 6) {
                items.append(std::make_shared<Magazine>(tokens[2], tokens[3], tokens[1].toInt(), tokens[4].toInt(), tokens[5].toInt()));
                nextId = qMax(nextId, tokens[1].toInt() + 1);
            }
        }
        file.close();
    }
}

QStringList Library::split(const QString& str, const QChar& character) const {
    return str.split(character);
}
