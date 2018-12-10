#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include "Markup.h"
#include "Income.h"

using namespace std;

class IncomeFile{
    CMarkup xml;
    const string nameOfIncomesFile;
    int numberOfIncomes;
public:
    IncomeFile(string NAMEOFINCOMEFILE): nameOfIncomesFile(NAMEOFINCOMEFILE){
    numberOfIncomes = 0;}
    void saveIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int idOfLoggedInUser);
    int getIdOfLastIncomeAtFile();
    void increaseNumberOfIncomes();
};
#endif // INCOMEFILE_H
