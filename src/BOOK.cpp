#include "BOOK.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

int BOOK::count=0;

// initialize the 3 variables in default constructor
BOOK::BOOK():rating(0), num_rates(0), averageRating(0) {
    count++;
    id=count;
}

// initialize the 3 variables in parameterized constructor
BOOK::BOOK(string t, string i, string c):rating(0), num_rates(0), averageRating(0) {
    title=t;
    isbn=i;
    category=c;
    count++;
    id=count;
}

// initialize the 3 variables in copy constructor
BOOK::BOOK(BOOK &book){
    averageRating = book.averageRating;
    num_rates=book.num_rates;
    rating = book.rating;
    title=book.title;
    isbn=book.isbn;
    category=book.category;
    Author=book.Author;
    id=book.id;
}
void BOOK::setTitle(string t){                  // It sets the Title of the book
    title=t;
}
string BOOK::getTitle(){                        // Printing the Title of the book on the screen
    return title;
}
void BOOK::setISBN(string is){                  // It sets the ISBN of the book
    isbn=is;
}
string BOOK::getISBN(){                         // Printing the ISBN of the book on the screen
    return isbn;
}
void BOOK::setCategory(string c){               // It sets the Category of the book
    category=c;
}
string BOOK::getCategory(){                     // Printing the Category of the book on the screen
    return category;
}

void BOOK::setID(int i){
    id=i;
}
int BOOK::getID(){                                  // Printing the ID of the book on the screen
    return id;
}

void BOOK::setAuthor(User &A){                      // It sets the Author of the book
    Author=A;
}
User BOOK::getAuthor(){                             // It prints the Author of the book in the screen
    return Author;
}
void BOOK::rateBook(int r){
     num_rates++;                                     // increment the counter of rates;
     rating += r;                                    // adding the new rating over the previous
     averageRating = rating/num_rates;              // getting the AVG
}
double BOOK::getAvg(){                              // Function to print the Average rating on the screen
    return averageRating;
}
bool BOOK::operator==(BOOK &book){                  // Operator overloading for "==" to check the equality of two books
    if(book.title==title && book.isbn==isbn && book.category==category && book.id==id && book.Author==Author)
        return true;
    else
        return false;
}
ostream &operator<<(ostream &output, BOOK &book){    // Operator overloading for "<<" to print the whole object attributes directly
    output<<"=============================== Book " <<book.getID()<<" Info ==============================="<<endl
    <<"TITLE: "<<book.title<<endl<<"ISBN: "<<book.isbn<<endl<<"CATEGORY: "<<book.category<<endl<<"ID: "<<book.id
    <<endl<<"AVG. RATE: "<<book.averageRating<<endl;

    if(book.Author.getName()!=" ")
        output<<book.Author;

    return output;
}
istream &operator>>(istream &input, BOOK &book){     // Operator overloading for ">>" to input the whole object attributes directly
    cout << "Please, Enter your data in the following order: \n" << "Title ISBN Category  ((Space separated)" << endl;
    input>>book.title>>book.isbn>>book.category;
    return input;
}
BOOK::~BOOK()
{
    //dtor
}
