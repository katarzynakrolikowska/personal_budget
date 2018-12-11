#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "IncomeFile.h"
#include "DateManager.h"

using namespace std;

class IncomeManager{
    Income income;
    IncomeFile incomeFile;
    DateManager dateManager;
    const int idOfLoggedInUser;
    vector <Income> incomes;
    float sumOfIncomes;

    void showIncome(Income &income);
    Income enterIncomeOfSelectedDate(string date);
    int getIdOfLastIncome();

public:
    IncomeManager(string NAMEOFINCOMESFILE, int IDOFLOGGEDINUSER):
        incomeFile(NAMEOFINCOMESFILE), idOfLoggedInUser(IDOFLOGGEDINUSER) {
        sumOfIncomes = 0.0;}
    void loadIncomesOfLoggedInUser();
    void addIncome();
    void displayIncomesOfCurrentMonth();
    void displayIncomesOfPreviousMonth();
    void displayIncomesOfSelectedPeriod(string earlierDate, string laterDate);
    float getSumOfIncomes();

};



#endif // INCOMEMANAGER_H
