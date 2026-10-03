#ifndef JANASHEEN_DISEASE_H
#define JANASHEEN_DISEASE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

class Disease {
private:
    string name;
    bool critical;
    string description;
    vector<string> affectedOrgans;
    string diseaseId;
public:
    Disease();

    Disease(const string &n, const bool &c, const string &des, const vector<string> &affectedOrg, string disID);

    string getName();

    string getDescription();

    vector<string> getAffectedOrgans();

    bool getCriticality();

    string getDiseaseId();

    void setDiseaseId(int dId);

    void setName(string n);

    void setDescription(string d);

    void setCriticality(bool c);

    void displayInfo();

    Disease operator+(const Disease &other);

    friend ostream &operator<<(ostream &os, const Disease &other);

    static Disease* getUserInput();
};

#endif