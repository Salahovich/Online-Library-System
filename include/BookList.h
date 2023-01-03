#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "BOOK.h"
#include "BOOK.h"
#include <iostream>
using namespace std;

class BookList
{
    private:
        BOOK* books;
        int capacity;
        int booksCount;
    public:
        int counterBooksList;
        BookList();
        BookList(int cap);
        BookList(const BookList &anotherbooklist);
        void setCapacity(int cap);
        void addBook(BOOK &book);
        BOOK &searchBook(string name);
        BOOK &searchBook(int id);
        void deleteBook(int id);
        BOOK &getTheHighestRatedBook();
        BOOK* getBooksforUser(User);
        BOOK &operator[](int position);
        friend ostream &operator<<(ostream &output, BookList &bookList);
        virtual ~BookList();

    protected:

};

#endif // BOOKLIST_H
