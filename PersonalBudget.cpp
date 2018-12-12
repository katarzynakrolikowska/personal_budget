#include <iostream>
#include "PersonalBudget.h"
#include "HelperMethods.h"

using namespace std;

void PersonalBudget::registerUser() {
    userManager.registerUser();
}

void PersonalBudget::logInUser() {
    userManager.logInUser();
    if(userManager.ifUserIsLoggedIn()) {
        financesManager = new FinancesManager(nameOfIncomesFile, nameOfExpensesFile, userManager.getIdOfLoggedInUser());
    }
}

void PersonalBudget::logOutUser() {
    if(userManager.ifUserIsLoggedIn()) {
        userManager.logOutUser();
        delete financesManager;
        financesManager = NULL;
    } else
        cout << "Nie jestes zalogowany";
}

bool PersonalBudget::ifUserIsLoggedIn() {
    return userManager.ifUserIsLoggedIn();
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
    if(userManager.ifUserIsLoggedIn())
        return userManager.selectOptionFromUserMenu();
    else {
        cout << "Aby wybrac opcje z menu uzytkownika zaloguj sie";
        system("pause");
    }
}

void PersonalBudget::addIncome() {
    if(userManager.ifUserIsLoggedIn()) {
        financesManager -> addIncome();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense() {
    if(userManager.ifUserIsLoggedIn()) {
        financesManager -> addExpense();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceOfCurrentMonth() {
    if(userManager.ifUserIsLoggedIn()) {
        financesManager -> displayBalanceOfCurrentMonth();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceOfPreviousMonth() {
    if(userManager.ifUserIsLoggedIn()) {
        financesManager -> displayBalanceOfPreviousMonth();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceOfSelectedPeriod() {
    if(userManager.ifUserIsLoggedIn()) {
        financesManager -> displayBalanceOfSelectedPeriod();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }
}

void PersonalBudget::changeUserPassword(){
    if(userManager.ifUserIsLoggedIn()) {
        userManager.changePassword();
    } else {
        cout << "Nie jestes zalogowany" << endl;
        system("pause");
    }

}
