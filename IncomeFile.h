#ifndef INCOMEFILE_H
#define INCOMEFILe_H

#include <iostream>
#include "Markup.h"
#include "Income.h"

using namespace std;

class IncomeFile{
    CMarkup xml;
    const string nameOfIncomesFile;
public:
    IncomeFile(string NAMEOFINCOMEFILE): nameOfIncomesFile(NAMEOFINCOMEFILE){}
    void saveIncomeToFile(Income income);
};
#endif // INCOMEFILE_H
