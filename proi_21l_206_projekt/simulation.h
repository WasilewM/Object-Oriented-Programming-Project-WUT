#pragma once
#include <vector>
#include <map>
#include "aircraft.h"
#include "CrewMember.h"
#include "flight.h"
#include "Passenger.h"

/**
 * Simulation is a class written in purpose of simulating working airport
 * It works with randomness, so any try to run it will wield different results
 * 
 */

class Data {
public:
	Data(int time_intervals = 0, int clekrs_number = 3);
	std::vector <Aircraft> getAircrafts();
	std::vector <CrewMember> getCrewMembers();
	std::vector <Flight> getFlights();
	std::vector <Passenger> getPassengers();

	Flight getFlightByNum(int flight_num);

private:
	std::vector <Aircraft> aircrafts;
	std::vector <CrewMember> crew_members;
	std::vector <CrewMember> captains;
	std::vector <Flight> flights;
	std::vector <Passenger> passengers;
	std::map <int, bool> passengers_id_map;

	std::vector <int> flight_nums;
	std::vector < std::string> names;
	std::vector < std::string> surnames;

	int convert_str_to_int(std::string value);
	bool convert_str_to_bool(std::string value);
	std::vector<std::string> splitString(const std::string& s, const char& separator);

	void importAircrafts();
	void importCrewMembers();
	void importFlights();
	void importPassengers();

	void simulate(int time_intervals=0, int clerks_number =3);
};
