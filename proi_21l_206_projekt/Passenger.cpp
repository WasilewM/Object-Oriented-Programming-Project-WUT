#include <iostream>
#include <string>
#include "Passenger.h"

// derived constrctor, in addition to new data
Passenger::Passenger(
	std::string name,
	std::string surname,
	int age,
	int id,
	int flight_id,
	int new_place_num,
	bool if_first_class,
	int carry_on_w,
	int suitcase_w,
	bool assist
) : Person(name, surname, age, id) {
	setName(name, surname);
	setAge(age);
	setId(id);
	setFlightId(flight_id);
	setPlaceNum(new_place_num);
	setSeatClass(if_first_class);

	setCarryOnWeight(carry_on_w);
	setSuitcaseWeight(suitcase_w);
	setAssistant(assist);
}

// setter checking whether flight id is ok
void Passenger::setFlightId(int flight_id) {
	if (flight_id > 0) {
		m_flight_id = flight_id;
	}
	else {
		m_flight_id = 0;
	}
}
// id getter
int Passenger::getFlightId() {
	return m_flight_id;
}

// setter checking whether place number is fine
void Passenger::setPlaceNum(int new_place_num) {
	if (new_place_num > 0) {
		place_num = new_place_num;
	}
	else {
		place_num = 0;
	}
}

// place num getter
int Passenger::getPlaceNum() {
	return place_num;
}

// setter whether passenger is in first class or nah
void Passenger::setSeatClass(bool if_first_class) {
	first_class = if_first_class;
}

// class getter true if first/false otherwise
bool Passenger::getSeatClass() {
	return first_class;
}

// checking if passengers belongings are within acceptable range
bool Passenger::checkWeight(int weight, int max_acceptable_w) {
	if (weight >= 0 && weight <= max_acceptable_w) {
		return true;
	}

	return false;
}
// setter for the weight passenger can carry
void Passenger::setCarryOnWeight(int weight) {
	if (checkWeight(weight)) {
		carry_on_weight = weight;
	}

	carry_on_weight = 0;
}

// getter of the weight
int Passenger::getCarrryOnWeight() {
	return carry_on_weight;
}

// suitcase weight setter
void Passenger::setSuitcaseWeight(int weight) {
	if (checkWeight(weight)) {
		suitcase_weight = weight;
	}

	suitcase_weight = 0;
}

// suitcase weight getter
int Passenger::getSuitcaseWeight() {
	return suitcase_weight;
}
// answers the question, whether the passenger has carry on luggage
bool Passenger::hasCarryOn() {
	if (carry_on_weight > 0) {
		return true;
	}

	return false;
}
// answers the question, whether the passenger has suitcase
bool Passenger::hasSuitcase() {
	if (suitcase_weight > 0) {
		return true;
	}

	return false;
}
// setter  for assistant
void Passenger::setAssistant(bool new_assist) {
	assistant = new_assist;
}
// getter  for assistant
bool Passenger::getAssistant() {
	return assistant;
}

std::ostream& operator<<(std::ostream& os, Passenger& ps) {
	os << ps.getDescription() << std::endl;
	return os;
}

std::string Passenger::getDescription() {
	std::string description = "PASSENGER DATA:\n";
	description += getName() + " " + getSurname() + "; ";
	description += std::string("ID: ") + std::to_string(getId());
	description += std::string(" Age: ") + std::to_string(getAge()) + '\n';

	description += std::string("FLGIHT NUM: ") + std::to_string(getFlightId()) + "; ";
	if (getSeatClass()) {
		description += std::string("CLASS: Business") + '\n';
	}
	else {
		description += std::string("CLASS: Economic") + '\n';
	}

	description += std::string("Place number: ") + std::to_string(getPlaceNum()) + '\n';;
	description += std::string("Suitcase weight: ") + std::to_string(getSuitcaseWeight()) + "; ";
	description += std::string("Carry on weight: ") + std::to_string(getCarrryOnWeight()) + '\n';

	if (getAssistant()) description += std::string("Assistance requested");

	return description;
}
