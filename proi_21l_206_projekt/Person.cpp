#include <iostream>
#include "Person.h"
#include "check_data.h"

// basic constroctor using setters
Person::Person(std::string name, std::string surname, int age, int id) {
	setName(name, surname);
	setAge(age);
	setId(id);
}

// setter for name and surname checking whether data is correct
void Person::setName(std::string name, std::string surname) {
	if (checkIfOnlyLetters(name)) {
		m_name = name;
	}
	else {
		m_name = "INVALID_DATA";
	}

	if (checkIfOnlyLetters(surname)) {
		m_surname = surname;
	}
	else {
		surname = "INVALID_DATA";
	}
}

// setter of age checking if age is negative
void Person::setAge(int age) {
	if (age > 0) {
		m_age = age;
	}
	else {
		m_age = 0;
	}
}

// id setter, id must be uns
void Person::setId(int id) {
	if (id > 0) {
		m_id = id;
	}
	else {
		m_id = 0;
	}
}

// basic descriptor of a person member
void Person::introduce() {
	std::cout << "Name: " << m_name << " " << m_surname << " Id: " << m_id << " Age: " << m_age << std::endl;
}

// getters below

int Person::getId() {
	return m_id;
}

int Person::getAge() {
	return m_age;
}

std::string Person::getName() {
	return m_name;
}

std::string Person::getSurname() {
	return m_surname;
}