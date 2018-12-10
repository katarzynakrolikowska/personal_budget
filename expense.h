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
    int numberOfDaysFromZeroDateToExpenseDate;
public:
    int getExpenseID();
    int getUserID();
    string getDate();
    string getItem();
    float getAmount();
    int getNumberOfDaysFromZeroDateToExpenseDate();
    void setExpenseID(int newID);
    void setUserID(int newID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    void setNumberOfDaysFromZeroDateToExpenseDate(int newNumberOfDaysFromZeroDateToExpenseDate);
    static bool sortBy(const Expense& expense1, const Expense& expense2);
};

#endif // EXPENSE_H
