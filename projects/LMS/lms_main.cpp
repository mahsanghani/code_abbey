//
// Created by Ahsan Ghani on 2022-09-01.
//
#include <iostream>
#include <curses.h>
#include <string>

using namespace std;

class Book
{
private:
    // variables
    string isbn;
    string title;
    string author;
    string edition;
    string publication;

public:
    // setters
    void setIsbn(string a)
    {
        isbn = a;
    }
    void setTitle(string b)
    {
        title = b;
    }
    void setAuthor(string c)
    {
        author = c;
    }
    void setEdition(string d)
    {
        edition = d;
    }
    void setPublication(string e)
    {
        publication = e;
    }

    // getters
    string getIsbn()
    {
        return isbn;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getEdition()
    {
        return edition;
    }
    string getPublication()
    {
        return publication;
    }
};

// functions
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void quit();

int counter = 0;

void increment(int a)
{
    a++;
    counter=a;
}

void decrement(int a)
{
    a--;
    counter=a;
}

Book books[10];

int main()
{
    string choice;
    system("CLS");

    cout << "Library Management System" << endl;
    cout << "[1] Add Book" << endl;
    cout << "[2] Delete Book" << endl;
    cout << "[3] Edit Book" << endl;
    cout << "[4] Search Book" << endl;
    cout << "[5] View All Books" << endl;
    cout << "[6] Quit" << endl;

    cout << "Enter Choice: " << endl;
    getline(cin, choice);
    system("CLS");

    if(choice=="1")
    {
        addBook(counter);
    }
    else if(choice=="2")
    {
        deleteBook(counter);
    }
    else if(choice=="3")
    {
        editBook(counter);
    }
    else if(choice=="4")
    {
        searchBook(counter);
    }
    else if(choice=="5")
    {
        viewAllBooks(counter);
    }
    else if(choice=="6")
    {
        quit();
    }
    else
    {
        main();
    }
    getch();
    return 0;
}

void addBook(int counter)
{
    // variables
    string isbn;
    string title;
    string author;
    string edition;
    string publication;

    cout << "Add Book" << endl;
    if(counter<10)
    {
        cout << "Enter ISBN: " << endl;
        getline(cin, isbn);
        cout << "Enter Title: " << endl;
        getline(cin, title);
        cout << "Enter Author: " << endl;
        getline(cin, author);
        cout << "Enter Edition: " << endl;
        getline(cin, edition);
        cout << "Enter Publication: " << endl;
        getline(cin, publication);

        books[counter].setIsbn(isbn);
        books[counter].setTitle(title);
        books[counter].setAuthor(author);
        books[counter].setEdition(edition);
        books[counter].setPublication(publication);

        increment(counter);

        cout << "Book added successfully!" << endl;
        cout << "Press any key to continue..." << endl;

        getch();
        main();
    }
    else
    {
        cout << "You have reached the maximum number of books to be added!" << endl;
        cout << "Press any key to continue..." << endl;

        getch();
        main();
    }
}

void deleteBook(int counter)
{
    string isbn;
    int choice;
    cout << "Delete Book" << endl;

    if (counter == 0)
    {
        cout << "There are no more books left to delete!" << endl;
        getch();
        main();
    }

    cout << "Enter ISBN: " << endl;
    getline(cin, isbn);

    for (int i = 0; i < counter; i++)
    {
        if (books[i].getIsbn() == isbn)
        {
            cout << "Book Found!" << endl;
            cout << "Do you want to delete this book? \n[1] Yes\n[2] No\n\n Enter Choice: ";
            cin >> choice;

            if (choice == 1)
            {
                books[i].setIsbn("");
                books[i].setTitle("");
                books[i].setAuthor("");
                books[i].setEdition("");
                books[i].setPublication("");

                for (int j = i; j < counter; j++)
                {
                    books[j] = books[j + 1];
                }

                books[9].setIsbn("");
                books[9].setTitle("");
                books[9].setAuthor("");
                books[9].setEdition("");
                books[9].setPublication("");

                decrement(counter);

                cout << "Book successfully deleted!" << endl;
                cout << "Press any key to continue..." << endl;

                getch();
                main();
            } else
            {
                main();
            }
        }
    }

    cout << "Book not found!" << endl;
    cout << "Press any key to continue..." << endl;

    getch();
    main();
}

void editBook(int counter)
{
    // variables
    system("CLS");
    string editIsbn;
    string choice;
    string isbn;
    string title;
    string author;
    string edition;
    string publication;

    cout << "Edit Book" << endl;

    if(counter==0)
    {
        cout << "There is no book to edit!" << endl;
        cout << "Press any key to continue..." << endl;

        getch();
        main();
    }

    cout << "Enter ISBN: " << endl;
    getline(cin,editIsbn);

    for(int i=0; i<counter; i++)
    {
        if(books[i].getIsbn()==editIsbn)
        {
            cout << "ISBN: " << books[i].getIsbn() << endl;
            cout << "Title: " << books[i].getTitle() << endl;
            cout << "Author: " << books[i].getAuthor() << endl;
            cout << "Edition: " << books[i].getEdition() << endl;
            cout << "Publication: " << books[i].getPublication() << endl;

            cout << "Do you want to edit this book? \n[1] Yes\n[2] No\n\n Enter Choice: ";
            getline(cin, choice);

            if(choice=="1")
            {
                cout << "Enter ISBN: " << endl;
                getline(cin, isbn);
                cout << "Enter Title: " << endl;
                getline(cin, title);
                cout << "Enter Author: " << endl;
                getline(cin, author);
                cout << "Enter Edition: " << endl;
                getline(cin, edition);
                cout << "Enter Publication: " << endl;
                getline(cin, publication);

                books[i].setIsbn(isbn);
                books[i].setTitle(title);
                books[i].setAuthor(author);
                books[i].setEdition(edition);
                books[i].setPublication(publication);

                cout << "Book edited successfully!" << endl;
                cout << "Press any key to continue..." << endl;

                getch();
                editBook(counter);
            }
            else
            {
                main();
            }
        }
    }
    cout << "Book not found!" << endl;
    cout << "Press any key to continue..." << endl;

    getch();
    main();
}

void searchBook(int counter)
{
    string isbn;
    int choice;
    bool print = false;

    cout << "Search Book" << endl;

    if(counter==0)
    {
        cout << "There is no book to search!" << endl;
        cout << "Press any key to continue..." << endl;

        getch();
        main();
    }

    for(int i=0; i<counter; i++)
    {
        if (books[i].getIsbn() == isbn)
        {
            cout << "ISBN: " << books[i].getIsbn() << endl;
            cout << "Title: " << books[i].getTitle() << endl;
            cout << "Author: " << books[i].getAuthor() << endl;
            cout << "Edition: " << books[i].getEdition() << endl;
            cout << "Publication: " << books[i].getPublication() << endl;
            print = true;
        }
    }

    if(print)
    {
        cout << "Press any key to continue..." << endl;

        getch();
        main();
    }
    else
    {
        cout << "Book not found!" << endl;
        cout << "Press any key to continue..." << endl;

        getch();
        main();
    }
}

void viewAllBooks(int counter)
{
    cout << "View All Books!" << endl;

    for(int i=0; i<counter; i++)
    {
        cout << "Book Details" << endl;
        cout << "ISBN: " << books[i].getIsbn() << endl;
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "Author: " << books[i].getAuthor() << endl;
        cout << "Edition: " << books[i].getEdition() << endl;
        cout << "Publication: " << books[i].getPublication() << endl;
    }

    cout << "Press any key to continue..." << endl;

    getch();
    main();
}

void quit()
{
    exit(1);
}