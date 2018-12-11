#include <iostream>
#include <ctime>
#include "DateManager.h"
#include <sstream>
#include <string>
#include <windows.h>
#include "HelperMethods.h"
#include "Date.h"
using namespace std;

DateManager::DateManager():ZERO_DATE("2000-01-01"), SECONDS_PER_DAY(86400) {
    currentDate = getTodayDate();
}

int DateManager::getYears(string selectedDate) {
    string yearsStr = "";
    int i = 0;
    while(selectedDate[i] != '-') {
        yearsStr += selectedDate[i];
        i++;
    }
    date.years = HelperMethods::convertStringIntoInt(yearsStr);
    return date.years;
}

int DateManager::getMonths(string selectedDate) {
    string monthsStr = "";
    monthsStr = selectedDate.substr(5,2);
    date.months = HelperMethods::convertStringIntoInt(monthsStr);
    return date.months;
}

int DateManager::getDays(string selectedDate) {
    string daysStr = "";
    daysStr = selectedDate.substr(8,2);
    date.days = HelperMethods::convertStringIntoInt(daysStr);
    return date.days;
}

Date DateManager::getTodayDate() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    Date todayDate;
    todayDate.years = st.wYear;
    todayDate.months = st.wMonth;
    todayDate.days = st.wDay;
    return todayDate;
}

string DateManager::convertDateIntoString(Date date){
    string dateStr = "", yearStr = "", monthStr = "", dayStr = "";
    yearStr = HelperMethods::convertIntIntoString(date.years);
    monthStr = HelperMethods::convertIntIntoString(date.months);
    dayStr = HelperMethods::convertIntIntoString(date.days);
    if (dayStr.length() == 1)
        dayStr = '0' + dayStr;

    dateStr = yearStr + "-" + monthStr + "-" + dayStr;
    return dateStr;
}
bool DateManager::ifLeapYear(int year) {
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) {
        return true;
    } else
        return false;
}

int DateManager::getNumberOfDaysAtMonth(int month, int year) {

    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        if (ifLeapYear(year))
            return 29;
        else
            return 28;
        break;
    }
}

bool DateManager::ifYearIsCorrect(int year) {

    if(year < 2000 || year > currentDate.years)
        return false;
    else
        return true;
}

bool DateManager::ifMonthIsCorrect(int month, int year) {
    if((month < 1 || month > 12) || (year == currentDate.years && month > currentDate.months))
        return false;
    else
        return true;
}

bool DateManager::ifDayIsCorrect(int day, int month, int year) {
    if (day < 1 || day > getNumberOfDaysAtMonth(month, year))
        return false;
    else
        return true;
}

bool DateManager::ifDateIsCorrect(string testedDate) {
    date.years = getYears(testedDate);
    date.months = getMonths(testedDate);
    date.days = getDays(testedDate);
    if (ifYearIsCorrect(date.years) && ifMonthIsCorrect(date.months, date.years) && ifDayIsCorrect(date.days, date.months, date.years))
        return true;
    else
        return false;
}


int DateManager::getDaysFromZeroDateToSelectedDate(string selectedDate) {
    struct tm date, zeroDate;
    long long int differenceSeconds;

    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;
    date.tm_year = getYears(selectedDate)-1900;
    date.tm_mon = getMonths(selectedDate)-1;
    date.tm_mday = getDays(selectedDate);

    zeroDate.tm_hour = 0;
    zeroDate.tm_min = 0;
    zeroDate.tm_sec = 0;
    zeroDate.tm_year = getYears(ZERO_DATE) - 1900;
    zeroDate.tm_mon = getMonths(ZERO_DATE) - 1;
    zeroDate.tm_mday = getDays(ZERO_DATE);
    differenceSeconds = difftime(mktime(&date), mktime(&zeroDate));
    return differenceSeconds/SECONDS_PER_DAY;
}

string DateManager::getEarlierDate(string date1, string date2) {
    if(getDaysFromZeroDateToSelectedDate(date1) <= getDaysFromZeroDateToSelectedDate(date2)) {
        return date1;
    } else
        return date2;
}

bool DateManager::ifDateIsFromCurrentMonth(string date){
    if(getYears(date) == currentDate.years && getMonths(date) == currentDate.months)
        return true;
    else return false;
}

bool DateManager::ifDateIsFromPreviousMonth(string date){
    if(getYears(date) == currentDate.years && getMonths(date) == currentDate.months - 1)
        return true;
    else return false;
}

bool DateManager::ifDateIsFromSelectedPeriod(string earlierDate, string laterDate, int numbersOfDaysFromZeroDateToCheckedDate){
    if(numbersOfDaysFromZeroDateToCheckedDate >= getDaysFromZeroDateToSelectedDate(earlierDate) && numbersOfDaysFromZeroDateToCheckedDate <= getDaysFromZeroDateToSelectedDate(laterDate)){
        return true;
    }else return false;
}
