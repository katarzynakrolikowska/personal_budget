#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "DateManager.h"

using namespace std;

class Income{
    int incomeID;
    int userID;
    string date;
    string item;
    float amount;
    int numberOfDaysFromZeroDateToIncomeDate;
public:
    int getIncomeID();
    int getUserID();
    string getDate();
    string getItem();
    float getAmount();
    int getNumberOfDaysFromZeroDateToIncomeDate();
    void setIncomeID(int newID);
    void setUserID(int newID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    void setNumberOfDaysFromZeroDateToIncomeDate(int newNumberOfDaysFromZeroDateToIncomeDate);
    static bool sortBy(const Income& income1, const Income& income2);
};

#endif // INCOME_H
