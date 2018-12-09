#include <iostream>
#include "PersonalBudget.h"
using namespace std;

int main()
{
    PersonalBudget personalBudget("Users.xml");
    char choice;

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
        }
    }

    return 0;
}
