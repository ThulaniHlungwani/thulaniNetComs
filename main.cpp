#include <QCoreApplication>
#include <QTextStream>
#include "library.h"
#include <iostream>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    Library library;
    int choice;

    /*cout << "\nLibrary Management System Menu:\n";
    cout << "1. Add Book\n2. Add Magazine\n3. Search by Title\n";
    cout << "4. Display All Items\n5. Borrow Item\n6. Return Item\n7. Exit\nChoice:";*/

    while (true) {
        //cout << "\n1. Add Book\n2. Add Magazine\n3. Display All\n4. Search\n5. Borrow\n6. Return\n0. Exit\nChoice: ";
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Add Book\n2. Add Magazine\n3. Search by Title\n";
        cout << "4. Display All Items\n5. Borrow Item\n6. Return Item\n7. Exit\nChoice: ";
        cout.flush();
        cin >> choice;
        cin.readLine(); // clear newline

        if (choice == 0) break;

        QString title, author, genre;
        int issue, id;

        switch (choice) {
        case 1:
            cout << "Title: "; title = cin.readLine();
            cout << "Author: "; author = cin.readLine();
            cout << "Genre: "; genre = cin.readLine();
            library.addBook(title, author, genre);
            break;
        case 2:
            cout << "Title: "; title = cin.readLine();
            cout << "Author: "; author = cin.readLine();
            cout << "Issue #: "; cin >> issue; cin.readLine();
            library.addMagazine(title, author, issue);
            break;
        case 3:
            library.getDisplayedItems();
            break;
        case 4:
            cout << "Keyword: "; title = cin.readLine();
            library.searchItem(title);
            break;
        case 5:
            cout << "ID to borrow: "; cin >> id; cin.readLine();
            if (!library.getBorrowedItem(id)) cout << "Cannot borrow.\n";
            break;
        case 6:
            cout << "ID to return: "; cin >> id; cin.readLine();
            if (!library.getReturnedItem(id)) cout << "Cannot return.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }


    return 0;
}
