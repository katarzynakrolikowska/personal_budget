#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "ExpenseFile.h"
#include "DateManager.h"

using namespace std;

class ExpenseManager{
    Expense expense;
    ExpenseFile expenseFile;
    DateManager dateManager;
    const int idOfLoggedInUser;
    vector <Expense> expenses;

    void showExpense(Expense &expense);
    Expense enterExpenseOfSelectedDate(string date);
    int getIdOfLastExpense();
public:
    ExpenseManager(string NAMEOFEXPENSESFILE, int IDOFLOGGEDINUSER):
        expenseFile(NAMEOFEXPENSESFILE), idOfLoggedInUser(IDOFLOGGEDINUSER) {}
    void loadExpensesOfLoggedInUser();
    void addExpense();
    float displayExpensesOfCurrentMonth();
    float displayExpensesOfPreviousMonth();
    float displayExpensesOfSelectedPeriod(string earlierDate, string laterDate);
};



#endif // EXPENSEMANAGER_H
