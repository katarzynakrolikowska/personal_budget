#ifndef PERSONALBUDGET_H
#define PERSONALBUDGE_H

#include <iostream>
#include "UserManager.h"
#include "FinancesManager.h"
using namespace std;


class PersonalBudget{
    UserManager userManager;
    FinancesManager *financesManager;
    const string nameOfIncomesFile;
    const string nameOfExpensesFile;
public:
    PersonalBudget(string NAMEOFUSERSFILE, string NAMEOFINCOMESFILE, string NAMEOFEXPENSESFILE):
        userManager(NAMEOFUSERSFILE), nameOfIncomesFile(NAMEOFINCOMESFILE), nameOfExpensesFile(NAMEOFEXPENSESFILE){}
    ~PersonalBudget(){
        delete financesManager;
    }
    void registerUser();
    void logInUser();
    void logOutUser();
    bool ifUserIsLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void addIncome();
    void addExpense();
    void displayBalanceOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    void displayBalanceOfSelectedPeriod();
    void changeUserPassword();
};


#endif // PERSONALBUDGET_H


