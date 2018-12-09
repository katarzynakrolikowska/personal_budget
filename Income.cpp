#include <iostream>
#include "Income.h"

using namespace std;

int Income::getIncomeID() {
    return incomeID;
}

int Income::getUserID() {
    return userID;
}

string Income::getDate() {
    return date;
}

string Income::getItem() {
    return item;
}

float Income::getAmount() {
    return amount;
}

void Income::setIncomeID(int newID) {
    if(newID > 0)
        incomeID = newID;
}

void Income::setUserID(int newID) {
    if(newID > 0)
        userID = newID;
}

void Income::setDate(string newDate) {
    date = newDate;
}

void Income::setItem(string newItem) {
    item = newItem;
}

void Income::setAmount(float newAmount) {
    if(newAmount > 0)
        amount = newAmount;
}
