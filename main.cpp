#include <iostream>

#include "PersonInfo.h"
#include "Petinfo.h"
#include "Pet.h"
#include "VetClinic.h"
#include "MedicalCenter.h"
#include "PatientHistory.h"
#include "Disease.h"
#include "Cat.h"

#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;


int main() {
    Address *personAddress = new Address(1, 'A', "Lhr", "Bahria"); // Create a new Address object

    PersonInfo person("Felix", "Fel", "Kena", personAddress, "23/04/1934", 'M', 10, "03218456746",
                      "john@gmail.com");

    int c;
    const string fileName = "datastorage.json";
    do {
        cout << "Welcome to Lahore Medical Center!" << endl;
        cout << "Choose a function from the menu below\n"
                "1.Test Medical Center and Address class\n"
                "2.Test Person info class\n"
                "3.Test Pet Info and Pet class\n"
                "4.Test Vet Clinic class\n"
                "5.Test specialized class\n"
                "6.Exit program"
             << endl;
        cin >> c;

        switch (c) {
            case 1: {
                cout << "\n\n\tTesting Medical Centre and Address\t\n\n";
                int choice;

                //so these can be used in all cases
                Address medicalCenterAddress;
                MedicalCenter medicalCenter;
                do {
                    cout << "1. Add Address\n";
                    cout << "2. Add Medical Center\n";
                    cout << "3. Display Address\n";
                    cout << "4. Display Medical Center\n";
                    cout << "5. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            medicalCenterAddress = Address(123, 'A', "City", "Society");
                            cout << "Address object created.\n";
                            break;
                        }
                        case 2: {
                            if (!medicalCenterAddress.isValid()) {
                                cout << "Error: Address must be added.\n";
                            } else {
                                MedicalCenter medicalCenter(1, "Hospital", true, medicalCenterAddress);
                                cout << "Medical Center object created.\n";
                            }
                            break;
                        }
                        case 3: {
                            medicalCenterAddress.displayAddress();
                            break;
                        }
                        case 4: {
                            medicalCenter.display();
                            break;
                        }
                        case 5: {
                            cout << "Exiting program...\n";
                            break;
                        }
                        default: {
                            cout << "Invalid choice. Please try again.\n";
                            break;
                        }
                    }
                } while (choice != 5);
                cout << "------------------------------------------------------------------------------" << endl;
                break;
            }
            case 2: {
                // Testing Person Info class
                // Address *personAddress = new Address(1, 'A', "Lhr", "Bahria"); // Create a new Address object
                // // Creating a Person object
                // PersonInfo person("Felix", "Fel", "Kena", personAddress, "23/04/1934", 'M', 10, "03218456746", "john@gmail.com");
                // PersonInfo person2("Pen","Luc","Bon",personAddress,"20/11/2000",'F',23,"0111222333","Luck@gmail.com");
                person.displayInfo();
                person.getPersonAddress();
                cout << "------------------------------------------------------------------------------" << endl;
                break;
            }
            case 3: {
                cout << "----------------------------------------------------------------------\n" << endl;

                // PersonInfo object for the pet owner
                PersonInfo petOwner("Noor", "Rizz", "Rizwan", personAddress, "07/01/1980", 'F', 20,
                                    "1234567890", "noor@example.com");

                // PetInfo object linked with the owner
                PetInfo pet;
                cout << "Enter your pet's details:\n";
                cin >> pet; //ifstream overloading >>
                pet.setOwner(petOwner);
                cout << "\nPet Info added\n";
                cout << pet; //ostream overloading <<

                //Now for Pet class:
                vector<string> organ = {"Ears", "Skin"};
                vector<string> organ2 = {"Abdomen", "Fur"};
                Disease petDisease1("Mites", false, "Ear mites", organ, "1");
                Disease petDisease2("Un-spayed", false, "Health issues", organ2, "2");

                //vector of diseases and adding 2 diseases
                vector<Disease *> petDiseases;
                petDiseases.push_back(&petDisease1);
                petDiseases.push_back(&petDisease2);
                //pet History
                PatientHistory petHis;
                petHis.addDisease(petDisease1);
                petHis.addDisease(petDisease2);

                // Pet object
                Pet myPet("1", petDiseases, petHis, false, pet);
                cout << "\nPet ID allocated\n";
                myPet.displayPet();
                cout << endl;

                vector<string> organ3 = {"Blood", "Skin"};
                Disease petDisease3("Fleas", true, "Seasonal disease", organ3, "3");
                myPet.addPetDisease(&petDisease3);
                cout << "New disease added\n";

                cout << endl;
                myPet.addPetSurgery("Spaying");
                cout << "Surgery added\n";

                int choice;
                do {
                    cout << "1. Display Pet Diseases\n";
                    cout << "2. Display Pet History\n";
                    cout << "3. Mark Pet as dead\n";
                    cout << "4. Display Pet\n";
                    cout << "5. Save Pet to JSON\n";
                    cout << "6. Load Pet from JSON\n";
                    cout << "7. Exit\n";
                    cin >> choice;
                    switch (choice) {
                        case 1: {
                            cout << endl;
                            myPet.displayPetDiseases();
                            break;
                        }
                        case 2: {
                            myPet.displayPetHistory();
                            cout << endl;
                            break;
                        }
                        case 3: {
                            myPet.markAsDead();
                            cout << "Marked as dead\n";
                            break;
                        }
                        case 4: {
                            myPet.displayPet();
                            break;
                        };
                        case 5: {

                            // myPet.savePetToJson("petInfo.json");
                            myPet.savePetToJson(myPet.getPetID() + ".json");
                            break;
                        }
                        case 6: {
                            myPet.loadPetFromJson(myPet.getPetID() + ".json");
                            break;
                        }
                        case 7: {
                            cout << "Exiting program.\n";
                            break;
                        }
                        default: {
                            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
                            break;
                        }
                    }
                    cout << "------------------------------------------------------------------------------" << endl;
                } while (choice != 7);
                break;
            }
            case 4: {
                // Adding pets to VetClinic
                VetClinic *clinic = VetClinic::getInstance();

                // PersonInfo object for the pet owner
                PersonInfo petOwner1("Noor", "Rizz", "Rizwan", personAddress, "07/01/1980", 'F', 20,
                                     "1234567890", "noor@example.com");
                // PetInfo object linked with the owner
                PetInfo pet("Luna", "Cat", "Fawn", "123456789", "Persian", 1.1, 'F', false, true, false,
                            &petOwner1);

                vector<string> organ = {"Ears", "Skin"};
                vector<string> organ2 = {"Abdomen", "Fur"};
                Disease petDisease1("Mites", false, "Ear mites", organ, "1");
                Disease petDisease2("Un-spayed", false, "Health issues", organ2, "2");
                vector<Disease *> petDiseases;
                petDiseases.push_back(&petDisease1);
                petDiseases.push_back(&petDisease2);
                PatientHistory petHis;
                petHis.addDisease(petDisease1);
                petHis.addDisease(petDisease2);

                // Pet object
                Pet myPet1("123", petDiseases, petHis, true, pet);

                PersonInfo petOwner2("N", "R", "Rizwan", personAddress, "07/01/1980", 'F', 20,
                                     "1234567890", "noor@example.com");
                PetInfo pet2("Terra", "Cat", "Fawn", "123456789", "Persian", 1.1, 'F', false, true, false,
                             &petOwner2);

                vector<string> organ0 = {"Eyes", "Skin"};
                vector<string> organ01 = {"Eyes", "Fur"};
                Disease petDisease0("Mites", false, "Ear mites", organ, "00");
                Disease petDisease01("Un-spayed", false, "Health issues", organ2, "01");
                vector<Disease *> petDiseases2;
                petDiseases.push_back(&petDisease0);
                petDiseases.push_back(&petDisease01);
                PatientHistory petHis2;
                petHis2.addDisease(petDisease0);
                petHis2.addDisease(petDisease01);
                Pet myPet2("456", petDiseases2, petHis2, false, pet2);


                int choice;
                do {
                    cout << "\nMenu:\n"
                         << "1. Add Pet\n"
                         << "2. Display All Pets\n"
                         << "3. Find Pet\n"
                         << "4. Update Pet\n"
                         << "5. Get Number of Pets\n"
                         << "6. Exit\n"
                         << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            clinic->addPet(&myPet1);
                            clinic->addPet(&myPet2);
                            cout << "\nAdded pets\n";
                            break;
                        }
                        case 2: {
                            clinic->displayAllPets();
                            break;
                        }
                        case 3: {
                            string petID;
                            cout << "\nEnter Pet ID to find: ";
                            cin >> petID;
                            clinic->findPet(petID);
                            break;
                        }
                        case 4: {
                            PersonInfo updatedOwner("Updated", "Owner", "Name", personAddress, "01/01/2000", 'M', 30,
                                                    "9876543210", "updated@example.com");
                            PetInfo updatedPetInfo("Updated Pet Name", "Updated Species", "Updated Color", "987654321",
                                                   "Updated Breed",
                                                   2.5, 'M', true, false, true, &updatedOwner);

                            vector<string> updatedOrgans = {"Updated Organ1", "Updated Organ2"};
                            Disease updatedDisease1("Updated Disease Name 1", true, "Updated Disease Description 1",
                                                    updatedOrgans, "1");
                            Disease updatedDisease2("Updated Disease Name 2", false, "Updated Disease Description 2",
                                                    updatedOrgans, "2");

                            vector<Disease *> updatedDiseases;
                            updatedDiseases.push_back(&updatedDisease1);
                            updatedDiseases.push_back(&updatedDisease2);

                            PatientHistory updatedPatientHistory;
                            updatedPatientHistory.addDisease(updatedDisease1);
                            updatedPatientHistory.addDisease(updatedDisease2);

                            Pet updatedPet("789", updatedDiseases, updatedPatientHistory, false, updatedPetInfo);

                            clinic->updatePet("456", updatedPet);
                            break;
                        }
                        case 5: {
                            cout << "Total number of pets: " << clinic->getNumberOfPets() << endl;
                            break;
                        }
                        case 6: {
                            cout << "Exiting program\n";
                            break;
                        }
                        default:
                            cout << "Invalid choice. Enter a valid option.\n";
                    }
                } while (choice != 6);

                break;
            }
            case 5: {
                PersonInfo petOwner("Noor", "Rizz", "Rizwan", personAddress, "07/01/1980", 'F', 20,
                                          "1234567890", "noor@example.com");
                Cat myCat("Fluffy", "Cat", "White", "123456789", "Persian", 2.5, 'F', false, true, false,
                          &petOwner, true, "Long");

                // Displaying pet information
                cout << "Pet Information:\n";
                myCat.displayPetInfo();
                cout << "Making cat sound:\n";
                myCat.makeSound();
            }
            case 6:
                cout << "Exiting";
                return 0;
            default:
                break;
        }
    } while (c != 6);
    delete personAddress;
    return 0;
}
