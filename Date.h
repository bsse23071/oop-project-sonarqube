//
// Created by noorr on 4/4/2024.
//

#ifndef INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_DATE_H
#define INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    //default constructor
    Date();

    //parametrized constructor
    Date(int year, int month, int day, int hour, int minute, int second);

    //destructor
    ~Date();

    //overloading << operator to display
    friend ostream &operator<<(ostream &oss, const Date &date);

    //getters for specific values
    int getYear() const;

    int getMonth() const;

    int getDay() const;

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    string getDate() const;

    void setYear(int val);

    void setMonth(int val);

    void setDay(int val);

    void setHour(int val);

    void setMinute(int val);

    void setSecond(int val);

    bool operator!=(const Date &other) const;

    bool operator==(const Date &other) const;

};


#endif //INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_DATE_H
