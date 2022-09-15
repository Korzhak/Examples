#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <regex>
#include "Student.h"


class StudentsList
{
	std::vector<Student> students;

public:
	StudentsList(std::string filePath);
	std::vector<Student> getStudents();
	void WriteDataToFile(std::vector<Student> new_students, std::string filePath);
	std::vector<Student> sortingByName();
	std::vector<Student> getGmail();
	std::vector<Student> getUniqByName();
};

