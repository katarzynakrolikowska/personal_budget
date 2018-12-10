#include <iostream>
#include <vector>
#include "ExpenseFile.h"
#include "HelperMethods.h"
#include "DateManager.h"
#include "Expense.h"

using namespace std;

void ExpenseFile::saveExpenseToFile(Expense expense) {
    xml.Load(nameOfExpensesFile.c_str());
    xml.AddElem("EXPENSE");
    xml.IntoElem();
    xml.AddElem("EXPENSEID", expense.getExpenseID());
    xml.AddElem("USERID", expense.getUserID());
    xml.AddElem("DATE", expense.getDate());
    xml.AddElem("ITEM", expense.getItem());
    xml.AddElem("AMOUNT", HelperMethods::convertFloatIntoString(expense.getAmount()));
    xml.OutOfElem();
    xml.Save(nameOfExpensesFile.c_str());
}

vector <Expense> ExpenseFile::loadExpensesFromFile(int idOfLoggedInUser) {
    vector <Expense> expenses;
    Expense expense;
    DateManager dateManager;
    numberOfExpenses = 0;
    xml.Load(nameOfExpensesFile.c_str());

    while(xml.FindElem("EXPENSE")) {
        xml.IntoElem();

        xml.FindElem("USERID");
        if(HelperMethods::convertStringIntoInt(xml.GetData()) == idOfLoggedInUser) {
            expense.setUserID(idOfLoggedInUser);
            xml.ResetMainPos();
            xml.FindElem("EXPENSEID");
            expense.setExpenseID(HelperMethods::convertStringIntoInt(xml.GetData()));
            xml.FindElem("DATE");
            expense.setDate(xml.GetData());
            xml.FindElem("ITEM");
            expense.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            expense.setAmount(HelperMethods::convertStringIntoFloat(xml.GetData()));
            expense.setNumberOfDaysFromZeroDateToExpenseDate(dateManager.getSecondsFromZeroDateToSelectedDate(expense.getDate()));
            expenses.push_back(expense);
        }
        numberOfExpenses ++;
        xml.OutOfElem();
    }
    numberOfExpenses ++;
    return expenses;
}

int ExpenseFile::getIdOfLastExpenseAtFile() {
    xml.Load(nameOfExpensesFile.c_str());
    if(xml.FindElem("EXPENSE")) {
        return numberOfExpenses;
    } else {
        return 1;
    }
}

void ExpenseFile::increaseNumberOfExpenses(){
    numberOfExpenses ++;
}
