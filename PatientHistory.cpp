#include "PatientHistory.h"

PatientHistory::PatientHistory() {
    familyDiseaseHistory = false;
    diseaseCount = 0;
}

void PatientHistory::addDisease(const Disease &disease) {
    diseaseHistory.push_back(disease);
    diseaseCount++;
}

void PatientHistory::addSurgery(const string &sur) {
    prevSurgeries.push_back(sur);
}

vector<string> PatientHistory::getPrevSurgeries(){
        return prevSurgeries;
}

bool PatientHistory::getFamilyDiseaseHistory(){
        return familyDiseaseHistory;
}

void PatientHistory::setFamilyDiseaseHistory(bool hasFamilyDisease) {
    familyDiseaseHistory = hasFamilyDisease;
}

void PatientHistory::displayPatientHistory() {
    cout << "Patient disease history:" << endl;
    for (int i = 0; i < diseaseHistory.size(); i++) {
        const Disease &disease = diseaseHistory[i];
        cout << "Disease " << i + 1 << endl;
        cout << disease << endl;
    }
    cout << "Family disease history:";
    if (familyDiseaseHistory) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << "Previous surgeries: ";
    for (const string &surgery: prevSurgeries) {
        cout << surgery << ", ";
    }
    cout << endl;
    cout << "\nTotal diseases: " << diseaseCount << endl;
}


ostream &operator<<(ostream &oo, const PatientHistory &pH) {

    oo << "Patient disease history:" << endl;
    for (int i = 0; i < pH.diseaseHistory.size(); i++) {
        const Disease &disease = pH.diseaseHistory[i];
        oo << "Disease " << i + 1 << endl;
        oo << disease << endl
           << endl;
    }
    oo << "Family disease history:";
    if (pH.familyDiseaseHistory) {
        oo << "Yes" << endl;
    } else {
        oo << "No" << endl;
    }
    oo << "Previous surgeries: ";
    for (const string &surgery: pH.prevSurgeries) {
        oo << surgery << ", ";
    }
    oo << endl;
    oo << "\nTotal diseases: " << pH.diseaseCount << endl;

    return oo;
}

void PatientHistory::savePatientHistory(const string &filename) const {
    ifstream inFile(filename);
    json j;
    if (!inFile.is_open()) {
        cout << "Can't open file" << endl;
        return;
    }
    inFile >> j;
    inFile.close();
    for (int i = 0; i < diseaseHistory.size(); i++) {
        Disease disease = diseaseHistory[i];
        json js;
        js["Name"] = disease.getName();
        js["Description"] = disease.getDescription();
        js["Critical"] = disease.getCriticality() ? "Yes" : "No";
        js["Affected Organs"] = disease.getAffectedOrgans();
        j["Disease " + to_string(i + 1)] = js;
    }
    j["Familiy disease History"] = familyDiseaseHistory ? "Yes" : "No";
    json jso;
    for (const string &surgery: prevSurgeries) {
        jso.push_back(surgery);
    }
    j["Previous Surgeries"] = jso;
    j["Total dieseases"] = diseaseCount;


    ofstream out(filename);
    if (out.is_open()) {
        out << setw(1) << j << endl;
        out.close();
        cout << "Patient History stored successfully" << endl;
    } else {
        cout << "Couldn't open file" << endl;
    }
}

PatientHistory &PatientHistory::operator+=(const PatientHistory &other) {
    diseaseHistory.insert(diseaseHistory.end(), other.diseaseHistory.begin(), other.diseaseHistory.end());
    familyDiseaseHistory = familyDiseaseHistory || other.familyDiseaseHistory;
    prevSurgeries.insert(prevSurgeries.end(), other.prevSurgeries.begin(), other.prevSurgeries.end());
    diseaseCount += other.diseaseCount;

    return *this;
}