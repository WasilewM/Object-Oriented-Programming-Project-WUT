#include <iostream>
#include <vector>
#include <string>
#include "aircraft.h"

using namespace std;

// constructor for class Aircraft
Aircraft::Aircraft(string num, string mod, int e_seats, int b_seats) {
    number = num;
    model = mod;
    eco_seats = e_seats;
    business_seats = b_seats;
}
// getter for aircraft number
string Aircraft::getNumber() {
    return number;
}
// getter for aircraft model
string Aircraft::getModel() {
    return model;
}
// setter for aircraft number
void Aircraft::setNumber(string new_num) {
    number = new_num;
}
// setter for aircraft model
void Aircraft::setModel(string new_model) {
    model = new_model;
}
// getter for aircraft eco seats number
int Aircraft::getEcoSeats() {
    return eco_seats;
}
// getter for aircraft business seats number
int Aircraft::getBusinessSeats() {
    return business_seats;
}
// setter for aircraft eco seats number
void Aircraft::setEcoSeats(int new_eseats) {
    eco_seats = new_eseats;
}
// setter for aircraft business seats number
void Aircraft::setBusinessSeats(int new_bseats) {
    business_seats = new_bseats;
}
// getter for eco facilities list
vector<string> Aircraft::getEcoFacilities() {
    return eco_facilities;
}
// getter for business facilities list
vector<string> Aircraft::getBusinessFacilities() {
    return business_facilities;
}
// setter for eco facilities list
void Aircraft::setEcoFacilities(vector<string> new_efac) {
    eco_facilities = new_efac;
}
// setter for business facilities list
void Aircraft::setBusinessFacilities(vector<string> new_bfac) {
    business_facilities = new_bfac;
}
// adds facility to eco facilities list
void Aircraft::addEcoFacility(std::string facility) {
    eco_facilities.push_back(facility);
}
// adds facility to business facilities list
void Aircraft::addBusinessFacility(std::string facility) {
    business_facilities.push_back(facility);
}
// removes eco facility with given index
void Aircraft::removeEcoFacility(unsigned int index) {
    eco_facilities.erase(eco_facilities.begin() + index);
}
// removes business facility with given index
void Aircraft::removeBusinessFacility(unsigned int index) {
    business_facilities.erase(business_facilities.begin() + index);
}
// returns short description of aircraft
string Aircraft::shortDescription() {
    return(model + " Num: " + number);
}
// overloaded operator<< for class aircraft
ostream& operator<<(ostream& os, Aircraft& ac) {
    os << ac.getDescription() << endl;
    return os;
}
// returns full description of aircraft
string Aircraft::getDescription() {
    string description = "";
    description += model + " Num: " + number + '\n';
    description += string("Number of eco seats: ") + to_string(eco_seats) + '\n';
    description += string("Number of business seats: ") + to_string(business_seats) + '\n';

    if (!eco_facilities.empty()) {
        description += "Economic class facilities:\n";
        for (const auto& facility : eco_facilities)
            description += '-' + facility + '\n';
    }
    if (!business_facilities.empty()) {
        description += "Business class facilities:\n";
        for (const auto& facility : business_facilities)
            description += '-' + facility + '\n';
    }
    return description;
}