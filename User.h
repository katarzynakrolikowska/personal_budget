#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;


class User {
    int userID;
    string login;
    string password;
    string name;
    string surname;
public:
    User() {
        userID = 0;
        login = "";
        password = "";
        name = "";
        surname = "";
    }

    void setUserID(int newID);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);
    int getUserID();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();

};





#endif
