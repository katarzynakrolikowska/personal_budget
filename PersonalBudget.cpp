#include <iostream>
#include "PersonalBudget.h"
#include "HelperMethods.h"

using namespace std;

void PersonalBudget::registerUser() {
    userManager.registerUser();
}

void PersonalBudget::logInUser() {
    userManager.logInUser();
    if(userManager.isUserLoggedIn()) {
        financesManager = new FinancesManager(nameOfIncomesFile, nameOfExpensesFile, userManager.getIdOfLoggedInUser());
    }
}

void PersonalBudget::logOutUser() {
    if(userManager.isUserLoggedIn()) {
        userManager.logOutUser();
        delete financesManager;
        financesManager = NULL;
    } else
        cout << "Nie jestes zalogowany";
}

bool PersonalBudget::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

char PersonalBudget::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = HelperMethods::getCharacter();
    return choice;
}

char PersonalBudget::selectOptionFromUserMenu() {
    if(userManager.isUserLoggedIn())
        return userManager.selectOptionFromUserMenu();
    else {
        cout << "Aby wybrac opcje z menu uzytkownika zaloguj sie";
        system("pause");
    }
}

void PersonalBudget::addIncome() {
    if(userManager.isUserLoggedIn()) {
        financesManager -> addIncome();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense() {
    if(userManager.isUserLoggedIn()) {
        financesManager -> addExpense();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceOfCurrentMonth() {
    if(userManager.isUserLoggedIn()) {
        financesManager -> displayBalanceOfCurrentMonth();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceOfPreviousMonth() {
    if(userManager.isUserLoggedIn()) {
        financesManager -> displayBalanceOfPreviousMonth();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceOfSelectedPeriod() {
    if(userManager.isUserLoggedIn()) {
        financesManager -> displayBalanceOfSelectedPeriod();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::changeUserPassword(){
    if(userManager.isUserLoggedIn()) {
        userManager.changePassword();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }

}
