#include <iostream>
#include "flight.h"
#include "check_data.h"

// constructor for class Flight
Flight::Flight(
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
) : plane(pl), captain(capt) {
    setFlightNumber(flight_num);
    setGateNumber(gate);
    setCaptain(capt);
    setDepartureTime(departure_t);
    setLandingTime(landing_t);
    setDeparturePlace(departure_pl);
    setDestination(destination_pl);
    setBusinessSeatPrice(business_seat_pr);
    setEcoSeatPrice(eco_seat_pr);
}

// setter for plane
bool Flight::setPlane(Aircraft new_plane)
{
    // new plane must have at least the same number of seats
    // in order to accomodate all passengers
    if (new_plane.getEcoSeats() >= plane.getEcoSeats() &&
        new_plane.getBusinessSeats() >= plane.getBusinessSeats())
    {
        plane = new_plane;
        return true;
    }

    return false;
}

// getter for plane
Aircraft Flight::getPlane()
{
    return plane;
}

// setter for flight_number
bool Flight::setFlightNumber(int flight_num)
{
    if (flight_num > 0)
    {
        flight_number = flight_num;
        return true;
    }

    flight_number = 0;
    return false;
}

// getter for flight_number
int Flight::getFlightNumber()
{
    return flight_number;
}

// setter for gate_number
bool Flight::setGateNumber(int gate)
{
    if (gate > 0)
    {
        gate_number = gate;
        return true;
    }

    gate_number = 0;
    return false;
}

// getter for gate_number
int Flight::getGateNumber()
{
    return gate_number;
}

// setter for eco_seat_price
bool Flight::setEcoSeatPrice(int new_price)
{
    if (new_price > 0)
    {
        eco_seat_price = new_price;
        return true;
    }

    eco_seat_price = 0;
    return false;
}

// getter for eco_seat_price
int Flight::getEcoSeatPrice()
{
    return eco_seat_price;
}

// setter for business_seat_price
bool Flight::setBusinessSeatPrice(int new_price)
{
    if (new_price > 0)
    {
        business_seat_price = new_price;
        return true;
    }

    business_seat_price = 0;
    return false;
}

// getter for business_seat_price
int Flight::getBusinessSeatPrice()
{
    return business_seat_price;
}

// setter for departure_time
bool Flight::setDepartureTime(std::string new_time)
{
    if (checkDateCorrectness(new_time))
    {
        departure_time = new_time;
        return true;
    }

    departure_time = "INVALID_DATA";
    return false;
}

// getter for departure_time
std::string Flight::getDepartureTime()
{
    return departure_time;
}

// setter for landing_time
bool Flight::setLandingTime(std::string new_time)
{
    if (checkDateCorrectness(new_time))
    {
        landing_time = new_time;
        return true;
    }

    landing_time = "INVALID_DATA";
    return false;
}

// getter for landing_time
std::string Flight::getLandingTime()
{
    return landing_time;
}

// setter for departure_place
bool Flight::setDeparturePlace(std::string new_place)
{
    if (checkIfOnlyLetters(new_place))
    {
        departure_place = new_place;
        return true;
    }

    departure_place = "INVALID_DATA";
    return false;
}

// getter for departure_place
std::string Flight::getDeparturePlace()
{
    return departure_place;
}

// setter for destination
bool Flight::setDestination(std::string new_place)
{
    if (checkIfOnlyLetters(new_place))
    {
        destination = new_place;
        return true;
    }

    destination = "INVALID_DATA";
    return false;
}

// getter for destination
std::string Flight::getDestination()
{
    return destination;
}

// getter for business_seats
std::map <int, Passenger> Flight::getBusinessSeats()
{
    return business_seats;
}

// getter for eco_seats
std::map <int, Passenger> Flight::getEconomicSeats()
{
    return eco_seats;
}

// checks whether business class seat with given id is free
// returns true if is free
bool Flight::checkBusinessSeat(int id)
{
    if (business_seats[id].getId() != 0)
    {
        return false;
    }

    return true;
}

// checks whether eco class seat with given id is free
// returns true if is free
bool Flight::checkEcoSeat(int id)
{
    if (eco_seats[id].getId() != 0)
    {
        return false;
    }

    return true;
}

// allows for the reservation of seats for Passenger class objects
// returns true is complited successfully
// otherwise returns false
bool Flight::reserveSeat(Passenger new_passenger)
{
    if (new_passenger.getSeatClass())
    {
        if (new_passenger.getPlaceNum() <= plane.getBusinessSeats())
        {
            if (business_seats[new_passenger.getPlaceNum()].getPlaceNum() == 0)
            {
                if (passengers[new_passenger.getId()].getId() == 0)
                {
                    business_seats[new_passenger.getPlaceNum()] = new_passenger;
                    passengers[new_passenger.getId()] = new_passenger;

                    if (new_passenger.getAssistant())
                    { addAssistPassenger(new_passenger); }

                    return true;
                }
            }
        }
    }
    else
    {
        if (new_passenger.getPlaceNum() <= plane.getEcoSeats())
        {
            if (passengers[new_passenger.getId()].getId() == 0)
            {
                eco_seats[new_passenger.getPlaceNum()] = new_passenger;
                passengers[new_passenger.getId()] = new_passenger;

                if (new_passenger.getAssistant())
                { addAssistPassenger(new_passenger); }

                return true;
            }
        }
    }

    return false;
}

// allows passengers to change their seat
bool Flight::changeSeat(Passenger &check_passenger, int new_seat_num, bool new_seat_class)
{
    // checking new seat class
    if (new_seat_class) {
        // new seat class is business class

        // checking if asked place number in business class is free
        if (checkBusinessSeat(new_seat_num)) {
            // asked place number in business class is free

            // getting current seat class
            if (check_passenger.getSeatClass()) {
                // current seat class is business

                // checking the range of the new seat number
                if (plane.getBusinessSeats() >= new_seat_num) {
                    business_seats[check_passenger.getPlaceNum()] = Passenger();
                    check_passenger.setPlaceNum(new_seat_num);
                    business_seats[new_seat_num] = check_passenger;
                    return true;
                }
            }
            else {
                // current seat class is eco class

                // checking the range of the new seat number
                if (plane.getBusinessSeats() >= new_seat_num) {
                    eco_seats[check_passenger.getPlaceNum()] = Passenger();
                    check_passenger.setPlaceNum(new_seat_num);
                    check_passenger.setSeatClass(new_seat_class);
                    business_seats[new_seat_num] = check_passenger;
                    return true;
                }
            }
        }
    }
    else {
        // new seat class is eco class

        // checking if asked place number in eco class is free
        if (checkEcoSeat(new_seat_num)) {
            // asked place number in eco class is free

            // getting current seat class
            if (check_passenger.getSeatClass()) {
                // current seat class is business

                // checking the range of the new seat number
                if (plane.getEcoSeats() >= new_seat_num) {
                    business_seats[check_passenger.getPlaceNum()] = Passenger();
                    check_passenger.setPlaceNum(new_seat_num);
                    check_passenger.setSeatClass(new_seat_class);
                    eco_seats[new_seat_num] = check_passenger;
                    return true;
                }
            }
            else {
                // current seat class is eco class

                // checking the range of the new seat number
                if (plane.getEcoSeats() >= new_seat_num) {
                    eco_seats[check_passenger.getPlaceNum()] = Passenger();
                    check_passenger.setPlaceNum(new_seat_num);
                    eco_seats[new_seat_num] = check_passenger;
                    return true;
                }
            }
        }
    }

    return false;
}

// setter for captain
bool Flight::setCaptain(CrewMember new_capt)
{
    if (new_capt.getRole() == "captain")
    {
        captain = new_capt;

        crew_members[captain.getId()] = new_capt;

        return true;
    }

    return false;
}

// allows for the addition of CrewMember class objects to crew_members
// returns true is complited successfully
// otherwise returns false
CrewMember Flight::getCaptain()
{
    return captain;
}

bool Flight::addCrewMember(CrewMember new_member)
{
    // 0 is default id for instances of class Crew
    // it means that the instance was created only to check whether
    // any object connected with its id existed in the map
    if (crew_members[new_member.getId()].getId() == 0 &&
        new_member.getRole() != "captain")
    {
        crew_members[new_member.getId()] = new_member;
        return true;
    }

    return false;
}

// getter for the list of Flight parameters
std::string Flight::getFlightParams()
{
    std::string params = "FLIGHT PARAMETERS:\n";
    params = params + ("FLIGHT NUMBER: " + std::to_string(flight_number) + '\n');
    params = params + ("DEPARTURE TIME: " + departure_time + '\n');
    params = params + ("DEPARTURE PLACE: " + departure_place + '\n');
    params = params + ("LANDING TIME: " + landing_time + '\n');
    params = params + ("DESTINATION: " + destination + '\n');
    params = params + ("BUSINESS SEATS NUMBER: " + std::to_string(plane.getBusinessSeats()) + '\n');
    params = params + ("BUSINESS SEAT PRICE: " + std::to_string(business_seat_price) + '\n');
    params = params + ("ECO SEATS NUMBER: " + std::to_string(plane.getEcoSeats()) + '\n');
    params = params + ("ECO SEAT PRICE: " + std::to_string(eco_seat_price) + '\n');

    return params;
}

// returns the boarding pass of the passenger with given id
// if there is no passenger with given id returns empty string
std::string Flight::getBoardingPass(int passenger_id)
{
    std::string boarding_pass = "";

    // checking whether Passenger with given id is attached to this Flight object
    if (passengers[passenger_id].getId() != 0)
    {
        // checking which seat class the passenger with given id occupies
        if (business_seats[passengers[passenger_id].getPlaceNum()].getId() != 0)
        {
            boarding_pass = "BOARDING PASS\n";
            boarding_pass += "PASSENGER ID: ";
            boarding_pass += std::to_string(passengers[passenger_id].getId());
            boarding_pass += '\n';
            boarding_pass += "FLIGHT NUMBER: ";
            boarding_pass += std::to_string(flight_number);
            boarding_pass += '\n';
            boarding_pass += "SEAT CLASS: business class\n";
            boarding_pass += "SEAT NUMBER: ";
            boarding_pass += std::to_string(passengers[passenger_id].getPlaceNum());
            boarding_pass += '\n';
            boarding_pass += "GATE NUMBER: ";
            boarding_pass += std::to_string(gate_number);
            boarding_pass += '\n';
        }
        else
        {
            if (eco_seats[passengers[passenger_id].getPlaceNum()].getId() != 0)
            {
                boarding_pass = "BOARDING PASS\n";
                boarding_pass += "PASSENGER ID: ";
                boarding_pass += std::to_string(passengers[passenger_id].getId());
                boarding_pass += '\n';
                boarding_pass += "FLIGHT NUMBER: ";
                boarding_pass += std::to_string(flight_number);
                boarding_pass += '\n';
                boarding_pass += "SEAT CLASS: eco class\n";
                boarding_pass += "SEAT NUMBER: ";
                boarding_pass += std::to_string(passengers[passenger_id].getPlaceNum());
                boarding_pass += '\n';
                boarding_pass += "GATE NUMBER: ";
                boarding_pass += std::to_string(gate_number);
                boarding_pass += '\n';
            }
        }
    }

    return boarding_pass;
}

void Flight::addAssistPassenger(Passenger new_passenger)
{ assist_passengers.push_back(new_passenger); }

std::vector <Passenger> Flight::getAssistPassengers()
{ return assist_passengers; }

std::ostream& operator<<(std::ostream& os, Flight& fl) {
    os << fl.getFlightParams() << std::endl;
    return os;
}
