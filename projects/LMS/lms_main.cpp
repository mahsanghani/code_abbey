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
};