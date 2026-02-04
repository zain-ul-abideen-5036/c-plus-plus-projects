#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int countWordsInFile(const string& fileName){

	ifstream file(fileName);
	if (!file.is_open()){
		cout << "Error in opening file " << fileName << endl;
		return -1;
	}

	int wordCount{ 0 };
	string wordString;

	while (file >> wordString){

		wordCount++;

	}
	
	file.close();
	return wordCount;

}


int main(){

	string nameOfFile;
	int wordCount{};

	cout << "Enter name of File." << endl;
	cin >> nameOfFile;
	cout << endl;

	wordCount = countWordsInFile(nameOfFile);

	if (wordCount >= 0){

		cout << "Total count of words in file " << "'" << nameOfFile << "' : " << wordCount << endl;
		
	}


	system("pause");
	return 0;
}