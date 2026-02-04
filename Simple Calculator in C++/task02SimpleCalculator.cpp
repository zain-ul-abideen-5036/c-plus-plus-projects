#include<iostream>
using namespace std;

//Addition Function
template<typename T>
T addition(T firstValue, T secondValue){
	
	return firstValue + secondValue;
}

//Subtraction Function
template<typename T>
T subtraction(T firstValue, T secondValue){

	return firstValue - secondValue;
}

//Multiplication Function
template<typename T>
T multiplication(T firstValue, T secondValue){

	return firstValue*secondValue;
}

//Division Function
template<typename T>
T division(T firstValue, T secondValue){

	if (secondValue == 0){
		cout << "Error: Can't Divide By Zero. " << endl;
	}
	else{
	
		return firstValue / secondValue;

	}

}

//Display Function
template<typename T>
void displayResult(T result){

	cout << "Result: " << result << endl;
}

int main()
{
	//Declaring and Initilizing Variables 
	char operationToPerform;
	double firstInput{};
	double secondInput{};
	double result{};

	//Takeing Inputs From User
	cout << "Enter you'r first Input: " << endl;
	cin >> firstInput;

	cout << endl;

	cout << "Enter you'r second Input: " << endl;
	cin >> secondInput;

	cout << endl;

	//Input For Operation To Perform
	cout << "Enter you'r operation to perform: " << endl;
	cout << endl;
	cout << "  **************************  " << endl;
	cout << "  *  1. Addition[+]        *  " << endl;
	cout << "  *  2. Subtraction[-]     *  " << endl;
	cout << "  *  3. Multiplication[*]  *  " << endl;
	cout << "  *  4. Division[/]        *  " << endl;
	cout << "  **************************  " << endl;
	cout << endl;
	cin >> operationToPerform;


	switch (operationToPerform)
	{
	case '+':
	{
				result = addition(firstInput, secondInput);
				break;
	}
	case '-':
	{
				result = subtraction(firstInput, secondInput);
				break;
	}
	case '*':
	{
				result = multiplication(firstInput, secondInput);
				break;
	}
	case '/':
	{
				result = division(firstInput, secondInput);
				break;
	}
	default:
	{
			   cout << "Error: Invalid Operation Selected. " << endl;
			   break;
	}
		
	}

	if (operationToPerform == '+' || operationToPerform == '-' || operationToPerform == '*' || operationToPerform == '/'){
		displayResult(result);
	}
	else{
		result = -1;
		displayResult(result);
	}
	

	system("pause");
	return 0;
}