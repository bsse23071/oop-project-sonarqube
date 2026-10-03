//
// Created by noorr on 4/3/2024.
//

#include "MedicalCenter.h"

MedicalCenter::MedicalCenter() {
    int centerID = 0;
    string centerName = " ";
    bool ambulance = false;
}

MedicalCenter::MedicalCenter(const int &centerID, const string &centerName, const bool &ambulance, const int &plotNo,
                             const char &sector, const string &city, const string &society)
        : address(plotNo, sector, city, society), centerID(centerID), centerName(centerName), ambulance(ambulance) {}


MedicalCenter::MedicalCenter(const int &centerID, const string &centerName, const bool &ambulance, const Address &addr)
        : address(addr), centerID(centerID), centerName(centerName), ambulance(ambulance) {}

int MedicalCenter::getCenterID() const {
    return centerID;
}

string MedicalCenter::getCenterName() const {
    return centerName;
}

Address MedicalCenter::getAddress() {
    return address;
}

bool MedicalCenter::ambulanceIsAvailable() {
    return ambulance;
}

void MedicalCenter::display() {
    cout << "Center ID: " << centerID << endl;
    cout << "Center Name: " << centerName << endl;
    cout << "Ambulance: " << (ambulance ? "Yes" : "No") << endl;
}
