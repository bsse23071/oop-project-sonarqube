//
// Created by noorr on 4/3/2024.
//
#include "Address.h"

//Default Constructor
Address::Address() {
    plotNo = 0;
    sector = ' ';
    city = " ";
    society = " ";

}

//Parametrized Constructor
Address::Address(const int &plotNo, const char &sector, const string &city, const string &society) {
    this->plotNo = plotNo;
    this->sector = sector;
    this->city = city;
    this->society = society;

}

//Destructor
Address::~Address() {

}

int Address::getPlotNo() const {
    return plotNo;
}

char Address::getSector() const {
    return sector;

}

string Address::getCity() const {
    return city;
}

string Address::getSociety() const {
    return society;
}

void Address::setPlotNo(int p) { plotNo = p; }

void Address::setSector(char s) { sector = s; }

void Address::setCity(const string c) { city = c; }

void Address::setSociety(const string s) { society = s; }

json Address::to_json() const
{
    json j;
    j = json{
        {"plotNo", this->getPlotNo()},
        {"sector", string(1, this->getSector())}, // Convert char to string for JSON
        {"city", this->getCity()},
        {"society", this->getSociety()}};

    return j;
}
bool Address::isValid() const {
    return (plotNo != 0 && !city.empty() && !society.empty());
}

Address &Address::operator=(const Address &other) {
    if (this != &other) {
        plotNo = other.plotNo;
        sector = other.sector;
        city = other.city;
        society = other.society;
    }
    return *this;
}



void Address::saveToJson(const string &filename) const {
    json j;
    to_json(); 

    ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
        cout << "Address saved to " << filename << endl;
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void Address::displayAddress() {
    cout << "Address: " << endl;
    cout << "Plot No: " << plotNo << endl;
    cout << "Sector: " << sector << endl;
    cout << "City: " << city << endl;
    cout << "Society: " << society << endl;
}

