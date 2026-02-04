#include <iostream>
#include <string>

using namespace std;

const int MAX_CATALOG_SIZE = 100;

// Data structure to represent book information.
class Book
{
public:
	string title;
	string author;
	string ISBN;
	bool available;
};

Book libraryCatalog[MAX_CATALOG_SIZE];
int catalogSize = 0;

// User-friendly command-line interface using a menu-based system.
void displayMenu()
{
	cout << "Library Management System Menu:\n";
	cout << "1. Add Book\n";
	cout << "2. Remove Book\n";
	cout << "3. Check Availability\n";
	cout << "4. Display Catalog\n";
	cout << "5. Exit\n";
	cout << "Enter your choice: ";
}

// Function to add new books to the library catalog. Collect book details from the user and add the book to the catalog.
void addBook()
{
	if (catalogSize >= MAX_CATALOG_SIZE)
	{
		cout << "Catalog is full. Cannot add more books.\n";
		return;
	}

	Book newBook;
	cout << "Enter book title: ";
	cin.ignore();
	getline(cin, newBook.title);
	cout << "Enter author: ";
	getline(cin, newBook.author);
	cout << "Enter ISBN: ";
	cin >> newBook.ISBN;
	newBook.available = true;
	libraryCatalog[catalogSize++] = newBook;
	cout << "Book added successfully!\n";
	cout << endl;
}

// Function to remove books from the catalog based on criteria like title or ISBN. Ensure the availability status is updated accordingly.
void removeBook()
{
	string titleToRemove;
	cout << "Enter the title of the book to remove: ";
	cin.ignore();
	getline(cin, titleToRemove);

	for (int i = 0; i < catalogSize; ++i)
	{
		if (libraryCatalog[i].title == titleToRemove)
		{
			for (int j = i; j < catalogSize - 1; ++j)
			{
				libraryCatalog[j] = libraryCatalog[j + 1];
			}
			catalogSize--;
			cout << "Book removed successfully!\n";
			cout << endl;
			return;
		}
	}

	cout << "Book not found in the catalog.\n";
	cout << endl;
}

// Function to check the availability of a book by its title.
void checkAvailability()
{
	string searchTitle;
	cout << "Enter the title of the book: ";
	cin.ignore();
	getline(cin, searchTitle);

	for (int i = 0; i < catalogSize; ++i)
	{
		if (libraryCatalog[i].title == searchTitle)
		{
			if (libraryCatalog[i].available)
			{
				cout << "Book is available.\n";
				cout << endl;
			}
			else
			{
				cout << "Book is currently checked out.\n";
			}
			return;
		}
	}
	cout << "Book not found in the catalog.\n";
	cout << endl;
}

// Function to display the library's catalog, including book details and availability status.
void displayCatalog()
{
	if (catalogSize == 0)
	{
		cout << "No books available in the catalog.\n";
	}
	else
	{
		cout << "Library Catalog:\n";
		cout << "---------------------------\n";
		for (int i = 0; i < catalogSize; ++i)
		{
			cout << "Title: " << libraryCatalog[i].title << "\n";
			cout << "Author: " << libraryCatalog[i].author << "\n";
			cout << "ISBN: " << libraryCatalog[i].ISBN << "\n";
			if (libraryCatalog[i].available)
			{
				cout << "Availability: Available\n";
			}
			else
			{
				cout << "Availability: Checked Out\n";
			}
			cout << "---------------------------\n";
		}
	}
	cout << endl;
}

int main()
{
	int choice;
	do
	{
		displayMenu();
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			addBook();
			break;
		case 2:
			removeBook();
			break;
		case 3:
			checkAvailability();
			break;
		case 4:
			displayCatalog();
			break;
		case 5:
			cout << "Exiting the program.\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 5);

	system("pause");
	return 0;
}
