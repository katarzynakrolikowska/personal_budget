#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager {
    vector <User> users;
    User user;
    UserFile userFile;
    int idOfLoggedInUser;

    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool ifLoginIsBookedUp(string login);

public:
    UserManager(string USERSFILE): userFile(USERSFILE){
        users = userFile.loadUsersFromFile();
        idOfLoggedInUser = 0;
    }
    void registerUser();
    void logInUser();
    void logOutUser();
    bool isUserLoggedIn();
    char selectOptionFromUserMenu();
    int getIdOfLoggedInUser();
    void changePassword();
};





#endif
