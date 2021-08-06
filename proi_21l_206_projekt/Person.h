#ifndef PERSON_H
#define PERSON_H
#include <iostream>

/**
 * Parent class made for passenger and crewmember
 *
 * Person is basically a base constructor used by it's deriveds
 * the purpose of it is to make code work smoother
 */

class Person {
protected:
	std::string m_name;
	std::string m_surname;
	int m_age;
	int m_id;

public:
	// basic constroctor using setters
	Person(std::string name, std::string surname, int age, int id);
	// setter for name and surname checking whether data is correct
	void setName(std::string name, std::string surname);
	// setter of age checking if age is negative
	void setAge(int age);
	// id setter, id must be uns
	void setId(int id);
	// basic descriptor of a person member
	void introduce();
	// getters below
	int getId();
	int getAge();
	std::string getName();
	std::string getSurname();
};
#endif