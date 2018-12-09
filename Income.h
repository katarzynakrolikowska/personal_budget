#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{
    int incomeID;
    int userID;
    string date;
    string item;
    float amount;
public:
    int getIncomeID();
    int getUserID();
    string getDate();
    string getItem();
    float getAmount();
    void setIncomeID(int newID);
    void setUserID(int newID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
};

#endif // INCOME_H
