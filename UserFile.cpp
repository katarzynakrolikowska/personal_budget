#include <iostream>
#include "UserFile.h"
#include "Markup.h"
#include "HelperMethods.h"

using namespace std;

void UserFile::saveUserToFile(User user) {

    xml.Load(nameOfUsersFile.c_str());
    xml.AddElem("USER");
    xml.IntoElem();
    xml.AddElem("USERID", user.getUserID());
    xml.AddElem("LOGIN", user.getLogin());
    xml.AddElem("PASSWORD", user.getPassword());
    xml.AddElem("NAME", user.getName());
    xml.AddElem("SURNAME", user.getSurname());
    xml.OutOfElem();
    xml.Save(nameOfUsersFile.c_str());
}

vector <User> UserFile::loadUsersFromFile() {
        vector <User> users;
        User user;
        xml.Load(nameOfUsersFile.c_str());

        while(xml.FindElem("USER")) {
            xml.IntoElem();
            xml.FindElem("USERID");
            user.setUserID(HelperMethods::convertStringIntoInt(xml.GetData()));
            xml.FindElem("LOGIN");
            user.setLogin(xml.GetData());
            xml.FindElem("PASSWORD");
            user.setPassword(xml.GetData());
            xml.FindElem("NAME");
            user.setName(xml.GetData());
            xml.FindElem("SURNAME");
            user.setSurname(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
        return users;
    }
