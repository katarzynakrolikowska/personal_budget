#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include "User.h"
#include"Markup.h"

using namespace std;

class UserFile {
    const string nameOfUsersFile;
    CMarkup xml;
public:
    UserFile(string USERSFILE) : nameOfUsersFile(USERSFILE) {}
    void saveUserToFile(User user);
    vector <User> loadUsersFromFile();
    void editUserPasswordAtFile(int idOfLoggedInUser, string newPassword);
};










#endif
