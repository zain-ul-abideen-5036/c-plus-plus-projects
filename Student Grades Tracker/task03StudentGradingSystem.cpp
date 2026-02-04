#include <iostream>
#include <string>
using namespace std;
const int MAX_STUDENTS = 100;

int main() {

	string name;
	string grade;
	string studentNames[MAX_STUDENTS];
	string studentGrades[MAX_STUDENTS];
	int numStudents = {};
	double sumGrades = { 0.0 };
	string highestGrade;
	string lowestGrade;
	double averageGrade;


	while (numStudents < MAX_STUDENTS) {
		
		cout << "Enter student name (or 'b' to quit): ";
		getline(cin, name);

		if (name == "b") {
			break;
		}

		cout << "Enter student grade (A, B, C, D, F) : ";
		getline(cin, grade);

		studentNames[numStudents] = name;
		studentGrades[numStudents] = grade;
		numStudents++;
	}

	if (numStudents == 0) {
		cout << "No students entered. Exiting program." << endl;
		return 0;
	}

	// Calculate the average grade
	for (int i = 0; i < numStudents; i++) {

		// Convert string grades to numeric if needed (e.g., A = 90, B = 80, etc.)
		int numericGrade = 100 - (studentGrades[i][0] - 'A') * 10;
		sumGrades += numericGrade;
	}

	//Average formula
	averageGrade = sumGrades / numStudents;

	// Find the highest and lowest grades
	highestGrade = studentGrades[0];
	lowestGrade = studentGrades[0];

	for (int i = 1; i < numStudents; i++) {
		if (studentGrades[i] < highestGrade) {
			highestGrade = studentGrades[i];
		}
		if (studentGrades[i] > lowestGrade) {
			lowestGrade = studentGrades[i];
		}
	}
	cout << endl;

	cout << "\n----- Student Grades Summary -----" << endl;
	cout << endl;

	for (int i = 0; i < numStudents; i++) {
		cout << studentNames[i] << ": " << studentGrades[i] << endl;
	}
	cout << endl;

	cout << "Average Grade: " << averageGrade << endl;
	cout << endl;

	cout << "Highest Grade: " << highestGrade << endl;
	cout << "Lowest Grade: " << lowestGrade << endl;


	system("pause");
	return 0;
}
