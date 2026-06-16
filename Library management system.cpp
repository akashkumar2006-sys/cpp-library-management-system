#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int bookID;
    string title;
    string author;
    bool issued;

    Book()
    {
        bookID = 0;
        title = "";
        author = "";
        issued = false;
    }
};

Book library[100];
int totalBooks = 0;

void addBook()
{
    cout << "\nEnter Book ID: ";
    cin >> library[totalBooks].bookID;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, library[totalBooks].title);

    cout << "Enter Author Name: ";
    getline(cin, library[totalBooks].author);

    library[totalBooks].issued = false;

    totalBooks++;

    cout << "\nBook Added Successfully!\n";
}

void displayBooks()
{
    if (totalBooks == 0)
    {
        cout << "\nNo books available.\n";
        return;
    }

    cout << "\n========== BOOK LIST ==========\n";

    for (int i = 0; i < totalBooks; i++)
    {
        cout << "\nBook ID: " << library[i].bookID;
        cout << "\nTitle: " << library[i].title;
        cout << "\nAuthor: " << library[i].author;
        cout << "\nStatus: ";

        if (library[i].issued)
            cout << "Issued";
        else
            cout << "Available";

        cout << "\n---------------------------\n";
    }
}

void searchBook()
{
    int id;
    cout << "\nEnter Book ID to Search: ";
    cin >> id;

    for (int i = 0; i < totalBooks; i++)
    {
        if (library[i].bookID == id)
        {
            cout << "\nBook Found!\n";
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;

            if (library[i].issued)
                cout << "Status: Issued\n";
            else
                cout << "Status: Available\n";

            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

void issueBook()
{
    int id;
    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < totalBooks; i++)
    {
        if (library[i].bookID == id)
        {
            if (library[i].issued)
            {
                cout << "\nBook is already issued.\n";
            }
            else
            {
                library[i].issued = true;
                cout << "\nBook Issued Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

void returnBook()
{
    int id;
    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < totalBooks; i++)
    {
        if (library[i].bookID == id)
        {
            if (!library[i].issued)
            {
                cout << "\nBook was not issued.\n";
            }
            else
            {
                library[i].issued = false;
                cout << "\nBook Returned Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

void deleteBook()
{
    int id;
    cout << "\nEnter Book ID to Delete: ";
    cin >> id;

    for (int i = 0; i < totalBooks; i++)
    {
        if (library[i].bookID == id)
        {
            for (int j = i; j < totalBooks - 1; j++)
            {
                library[j] = library[j + 1];
            }

            totalBooks--;

            cout << "\nBook Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===================================";
        cout << "\n LIBRARY MANAGEMENT SYSTEM";
        cout << "\n===================================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Delete Book";
        cout << "\n7. Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            deleteBook();
            break;

        case 7:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}