#ifndef JANASHEEN_PATIENT_HISTORY_H
#define JANASHEEN_PATIENT_HISTORY_H

#include "Disease.h"

class PatientHistory {
private:
    vector<Disease> diseaseHistory;
    bool familyDiseaseHistory;
    vector<string> prevSurgeries;
    int diseaseCount;
public:

    PatientHistory();

    void setFamilyDiseaseHistory(bool hasFamilyDisease);

    bool getFamilyDiseaseHistory();

    vector<string> getPrevSurgeries();

    void addDisease(const Disease &disease);

    void addSurgery(const string &sur);

    void displayPatientHistory();

    void savePatientHistory(const string& filename)const;

    PatientHistory& operator+=(const PatientHistory& other);
    
    friend ostream &operator<<(ostream &oo, const PatientHistory &pH);
};

#endif