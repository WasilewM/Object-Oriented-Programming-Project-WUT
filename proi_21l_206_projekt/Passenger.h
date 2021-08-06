#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include "Person.h"

/**
 * Passenger is derived from person, made to represent to well, itself
 *
 * Class is expanded version of person in a way it can better represent a passenger of a plane
 * by that it means it can hold various data about what passenger has boarding a plane, what he wants
 * or even check if what he wants is available
 */

class Passenger : public Person {
private:
	int m_flight_id;
	int place_num;
	int carry_on_weight;
	int suitcase_weight;
	bool first_class;
	bool assistant;
public:
	// derived constrctor, in addition to new data
	Passenger(
		std::string name = "NODATA",
		std::string surname = "NODATA",
		int age = 0,
		int id = 0,
		int flight_id = 0,
		int new_place_num = 0,
		bool if_first_class = false,
		int carry_on_w = 0,
		int suitcase_w = 0,
		bool assist = false
	);
	// setter checking whether flight id is ok
	void setFlightId(int flight_id);
	// id getter
	int getFlightId();
	// setter checking whether place number is fine
	void setPlaceNum(int new_place_num);
	// place num getter
	int getPlaceNum();
	// setter whether passenger is in first class or nah
	void setSeatClass(bool if_first_class);
	// class getter true if first/false otherwise
	bool getSeatClass();
	// checking if passengers belongings are within acceptable range
	bool checkWeight(int weight, int max_acceptable_w = 20);
	// setter for the weight passenger can carry
	void setCarryOnWeight(int weight);
	// getter of the weight
	int getCarrryOnWeight();
	// suitcase weight setter
	void setSuitcaseWeight(int weight);
	// suitcase weight getter
	int getSuitcaseWeight();
	// answers the question, whether the passenger has carry on luggage
	bool hasCarryOn();
	// answers the question, whether the passenger has suitcase
	bool hasSuitcase();
	// setter  for assistant
	void setAssistant(bool new_assist);
	// getter  for assistant
	bool getAssistant();

	friend std::ostream& operator<<(std::ostream& os, Passenger& ps);

	std::string getDescription();
};

#endif