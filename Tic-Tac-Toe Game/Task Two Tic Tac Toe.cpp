#include <iostream>
#include<string>

using namespace std;

// Function to initialize the game board
void initializeBoard(char board[3][3]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board[i][j] = ' ';
		}
	}
}

// Function to display the game board
void displayBoard(const char board[3][3]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << board[i][j];
			if (j < 2) cout << " | ";
		}
		cout << endl;
		if (i < 2) cout << "---------" << endl;
	}
	cout << endl;
}

// Function to check if a player has won
bool checkWin(const char board[3][3], char player) {
	// Check rows
	for (int i = 0; i < 3; ++i) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
			return true;
		}
	}

	// Check columns
	for (int j = 0; j < 3; ++j) {
		if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
			return true;
		}
	}

	// Check diagonals
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return true;
	}
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		return true;
	}

	return false;
}

// Function to check if the game ended in a draw
bool checkDraw(const char board[3][3]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == ' ') {
				return false; // There are empty spaces, the game is not a draw
			}
		}
	}
	return true; // All cells are filled, the game is a draw
}

// Function to get a valid player move
void getPlayerMove(char board[3][3], char player) {
	int row, col;
	while (true) {
		cout << "Player " << player << ", enter your move (row and column): ";
		cin >> row >> col;

		if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
			board[row - 1][col - 1] = player;
			break;
		}
		else {
			cout << "Invalid move. Please try again." << endl;
		}
	}
}

int main() {
	char board[3][3];
	char currentPlayer = 'X';
	bool gameover = false;

	initializeBoard(board);

	while (!gameover) {
		displayBoard(board);
		getPlayerMove(board, currentPlayer);

		if (checkWin(board, currentPlayer)) {
			displayBoard(board);
			cout << "Player " << currentPlayer << " wins!" << endl;
			gameover = true;
		}
		else if (checkDraw(board)) {
			displayBoard(board);
			cout << "It's a draw!" << endl;
			gameover = true;
		}
		else {
			currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
		}
	}

	cout << "Do you want to play again? (yes/no): ";
	string playAgain;
	cin >> playAgain;

	if (playAgain == "yes") {
		main(); // Restart the game
	}
	else {
		cout << "Thanks for playing!" << endl;
	}


	system("pause");
	return 0;
}
