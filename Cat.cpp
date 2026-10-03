//
// Created by noorr on 5/5/2024.
//

#include "Cat.h"

Cat::Cat() : PetInfo(), isNeutered(false), furType("Short") {}

Cat::Cat(const string &petName, const string &species, const string &color,
         const string &microchipID, const string &breed, float petAge,
         char petGender, bool isReptile, bool isMammal, bool isBird,
         const PersonInfo *owner, bool neutered, const string &fur)
        : PetInfo(petName, species, color, microchipID, breed, petAge, petGender, isReptile, isMammal, isBird, owner),
          isNeutered(neutered), furType(fur) {}

bool Cat::getIsNeutered() const {
    return isNeutered;
}

void Cat::setIsNeutered(bool neutered) {
    isNeutered = neutered;
}

string Cat::getFurType() const {
    return furType;
}

void Cat::setFurType(const string &fur) {
    furType = fur;
}

void Cat::makeSound() const {
    cout << "Meow!" << endl;
}

// Overridden function to display cat-specific information
void Cat::displayPetInfo() {
    PetInfo::displayPetInfo(); //base class
    //  cat information
    cout << "Neutered: " << (isNeutered ? "Yes" : "No") << endl;
}
