#include <iostream>
#include <cstdlib>
#include "UserManager.h"
#include "HelperMethods.h"

using namespace std;

void UserManager::registerUser() {
    user = enterDataOfNewUser();
    users.push_back(user);
    userFile.saveUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
    showUsers();
}

User UserManager::enterDataOfNewUser() {
    user.setUserID(getIdOfNewUser());
    string name, surname, login, password;

    cout << "Podaj imie: ";
    name = HelperMethods::getString();
    user.setName(HelperMethods::convertFirstCharToUppercaseLetterOthersToLowercaseLetters(name));
    cout << endl<< "Podaj nazwisko: ";
    surname = HelperMethods::getString();
    user.setSurname(HelperMethods::convertFirstCharToUppercaseLetterOthersToLowercaseLetters(surname));

    do {
        cout << endl << "Podaj login: ";
        login = HelperMethods::getString();
        user.setLogin(login);
    } while (ifLoginIsBookedUp(user.getLogin()) == true);

    cout << endl << "Podaj haslo: ";
    password = HelperMethods::getString();
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

void UserManager::logInUser() {
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                cin >> password;

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idOfLoggedInUser = itr -> getUserID();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}

void UserManager::logOutUser() {
    idOfLoggedInUser = 0;
}

bool UserManager::ifUserIsLoggedIn() {
    if(idOfLoggedInUser != 0)
        return 1;
    else
        return 0;
}

char UserManager::selectOptionFromUserMenu(){
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelperMethods::getCharacter();

    return choice;
}

int UserManager::getIdOfLoggedInUser(){
    return idOfLoggedInUser;
}

void UserManager::changePassword(){
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = HelperMethods::getString();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserID() == idOfLoggedInUser) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    userFile.editUserPasswordAtFile(idOfLoggedInUser, newPassword);
}
