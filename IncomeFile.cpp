#include <iostream>
#include "IncomeFile.h"
#include "Income.h"
using namespace std;

void IncomeFile::saveIncomeToFile(Income income){
    xml.Load(nameOfIncomesFile.c_str());
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem("INCOMEID", income.getIncomeID());
    xml.AddElem("USERID", income.getUserID());
    xml.AddElem("DATE", income.getDate());
    xml.AddElem("ITEM", income.getItem());
    xml.AddElem("AMOUNT", income.getAmount());
    xml.OutOfElem();
    xml.Save(nameOfIncomesFile.c_str());
}
