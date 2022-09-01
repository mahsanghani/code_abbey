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

