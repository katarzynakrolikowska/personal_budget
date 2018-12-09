#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;

class DateManager {
    Date date;
    Date currentDate;
    const string ZERO_DATE;
    const int SECONDS_PER_DAY;

    int getYears(string selectedDate);
    int getMonths(string selectedDate);
    int getDays(string selectedDate);
    bool ifLeapYear(int year);
    int getNumberOfDaysAtMonth(int month, int year);
    bool ifYearIsCorrect(int year);
    bool ifMonthIsCorrect(int month, int year);
    bool ifDayIsCorrect(int day, int month, int year);

public:
    DateManager();
    Date getTodayDate();
    string convertDateIntoString(Date date);
    bool ifDateIsCorrect(string testedDate);
    int getSecondsFromZeroDateToSelectedDate(string selectedDate);
    string getEarlierDate(string date1, string date2);
};
#endif
