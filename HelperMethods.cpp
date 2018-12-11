#include<iostream>
#include "HelperMethods.h"
#include<sstream>
#include<string>
#include <algorithm>
using namespace std;

string HelperMethods::input = "";

string HelperMethods::convertIntIntoString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelperMethods::convertFloatIntoString(float number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int HelperMethods::convertStringIntoInt(string numberStr) {
    int number;
    istringstream iss(numberStr);
    iss >> number;

    return number;
}

float HelperMethods::convertStringIntoFloat(string numberStr) {
    float number;
    istringstream iss(numberStr);
    iss >> number;

    return number;
}

string HelperMethods::convertFirstCharToUppercaseLetterOthersToLowercaseLetters(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string HelperMethods::getString() {
    string word = "";
    cin >> word;
    cin.ignore(1000, '\n');
    return word;
}

char HelperMethods::getCharacter() {
    char character = {0};

    while (true) {
        cin >> input;
        cin.ignore(1000, '\n');
        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string HelperMethods::getTextLine() {
    getline(cin, input);
    return input;
}

float HelperMethods::getAmount() {
    float amount = 0;
    while (true) {
        getline(cin, input);
        for(int i =0; i < input.length(); i++) {
            if(input[i] == ',') {
                input[i] = '.';
            }
        }
        stringstream myStream(input);
        if (myStream >> amount && amount >= 0.0)
            break;
        cout << "To nie jest kwota. Wpisz ponownie. " << endl;
    }
    return amount;
}

string HelperMethods::getDateInFormatYYYYMMDD() {
    string date = "";
    while(true) {
        getline(cin, date);
        if((date.length() != 10) || (date[4] != '-' && date[7] != '-')) {
            cout << "Nipoprawny format!" << endl;
            cout << "Podaj date ";
        } else {
            for(int i = 0; i < date.length(); i++) {
                if(date[i] != '-') {
                    if(date[i] < '0' || date[i] > '9') {
                        cout << "Data nie prawidlowa" << endl;
                        cout << "Podaj date ";
                        break;
                    } else if(i == date.length() - 1)
                        return date;
                }
            }
        }
    }
}
