#include<iostream>
#include "HelperMethods.h"
#include<sstream>
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

float HelperMethods::getFloat() {
    float number = 0;
    while (true) {
        getline(cin, input);
        for(int i =0; i < input.length(); i++){
            if(input[i] == ','){
                input[i] = '.';
            }
        }
        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

bool HelperMethods::ifAmountIsCorrect(float amount){
    if(amount < 0.0){
        return 0;
    }else return 1;
}
