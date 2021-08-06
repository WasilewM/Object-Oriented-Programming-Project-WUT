#include <iostream>
#include "CrewMember.h"
#include "check_data.h"

CrewMember::CrewMember(
	std::string name,
	std::string surname,
	int age,
	int id,
	std::string role
) : Person(name, surname, age, id) {
	setName(name, surname);
	setAge(age);
	setId(id);
	setRole(role);
}

void CrewMember::setRole(std::string role) {
	if (checkPosition(role)) {
		m_role = role;
	}
	else {
		m_role = "INVALID_DATA";
	}
}

std::string CrewMember::getRole() {
	return m_role;
}

std::ostream& operator<<(std::ostream& os, CrewMember& cm) {
	os << cm.getDescription() << std::endl;
	return os;
}

std::string CrewMember::getDescription() {
	std::string description = "";
	description += getRole() + " " + getName() + " " + getSurname() + '\n';
	description += std::string("ID: ") + std::to_string(getId());
	description += std::string(" Age: ") + std::to_string(getAge()) + '\n';

	return description;
}