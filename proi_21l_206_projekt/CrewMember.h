#ifndef CREWMEMBER_H
#define CREWMEMBER_H
#include <iostream>
#include "Person.h"

/**
 * Crewmember is derived from person, made to represent to well, itself
 *
 * Class is expanded version of person in a way it can better represent a crewmember of a plane
 * by that it means it can hold various data about who passenger has crewmember is on a plane
 */

class CrewMember : public Person {
private:
	std::string m_role;

public:
	CrewMember(
		std::string name = "NODATA",
		std::string surname = "NODATA",
		int age = 0,
		int id = 0,
		std::string role = "assistant");
	void setRole(std::string role);
	std::string getRole();
	friend std::ostream& operator<<(std::ostream& os, CrewMember& cm);

	std::string getDescription();
};


#endif