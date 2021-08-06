#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include "simulation.h"

#define AC_DATA_PATH "data/aircrafts.csv"
#define CM_DATA_PATH "data/crew_members.csv"
#define FL_DATA_PATH "data/flights.csv"
#define PS_DATA_PATH "data/passengers.csv"
#define SIM_LOG_PATH "data/simulation_log.txt"
// const value set to be the delay time between information printed on the screen
const int TIME_DELAY = 1500;
// macro used to make a delay between test to allow for easier reading of the results
#define wait() std::this_thread::sleep_for(std::chrono::milliseconds(TIME_DELAY));


Data::Data(int time_intervals, int clerks_number) {	
	std::ofstream sim_file;
	sim_file.open(SIM_LOG_PATH, 'w');
	sim_file.close();

	importAircrafts();
	wait();
	importCrewMembers();
	wait();
	importFlights();
	wait();
	importPassengers();
	wait();
	simulate(time_intervals, clerks_number);
}

int Data::convert_str_to_int(std::string value) {
	//simple conversion to double from string
	int number;
	try {
		number = std::stoi(value);
	}
	catch (std::invalid_argument const& e) {
		std::cout << "Wrong input value" << std::endl;
		return -1;
	}
	catch (std::out_of_range const& e) {
		std::cout << "Value out of range" << std::endl;
		return -1;
	}
	return number;
}

bool Data::convert_str_to_bool(std::string value) {
	if (value == "true") return true;
	else return false;
}

std::vector<std::string> Data::splitString(const std::string& s, const char& separator) {
	//function splits string to vector of strings by given separator
	std::string buff = "";
	std::vector <std::string> splitted;

	for (auto n : s) {
		if (n != separator) buff += n;
		else if (n == separator && buff != "") {
			splitted.push_back(buff);
			buff = "";
		}
	}
	if (buff != "") splitted.push_back(buff);

	return splitted;
}

std::vector <Aircraft> Data::getAircrafts() {
	return aircrafts;
}

std::vector <CrewMember> Data::getCrewMembers() {
	return crew_members;
}

std::vector <Flight> Data::getFlights() {
	return flights;
}

std::vector <Passenger> Data::getPassengers() {
	return passengers;
}

Flight Data::getFlightByNum(int flight_num) {
	for (auto flight : flights) {
		if (flight.getFlightNumber() == flight_num) return flight;
	}
}

void Data::importAircrafts() {
	std::vector <std::string> data_line;
	std::ifstream ac_file;
	std::ofstream sim_file;
	std::string line;
		
	ac_file.open(AC_DATA_PATH);
	sim_file.open(SIM_LOG_PATH, std::ofstream::out | std::ofstream::app);

	std::cout << "-----------------------------------" << std::endl;
	sim_file << "-----------------------------------" << std::endl;
	std::cout << "LOADING AIRCRAFTS" << std::endl;
	sim_file << "LOADING AIRCRAFTS" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	sim_file << "-----------------------------------" << std::endl;

	while (getline(ac_file, line)) {
		data_line = splitString(line, ',');
		Aircraft aircraft(
			data_line[0],
			data_line[1],
			convert_str_to_int(data_line[2]),
			convert_str_to_int(data_line[3])
		);
		aircrafts.push_back(aircraft);
		std::cout << "LOADED AIRCRAFT" << std::endl;
		sim_file << "LOADED AIRCRAFT" << std::endl;
		std::cout << aircraft << std::endl;
		sim_file << aircraft << std::endl;
	}
	std::cout << std::endl;
	sim_file << std::endl;
	ac_file.close();
	sim_file.close();
}

void Data::importCrewMembers() {
	std::vector <std::string> data_line;
	std::ifstream cm_file;
	std::ofstream sim_file;
	std::string line;

	cm_file.open(CM_DATA_PATH);
	sim_file.open(SIM_LOG_PATH, std::ofstream::out | std::ofstream::app);

	std::cout << "-----------------------------------" << std::endl;
	sim_file << "-----------------------------------" << std::endl;
	std::cout << "LOADING CREW MEMBERS" << std::endl;
	sim_file << "LOADING CREW MEMBERS" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	sim_file << "-----------------------------------" << std::endl;

	while (getline(cm_file, line)) {
		data_line = splitString(line, ',');
		CrewMember crew_member(
			data_line[0],
			data_line[1],
			convert_str_to_int(data_line[2]),
			convert_str_to_int(data_line[3]),
			data_line[4]
		);
		// creating data set for random part of the simulation
		names.push_back(data_line[0]);
		surnames.push_back(data_line[1]);

		if (crew_member.getRole() == "captain") {
			captains.push_back(crew_member);
		}
		crew_members.push_back(crew_member);
		std::cout << "LOADED CREW MEMBER" << std::endl;
		sim_file << "LOADED CREW MEMBER" << std::endl;
		std::cout << crew_member << std::endl;
		sim_file << crew_member << std::endl;
	}
	std::cout << std::endl;
	sim_file << std::endl;
	cm_file.close();
	sim_file.close();
}

void Data::importFlights() {
	std::vector <std::string> data_line;
	std::ifstream fl_file;
	std::ofstream sim_file;
	std::string line;

	fl_file.open(FL_DATA_PATH);
	sim_file.open(SIM_LOG_PATH, std::ofstream::out | std::ofstream::app);

	std::cout << "-----------------------------------" << std::endl;
	sim_file << "-----------------------------------" << std::endl;
	std::cout << "LOADING FLIGHTS" << std::endl;
	sim_file << "LOADING FLIGHTS" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	sim_file << "-----------------------------------" << std::endl;

	while (getline(fl_file, line)) {
		data_line = splitString(line, ',');
		Aircraft rand_ac = aircrafts[rand() % aircrafts.size()];
		CrewMember rand_cm = captains[rand() % captains.size()];
		Flight flight(
			rand_ac,
			rand_cm,
			data_line[0],
			data_line[1],
			data_line[2],
			data_line[3],
			convert_str_to_int(data_line[4]),
			convert_str_to_int(data_line[5]),
			convert_str_to_int(data_line[6]),
			convert_str_to_int(data_line[7])
		);
		flights.push_back(flight);
		flight_nums.push_back(flight.getFlightNumber());

		std::cout << "LOADED FLIGHT" << std::endl;
		sim_file << "LOADED FLIGHT" << std::endl;
		std::cout << flight << std::endl;
		sim_file << flight << std::endl;
	}
	std::cout << std::endl;
	sim_file << std::endl;

	// sorting flight number contained in flight_nums for letter use
	sort(flight_nums.begin(), flight_nums.end());

	fl_file.close();
	sim_file.close();
}

void Data::importPassengers() {
	std::vector <std::string> data_line;
	std::ifstream ps_file;
	std::ofstream sim_file;
	std::string line;

	ps_file.open(PS_DATA_PATH);
	sim_file.open(SIM_LOG_PATH, std::ofstream::out | std::ofstream::app);

	std::cout << "-----------------------------------" << std::endl;
	sim_file << "-----------------------------------" << std::endl;
	std::cout << "LOADING PASSENGERS" << std::endl;
	sim_file << "LOADING PASSENGERS" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	sim_file << "-----------------------------------" << std::endl;

	while (getline(ps_file, line)) {
		data_line = splitString(line, ',');
		int flight_num = convert_str_to_int(data_line[4]);
		
		if (std::find(flight_nums.begin(), flight_nums.end(), flight_num) != flight_nums.end()) {
			Passenger passenger(
				data_line[0],
				data_line[1],
				convert_str_to_int(data_line[2]),
				convert_str_to_int(data_line[3]),
				flight_num,
				convert_str_to_int(data_line[5]),
				convert_str_to_bool(data_line[6])
			);
			// creating data set for random part of the simulation
			names.push_back(data_line[0]);
			surnames.push_back(data_line[1]);
			
			// checking for duplicated passenger id values
			if (passengers_id_map[passenger.getId()] == true) {
				std::cout << "Duplicated passenger id detected." << std::endl;
				std::cout << "Data line will be omitted." << std::endl;
				sim_file << "Duplicated passenger id detected." << std::endl;
				sim_file << "Data line will be omitted." << std::endl;
			}
			else {
				std::cout << "LOADED PASSENGER" << std::endl;
				sim_file << "LOADED PASSENGER" << std::endl;
				std::cout << passenger << std::endl;
				sim_file << passenger << std::endl;

				Flight flight = getFlightByNum(flight_num);
				bool is_reserved = flight.reserveSeat(passenger);

				if (is_reserved) {
					passengers.push_back(passenger);
					passengers_id_map[passenger.getId()] = true;
					std::cout << "Seat reserved" << std::endl;
					sim_file << "Seat reserved" << std::endl;
					std::string bp = flight.getBoardingPass(passenger.getId());

					std::cout << "-----------------------------------" << std::endl;
					sim_file << "-----------------------------------" << std::endl;
					std::cout << bp << std::endl;
					sim_file << bp << std::endl;
					std::cout << "-----------------------------------" << std::endl;
					sim_file << "-----------------------------------" << std::endl;
				}
			}
		}
		else {
			std::cout << "Flight with number: " << flight_num << " does not exist" << std::endl;
			std::cout << "Passenger not registered" << std::endl;
			sim_file << "Flight with number: " << flight_num << " does not exist" << std::endl;
			sim_file << "Passenger not registered" << std::endl;
		}
	}
	std::cout << std::endl;
	sim_file << std::endl;

	ps_file.close();
	sim_file.close();
}

void Data::simulate(int time_intervals, int clerks_number)
{
	std::ofstream sim_file;
	sim_file.open(SIM_LOG_PATH, std::ofstream::out | std::ofstream::app);

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "SIMULATION" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	sim_file << "-----------------------------------" << std::endl;
	sim_file << "SIMULATION" << std::endl;
	sim_file << "-----------------------------------" << std::endl;
	
	int iteration_num = 1;
	while (iteration_num <= time_intervals) {
		std::cout << "Time interval number: " << std::to_string(iteration_num) << std::endl;
		std::cout << "Clerk number: " << std::to_string(rand() % clerks_number + 1) << std::endl;
		std::cout << "It's is turn of the Passenger:" << std::endl;

		sim_file << "Time interval number: " << std::to_string(iteration_num) << std::endl;
		sim_file << "Clerk number: " << std::to_string(rand() % clerks_number + 1) << std::endl;
		sim_file << "It's is turn of the Passenger:" << std::endl;

		// getting "random" Passenger data:
		std::string first_name = names[rand() % names.size()];
		std::string last_name = surnames[rand() % surnames.size()];
		int age = rand() % 100;
		bool if_id_correct = false;
		int id_number = 0;
		// checking id correctness in order to avoid duplicated values
		while (!if_id_correct) {
			id_number = rand() % 1000;

			if (passengers_id_map[id_number] == false) {
				if_id_correct = true;
			}
		}
		// getting "random" but correct flight number
		// flight number must be a number of one of the flights
		// contained in Data class instance
		int flight_idx = rand() % flight_nums.size();
		int fl_number = flight_nums[flight_idx];
		// getting rest of the params
		Flight current_flight = getFlightByNum(fl_number);
		int suitcase_w = rand() % 40;
		int carry_on_w = rand() % 25;
		// getting seat params
		bool seat_class = rand() % 2;
		int seat_number = 0;
		if (seat_class) {
			if (current_flight.getPlane().getBusinessSeats() != 0) {
				seat_number = rand() % current_flight.getPlane().getBusinessSeats() + 1;
			}
			else {
				seat_number = 0;
			}
		}
		else {
			if (current_flight.getPlane().getEcoSeats() != 0) {
				seat_number = rand() % current_flight.getPlane().getEcoSeats() + 1;
			}
			else {
				seat_number = 0;
			}
		}

		// creating passenger
		Passenger new_passenger(
			first_name,
			last_name,
			age,
			id_number,
			fl_number,
			seat_number,
			seat_class,
			carry_on_w,
			suitcase_w,
			false
		);
		std::cout << new_passenger << std::endl;
		sim_file << new_passenger << std::endl;

		// trying to reserve seat
		bool operation_result = current_flight.reserveSeat(new_passenger);

		if (operation_result) {
			// printing operation result
			std::cout << "Passenger successfully boarded." << std::endl;
			sim_file << "Passenger successfully boarded." << std::endl;
			// printing seat price
			if (seat_class) {
				std::cout << "Ticket price: ";
				std::cout << std::to_string(getFlightByNum(fl_number).getBusinessSeatPrice());
				std::cout << std::endl;

				sim_file << "Ticket price: ";
				sim_file << std::to_string(getFlightByNum(fl_number).getBusinessSeatPrice());
				sim_file << std::endl;
			}
			else {
				std::cout << "Ticket price: ";
				std::cout << std::to_string(getFlightByNum(fl_number).getEcoSeatPrice());
				std::cout << std::endl;

				sim_file << "Ticket price: ";
				sim_file << std::to_string(getFlightByNum(fl_number).getEcoSeatPrice());
				sim_file << std::endl;
			}

			passengers_id_map[id_number] = true;
			passengers.push_back(new_passenger);
			
		}
		else {
			std::cout << "Passenger could not be boarded." << std::endl;
			std::cout << "Probably due to the seat occupancy" << std::endl;

			sim_file << "Passenger could not be boarded." << std::endl;
			sim_file << "Probably due to the seat occupancy" << std::endl;
		}

		std::cout << "-----------------------------------" << std::endl;
		sim_file << "-----------------------------------" << std::endl;
		wait();

		// creating a "random" action of one of the boarded passengers
		// first one is an attempt to change seat
		// second one is asking for help
		enum random_actions {
			seat_change,
			ask_assistance,
			print_boarding_pass,
			print_flight_params,
			gate
		};
		int boarded_passenger_action = rand() % 5;
	
		if (boarded_passenger_action == random_actions::seat_change) {
			int passenger_num_in_vect = rand() % passengers.size();
			Passenger random_passenger = passengers[passenger_num_in_vect];
			current_flight = getFlightByNum(random_passenger.getFlightId());
			seat_class = rand() % 2;
			fl_number = random_passenger.getFlightId();

			if (seat_class) {
				if (current_flight.getPlane().getBusinessSeats() != 0) {
					seat_number = rand() % current_flight.getPlane().getBusinessSeats() + 1;
				}
				else {
					seat_number = 0;
				}
			}
			else {
				if (current_flight.getPlane().getEcoSeats() != 0) {
					seat_number = rand() % current_flight.getPlane().getEcoSeats() + 1;
				}
				else {
					seat_number = 0;
				}
			}
			
			Flight passenger_flight = getFlightByNum(fl_number);
			if (passenger_flight.changeSeat(random_passenger, seat_number, seat_class)) {
				std::cout << "Passeger with id: " << random_passenger.getId() << std::endl;
				std::cout << "has successfully changed seat" << std::endl;

				sim_file << "Passeger with id: " << random_passenger.getId() << std::endl;
				sim_file << "has successfully changed seat" << std::endl;

				random_passenger.setPlaceNum(seat_number);
				random_passenger.setSeatClass(seat_class);
				std::cout << random_passenger << std::endl;
				sim_file << random_passenger << std::endl;
			}
			else {
				std::cout << "Passeger with id: " << random_passenger.getId();
				std::cout << "could not changed seat" << std::endl;
				std::cout << random_passenger << std::endl;

				sim_file << "Passeger with id: " << random_passenger.getId();
				sim_file << "could not changed seat" << std::endl;
				sim_file << random_passenger << std::endl;
			}
		}
		else if (boarded_passenger_action == random_actions::ask_assistance) {
			int passenger_num_in_vect = rand() % passengers.size();
			Flight passenger_flight = getFlightByNum(fl_number);
			passenger_flight.addAssistPassenger(passengers[passenger_num_in_vect]);
			passengers[passenger_num_in_vect].setAssistant(true);
			
			std::cout << "Passenger asked for assistance:" << std::endl;
			std::cout << passengers[passenger_num_in_vect] << std::endl;

			sim_file << "Passenger asked for assistance:" << std::endl;
			sim_file << passengers[passenger_num_in_vect] << std::endl;
		}
		else if (boarded_passenger_action == random_actions::print_boarding_pass &&
			operation_result == true) {
			std::cout << "Passenger with id: " << id_number << std::endl;
			std::cout << "has requested their boarding pass:" << std::endl;
			std::cout << current_flight.getBoardingPass(id_number) << std::endl;

			sim_file << "Passenger with id: " << id_number << std::endl;
			sim_file << "has requested their boarding pass:" << std::endl;
			sim_file << current_flight.getBoardingPass(id_number) << std::endl;
		}
		else if (boarded_passenger_action == random_actions::print_flight_params) {
			std::cout << "Passenger with id: " << id_number << std::endl;
			std::cout << "has requested their flight params:" << std::endl;
			std::cout << current_flight.getFlightParams() << std::endl;

			sim_file << "Passenger with id: " << id_number << std::endl;
			sim_file << "has requested their flight params:" << std::endl;
			sim_file << current_flight.getFlightParams() << std::endl;
		}
		else if (boarded_passenger_action == random_actions::gate &&
			operation_result == true) {
			std::cout << "Checking departure gate number for flight id ";
			std::cout << current_flight.getFlightNumber() << std::endl;
			std::cout << "Gate number: " << current_flight.getGateNumber() << std::endl;

			sim_file << "Checking departure gate number for flight id ";
			sim_file << current_flight.getFlightNumber() << std::endl;
			sim_file << "Gate number: " << current_flight.getGateNumber() << std::endl;
		}

		std::cout << "-----------------------------------" << std::endl;
		sim_file << "-----------------------------------" << std::endl;
		wait();
		iteration_num++;
	}
	sim_file << std::endl;
	sim_file.close();
}