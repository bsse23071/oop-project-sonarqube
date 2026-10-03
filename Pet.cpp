//
// Created by noorr on 4/20/2024.
//

#include "Pet.h"

Pet::Pet()
        : petID(""), // Initialize petID to an empty string
          petHistory(), // Initialize petHistory using default constructor
          isPetDead(false), // Initialize isPetDead to false
          petI() // Initialize petI using default constructor
{}

Pet::Pet(const string &petID, const vector<Disease *> &petDiseases,
         const PatientHistory &petHistory, bool isPetDead, const PetInfo &petI) :
        petID(petID), petDiseases(petDiseases),
        petHistory(petHistory), isPetDead(isPetDead), petI(petI) {}


Pet::~Pet() {
}

// Getters
string Pet::getPetID() const {
    return petID;
}

vector<Disease *> Pet::getPetDiseases() const {
    return petDiseases;
}

PatientHistory Pet::getPetHistory() const {
    return petHistory;
}

bool Pet::getIsDead() const {
    return isPetDead;
}

void Pet::addPetDisease(Disease *disease) {
    petDiseases.push_back(disease);
}

void Pet::removePetDisease(Disease *disease) {
    for (int i = 0; i < petDiseases.size(); i++) {
        if (disease->getName() == petDiseases[i]->getName()) {
            cout << "\n\nDisease " << petDiseases[i]->getName() << " Found in record is now cured\n";
            cout << "Removing disease\n";
            petDiseases.erase(petDiseases.begin() + i);
            break;
        }
    }
    cout << "Could not find this disease in record\n";
}

void Pet::addPetSurgery(const string &pSur) {
    petHistory.addSurgery(pSur);
}

vector<string> Pet::getPetSurgeries() {
    return petHistory.getPrevSurgeries();
}

void Pet::displayPetDiseases() {
    for (int i = 0; i < petDiseases.size(); i++) {
        petDiseases[i]->displayInfo();
    }
}

void Pet::displayPetHistory() {
    petHistory.displayPatientHistory();
}

void Pet::markAsDead() {
    isPetDead = true;
}

void Pet::displayPet() {
    cout << "\nPet ID: " << petID << endl;
    cout << "Is Dead: " << (isPetDead ? "Yes" : "No") << endl;
    petI.displayPetInfo(); // Calling function from PetInfo
}

void Pet::savePetToJson(const string &fileName) {
    //data needs to be saved in an object to be overwritten later
    ifstream inFile(fileName);
    json j;
    if (inFile.fail()) {
        cout << "ERROR: File to read data from not found, will create a new one." << endl;
    } else {
        if (!isFileEmpty(inFile)) {
            inFile >> j;
        }
        inFile.close();
    }
    json js;

    // Add pet information
    json petJson;
    petJson["Pet ID"] = petID;
    petJson["Pet Name"] = petI.getPetName();
    stringstream ss;
    ss << fixed << setprecision(2) << petI.getPetAge();
    petJson["Pet Age"] = ss.str(); // string to the JSON object
    //petJson["Pet Age"] = petI.getPetAge();
    petJson["Pet Gender"] = string(1, petI.getPetGender()); // char to string
    petJson["Pet Breed"] = petI.getBreed();
    petJson["Pet Color"] = petI.getColor();
    petJson["Is Reptile"] = petI.getIsReptile();
    petJson["Is Mammal"] = petI.getIsMammal();
    petJson["Is Bird"] = petI.getIsBird();
    js["Pet"] = petJson;

    // Add owner information
    const PersonInfo *ownerInfo = petI.getOwner();
    json ownerJson;
    ownerJson["First Name"] = ownerInfo->getFirstName();
    ownerJson["Middle Name"] = ownerInfo->getMiddleName();
    ownerJson["Last Name"] = ownerInfo->getLastName();
    ownerJson["Age"] = ownerInfo->getAge();
    ownerJson["Phone Number"] = ownerInfo->getPhoneNumber();
    ownerJson["Email"] = ownerInfo->getEmail();
    js["Owner"] = ownerJson;

    // Add diseases
    json diseasesArray;
    for (const auto &disease: petDiseases) {
        json diseaseJson;
        diseaseJson["Name"] = disease->getName();
        diseaseJson["Description"] = disease->getDescription();
        diseaseJson["Critical"] = disease->getCriticality();
        diseaseJson["Affected Organs"] = disease->getAffectedOrgans();
        diseasesArray.push_back(diseaseJson);
    }
    js["Diseases"] = diseasesArray;

    js["Is Dead"] = isPetDead;

    ofstream out(fileName);
    if (!out) {
        cerr << "ERROR: Unable to open file for writing." << endl;
        return;
    }
    out << setw(2) << js << endl;
    out.close();

    cout << "Pet data has been successfully written." << endl;
}

bool Pet::isFileEmpty(ifstream &inFile) {
    return inFile.peek() == ifstream::traits_type::eof();
}

void Pet::loadPetFromJson(const string &fileName) {
    ifstream inFile(fileName);
    if (inFile.fail()) {
        cout << "ERROR: File not found\n";
        return;
    }

    json j;
    if (!isFileEmpty(inFile)) {
        try {
            inFile >> j;
        } catch (json::parse_error &e) {
            cout << "ERROR: JSON parsing error: " << e.what() << endl;
            return;
        }

        if (j.contains("Pet") && !j["Pet"].is_null()) {
            auto &petData = j["Pet"];
            cout << "\n\tPet Data:\t\n";
            cout << "Pet ID: " << petData["Pet ID"] << endl;
            cout << "Pet Name: " << petData["Pet Name"] << endl;
            cout << "Pet Age: " << petData["Pet Age"] << endl;
            cout << "Pet Gender: " << petData["Pet Gender"] << endl;
            cout << "Pet Breed: " << petData["Pet Breed"] << endl;
            cout << "Pet Color: " << petData["Pet Color"] << endl;
            cout << "Is Reptile: " << (petData["Is Reptile"] ? "Yes" : "No") << endl;
            cout << "Is Mammal: " << (petData["Is Mammal"] ? "Yes" : "No") << endl;
            cout << "Is Bird: " << (petData["Is Bird"] ? "Yes" : "No") << endl;

            cout << "Is Dead: " << (j["Is Dead"] ? "Yes" : "No") << endl;

            // for Diseases
            if (j.contains("Diseases") && !j["Diseases"].empty()) {
                cout << "\n\tDiseases:\t\n";
                for (const auto &disease: j["Diseases"]) {
                    cout << "- Name: " << disease["Name"] << endl;
                    cout << "  Description: " << disease["Description"] << endl;
                    cout << "  Criticality: " << (disease["Critical"] ? "Critical" : "Not Critical") << endl;
                    cout << " Affected Organs: ";
                    for (const auto &organ: disease["Affected Organs"]) {
                        cout << organ << ", ";
                    }
                    cout << endl;
                }
            } else {
                cout << "No diseases found." << endl;
            }

            // owner information
            if (j.contains("Owner") && !j["Owner"].is_null()) {
                auto &ownerData = j["Owner"];
                cout << "\n\tOwner Information:\t\n";
                cout << "First Name: " << ownerData["First Name"] << endl;
                cout << "Middle Name: " << ownerData["Middle Name"] << endl;
                cout << "Last Name: " << ownerData["Last Name"] << endl;
                cout << "Age: " << ownerData["Age"] << endl;
                cout << "Phone Number: " << ownerData["Phone Number"] << endl;
                cout << "Email: " << ownerData["Email"] << endl;
            } else {
                cout << "No owner information found." << endl;
            }
        } else {
            cout << "No data found for Pet." << endl;
        }
    }
    inFile.close();
}