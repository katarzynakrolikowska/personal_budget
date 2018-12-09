#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "IncomeManager.h"
#include "HelperMethods.h"


using namespace std;

void IncomeManager::addIncome(){
    char answear = {0};
    string date = "";
    cout << "Czy chcesz dodac przychod z dzisiejsza data? (Potwierdz naciskajac klawisz 't') ";
    answear = HelperMethods::getCharacter();

    if(answear == 'T' || answear == 't'){
        date = dateManager.convertDateIntoString(dateManager.getTodayDate());
    }else{
        cout << "Podaj date w formacie rrrr-mm-dd ";
        date = HelperMethods::getString();
    }

    if(dateManager.ifDateIsCorrect(date)){
    income = enterIncomeOfSelectedDate(date);
    incomes.push_back(income);
    }else{
        cout << "Data niepoprawana" << endl;
    }

}

Income IncomeManager::enterIncomeOfSelectedDate(string selectedDate){
    string item = "";
    float amount = 0.0;

    income.setIncomeID(getIdOfLastIncome());
    income.setUserID(idOfLoggedInUser);
    income.setDate(selectedDate);

    cout << "Podaj opis przychodu: ";
    item = HelperMethods::getTextLine();
    income.setItem(item);

    cout << "Podaj wartosc przychodu: ";

    amount = HelperMethods::getFloat();
    if(HelperMethods::ifAmountIsCorrect(amount)){
        amount = round(amount * 100) / 100;
        income.setAmount(amount);
    }else{
        cout << "Kwota niepoprawna";
        system("pause");
    }
    return income;
}

int IncomeManager::getIdOfLastIncome(){
    if(incomes.empty())
        return 1;
    else return incomes.size() + 1;
}


