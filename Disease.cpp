#include "Disease.h"

Disease::Disease()
{
    name = "";
    critical = false;
    description = "";
    diseaseId="";
}

Disease::Disease(const string &n, const bool &c, const string &des, const vector<string> &affectedOrg, string disID)
{
    name = n;
    critical = c;
    description = des;
    affectedOrgans = affectedOrg;
    diseaseId=disID;
}

string Disease::getDiseaseId(){
    return diseaseId;
}

void Disease::setDiseaseId(int dId){
    diseaseId=dId;
}

string Disease::getName()
{
    return name;
}

string Disease::getDescription()
{
    return description;
}

bool Disease::getCriticality()
{
    return critical;
}

vector<string> Disease::getAffectedOrgans()
{
    return affectedOrgans;
}

void Disease::setName(string n)
{
    name = n;
}

void Disease::setDescription(string d)
{
    description = d;
}

void Disease::setCriticality(bool c)
{
    critical = c;
}

void Disease::displayInfo()
{
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Critical: ";
    if (critical)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    cout << "Affected Organs: ";
    for (const string &organ : affectedOrgans)
    {
        cout << organ << ", ";
    }
    cout << endl;
}

ostream &operator<<(ostream &os, const Disease &other)
{
    os << "Name: " << other.name << endl;
    os << "Description: " << other.description << endl;
    os << "Critical: ";
    if (other.critical)
    {
        os << "Yes" << endl;
    }
    else
    {
        os << "No" << endl;
    }
    os << "Affected Organs: ";
    for (const string &organ : other.affectedOrgans)
    {
        os << organ << ", ";
    }

    os << "\n\n";
    return os;
}

Disease Disease::operator+(const Disease &other)
{
    bool overallCriticality = true;
    if (!critical && !other.critical)
    {
        overallCriticality = false;
    }
    vector<string> combinedOrgans = affectedOrgans;
    combinedOrgans.insert(combinedOrgans.end(), other.affectedOrgans.begin(), other.affectedOrgans.end());

    return Disease(name + " + " + other.name, overallCriticality, description + " + " + other.description, combinedOrgans, diseaseId +" + " + other.diseaseId);
}

Disease *Disease::getUserInput()
{
    string n;
    string d;
    bool c;
    vector<string> affOrg;
    string disId;

    cout<<"Enter the disease ID: ";
    cin>>disId;
    cin.ignore();
    
    cout << "Enter the name of the disease: ";
    getline(cin, n);
    cin.ignore();

    cout << "\nIs the disease critical? Enter 1 if Yes and 0 if No: ";
    cin >> c;
    cin.ignore();

    cout << "\nEnter the description of the disease: ";
    getline(cin, d);

    cout << "\nEnter the affected organs (enter 'end' when done) ";
    while (true)
    {
        string o;

        cout << "->";

        getline(cin, o);
        if (o == "end")
        {
            break;
        }

        affOrg.push_back(o);
    }

    return new Disease(n, c, d, affOrg, disId);
}