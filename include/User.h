#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User
{
    private:
        string name;
        int id;
        int age;
        string Email;
        string Password;
    public:
        static int count;   // Static variable to get the ID
        // Constructors
        User();
        User(string n, int a, string Em, string Pass);
        User(User&);
        // Setters and Getters Functions
        void setName(string);
        string getName() const;
        void setPassword(string);
        string getPassword();
        void setEmail(string);
        string getEmail();
        void setAge(int);
        int getAge();
        void setId(int);
        int getId();
        // Operator Overloading Functions
        bool operator==(User&);
        friend ostream &operator<<(ostream &output, User&);
        friend istream &operator>>(istream &input, User&);
        //Destructor
        virtual ~User();
};

#endif // USER_H
