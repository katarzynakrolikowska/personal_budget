#include <iostream>

#include "FinancesManager.h"

using namespace std;

void FinancesManager::addIncome() {
    incomeManager.addIncome();
}

void FinancesManager::addExpense() {
    expenseManager.addExpense();
}

void FinancesManager::showExpenses() {
    expenseManager.showExpenses();
}

void FinancesManager::displayBalanceOfCurrentMonth(){
    cout << endl << "Wartosc bilansu: " << incomeManager.displayIncomesOfCurrentMonth() - expenseManager.displayExpensesOfCurrentMonth() << endl;
    system("pause");
}
