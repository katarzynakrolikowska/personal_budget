#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include<iostream>
#include<fstream>

using namespace std;

class HelperMethods {
    static string input;
public:
    static string convertIntIntoString(int number);
    static int convertStringIntoInt(string numberStr);
    static float convertStringIntoFloat(string numberStr);
    static string convertFloatIntoString(float number);
    static string convertFirstCharToUppercaseLetterOthersToLowercaseLetters(string text);
    static string getString();
    static char getCharacter();
    static string getTextLine();
    static float getFloat();
    static bool ifAmountIsCorrect(float amount);
};
#endif
