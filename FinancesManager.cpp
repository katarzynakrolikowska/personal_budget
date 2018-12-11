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
    incomeManager.displayIncomesOfCurrentMonth();
    expenseManager.displayExpensesOfCurrentMonth();
    balance = incomeManager.getSumOfIncomes() - expenseManager.getSumOfExpenses();
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
    incomeManager.displayIncomesOfPreviousMonth();
    expenseManager.displayExpensesOfPreviousMonth();
    balance = incomeManager.getSumOfIncomes() - expenseManager.getSumOfExpenses();
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
    cout << "Podaj date poczatkowa (rrrr-mm-dd) ";
    earlierDate = HelperMethods::getDateInFormatYYYYMMDD();
    if(!dateManager.ifDateIsCorrect(earlierDate)) {
        cout << "Data niepoprawana" << endl;
        system("Pause");
        return;
    }

    cout << "Podaj date koncowa (rrrr-mm-dd) ";
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
    incomeManager.displayIncomesOfSelectedPeriod(earlierDate, laterDate);
    expenseManager.displayExpensesOfSelectedPeriod(earlierDate, laterDate);
    balance = incomeManager.getSumOfIncomes() - expenseManager.getSumOfExpenses();
    cout << endl << "W okresie od " << earlierDate << " do " << laterDate << " wygenerowano ";
    if(balance >= 0)
        cout << "oszczednosci: " << balance << endl;
    else
        cout << "dlug: " << fabs(balance) << endl;
    system("pause");
}
