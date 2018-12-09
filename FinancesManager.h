#ifndef FINANCESMANAGER_H
#define FINANCESMANAGER_H

#include <iostream>
#include "IncomeManager.h"
using namespace std;

class FinancesManager{
    IncomeManager incomeManager;
public:
    FinancesManager(string NAMEOFINCOMESFILE, int IDOFLOGGEDINUSER): incomeManager(NAMEOFINCOMESFILE, IDOFLOGGEDINUSER) {}
    void addIncome();
};
#endif // FINANCESMANAGER_H
