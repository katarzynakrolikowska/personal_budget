#include <iostream>

#include "FinancesManager.h"

using namespace std;

void FinancesManager::addIncome() {
    incomeManager.addIncome();
}

void FinancesManager::addExpense() {
    expenseManager.addExpense();
}

void FinancesManager::displayBalanceOfCurrentMonth(){
    cout << endl << "Wartosc bilansu: " << incomeManager.displayIncomesOfCurrentMonth() - expenseManager.displayExpensesOfCurrentMonth() << endl;
    system("pause");
}

void FinancesManager::displayBalanceOfPreviousMonth(){
    cout << endl << "Wartosc bilansu: " << incomeManager.displayIncomesOfPreviousMonth() - expenseManager.displayExpensesOfPreviousMonth() << endl;
    system("pause");
}
