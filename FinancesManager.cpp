#include <iostream>
#include "FinancesManager.h"

using namespace std;

void FinancesManager::addIncome() {
    incomeManager.addIncome();
}

void FinancesManager::showIncomes() {
    incomeManager.showIncomes();
}

void FinancesManager::addExpense() {
    expenseManager.addExpense();
}

void FinancesManager::showExpenses() {
    expenseManager.showExpenses();
}
