#include <iostream>
using namespace std;

const int ROWS = 5;         // Number of rows in the theater
const int COLS = 5;         // Number of seats per row
const double TICKET_PRICE = 10.0;  // Price per ticket

class MovieTicketBookingSystem {
private:

	bool seatMatrix[ROWS][COLS]; // Matrix to represent seat availability

public:

	MovieTicketBookingSystem() {
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				seatMatrix[i][j] = true;
			}
		}
	}

	void showMovieListings() {
		cout << "------ Movie Listings ------" << endl;
		// Code to display available movie listings goes here
		cout << "1. Movie A" << endl;
		cout << "2. Movie B" << endl;
		cout << "3. Movie C" << endl;
		std::cout << "---------------------------" << std::endl;
	}

	bool isSeatAvailable(int row, int col) {
		return seatMatrix[row][col];
	}

	void markSeatAsBooked(int row, int col) {
		seatMatrix[row][col] = false;
	}

	void displaySeatMatrix() {
		cout << "------ Seat Matrix ------" << endl;
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				cout << (seatMatrix[i][j] ? "O " : "X ");
			}
			cout << endl;
		}
		cout << "-------------------------" << endl;
	}

	double calculateTotalCost(int numTickets) {
		return numTickets * TICKET_PRICE;
	}

};

int main() {

	MovieTicketBookingSystem ticketSystem;
	int row, col;
	int numTickets;
	int movieChoice;

	cout << "Welcome to the Movie Ticket Booking System!" << endl;

	// Display movie listings
	ticketSystem.showMovieListings();

	// Let the user select a movie
	cout << "Enter the movie number you want to watch: ";
	cin >> movieChoice;

	// Assume movieChoice validation and other user inputs are handled properly.
	// Display seat matrix
	ticketSystem.displaySeatMatrix();

	// Let the user select seats and book tickets
	cout << "Enter the row and column number of the seat you want to book: ";
	cin >> row >> col;

	if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
		if (ticketSystem.isSeatAvailable(row, col)) {
			cout << "Enter the number of tickets you want to book: ";
			cin >> numTickets;

			if (numTickets > 0) {
				double totalCost = ticketSystem.calculateTotalCost(numTickets);
				ticketSystem.markSeatAsBooked(row, col);
				cout << "Tickets booked successfully!" << endl;
				cout << "Total cost: $" << totalCost << endl;
			}
			else {
				cout << "Invalid number of tickets. Please enter a positive integer." << endl;
			}
		}
		else {
			cout << "Selected seat is not available. Please select another seat." << endl;
		}
	}
	else {
		cout << "Invalid seat selection. Please select a valid row and column number." << endl;
	}

	system("pause");
	return 0;
}
