#include <iostream>
#include "PersonalBudget.h"
using namespace std;

int main()
{
    PersonalBudget personalBudget("Users.xml");

    personalBudget.registerUser();
    personalBudget.logInUser();



    return 0;
}
