#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include<iostream>
#include<fstream>

using namespace std;

class HelperMethods {
public:
    static string convertIntIntoString(int number);
    static int convertStringIntoInt(string numberStr);
    static float convertStringIntoFloat(string numberStr);
    static string convertFloatIntoString(float number);
    static string convertFirstCharToUppercaseLetterOthersToLowercaseLetters(string text);
    static string getWord();
};
#endif
