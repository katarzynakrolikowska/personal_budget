#ifndef FINANCESMANAGER_H
#define FINANCESMANAGER_H

#include <iostream>
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "DateManager.h"
using namespace std;

class FinancesManager{
    IncomeManager incomeManager;
    ExpenseManager expenseManager;
    DateManager dateManager;
public:
    FinancesManager(string NAMEOFINCOMESFILE, string NAMEOFEXPENSESFILE, int IDOFLOGGEDINUSER):
         incomeManager(NAMEOFINCOMESFILE, IDOFLOGGEDINUSER), expenseManager(NAMEOFEXPENSESFILE, IDOFLOGGEDINUSER){
    incomeManager.loadIncomesOfLoggedInUser();
    expenseManager.loadExpensesOfLoggedInUser();
    }
    void addIncome();
    void addExpense();
    void displayBalanceOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    void displayBalanceOfSelectedPeriod();

};
#endif // FINANCESMANAGER_H
