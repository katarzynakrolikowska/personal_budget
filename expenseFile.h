#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include "Markup.h"
#include "Expense.h"

using namespace std;

class ExpenseFile{
    CMarkup xml;
    const string nameOfExpensesFile;
    int numberOfExpenses;
public:
    ExpenseFile(string NAMEOFEXPENSEFILE): nameOfExpensesFile(NAMEOFEXPENSEFILE){
    numberOfExpenses = 0;}
    void saveExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int idOfLoggedInUser);
    int getIdOfLastExpenseAtFile();
    void increaseNumberOfExpenses();
};
#endif // EXPENSEFILE_H
