//
// Created by noorr on 4/18/2024.
//

#include "Petinfo.h"

// Default constructor
PetInfo::PetInfo() : petName(""), species(""), color(""), microchipID(""), breed(""),
                     petAge(0.0), petGender(' '), isReptile(false), isMammal(false),
                     isBird(false), owner(nullptr) {}

PetInfo::PetInfo(const string &petN, const string &sp, const string &col,
                 const string &microID, const string &br, float pAge,
                 char pGender, bool reptile, bool mammal, bool bird,
                 const PersonInfo *ownerInfo) {
    petName = petN;
    species = sp;
    color = col;
    microchipID = microID;
    breed = br;
    petAge = pAge;
    petGender = pGender;
    isReptile = reptile;
    isMammal = mammal;
    isBird = bird;
    owner = new PersonInfo(*ownerInfo); // deep copy of ownerInfo
}


string PetInfo::getPetName() const {
    return petName;
}

string PetInfo::getSpecies() const {
    return species;
}

string PetInfo::getBreed() const {
    return breed;
}

string PetInfo::getColor() const {
    return color;
}

string PetInfo::getMicrochipID() const {
    return microchipID;
}


float PetInfo::getPetAge() const {
    return petAge;
}

char PetInfo::getPetGender() const {
    return petGender;
}

bool PetInfo::getIsReptile() const {
    return isReptile;
}

bool PetInfo::getIsMammal() const {
    return isMammal;
}

bool PetInfo::getIsBird() const {
    return isBird;
}

void PetInfo::setOwner(const PersonInfo &owner) {
    // memory for the owner and make deep copy
    this->owner = new PersonInfo(owner);
}

PersonInfo *PetInfo::getOwner() const {
    return owner;
}

void PetInfo::displayPetInfo() {
    cout << "\nOwner Information:\n";
    owner->displayInfo();
    //pet details
    cout << "\nPet Information:\n";
    cout << "Pet Name: " << petName << endl;
    cout << "Species: " << species << endl;
    cout << "Breed: " << breed << endl;
    cout << "Color: " << color << endl;
    cout << "Microchip ID: " << microchipID << endl;
    cout << "Age: " << petAge << endl;
    cout << "Gender: " << petGender << endl;
    cout << "Is Reptile: " << (isReptile ? "Yes" : "No") << endl;
    cout << "Is Mammal: " << (isMammal ? "Yes" : "No") << endl;
    cout << "Is Bird: " << (isBird ? "Yes" : "No") << endl;
}

istream &operator>>(istream &i, PetInfo &pet) {

    cout << "Enter pet name: ";
    i >> pet.petName;
    cout << "Enter species: ";
    i >> pet.species;
    cout << "Enter color: ";
    i >> pet.color;
    cout << "Enter microchip ID: (0 if none)";
    i >> pet.microchipID;
    cout << "Enter breed: ";
    i >> pet.breed;
    cout << "Enter pet age: ";
    i >> pet.petAge;
    cout << "Enter pet gender (M/F): ";
    i >> pet.petGender;
    cout << "Is the pet a reptile (0 for No/1 for Yes): ";
    i >> pet.isReptile;
    cout << "Is the pet a mammal (0 for No/1 for Yes): ";
    i >> pet.isMammal;
    cout << "Is the pet a bird (0 for No/1 for Yes): ";
    i >> pet.isBird;
    return i;
}

ostream &operator<<(ostream &o, const PetInfo &pet) {
    o << "\nPet Name: " << pet.getPetName() << endl;
    o << "Species: " << pet.getSpecies() << endl;
    o << "Color: " << pet.getColor() << endl;
    o << "Microchip ID: " << pet.getMicrochipID() << endl;
    o << "Breed: " << pet.getBreed() << endl;
    o << "Age: " << pet.getPetAge() << endl;
    o << "Gender: " << pet.getPetGender() << endl;
    o << "Is Reptile: " << (pet.getIsReptile() ? "Yes" : "No") << endl;
    o << "Is Mammal: " << (pet.getIsMammal() ? "Yes" : "No") << endl;
    o << "Is Bird: " << (pet.getIsBird() ? "Yes" : "No") << endl;
    return o;
}
