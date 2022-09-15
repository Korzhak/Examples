#include "StudentsList.h"

using namespace std;


StudentsList::StudentsList(string filePath) {
	ifstream studentFile(filePath);
	string lineContents;

	while (!studentFile.eof()) {
		getline(studentFile, lineContents);
		students.push_back(Student(lineContents));
	}
	studentFile.close();
}


vector<Student> StudentsList::getStudents() {
	return this->students;
}


void StudentsList::WriteDataToFile(vector<Student> new_students, string filePath) {
	ofstream outFile(filePath);
	for (auto& student : new_students) {
		outFile << student.getName() << ";" << student.getAge() << ";" << student.getId() << ";";
		outFile << student.getAverageScore() << ";" << student.getEmail() << endl;
	}
	outFile.close();
}

vector<Student> StudentsList::sortingByName() {
	vector<Student> copy_students;
	copy(this->students.begin(), this->students.end(), back_inserter(copy_students));

	sort(copy_students.begin(), copy_students.end(), [](Student &s1, Student &s2) {
		return s1.getName() < s2.getName();
		});
	return copy_students;
}


vector<Student> StudentsList::getGmail() {
	vector<Student> copy_students;
	copy_if(students.begin(), students.end(), back_inserter(copy_students), [](Student& s) {
			static const regex r(R"([\w\.]+@(gmail.com))");
			return regex_match(s.getEmail(), r);
		});

	return copy_students;

	
}

vector<Student> StudentsList::getUniqByName() {
	vector<Student> copy_students;
	copy(this->students.begin(), this->students.end(), back_inserter(copy_students));
	auto iter = unique(copy_students.begin(), copy_students.end(), [](Student& s1, Student& s2) {
		return s1.getFirstName() == s2.getFirstName();
		});
	copy_students.erase(iter, copy_students.end());
	return copy_students;
}