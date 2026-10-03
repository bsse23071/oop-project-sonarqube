//
// Created by noorr on 4/4/2024.
//

#include "Date.h"

Date::Date() {
    year = 2024;
    month = 0;
    day = 0;
    hour = 0;
    minute = 0;
    second = 0;
}


Date::Date(int year, int month, int day, int hour, int minute, int second) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}


Date::~Date() {}

ostream &operator<<(ostream &oss, const Date &date) {
    oss << "Date: " << date.year << "-" << date.month << "-" << date.day << endl;
    oss << "Time: " << date.hour << ":" << date.minute << ":" << date.second << endl;
    return oss;
}

string Date::getDate() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}


int Date::getYear() const { return year; }


int Date::getMonth() const { return month; }

int Date::getDay() const { return day; }

int Date::getHour() const { return hour; }

int Date::getMinute() const { return minute; }

int Date::getSecond() const { return second; }

void Date::setDay(int val) {
    day = val;
}

void Date::setHour(int val) {
    hour = val;
}

void Date::setMinute(int val) {
    minute = val;
}

void Date::setMonth(int val) {
    month = val;
}

void Date::setYear(int val) {
    year = val;
}

void Date::setSecond(int val) {
    second = val;
}

//Abdullah's functions in Doctor
bool Date::operator!=(const Date &other) const {
    return year != other.year && month != other.month && day != other.day && hour != other.hour;
}

bool Date::operator==(const Date &other) const {
    return year == other.year && month == other.month && day == other.day && hour == other.hour;
}