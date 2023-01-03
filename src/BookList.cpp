#include "BookList.h"
#include "User.h"
#include "BOOK.h"
#include <iostream>
using namespace std;

BookList::BookList(){
    booksCount=0;
    counterBooksList=0;
    capacity=0;
}

BookList::BookList(int cap){
    booksCount=0;
    counterBooksList=0;
    capacity = cap;
    books= new BOOK[cap];
}

BookList::BookList(const BookList &another){
    booksCount=another.booksCount;
    capacity = another.capacity;
    books = new BOOK[capacity];
    for(int i=0; i<booksCount; i++)
        books[i] = another.books[i];
}

void BookList::setCapacity(int cap){
    capacity = cap;
    books = new BOOK[capacity];
}

void BookList::addBook(BOOK &book){
    if(booksCount>=capacity){
        cout << "There's no more space for another book" << endl;
        return;
    }
    cin >> book;
    books[booksCount]= book;
    books[booksCount].setID(booksCount+1);
    booksCount++;
}

BOOK& BookList::searchBook(string name){
    for(int i=0; i<booksCount; i++){
        if(books[i].getTitle()==name)
            return books[i];
    }
    return books[0];
}

BOOK& BookList::searchBook(int id){
    for(int i=0; i<booksCount; i++){
        if(books[i].getID()==id)
            return books[i];
    }
    return books[0];
}

void BookList::deleteBook(int id){
    if(booksCount == 1){
        booksCount=0;
        return;
    }
    for(int i=0; i<booksCount; i++){
        if(books[i].getID()==id){
            for(int j=i; j<booksCount-1; j++){
                BOOK booksSwap = books[j];
                books[j] = books[j+1];
                books[j+1] = booksSwap;
            }
            booksCount--;
        }
    }
}

BOOK& BookList::getTheHighestRatedBook(){
    int max=books[0].getAvg(), j=0;
    for(int i=0; i<booksCount-1; i++){
        if(books[i].getAvg()>books[i+1].getAvg() && books[i].getAvg()>max){
            max=books[i].getAvg();
            j=i;
        }
    }
    return books[j];
}

BOOK* BookList::getBooksforUser(User user){
    for(int i=0; i<booksCount; i++){
        if(books[i].getAuthor()==user)
            counterBooksList++;
    }
    if(counterBooksList!=0){
        BOOK* userBooks = new BOOK[counterBooksList];
        for(int i=0; i<counterBooksList; i++){
            if(books[i].getAuthor()==user)
                userBooks[i] = books[i];
        }
        return userBooks;
    }
}
BOOK& BookList::operator[](int pos){
    if(pos<0 || pos>booksCount){
        cout << "\"Wrong index\" or \"There's no user with this ID or NAME\"" << endl;
    }
    else
        return books[pos];
}

ostream &operator<<(ostream &output, BookList &bookList){
    for(int i=0; i<bookList.booksCount; i++){
       output<<bookList.books[i]<<endl;
    }
    return output;
}

BookList::~BookList()
{
   delete[] books;
}
