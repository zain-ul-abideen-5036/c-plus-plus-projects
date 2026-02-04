#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100; // Maximum number of students to handle

struct Student {
	string name;
	int id;
	double assignmentScore;
	double quizScore;
	double examScore;
	double overallGrade;
	string letterGrade;
	string feedback;
};

// Function to save student data to a file
void saveStudentData(const Student& student) {
	ofstream outFile("student_data.txt", ios::app);
	if (outFile.is_open()) {
		outFile << student.name << "  " << student.id << "  "
			<< student.assignmentScore << "  " << student.quizScore << "  "
			<< student.examScore << "  " << student.overallGrade << "  "
			<< student.letterGrade << "  " << student.feedback << "\n";
		outFile.close();
	}
	else {
		cerr << "Unable to open the file for saving data." << endl;
	}
}

int main() {

	Student students[MAX_STUDENTS];
	int numStudents = 0;
	char addAnotherStudent;

	do {
		Student student;
		cout << "Enter student name: ";
		cin >> student.name;
		cout << "Enter student ID: ";
		cin >> student.id;
		cout << "Enter assignment score (0-100): ";
		cin >> student.assignmentScore;
		cout << "Enter quiz score (0-100): ";
		cin >> student.quizScore;
		cout << "Enter exam score (0-100): ";
		cin >> student.examScore;
		cout << endl;

		// Calculate overall grade, letter grade, and feedback
		student.overallGrade = ((student.assignmentScore * 0.3) + (student.quizScore * 0.2) + (student.examScore * 0.5));


		// Grade Assign
		if (student.overallGrade >= 90) {
			student.letterGrade = "A";
			student.feedback = "Congratulations! Excellent performance!";
		}
		else if (student.overallGrade >= 80) {
			student.letterGrade = "B";
			student.feedback = "Good job, but there is room for improvement.";
		}
		else if (student.overallGrade >= 70) {
			student.letterGrade = "C";
			student.feedback = "Satisfactory performance.";
		}
		else if (student.overallGrade >= 50) {
			student.letterGrade = "D";
			student.feedback = "You need to work harder to improve your grade.";
		}
		else {
			student.letterGrade = "F";
			student.feedback = "You failed.";
		}

		// Add the student to the array
		students[numStudents++] = student;

		// Save student data to a file
		saveStudentData(student);

		cout << "Student added successfully.\n";
		cout << "Do you want to add another student? (y/n): ";
		cin >> addAnotherStudent;
		cout << endl;
	} while (addAnotherStudent == 'y' || addAnotherStudent == 'Y');


	// Display student results
	cout << "\n<-----Student Results----->\n";
	cout << endl;
	for (int i = { 0 }; i < numStudents; ++i) {
		cout << "Name: " << students[i].name << "\n";
		cout << "ID: " << students[i].id << "\n";
		cout << "Overall Grade: " << students[i].overallGrade << "\n";
		cout << "Letter Grade: " << students[i].letterGrade << "\n";
		cout << "Feedback: " << students[i].feedback << "\n\n";
	}


	system("pause");
	return 0;
}
