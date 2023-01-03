#ifndef USERLIST_H
#define USERLIST_H
#include "User.h"


class UserList : public User
{
    private:
        User* users;
        int capacity;
        int usersCount;

    public:
        UserList();
        UserList(int Capacity);
        void addUser(User& user);
        User &searchUser(string name);
        User &searchUser(int id);
        void deleteUser(int id);
        void setCapacity(int cap);
        friend ostream &operator<<(ostream &output, UserList &userlist);
        virtual ~UserList();

    protected:

};

#endif // USERLIST_H
