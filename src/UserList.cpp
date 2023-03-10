#include "UserList.h"
#include "User.h"
#include <iostream>
using namespace std;

UserList::UserList()
{
    usersCount=0;
    capacity=0;
}

UserList::UserList(int cap){
    usersCount=0;
    capacity = cap;
    users = new User[capacity];
}

void UserList::addUser(User& user){
    if(usersCount>=capacity){
        cout << "There's no more space for another user" << endl;
        return;
    }
    cin >> user;
    users[usersCount]=user;
    users[usersCount].setId(usersCount+1);
    usersCount++;
}
void UserList::setCapacity(int cap){
        capacity = cap;
        users = new User[capacity];
}

User& UserList::searchUser(string name){
    for(int i=0; i<usersCount; i++){
        if(users[i].getName() == name)
            return users[i];
    }
    return users[0];
}

User& UserList::searchUser(int id){
    for(int i=0; i<usersCount; i++){
        if(users[i].getId()==id)
            return users[i];
    }
    return users[0];
}

void UserList::deleteUser(int id){
    for(int i=0; i<usersCount; i++){
        if(users[i].getId()==id){
            for(int j=i; j<usersCount-1; j++){
                User userSwap = users[j];
                users[j] = users[j+1];
                users[j+1] = userSwap;
            }
            usersCount--;
        }
    }
}
ostream &operator<<(ostream &output, UserList &userlist){
    for(int i=0; i<userlist.usersCount; i++){
        output<<userlist.users[i]<<endl;
    }
    return output;
}

UserList::~UserList()
{
    delete[] users;
}
