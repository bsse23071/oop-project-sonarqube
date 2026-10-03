//
// Created by USER on 03/04/2024.
//

#ifndef INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PERSONINFO_H
#define INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PERSONINFO_H

#include <iostream>
#include "Address.h"
#include <fstream>

using namespace std;

class PersonInfo {
public:           //changed the access Modifiers as the class is a parent class to Many others
    string firstName;
    string middleName;
    string lastName;
    Address *personAddress;
    string DOB;
    char gender;
    int age;
    string phoneNumber;
    string eMail;

    // Function declaration for adding information to a file stream
    string addInfo(fstream &os);

    // Function declaration for getting information froM a file
    string getInfo(fstream &os);

public:


    //Adding a default constructor layout to this parameterised one
    PersonInfo(const string &fName = "", const string &MName = "", const string &lName = "",
               Address *address = new Address(), const string &dob = "", char g = ' ', int MyAge = 0,
               string phone = "1234567890", const string &Mail = "");

    //Getters
    string getFirstName() const;
    string getMiddleName() const;
    string getLastName() const;
    Address getPersonAddress() const;
    string getDOB() const;
    char getGender() const;
    int getAge() const;
    string getPhoneNumber() const;
    string getEmail() const;

    // Virtual function to display information
    virtual void displayInfo();

    void savePersonToJSON(const string &filename) const; //ABDULLAH
    //BY SUHAIB

    void setFirstName(string _firstName);

    void setLastName(string _lastName);
};


#endif //INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PERSONINFO_H
