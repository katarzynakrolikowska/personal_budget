#include <iostream>
#include <cmath>
#include "FinancesManager.h"
#include "HelperMethods.h"

using namespace std;

void FinancesManager::addIncome() {
    incomeManager.addIncome();
}

void FinancesManager::addExpense() {
    expenseManager.addExpense();
}

void FinancesManager::displayBalanceOfCurrentMonth() {
    system("cls");
    float balance = 0.0;
    balance = incomeManager.displayIncomesOfCurrentMonth() - expenseManager.displayExpensesOfCurrentMonth();
    cout << endl << "W biezacym miesiacu wygenerowano ";
    if(balance >= 0)
        cout << "oszczednosci: " << balance << endl;
    else
        cout << "dlug: " << fabs(balance) << endl;
    system("pause");
}

void FinancesManager::displayBalanceOfPreviousMonth() {
    system("cls");
    float balance = 0.0;
    balance = incomeManager.displayIncomesOfPreviousMonth() - expenseManager.displayExpensesOfPreviousMonth();
    cout << endl << "W poprzednim miesiacu wygenerowano ";
    if(balance >= 0)
        cout << "oszczednosci: " << balance << endl;
    else
        cout << "dlug: " << fabs(balance) << endl;
    system("pause");
}

void FinancesManager::displayBalanceOfSelectedPeriod() {
    string earlierDate = "", laterDate = "";
    float balance = 0.0;
    cout << "Podaj date poczatkowa (rrrr-mm-yy) ";
    earlierDate = HelperMethods::getDateInFormatYYYYMMDD();
    if(!dateManager.ifDateIsCorrect(earlierDate)) {
        cout << "Data niepoprawana" << endl;
        system("Pause");
        return;
    }

    cout << "Podaj date koncowa (rrrr-mm-yy) ";
    laterDate = HelperMethods::getDateInFormatYYYYMMDD();
    if(!dateManager.ifDateIsCorrect(laterDate)) {
        cout << "Data niepoprawana" << endl;
        system("Pause");
        return;
    }

    if(dateManager.getEarlierDate(earlierDate, laterDate) == laterDate) {
        cout << "Daty nie sa podane w porzadku chronologicznym" << endl;
        system("Pause");
        return;
    }
    system("cls");
    balance = incomeManager.displayIncomesOfSelectedPeriod(earlierDate, laterDate) - expenseManager.displayExpensesOfSelectedPeriod(earlierDate, laterDate);
    cout << endl << "W okresie od " << earlierDate << " do " << laterDate << " wygenerowano ";
    if(balance >= 0)
        cout << "oszczednosci: " << balance << endl;
    else
        cout << "dlug: " << fabs(balance) << endl;
    system("pause");
}
