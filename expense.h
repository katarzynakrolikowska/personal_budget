#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{
    int expenseID;
    int userID;
    string date;
    string item;
    float amount;
public:
    int getExpenseID();
    int getUserID();
    string getDate();
    string getItem();
    float getAmount();
    void setExpenseID(int newID);
    void setUserID(int newID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
};

#endif // EXPENSE_H
