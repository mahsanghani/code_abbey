//
// Created by Ahsan Ghani on 2022-09-01.
//
#include <iostream>
#include <conio.h>
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
    _getch();
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

        _getch();
        main();
    }
    else
    {
        cout << "You have reached the maximum number of books to be added!" << endl;
        cout << "Press any key to continue..." << endl;

        _getch();
        main();
    }
}