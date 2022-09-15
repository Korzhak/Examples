
#include <iostream>
#include "Student.h"
#include "StudentsList.h"

using namespace std;


void ShowStudent(Student student) {
	cout << "Name:\t" << student.getName() << "\tAge:\t" << student.getAge() << "\tId:\t" << student.getId();
	cout << "\tAverage Score:\t" << student.getAverageScore() << "\tEmail:\t" << student.getEmail() << endl;
	cout << "------------------------------" << endl;
}


int main()
{
	StudentsList sl("C:\\Users\\student\\Downloads\\students.txt");

	/*for (auto student : sl.getStudents())
		ShowStudent(student);
	*/
	
	sl.WriteDataToFile(sl.getStudents(), "C:\\Users\\student\\Downloads\\out.csv");

	sl.WriteDataToFile(sl.sortingByName(), "C:\\Users\\student\\Downloads\\by_name.csv");

	sl.WriteDataToFile(sl.getGmail(), "C:\\Users\\student\\Downloads\\by_name.csv");
	
	sl.WriteDataToFile(sl.getUniqByName(), "C:\\Users\\student\\Downloads\\uniq.csv");
	return 0;
}




