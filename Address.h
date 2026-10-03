
//
// Created by noorr on 4/3/2024.
//

#ifndef INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_ADDRESS_H
#define INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_ADDRESS_H

#include <iostream>
#include <fstream>

using namespace std;

#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Address {
private:
    int plotNo;
    char sector;
    string city;
    string society;
public:
    Address();

    Address(const int &plotNo, const char &sector, const string &city, const string &society);

    ~Address();

    // Getters
    int getPlotNo() const;

    void setPlotNo(int p);

    void setSector(char s);

    void setCity(const string c);

    void setSociety(const string s);

    char getSector() const;

    string getCity() const;

    string getSociety() const;

    json to_json() const;

    bool isValid() const;

    Address &operator=(const Address &other);

    void saveToJson(const string &filename) const;

    void displayAddress();

};

#endif //INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_ADDRESS_H
