#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "IncomeManager.h"
#include "HelperMethods.h"


using namespace std;

void IncomeManager::addIncome() {
    char answear = {0};
    string date = "";
    cout << "Czy chcesz dodac przychod z dzisiejsza data? (Potwierdz naciskajac klawisz 't') ";
    answear = HelperMethods::getCharacter();

    if(answear == 'T' || answear == 't') {
        date = dateManager.convertDateIntoString(dateManager.getTodayDate());
    } else {
        cout << "Podaj date w formacie rrrr-mm-dd ";
        date = HelperMethods::getDateInFormatYYYYMMDD();
        if(!dateManager.ifDateIsCorrect(date)) {
            cout << "Data niepoprawana" << endl;
            system("pause");
            return;
        }
    }
    income = enterIncomeOfSelectedDate(date);
    incomes.push_back(income);
    incomeFile.saveIncomeToFile(income);
    incomeFile.increaseNumberOfIncomes();
}

Income IncomeManager::enterIncomeOfSelectedDate(string selectedDate) {
    string item = "";
    float amount = 0.0;

    income.setIncomeID(getIdOfLastIncome());
    income.setUserID(idOfLoggedInUser);
    income.setDate(selectedDate);

    cout << "Podaj opis przychodu: ";
    item = HelperMethods::getTextLine();
    income.setItem(item);

    cout << "Podaj wartosc przychodu: ";

    amount = HelperMethods::getAmount();

    amount = round(amount * 100) / 100;
    income.setAmount(amount);
    income.setNumberOfDaysFromZeroDateToIncomeDate(dateManager.getSecondsFromZeroDateToSelectedDate(selectedDate));
    return income;
}

int IncomeManager::getIdOfLastIncome() {
    return incomeFile.getIdOfLastIncomeAtFile();
}

void IncomeManager::showIncome(Income &income) {
    cout.precision(2);
    cout << fixed;
    cout << endl << "ID przychodu:      " << income.getIncomeID() << endl;
    cout << "Data:              " << income.getDate() << endl;
    cout << "Opis:              " << income.getItem() << endl;
    cout << "Wartosc:           " << income.getAmount() << endl;
}

void IncomeManager::loadIncomesOfLoggedInUser() {
    incomes = incomeFile.loadIncomesFromFile(idOfLoggedInUser);
}

float IncomeManager::displayIncomesOfCurrentMonth() {
    float sumOfIncomes = 0.0;
    sort(incomes.begin(), incomes.end(), Income::sortBy);
    vector <Income> ::iterator itr = incomes.begin();
    cout << "PRZYCHODY" << endl;
    for(itr; itr != incomes.end(); itr ++) {
        if(dateManager.ifDateIsFromCurrentMonth(itr -> getDate())) {
            sumOfIncomes += itr -> getAmount();
            showIncome(*itr);
        }
    }
    cout << "Suma przychodow z biezacego miesiaca: " << sumOfIncomes << endl;
    return sumOfIncomes;

}

float IncomeManager::displayIncomesOfPreviousMonth() {
    float sumOfIncomes = 0.0;
    sort(incomes.begin(), incomes.end(), Income::sortBy);
    vector <Income> ::iterator itr = incomes.begin();
    cout << "PRZYCHODY" << endl;
    for(itr; itr != incomes.end(); itr ++) {
        if(dateManager.ifDateIsFromPreviousMonth(itr -> getDate())) {
            sumOfIncomes += itr -> getAmount();
            showIncome(*itr);
        }
    }
    cout << "Suma przychodow z poprzedniego miesiaca: " << sumOfIncomes << endl;
    return sumOfIncomes;

}

float IncomeManager::displayIncomesOfSelectedPeriod(string earlierDate, string laterDate) {
    float sumOfIncomes = 0.0;
    sort(incomes.begin(), incomes.end(), Income::sortBy);
    vector <Income> ::iterator itr = incomes.begin();
    cout << "PRZYCHODY" << endl;
    for(itr; itr != incomes.end(); itr ++) {
        if(dateManager.ifDateIsFromSelectedPeriod(earlierDate, laterDate, itr -> getNumberOfDaysFromZeroDateToIncomeDate())) {
            sumOfIncomes += itr -> getAmount();
            showIncome(*itr);
        }
    }
    cout << "Suma przychodow z wybranego okresu: " << sumOfIncomes << endl;
    return sumOfIncomes;

}
