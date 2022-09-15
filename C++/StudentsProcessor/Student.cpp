#include "Student.h"

using namespace std;


Student::Student(string studentInformation) {
	stringstream studentsStream(studentInformation);
	studentsStream >> this->firstName;
	studentsStream >> this->lastName;
	studentsStream >> this->age;
	studentsStream >> this->id;
	studentsStream >> this->averageScore;
	studentsStream >> this->email;
}


string Student::getFirstName() {
	return this->firstName;
}


string Student::getLastName() {
	return this->lastName;
}

string Student::getName() {
	return getFirstName() + " " + getLastName();
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

int Student::getId() {
	return this->id;
}

double Student::getAverageScore() {
	return this->averageScore;
}
