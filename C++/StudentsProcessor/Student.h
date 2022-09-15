#pragma once
#include <iostream>
#include <sstream>


class Student
{
	std::string firstName;
	std::string lastName;
	int age;
	int id;
	double averageScore;
	std::string email;

public:
	Student(std::string studentInformation);
	std::string getFirstName();
	std::string getLastName();
	std::string getName();
	std::string getEmail();
	int getId();
	int getAge();
	double getAverageScore();
};

