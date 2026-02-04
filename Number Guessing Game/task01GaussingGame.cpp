#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    //Declaring and Initilizing variable
	int secretNumber = {};
	int guessInput = {};
	int numberOfAttempts = { 0 };

	srand(static_cast<unsigned int>(time(0)));

	//Genrate a random variable
	secretNumber = rand() % 10 + 1;

	cout << "            Welcome to the Guessing Game!" << endl;
	cout << "You have to picked a number between 1 and 10. Try to guess it!" << endl;
	cout << endl;

	do {

		cout << "Enter your guess: ";
		cin >> guessInput;
		numberOfAttempts++;

		//If guess number is less than 1 or greater than 10
		if (guessInput < 1 || guessInput > 10)
		{

			cout << "Error: Please enter guess input between (1 - 10)." << endl;
			cout << endl;
		}
		//If guess number is greater than secret number
		else if (guessInput > secretNumber)
		{

			cout << "Input Again: Too High....." << endl;
			cout << "Hint: Try a smaller number." << endl;
			cout << endl;
		}
		//If guess number is less than secret number
		else if (guessInput < secretNumber)
		{

			cout << "Input Again: Too Low....." << endl;
			cout << "Hint: Try a greater number." << endl;
			cout << endl;
		}
		//If guess number is equal to secret number 
		else
		{

			cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << numberOfAttempts << " attempts." << std::endl;
		}

		//If guess number is not equal to secret number
	} while (guessInput != secretNumber);


	system("pause");
	return 0;
}