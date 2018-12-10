#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "ExpenseManager.h"
#include "HelperMethods.h"


using namespace std;

void ExpenseManager::addExpense() {
    char answear = {0};
    string date = "";
    cout << "Czy chcesz dodac wydatek z dzisiejsza data? (Potwierdz naciskajac klawisz 't') ";
    answear = HelperMethods::getCharacter();

    if(answear == 'T' || answear == 't') {
        date = dateManager.convertDateIntoString(dateManager.getTodayDate());
    } else {
        cout << "Podaj date w formacie rrrr-mm-dd ";
        date = HelperMethods::getString();
        if(!dateManager.ifDateIsCorrect(date)) {
            cout << "Data niepoprawana" << endl;
            system("pause");
            return;
        }
    }
    expense = enterExpenseOfSelectedDate(date);
    expenses.push_back(expense);
    expenseFile.saveExpenseToFile(expense);
    expenseFile.increaseNumberOfExpenses();
}

Expense ExpenseManager::enterExpenseOfSelectedDate(string selectedDate) {
    string item = "";
    float amount = 0.0;

    expense.setExpenseID(getIdOfLastExpense());
    expense.setUserID(idOfLoggedInUser);
    expense.setDate(selectedDate);

    cout << "Podaj opis wydatku: ";
    item = HelperMethods::getTextLine();
    expense.setItem(item);

    cout << "Podaj wartosc wydatku: ";

    amount = HelperMethods::getFloat();
    if(HelperMethods::ifAmountIsCorrect(amount)) {
        amount = round(amount * 100) / 100;
        expense.setAmount(amount);
    } else {
        cout << "Kwota niepoprawna";
        system("pause");
    }
    expense.setNumberOfDaysFromZeroDateToExpenseDate(dateManager.getSecondsFromZeroDateToSelectedDate(selectedDate));
    return expense;
}

int ExpenseManager::getIdOfLastExpense() {
    return expenseFile.getIdOfLastExpenseAtFile();
}

void ExpenseManager::showExpense(Expense &expense) {
    cout << endl << "ID wydatku " << expense.getExpenseID() << endl;
    cout << "ID uzytkownika " << expense.getUserID() << endl;
    cout << "Data " << expense.getDate() << endl;
    cout << "Opis " << expense.getItem() << endl;
    cout << "Wartosc " << expense.getAmount() << endl;
}

void ExpenseManager::showExpenses() {
    vector <Expense> ::iterator itr = expenses.begin();
    for(itr; itr != expenses.end(); itr ++) {
        showExpense(*itr);
    }
    system("pause");
}

void ExpenseManager::loadExpensesOfLoggedInUser() {
    expenses = expenseFile.loadExpensesFromFile(idOfLoggedInUser);
}

float ExpenseManager::displayExpensesOfCurrentMonth(){
    float sumOfExpenses = 0.0;
    sort(expenses.begin(), expenses.end(), Expense::sortBy);
    vector <Expense> ::iterator itr = expenses.begin();
    for(itr; itr != expenses.end(); itr ++) {
        if(dateManager.ifDateIsFromCurrentMonth(itr -> getDate())){
            sumOfExpenses += itr -> getAmount();
            showExpense(*itr);
        }
    }
    cout << "Suma wydatkow z biezacego miesiaca: " << sumOfExpenses << endl;
    return sumOfExpenses;
}
