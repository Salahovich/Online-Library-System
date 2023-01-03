#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <User.h>
using namespace std;

class BOOK
{
    private:
        string title;
        string isbn;
        int id;
        string category;
        double averageRating;
        double rating; // Variable to hold the summation of the ratings
        User Author;
        int num_rates; // Variable to hold the number of rates (counter)
    public:
        static int count;   // Static variable to get the ID
        // Constructors
        BOOK();
        BOOK(string, string, string);
        BOOK(BOOK &book);
        // Setters and Getters
        void setTitle(string);
        string getTitle();
        void setISBN(string);
        string getISBN();
        void setID(int);
        int getID();
        void setCategory(string);
        string getCategory();
        void setAuthor(User &A);
        User getAuthor();
        // Rating Functions
        void rateBook(int);
        double getAvg();    // Function to print the average of the book on the screen
        // Operator Overloading Functions
        bool operator==(BOOK &book);
        friend ostream &operator<<(ostream &output, BOOK &book);
        friend istream &operator>>(istream &input, BOOK &book);
        // Destructor
        virtual ~BOOK();
};

#endif // BOOK_H
