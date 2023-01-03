#include "User.h"
#include <iostream>

int User::count=0;

User::User():name(" "), age(0){         // Initialize the name with empty word, and the age with zero in Default Constructor
      count++;
      id=count;                    // incrementing the counter with 1 and adding it to the id variable
}

 // Initialize the attributes of the object in the initialization list
User::User(string n, int a, string Em, string Pass):name(n),age(a),Email(Em),Password(Pass){
    count++;
    id=count;
}
// Copy constructor to copy the object values to another
User::User(User &user){
    age=user.age;
    Email=user.Email;
    name=user.name;
    Password=user.Password;
    id=user.id;
}
void User::setName(string n){                // It sets the Name of the user
    name=n;
}
string User::getName() const{               // It prints the Name of the user on the screen
    return name;
}
void User::setAge(int a){                    // It sets the Age of the user
    age = a;
}
int User::getAge(){                         // It prints the Age of the user on the screen
    return age;
}
void User::setEmail(string e){              // It sets the Email of the user
    Email = e;
}
string User::getEmail(){                    // It prints the Email of the user on the screen
    return Email;
}
void User::setPassword(string s){           // It sets the Password of the user
    Password = s;
}
string User::getPassword(){                 // It prints the Password of the user on the screen
    return Password;
}
void User::setId(int i){                    // It sets the ID of the user
    id = i;
}
int User::getId(){                           // It prints the ID of the user on the screen
    return id;
}

// Operator overloading for "==" to check the equality of two users
bool User::operator==(User &user){
    if(user.name==name && user.age==age && user.Password==Password && user.Email==Email)
        return true;
    else
        return false;
}
ostream &operator<<(ostream &output, User &user){      // Operator overloading for "<<" to print the whole object attributes directly
    output<<"=============================== User (Author) " <<user.getId()<<" Info ==============================="<<endl
    <<"NAME: "<<user.name<<endl<<"AGE: "<<user.age<<endl<<"EMAIL: "<<user.Email<<endl<<"PASSWORD: "<<user.Password<<endl<<"ID: "<<user.id;
    return output;
}
istream &operator>>(istream &input, User &user){
    cout << "Enter your data in the following order: \n" << "Name Age Email Password  (Space separated)" << endl;      // Operator overloading for ">>" to input the whole object attributes directly
    input>>user.name>>user.age>>user.Email>>user.Password;
    return input;
}

User::~User(){
    //dtor
}
