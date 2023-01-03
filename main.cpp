// Project = Online Library System
// Author = Eng. Mohamed Salah Abdallah (Solo)
// ID = 20190448
// Instructor = Dr. Cherry Adel
#include <iostream>
#include <BOOK.h>
#include <User.h>
#include "BookList.h"
#include "UserList.h"
using namespace std;

void mainMenu()
{
    cout << "/////////////////////////////////MAIN MENU\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "1- Books Menu" << endl;
    cout << "2- Users Menu" << endl;
    cout << "3- Exit" << endl;
}
void bookMenu()
{
    cout << "\n/////////////////////////////////BOOK MENU\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "1- Create a book and add it to the list" << endl;
    cout << "2- Search for a book" << endl;
    cout << "3- Display all books (with rating)" << endl;
    cout << "4- Get the highest rated book" << endl;
    cout << "5- Get all book for a user" << endl;
    cout << "6- Copy the current Book List to a new Book List and switch to it" << endl;
    cout << "7- Back to the main menu" << endl;
}
void userMenu()
{
    cout << "\n/////////////////////////////////USER MENU\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "1- Create a user and add it to the list" << endl;
    cout << "2- Search for a user" << endl;
    cout << "3- Display all users" << endl;
    cout << "4- Back to the main menu" << endl;
}
void bookSpecsMenu()
{
    cout << "1- Update Author" << endl;
    cout << "2- Update Name" << endl;
    cout << "3- Update Category" << endl;
    cout << "4- Delete Book" << endl;
    cout << "5- Rate Book" << endl;
    cout << "6- Back to Search Menu" << endl;
}
void UserSearchMenu()
{
    cout << "\n/////////////////////////////////SEARCH FOR A USER\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "1- Search User by name" << endl;
    cout << "2- Search User by ID" << endl;
    cout << "3- Back to User Menu" << endl;
}
void BookSearchMenu()
{
    cout << "\n/////////////////////////////////SEARCH FOR A BOOK\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "1- Search Book by Name" << endl;
    cout << "2- Search Book by ID" << endl;
    cout << "3- Back to Book Menu" << endl;
}
int main()
{

    int numUsers=0, numBooks=0, Usercounter=0, booksCounter=-1;
    UserList myUsersList;
    BookList myBookList;
    BOOK book;
    User user;
    char userChoice;
    while(true)
    {
        mainMenu();
        cin >> userChoice;

        // User Menu
        if(userChoice == '2')
        {
            cout << "How many users will be added?";
            cin  >> numUsers;
            myUsersList.setCapacity(numUsers);
            while(true)
            {
                userMenu();
                cin  >> userChoice;
                if(Usercounter<=0 && userChoice!='1' && userChoice!='4')
                {
                    cout << "There's no users in library, please add users!!" << endl;
                    continue;
                }
                if(userChoice == '1')
                {
                    myUsersList.addUser(user);
                    Usercounter++;
                }
                else if(userChoice == '2')
                {
                    while(true)
                    {
                        UserSearchMenu();
                        if(Usercounter<=0)
                            break;
                        cin >> userChoice;
                        if(userChoice == '1' || userChoice == '2')
                        {
                            User user;
                            bool userExist=false;
                            if(userChoice == '1')
                            {
                                string name;
                                cout << "Enter name: ";
                                cin >> name;
                                user = myUsersList.searchUser(name);

                                if(user.getName() == name)
                                {
                                    cout << user << endl;
                                    userExist = true;
                                }
                                else
                                    cout << "There's no USER with  NAME=" << name << endl;
                            }
                            else
                            {
                                int id;
                                cout << "Enter ID: ";
                                cin >> id;
                                user = myUsersList.searchUser(id);

                                if(user.getId() == id)
                                {
                                    userExist=true;
                                    cout << user << endl;
                                }
                                else
                                    cout << "There's no USER with ID=" << id << endl;

                            }
                            if(userExist)
                            {
                                cout << "\n1- Delete user" << endl;
                                cout << "2- Return to Users Menu" << endl;
                                cin >> userChoice;
                                if(userChoice == '1')
                                {
                                    myUsersList.deleteUser(user.getId());
                                    Usercounter--;
                                }
                                else if(userChoice == '2')
                                    break;
                                else
                                    cout << "Wrong Input" << endl;
                            }
                        }
                        else if(userChoice == '3')
                            break;
                        else
                            cout << "Wrong Input" << endl;
                    }
                }
                else if(userChoice == '3')
                {
                    cout << myUsersList << endl;
                }
                else if(userChoice == '4')
                    break;
                else
                    cout << "Wrong input" << endl;
            }
        }

        // Book Menu
        else if(userChoice == '1')
        {
            cout << "How many books will be added?";
            cin  >> numBooks;
            myBookList.setCapacity(numBooks);

            while(true)
            {
                bookMenu();
                cin >> userChoice;
                if(booksCounter<0 && userChoice!='1' && userChoice != '7')
                {
                    cout << "There's no books in the library, please add new books!!" << endl;
                    continue;
                }
                if(userChoice == '1')
                {
                    booksCounter++;
                    myBookList.addBook(book);
                    while(true)
                    {
                        cout << "1- Assign Author" << endl;
                        cout << "2- Continue" << endl;
                        cin >> userChoice;
                        if(userChoice == '1' && Usercounter>0)
                        {
                            cout << "Enter Author (user) id: " << endl;
                            int iD;
                            cin >> iD;

                            if(myUsersList.searchUser(iD).getId()==iD)
                            {
                                myBookList[booksCounter].setAuthor(myUsersList.searchUser(iD));
                                break;
                            }
                            else
                                cout << "Wrong ID" << endl;
                        }
                        else if(userChoice == '2')
                            break;
                        else
                        {
                            cout << "There's no users at all" << endl;
                            break;
                        }
                    }
                }
                else if(userChoice == '2')
                {
                    string name=" ";
                    int id;
                    while(true)
                    {
                        BookSearchMenu();
                        if(booksCounter<0)
                            break;
                        cin >> userChoice;
                        if(userChoice == '1'|| userChoice == '2')
                        {
                            bool entry=false;
                            if(userChoice == '1')
                            {
                                cout << "Enter name: " << endl;
                                cin >> name;
                                if(myBookList.searchBook(name).getTitle() == name)
                                    cout << myBookList.searchBook(name) << endl;
                                else
                                {
                                    cout << "There is no BOOK with NAME = " << name << endl;
                                    continue;
                                }
                            }
                            else
                            {
                                entry = true;
                                cout << "Enter ID: " << endl;
                                cin >> id;
                                if(myBookList.searchBook(id).getID() == id)
                                    cout << myBookList.searchBook(id) << endl;
                                else
                                {
                                    cout << "There is no BOOK with ID = " << id << endl;
                                    continue;
                                }
                            }
                            while(true)
                            {
                                bookSpecsMenu();
                                cin >> userChoice;
                                if(userChoice == '1')
                                {
                                    cout << "Enter user's ID" << endl;
                                    int ideee;
                                    cin >> ideee;
                                    if(myUsersList.searchUser(ideee).getId() == ideee)
                                    {
                                        if(entry)
                                            myBookList.searchBook(id).setAuthor(myUsersList.searchUser(ideee));
                                        else
                                            myBookList.searchBook(name).setAuthor(myUsersList.searchUser(ideee));
                                    }
                                    else
                                        cout << "There's no user with ID " << ideee << endl;
                                }
                                else if(userChoice == '2')
                                {
                                    cout << "Enter new Name" << endl;
                                    string n;
                                    cin >> n;
                                    if(entry)
                                        myBookList.searchBook(id).setTitle(n);
                                    else
                                        myBookList.searchBook(name).setTitle(n);
                                }
                                else if(userChoice == '3')
                                {
                                    cout << "Enter new Category" << endl;
                                    string c;
                                    cin >> c;
                                    if(entry)
                                        myBookList.searchBook(id).setCategory(c);
                                    else
                                        myBookList.searchBook(name).setCategory(c);
                                }
                                else if(userChoice == '4')
                                {
                                    if(entry)
                                        myBookList.deleteBook(id);
                                    else
                                        myBookList.deleteBook(myBookList.searchBook(name).getID());
                                    booksCounter--;
                                    break;
                                }
                                else if(userChoice == '5')
                                {
                                    cout << "Enter Rating Value: ";
                                    int r;
                                    cin >> r;
                                    if(entry)
                                        myBookList.searchBook(id).rateBook(r);
                                    else
                                        myBookList.searchBook(name).rateBook(r);
                                }
                                else if(userChoice == '6')
                                    break;
                                else
                                    cout << "Wrong Input" << endl;
                            }
                        }
                        else if(userChoice == '3')
                            break;
                        else
                            cout << "Wrong input" << endl;
                    }

                }
                else if(userChoice == '3')
                {
                    cout << myBookList << endl;
                }
                else if(userChoice == '4')
                {
                    cout << myBookList.getTheHighestRatedBook() << endl;
                }
                else if(userChoice == '5')
                {

                    cout << "Enter User's ID: ";
                    int userid;
                    cin >> userid;
                    BOOK* tempBook = new BOOK[myBookList.counterBooksList];
                    tempBook = myBookList.getBooksforUser(myUsersList.searchUser(userid));
                    if(myUsersList.searchUser(userid).getId() == userid)
                    {
                        for(int i=0; i<myBookList.counterBooksList; i++)
                            cout << tempBook[i] << endl;
                    }
                    else
                        cout << "There's no books for user " << userid <<"or There;s no users at all"<<endl;
                    delete[] tempBook;
                }
                else if(userChoice == '6')
                {
                    BookList myNewBookList;
                    myNewBookList = myBookList;
                    cout << "Copied current list (" << booksCounter << " books) to a new list and switched to it" << endl;
                }
                else if(userChoice == '7')
                    break;
                else
                    cout << "Wrong input" << endl;
            }

        }

        // Exit
        else if(userChoice == '3')
            break;

        // Wrong input
        else
            cout << "Wrong input" << endl;
    }

    return 0;
}

