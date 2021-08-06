#include <iostream>
#include "test_simulation.h"
#include "flight.h"
#include "aircraft.h"
#include "CrewMember.h"

// test simulation being a part of tests prepared to test the project behaviour
void test_simulation()
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "CREATING AN AIRPLANE AND A FLIGHT INSTANCES" << std::endl;
    Aircraft plane("123", "abc", 50, 10);
    CrewMember capt("FNAME", "LNAME", 10, 55, "captain");
    Flight test_flight(
        plane,
        capt,
        "2000.01.01-10:00:00",
        "2000.01.01-11:00:00",
        "RADOM",
        "BRZYDGOSZCZ",
        11,
        1,
        -30,
        300
    );

    std::cout << "--------------------------------" << std::endl;
    std::cout << test_flight.getFlightParams();

    std::cout << "--------------------------------" << std::endl;
    std::cout << "GET GATE NUMBER" << std::endl;
    std::cout << test_flight.getGateNumber() << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "CREATING PASSENGER INSTANCES" << std::endl;
    Passenger test_passenger_business("name", "surname", 10, 1, 11, 1, true);
    Passenger test_passenger_eco("name", "surname", 10, 2, 11, 12, false);

    std::cout << "--------------------------------" << std::endl;
    std::cout << "RESERVE SEATS VALID" << std::endl;
    std::cout << "test_flight.reserveSeat(test_passenger_business): ";
    std::cout << test_flight.reserveSeat(test_passenger_business) << std::endl;
    std::cout << "test_flight.reserveSeat(test_passenger_eco): ";
    std::cout << test_flight.reserveSeat(test_passenger_eco) << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "CHECK SEATS VALID" << std::endl;
    std::cout << "test_flight.checkBusinessSeat(test_passenger_business.getPlaceNum()): ";
    std::cout << test_flight.checkBusinessSeat(test_passenger_business.getPlaceNum()) << std::endl;
    std::cout << "test_passenger_business.getPlaceNum(): ";
    std::cout << test_passenger_business.getPlaceNum() << std::endl;
    std::cout << "test_flight.checkEcoSeat(test_passenger_eco.getPlaceNum()): ";
    std::cout << test_flight.checkEcoSeat(test_passenger_eco.getPlaceNum()) << std::endl;
    std::cout << "test_passenger_eco.getPlaceNum(): ";
    std::cout << test_passenger_eco.getPlaceNum() << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "CHECK SEATS OCCUPANCY AFTER RESERVING THE SEATS" << std::endl;
    std::cout << "test_flight.checkBusinessSeat(test_passenger_business.getPlaceNum()): ";
    std::cout << test_flight.checkBusinessSeat(test_passenger_business.getPlaceNum()) << std::endl;
    std::cout << "test_flight.checkEcoSeat(test_passenger_eco.getPlaceNum()): ";
    std::cout << test_flight.checkEcoSeat(test_passenger_eco.getPlaceNum()) << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "RESERVE SEATS ABOUVE MAXIMUM" << std::endl;
    test_passenger_business.setPlaceNum(100);
    test_passenger_eco.setPlaceNum(100);
    std::cout << "test_passenger_business.setPlaceNum(100);" << std::endl;
    std::cout << "test_passenger_eco.setPlaceNum(100);" << std::endl;
    std::cout << "test_flight.reserveSeat(test_passenger_business): ";
    std::cout << test_flight.reserveSeat(test_passenger_business) << std::endl;
    std::cout << "test_flight.reserveSeat(test_passenger_eco): ";
    std::cout << test_flight.reserveSeat(test_passenger_eco) << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "CAPTAIN METHODS" << std::endl;
    CrewMember new_capt("FNAME", "LNAME", 16, 65, "captain");
    std::cout << "test_flight.setCaptain(new_capt): " << test_flight.setCaptain(new_capt) << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "ADD CREW MEMBER" << std::endl;
    CrewMember new_member("Adam", "Siadam", 10, 77, "pilot");
    std::cout << "CrewMember new_member(\"Adam\", \"Siadam\", 10, 77, \"pilot\");" << std::endl;
    std::cout << "test_flight.addCrewMember(new_member): ";
    std::cout << test_flight.addCrewMember(new_member) << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "BOARDING PASS VALID" << std::endl;
    std::cout << "test_flight.getBoardingPass(1):\n";
    std::cout << test_flight.getBoardingPass(1) << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "BOARDING PASS VALID" << std::endl;
    std::cout << "test_flight.getBoardingPass(2):\n";
    std::cout << test_flight.getBoardingPass(2) << std::endl;

    std::cout << "--------------------------------" << std::endl;
    std::cout << "BOARDING PASS INVALID" << std::endl;
    std::cout << "test_flight.getBoardingPass(22):\n";
    std::cout << test_flight.getBoardingPass(22) << std::endl;

    std::cout << "--------------------------------" << std::endl;
}