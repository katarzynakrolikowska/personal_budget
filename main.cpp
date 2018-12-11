#include <iostream>
#include "PersonalBudget.h"
using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");
    char choice = {0};
    while (true) {
        if (!personalBudget.ifUserIsLoggedIn()) {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayBalanceOfCurrentMonth();
                break;
            case '4':
                personalBudget.displayBalanceOfPreviousMonth();
                break;
            case '5':
                personalBudget.displayBalanceOfSelectedPeriod();
                break;
            case '7':
                personalBudget.logOutUser();
                break;
            }
        }
    }

    return 0;
}
