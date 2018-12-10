#include <iostream>
#include <vector>
#include "IncomeFile.h"
#include "DateManager.h"
#include "HelperMethods.h"
#include "Income.h"
using namespace std;

void IncomeFile::saveIncomeToFile(Income income) {
    xml.Load(nameOfIncomesFile.c_str());
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem("INCOMEID", income.getIncomeID());
    xml.AddElem("USERID", income.getUserID());
    xml.AddElem("DATE", income.getDate());
    xml.AddElem("ITEM", income.getItem());
    xml.AddElem("AMOUNT", HelperMethods::convertFloatIntoString(income.getAmount()));
    xml.OutOfElem();
    xml.Save(nameOfIncomesFile.c_str());
}

vector <Income> IncomeFile::loadIncomesFromFile(int idOfLoggedInUser) {
    vector <Income> incomes;
    Income income;
    DateManager dateManager;
    numberOfIncomes = 0;
    xml.Load(nameOfIncomesFile.c_str());

    while(xml.FindElem("INCOME")) {
        xml.IntoElem();

        xml.FindElem("USERID");
        if(HelperMethods::convertStringIntoInt(xml.GetData()) == idOfLoggedInUser) {
            income.setUserID(idOfLoggedInUser);
            xml.ResetMainPos();
            xml.FindElem("INCOMEID");
            income.setIncomeID(HelperMethods::convertStringIntoInt(xml.GetData()));
            xml.FindElem("DATE");
            income.setDate(xml.GetData());
            xml.FindElem("ITEM");
            income.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            income.setAmount(HelperMethods::convertStringIntoFloat(xml.GetData()));
            income.setNumberOfDaysFromZeroDateToIncomeDate(dateManager.getSecondsFromZeroDateToSelectedDate(income.getDate()));
            incomes.push_back(income);
        }
        numberOfIncomes++;
        xml.OutOfElem();
    }
    numberOfIncomes ++;
    return incomes;
}

int IncomeFile::getIdOfLastIncomeAtFile() {
    xml.Load(nameOfIncomesFile.c_str());
    if(xml.FindElem("INCOME")) {
        return numberOfIncomes;
    } else {
        return 1;
    }
}

void IncomeFile::increaseNumberOfIncomes(){
    numberOfIncomes ++;
}
