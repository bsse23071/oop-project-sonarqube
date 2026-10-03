//
// Created by noorr on 4/19/2024.
//

#ifndef INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_VETCLINIC_H
#define INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_VETCLINIC_H

#include "Pet.h"
#include "MedicalCenter.h"


class VetClinic: public MedicalCenter {
private:
    vector<Pet *> pets;
    static VetClinic *instance;
    VetClinic() {} // Private constructor

public:
    static VetClinic *getInstance();

    void addPet(Pet *pet);

    Pet *findPet(const string &petID) const;

    void updatePet(const string &petID, const Pet &updatedPet);

    void displayAllPets();

    int getNumberOfPets() const;

};

#endif //INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_VETCLINIC_H
