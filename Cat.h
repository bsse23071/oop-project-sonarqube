//
// Created by noorr on 5/5/2024.
//

#ifndef MY_END_CAT_H
#define MY_END_CAT_H

#include "Petinfo.h"

class Cat : public PetInfo {
private:
    bool isNeutered;
    string furType;
public:
    Cat();

    Cat(const string &petName, const string &species, const string &color,
        const string &microchipID, const string &breed, float petAge,
        char petGender, bool isReptile, bool isMammal, bool isBird,
        const PersonInfo *owner, bool neutered, const string &fur);

    bool getIsNeutered() const;

    void setIsNeutered(bool neutered);

    string getFurType() const;

    void setFurType(const string &fur);

    void makeSound() const;

    // for polymorphism
    void displayPetInfo() override;
};

#endif //MY_END_CAT_H
