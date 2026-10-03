//
// Created by USER on 03/04/2024.
//

#include "PersonInfo.h"
#include <cstring>

PersonInfo::PersonInfo(const string &fName, const string &mName, const string &lName,
                       Address *address, const string &dob, char g, int myAge, string phone, const string &mail) {
    firstName = fName;
    middleName = mName;
    lastName = lName;
    personAddress = address;
    DOB = dob;
    gender = g;
    age = myAge;
    phoneNumber = phone;
    eMail = mail;
}

// Getters
string PersonInfo::getFirstName() const {
    return firstName;
}

string PersonInfo::getMiddleName() const {
    return middleName;
}

string PersonInfo::getLastName() const {
    return lastName;
}

Address PersonInfo::getPersonAddress() const {
    return *personAddress;
}

string PersonInfo::getDOB() const {
    return DOB;
}

char PersonInfo::getGender() const {
    return gender;
}

int PersonInfo::getAge() const {
    return age;
}

string PersonInfo::getPhoneNumber() const {
    return phoneNumber;
}

string PersonInfo::getEmail() const {
    return eMail;
}


string PersonInfo::addInfo(fstream &os) {
    os << "Additional information";
    return "Additional information added";
}


string PersonInfo::getInfo(fstream &os) {
    string info;
    os >> info;
    return info;
}

void PersonInfo::displayInfo() {
    cout << "First Name: " << firstName << endl;
    cout << "Middle Name: " << middleName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Address: \n";
    cout << "      Plot no.: " << personAddress->getPlotNo() << endl;
    cout << "      City: " << personAddress->getCity() << endl;
    cout << "      Sector: " << personAddress->getSector() << endl;
    cout << "      Society: " << personAddress->getSociety() << endl;
    cout << "DOB: " << DOB << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Email: " << eMail << endl;
}

void PersonInfo::savePersonToJSON(const string &filename) const
{
    json j;
    j["firstName"] = firstName;
    j["middleName"] = middleName;
    j["lastName"] = lastName;
    j["DOB"] = DOB;
    j["gender"] = string(1, gender); // Convert char to string
    j["age"] = age;
    j["phoneNumber"] = phoneNumber;
    j["eMail"] = eMail;

    j["address"] = personAddress->to_json();

    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << j.dump(4); // Pretty printing with an indent of 4 spaces
        outFile.close();

        cout << "Doctor " << firstName << "'s info saved to file" << filename;
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void PersonInfo::setFirstName(string _firstName) {
    firstName = _firstName;
}

void PersonInfo::setLastName(std::string _lastName) {
    lastName = _lastName;
}
