#include <iostream>
#include "Expense.h"

using namespace std;

int Expense::getExpenseID() {
    return expenseID;
}

int Expense::getUserID() {
    return userID;
}

string Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

float Expense::getAmount() {
    return amount;
}

int Expense::getNumberOfDaysFromZeroDateToExpenseDate(){
    return numberOfDaysFromZeroDateToExpenseDate;
}

void Expense::setExpenseID(int newID) {
    if(newID > 0)
        expenseID = newID;
}

void Expense::setUserID(int newID) {
    if(newID > 0)
        userID = newID;
}

void Expense::setDate(string newDate) {
    date = newDate;
}

void Expense::setItem(string newItem) {
    item = newItem;
}

void Expense::setAmount(float newAmount) {
    if(newAmount > 0)
        amount = newAmount;
}

void Expense::setNumberOfDaysFromZeroDateToExpenseDate(int newNumberOfDaysFromZeroDateToExpenseDate){
    numberOfDaysFromZeroDateToExpenseDate = newNumberOfDaysFromZeroDateToExpenseDate;
}

bool Expense::sortBy(const Expense& expense1, const Expense& expense2){
    if(expense1.numberOfDaysFromZeroDateToExpenseDate < expense2.numberOfDaysFromZeroDateToExpenseDate)
    return true;
    else return false;
}
