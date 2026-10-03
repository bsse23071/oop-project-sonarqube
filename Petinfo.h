//
// Created by noorr on 4/18/2024.
//

#ifndef INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PETINFO_H
#define INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PETINFO_H

#include "PersonInfo.h"

class PetInfo {
private:
    string petName;
    string species;
    string color;
    string microchipID;
    string breed;
    float petAge;
    char petGender;
    bool isReptile;
    bool isMammal;
    bool isBird;
    PersonInfo *owner; // Aggregation from PersonInfo class (Has-a)
public:

    PetInfo();

    PetInfo(const string &petN, const string &sp, const string &col,
            const string &microID, const string &br, float pAge,
            char pGender, bool reptile, bool mammal, bool bird,
            const PersonInfo *ownerInfo);

    //Getters
    string getPetName() const;

    string getSpecies() const;

    string getBreed() const;

    string getColor() const;

    string getMicrochipID() const;

    float getPetAge() const;

    char getPetGender() const;

    bool getIsReptile() const;

    bool getIsMammal() const;

    bool getIsBird() const;

    void setOwner(const PersonInfo &owner);

    PersonInfo *getOwner() const;

    virtual void displayPetInfo();

    friend istream &operator>>(istream &input, PetInfo &pet);

    friend ostream &operator<<(ostream &os, const PetInfo &pet);
};

#endif //INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PETINFO_H
