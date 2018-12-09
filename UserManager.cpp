#include <iostream>
#include <cstdlib>
#include "UserManager.h"
#include "HelperMethods.h"

using namespace std;

void UserManager::registerUser(){
    user = enterDataOfNewUser();
    users.push_back(user);
    userFile.saveUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
    showUsers();
}

User UserManager::enterDataOfNewUser(){
    user.setUserID(getIdOfNewUser());
    string name, surname, login, password;

    cout << "Podaj imie: ";
    name = HelperMethods::getWord();
    user.setName(HelperMethods::convertFirstCharToUppercaseLetterOthersToLowercaseLetters(name));
    cout << endl<< "Podaj nazwisko: ";
    surname = HelperMethods::getWord();
    user.setSurname(HelperMethods::convertFirstCharToUppercaseLetterOthersToLowercaseLetters(surname));

    do {
        cout << endl << "Podaj login: ";
        login = HelperMethods::getWord();
        user.setLogin(login);
    } while (ifLoginIsBookedUp(user.getLogin()) == true);

    cout << endl << "Podaj haslo: ";
    password = HelperMethods::getWord();
    user.setPassword(password);

    return user;
}

int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID() + 1;
}

bool UserManager::ifLoginIsBookedUp(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}


void UserManager::showUser(User user) {
    cout << "ID " << user.getUserID() << endl;
    cout << "nazwa " << user.getLogin() << endl;
    cout << "haslo " << user.getPassword() << endl;
    cout << "imie " << user.getName() << endl;
    cout << "nazwisko " << user.getSurname() << endl << endl;
}

void UserManager::showUsers() {
    vector <User> :: iterator itr;
    for(itr = users.begin(); itr != users.end(); itr ++) {
        showUser(*itr);
    }
}

