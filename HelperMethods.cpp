#include<iostream>
#include "HelperMethods.h"
#include<sstream>
#include <algorithm>
using namespace std;

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

string HelperMethods::getWord() {
    string word = "";
    cin >> word;
    cin.ignore(1000, '\n');
    return word;
}
