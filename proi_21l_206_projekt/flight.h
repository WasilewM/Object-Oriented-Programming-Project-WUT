#pragma once

#include <vector>
#include <map>
#include <string>
#include "aircraft.h"
#include "CrewMember.h"
#include "Passenger.h"

/**
 * Flight is a class written for connecting all the things alltogether
 *
 * It is made to connect aircraft, crewmembers and passengers
 */

class Flight
{
private:
    // represents the Aircraft attached to the instance of class Flight
    Aircraft plane;
    // represents the captain attached to the instance of class Flight
    // it is a titled CrewMember instance due to the fact that only one
    // captain can be assigned to the Flight
    CrewMember captain;

    // representats departure time in format yyyy.mm.dd-hh:mm:ss
    // if invalid data is given to the setter, value is set ot "INVALID_DATA"
    std::string departure_time;
    // representats landing time in format yyyy.mm.dd-hh:mm:ss
    // if invalid data is given to the setter, value is set ot "INVALID_DATA"
    std::string landing_time;
    // represents the name of the departure place, cannot be empty
    // if invalid data is given to the setter, value is set ot "INVALID_DATA"
    std::string departure_place;
    // represents the name of the destination place, cannot be empty
    // if invalid data is given to the setter, value is set ot "INVALID_DATA"
    std::string destination;

    // represents the flight number, must be positive
    // if is equal to 0 it means that invalid value was given to the setter
    int flight_number;
    // represents the gate number, must be positive
    // if is equal to 0 it means that invalid value was given to the setter
    int gate_number;
    // represents the price of eco class seat, must be positive
    // if is equal to 0 it means that invalid value was given to the setter
    int eco_seat_price;
    // represents the price of business class seat, must be positive
    // if is equal to 0 it means that invalid value was given to the setter
    int business_seat_price;

    // contains the crew members attached to the instance of class Flight
    std::map <int, CrewMember> crew_members;
    // represents the occupancy business class seats in the Airplane attached to class Flight
    std::map <int, Passenger> business_seats;
    // represents the occupancy eco class seats in the Airplane attached to class Flight
    std::map <int, Passenger> eco_seats;
    // represents the Passenger objects attached to object of class Flight
    std::map <int, Passenger> passengers;
    // contains Passengers that requested assistance
    std::vector <Passenger> assist_passengers;
public:
    // constructor for class Flight
    Flight(
        Aircraft pl,
        CrewMember capt,
        std::string departure_t,
        std::string landing_t,
        std::string departure_pl,
        std::string destination_pl,
        int flight_num,
        int gate,
        int eco_seat_pr,
        int business_seat_pr
    );

    // setter for plane
    bool setPlane(Aircraft new_plane);
    // getter for plane
    Aircraft getPlane();

    // setter for flight_number
    bool setFlightNumber(int flight_num);
    // getter for flight_number
    int getFlightNumber();

    // setter for gate_number
    bool setGateNumber(int gate);
    // getter for gate_number
    int getGateNumber();

    // setter for eco_seat_price
    bool setEcoSeatPrice(int new_price);
    // getter for eco_seat_price
    int getEcoSeatPrice();

    // setter for business_seat_price
    bool setBusinessSeatPrice(int new_price);
    // getter for business_seat_price
    int getBusinessSeatPrice();

    // setter for departure_time
    bool setDepartureTime(std::string new_time);
    // getter for departure_time
    std::string getDepartureTime();

    // setter for landing_time
    bool setLandingTime(std::string new_time);
    // getter for landing_time
    std::string getLandingTime();

    // setter for departure_place
    bool setDeparturePlace(std::string new_place);
    // getter for departure_place
    std::string getDeparturePlace();

    // setter for destination
    bool setDestination(std::string new_place);
    // getter for destination
    std::string getDestination();

    // getter for business_seats
    std::map <int, Passenger> getBusinessSeats();
    // getter for eco_seats
    std::map <int, Passenger> getEconomicSeats();

    // checks whether business class seat with given id is free
    // returns true if is free
    bool checkBusinessSeat(int id);
    // checks whether eco class seat with given id is free
    // returns true if is free
    bool checkEcoSeat(int id);

    // allows for the reservation of seats for Passenger class objects
    // returns true if complited successfully
    // otherwise returns false
    bool reserveSeat(Passenger new_passenger);

    // allows passengers to change their seat
    bool changeSeat(Passenger &check_passenger, int new_seat_num, bool new_seat_class);

    // setter for captain
    bool setCaptain(CrewMember new_capt);
    // getter for captain
    CrewMember getCaptain();

    // allows for the addition of CrewMember class objects to crew_members
    // returns true is complited successfully
    // otherwise returns false
    bool addCrewMember(CrewMember new_member);

    // returns the list of Flight parameters
    std::string getFlightParams();

    // returns the boarding pass of the passenger with given id
    // if there is no passenger with given id returns empty string
    std::string getBoardingPass(int passenger_id);

    // allows for adding the Passenger objects to the vector representing
    // Passengers that requested assistance
    void addAssistPassenger(Passenger new_passenger);
    // getter for assist passengers
    std::vector <Passenger> getAssistPassengers();

    friend std::ostream& operator<<(std::ostream& os, Flight& fl);
};
