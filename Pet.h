//
// Created by noorr on 4/20/2024.
//

#ifndef INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PET_H
#define INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PET_H

#include "Petinfo.h"
#include "Disease.h"
#include "PatientHistory.h"
#include <vector>
#include <sstream>

using namespace std;

#include "nlohmann/json.hpp"

using json = nlohmann::json;


class Pet {
private:
    string petID;
    vector<Disease *> petDiseases;
    PatientHistory petHistory;
    bool isPetDead;
    PetInfo petI;
public:

    Pet();

    Pet(const string &petID, const vector<Disease *> &petDiseases,
        const PatientHistory &petHistory, bool isPetDead, const PetInfo &petI);

    ~Pet();

    // Getters
    string getPetID() const;

    vector<Disease *> getPetDiseases() const;

    PatientHistory getPetHistory() const;

    bool getIsDead() const;

    void addPetDisease(Disease *disease);

    void removePetDisease(Disease *disease);

    void addPetSurgery(const string &pSur);

    vector<string> getPetSurgeries();

    void displayPetDiseases();

    void displayPetHistory();

    void markAsDead();

    void displayPet();

    void savePetToJson(const string &fileName);

    bool isFileEmpty(ifstream &inFile);

    void loadPetFromJson(const string &fileName);
};

#endif //INC_2024_SPRING_SE102TA_PROJECT_SE102A_G_PET_H
