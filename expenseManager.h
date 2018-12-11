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
    float sumOfExpenses;

    void showExpense(Expense &expense);
    Expense enterExpenseOfSelectedDate(string date);
    int getIdOfLastExpense();
public:
    ExpenseManager(string NAMEOFEXPENSESFILE, int IDOFLOGGEDINUSER):
        expenseFile(NAMEOFEXPENSESFILE), idOfLoggedInUser(IDOFLOGGEDINUSER) {
        sumOfExpenses = 0.0;}
    void loadExpensesOfLoggedInUser();
    void addExpense();
    void displayExpensesOfCurrentMonth();
    void displayExpensesOfPreviousMonth();
    void displayExpensesOfSelectedPeriod(string earlierDate, string laterDate);
    float getSumOfExpenses();
};



#endif // EXPENSEMANAGER_H
