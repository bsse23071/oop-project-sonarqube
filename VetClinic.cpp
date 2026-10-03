//
// Created by noorr on 4/19/2024.
//

#include "VetClinic.h"

VetClinic *VetClinic::instance = nullptr;

VetClinic *VetClinic::getInstance() {
    if (!instance) {
        instance = new VetClinic();
    }
    return instance;
}

void VetClinic::addPet(Pet *pet) {
    pets.push_back(pet);
}


Pet *VetClinic::findPet(const string &petID) const {
    for (size_t i = 0; i < pets.size(); ++i) {
        if (pets[i]->getPetID() == petID) {
            cout << "Pet with ID " << petID << " found in clinic.\n";
            return pets[i];
        }
    }
    cout << "Pet with ID " << petID << " not found in clinic.\n";
    return nullptr;
}

void VetClinic::updatePet(const string &petID, const Pet &updatedPet) {
    for (int i = 0; i < pets.size(); ++i) {
        if (pets[i]->getPetID() == petID) {
            *pets[i] = updatedPet; // Update the pet's information
            cout << "Pet with ID " << petID << " has been updated.\n";
            return;
        }
    }
    cout << "Pet with ID " << petID << " not found in the clinic. Update failed.\n";
}


void VetClinic::displayAllPets() {
    if (pets.empty()) {
        cout << "No pets registered in the clinic.\n";
        return;
    } else {
        for (int i = 0; i < pets.size(); ++i) {
            pets[i]->displayPet();
            cout << "-------------------------------------------------------\n";
        }
    }
}

int VetClinic::getNumberOfPets() const {
    return pets.size();
}
