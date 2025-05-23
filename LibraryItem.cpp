#include "LibraryItem.h"
#include "ui_LibraryItem.h"

#include "libraryitem.h"


LibraryItem::LibraryItem(const QString& title, const QString& author, int id, bool isBorrowed)
    : title(title), author(author), id(id), isBorrowed(false) {}

int LibraryItem::getId() const{
    return id;
}
bool LibraryItem::getIsBorrowed() const{
    return isBorrowed;
}
void LibraryItem::setBorrowedItem(){
    isBorrowed = true;
}
void LibraryItem::setReturnedItem(){
    isBorrowed = false;
}
