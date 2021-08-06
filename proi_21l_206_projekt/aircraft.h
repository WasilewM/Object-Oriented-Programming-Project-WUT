#pragma once

#include <iostream>
#include <string>
#include <vector>

class Aircraft {
private:
    std::string number;
    std::string model;

    int eco_seats;
    int business_seats;


    std::vector<std::string> eco_facilities;
    std::vector<std::string> business_facilities;


public:
    // constructor for class Aircraft
    Aircraft(std::string num, std::string mod, int e_seats, int b_seats);
    // getter for aircraft number
    std::string getNumber();
    // getter for aircraft model
    std::string getModel();
    // setter for aircraft number
    void setNumber(std::string new_num);
    // setter for aircraft model
    void setModel(std::string new_model);
    // getter for aircraft eco seats number
    int getEcoSeats();
    // getter for aircraft business seats number
    int getBusinessSeats();
    // setter for aircraft eco seats number
    void setEcoSeats(int new_eseats);
    // setter for aircraft business seats number
    void setBusinessSeats(int new_bseats);
    // getter for eco facilities list
    std::vector<std::string> getEcoFacilities();
    // getter for business facilities list
    std::vector<std::string> getBusinessFacilities();
    // setter for eco facilities list
    void setEcoFacilities(std::vector<std::string> new_efac);
    // setter for business facilities list
    void setBusinessFacilities(std::vector<std::string> new_bfac);
    // returns short description of aircraft
    std::string shortDescription();
    // adds facility to eco facilities list
    void addEcoFacility(std::string facility);
    // adds facility to business facilities list
    void addBusinessFacility(std::string facility);
    // removes eco facility with given index
    void removeEcoFacility(unsigned int index);
    // removes business facility with given index
    void removeBusinessFacility(unsigned int index);
    // returns full description of aircraft
    std::string getDescription();
    // overloaded operator<< for class aircraft
    friend std::ostream& operator<<(std::ostream& os, Aircraft& ac);
};