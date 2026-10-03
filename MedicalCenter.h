//
// Created by noorr on 4/3/2024.
//

#ifndef INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_MEDICALCENTER_H
#define INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_MEDICALCENTER_H

#include "Address.h"

class MedicalCenter {
protected: //Inherited in Hospital and Vet Clinic
    Address address; //Composition of address class
    int centerID;
    string centerName;
public:
    bool ambulance;

    MedicalCenter();

    MedicalCenter(const int &centerID, const string &centerName, const bool &ambulance, const int &plotNo,
                  const char &sector, const string &city, const string &society);

    // If passing an Address object directly is prefered
    MedicalCenter(const int &centerID, const string &centerName, const bool &ambulance, const Address &addr);

    int getCenterID() const;

    string getCenterName() const;

    Address getAddress();

    bool ambulanceIsAvailable();

    void display();
};


#endif //INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_MEDICALCENTER_H
