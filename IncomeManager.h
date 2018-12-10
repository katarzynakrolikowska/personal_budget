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

    void showIncome(Income &income);
    Income enterIncomeOfSelectedDate(string date);
    int getIdOfLastIncome();

public:
    IncomeManager(string NAMEOFINCOMESFILE, int IDOFLOGGEDINUSER):
        incomeFile(NAMEOFINCOMESFILE), idOfLoggedInUser(IDOFLOGGEDINUSER) {}
    void loadIncomesOfLoggedInUser();
    void addIncome();
    void showIncomes();
    float displayIncomesOfCurrentMonth();

};



#endif // INCOMEMANAGER_H
