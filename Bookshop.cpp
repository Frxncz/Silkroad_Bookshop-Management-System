// Silkroad Bookshop Version 1.0

// Bookshop Management System in C++ _ final project in prograamming 1

#include <iostream>
#include <string>       // for getline
#include <conio.h>     // for _getch()
#include <windows.h>  // for gotoxy()
#include <iomanip>   // for table style setw

using namespace std;


const int maxRecord = 100;

// Arrays to store book information
int bookIDs[maxRecord];
string names[maxRecord];
string authors[maxRecord];
double prices[maxRecord];
double quantities[maxRecord];

int recordCount = 0;

// Define the maximum number of orders and maximum book information per order
const int maxOrder = 100;
const int MAX_BOOK_INFO = 5;

// 2D array to store order information
int orderInfo[maxOrder][MAX_BOOK_INFO]; 

int orderCount = 0;



// ----------------------------------------------------- Function protoype --------------------------------------------------------- //

// MENU user-defined fuctions
void mainMenu();
void adminMenu();
void customerMenu();




// Functions for HEADER & DESIGN
void adminMenu_design();
void customerMenu_design();
void mainMenu_design();

void displayBookHeader();
void modifyBookHeader();
void deleteBookHeader();

void buyBooks_header();





// ADMINISTRATOR options user-defined fuctions

//---------------------------------  ADD BOOK
void addBooks();

//---------------------------------  DISPLAY BOOK
void addBookHeader();
void displayBooks();
void displayHeaderBookInfo();
void displayBookInfo();

//---------------------------------  MODIFY BOOK
void modifyBook();
void modifyBookProcess();

void modifyBook_ID();
void modifyBook_Name();
void modifyBook_Author();
void modifyBook_Price();
void modifyBook_Quantitiy();

//---------------------------------  DELETE BOOK
void deleteBook();
void deleteBookHeader();
void deleteBookProcess();




// CUSTOMER options user-defined fuctions
void buyBooks();
void buyBookProcess();
void askUser_displayOrders();
void displayOrders();
void total_Amount();
void another_Transaction();
void resetOrderInfo();





// --------------------------------------------- Function for text color and position ------------------------------------------------ //

                                        
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void setColor_BG(int text, int background, bool bold) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int intensity = bold ? FOREGROUND_INTENSITY : 0;
	SetConsoleTextAttribute(hConsole, text | (background << 4) | intensity);
}                                    
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





// ------------------------------------------------- Functions for HEADER & DESIGN ------------------------------------------------- //

// Admin Options header designs
void addBookHeader()
{
	gotoxy(30, 1);
	setColor(15);// bright white
	cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
	setColor(7);// white

	gotoxy(57, 3);
	cout << "ADD NEW BOOKS\n";

	gotoxy(30, 5);
	setColor(15);// bright white
	cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
	setColor(7);// white
}
void displayBookHeader()
{
	gotoxy(30, 1);
	setColor(15);// bright white
	cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
	setColor(7);// white

	gotoxy(56, 3);
	cout << "DISPLAY ALL BOOKS\n";

	gotoxy(30, 5);
	setColor(15);// bright white
	cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
	setColor(7);// white
}
void modifyBookHeader()
{
	gotoxy(30, 1);
	setColor(15);// bright white
	cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
	setColor(7);// white

	gotoxy(56, 3);
	cout << "MODIFY BOOKS\n";

	gotoxy(30, 5);
	setColor(15);// bright white
	cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
	setColor(7);// white
}
void deleteBookHeader()
{
	gotoxy(30, 1);
	setColor(15);// bright white
	cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
	setColor(7);// white

	gotoxy(56, 3);
	cout << "DELETE BOOKS\n";

	gotoxy(30, 5);
	setColor(15);// bright white
	cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
	setColor(7);// white
}

// Menu designs
void adminMenu_design()
{
	gotoxy(30, 1);
	setColor(15);// bright white
	cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
	setColor(7);// white

	gotoxy(57, 3);
	cout << "ADMINISTRATOR\n";

	gotoxy(30, 5);
	setColor(15);// bright white
	cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
	setColor(7);// white


	gotoxy(30, 8);
	cout << "[ 1 ]";
	setColor(14);// yellow
	cout << "  ADD BOOKS\n";
	setColor(7);// white

	gotoxy(30, 10);
	cout << "[ 2 ]";
	setColor(14);// yellow
	cout << "  DISPLAY BOOKS\n";
	setColor(7);// white

	gotoxy(30, 12);
	cout << "[ 3 ]";
	setColor(14);// yellow
	cout << "  MODIFY BOOKS\n";
	setColor(7);// white

	gotoxy(30, 14);
	cout << "[ 4 ]";
	setColor(14);// yellow
	cout << "  DELETE BOOKS\n";
	setColor(7);// white

	gotoxy(30, 16);
	cout << "[ 5 ]";
	setColor(12);// red
	cout << "  EXIT\n";
	setColor(7);// white
}
void customerMenu_design()
{
	gotoxy(30, 1);
	setColor(15);// bright white
	cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
	setColor(7);// white

	gotoxy(58, 3);
	cout << "CUSTOMER\n";

	gotoxy(30, 5);
	setColor(15);// bright white
	cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
	setColor(7);// white

	gotoxy(30, 8);
	cout << "[ 1 ]";
	setColor(14);// yellow
	cout << "  BUY BOOKS\n";
	setColor(7);// white

	gotoxy(30, 10);
	cout << "[ 2 ]";
	setColor(12);// yellow
	cout << "  EXIT\n";
	setColor(7);// white
}
void mainMenu_design()
{
	gotoxy(45, 14);
	setColor_BG(10, 0, true);

	std::cout << "   ";
	cout << "WELCOME! TO SILKROAD BOOKSHOP";
	std::cout << "   ";

	setColor_BG(7, 0, false);


	gotoxy(50, 1);
	setColor(10);  // light green
	cout << R"(
                                                      ,,__
                                            ..  ..   / o._)                   .---.
					   /--'/--\  \-'||        .----.    .'     '.
					  /        \_/ / |      .'      '..'         '-.
					.'\  \__\  __.'.'     .'          i-._
					  )\ |  )\ |      _.'
					 // \\ // \\
					||_  \\|_  \\_
					'--' '--'' '--'
	   )";
	setColor(7);  // Reset text color


	setColor(10);  // light green
	gotoxy(48, 25);
	cout << R"(
					      __...--~~~~~-._   _.-~~~~~--...__
                                            //               `V'               \\ 
					   //                 |                 \\ 
					  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\ 
					 //__.....----~~~~._\ | /_.~~~~----.....__\\
					====================\\|//====================
						            `---`
     )";
	setColor(7);  // Reset text color
}

void buyBooks_header()
{
	gotoxy(30, 1);
	setColor(15);// bright white
	cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
	setColor(7);// white

	gotoxy(56, 3);
	cout << "BOOK SELLING\n";

	gotoxy(30, 5);
	setColor(15);// bright white
	cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
	setColor(7);// white
}




// ------------------------------------------------------ Functions for MENUS ----------------------------------------------------- //

void customerMenu()
{

	customerMenu_design();     // Display the costumer menu design



	int customerChoice;

	do
	{
		gotoxy(30, 12);
		cout << "ENTER YOUR CHOICE: ";

		cin >> customerChoice;


		if (cin.fail())       // Error handling: If input is not an integer, clear input buffer
		{
			cin.ignore(10000, '\n');
		}


		switch (customerChoice)
		{
		case 1:

			// Execute buy book functionality

			system("cls");
			buyBooks();

			break;

		case 2:

			// Return to the main menu

			system("cls");
			mainMenu();

		default:

			// Display error message for invalid input

			gotoxy(29, 16);
			setColor(4);// red
			cout << " INVALID INPUT.";
			setColor(7);// white
			cout << " PLEASE ENTER A NUMBER (1-3)!";
		}

	} while (customerChoice != 2);

}

void adminMenu()
{

	adminMenu_design();    // Display the administrator menu design



	int adminChoice;

	do
	{
		gotoxy(30, 19);
		cout << "ENTER YOUR CHOICE: ";

		cin >> adminChoice;


		if (cin.fail())    // Error handling: If input is not an integer, clear input buffer
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}


		switch (adminChoice)
		{
		case 1:
			// Execute add new book functionality

			system("cls");
			addBooks();

			break;

		case 2:
			// Execute display all book functionality

			system("cls");
			displayBookHeader();
			displayBooks();

			break;


		case 3:
			// Execute modify book functionality

			system("cls");
			modifyBookHeader();
			modifyBook();

			break;


		case 4:
			// Execute delete book functionality

			system("cls");
			deleteBookHeader();
			deleteBook();

			break;


		case 5:

			// Return to the main menu

			system("cls");
			mainMenu();

		default:

			// Display error message for invalid input

			gotoxy(29, 23);
			setColor(4);// red
			cout << " INVALID INPUT.";
			setColor(7);// white
			cout << " PLEASE ENTER A NUMBER (1-5)!";
		}

	} while (adminChoice != 5);

}

void mainMenu()
{

	mainMenu_design();  // Display the main menu design



	int Set[] = { 7, 7, 7 };
	int counter = 2;
	char key;



	// This is the part where navigation starts

	for (;;)
	{

		// This is the part where menu options are displayed and the selected one is highlighted

		for (int i = 0; i < 3; ++i)
		{
			switch (i)
			{
			case 0:
				gotoxy(55, 18);
				setColor(Set[i]);
				cout << (i == counter ? "> " : "  ");
				cout << "User Login";
				break;
			case 1:
				gotoxy(51, 20);
				setColor(Set[i]);
				cout << (i == counter ? "> " : "  ");
				cout << "Administrator Login";
				break;
			case 2:
				gotoxy(52, 22);
				setColor(Set[i]);
				cout << (i == counter ? "> " : "  ");
				cout << "Exit the program";
				break;
			}
		}

		key = _getch();

		// This is the part where Enter key is pressed

		if ((key == 72 || key == 'w' || key == 'W') && counter > 0) {
			--counter;
		}
		else if ((key == 80 || key == 's' || key == 'S') && counter < 2) {
			++counter;
		}
		else if (key == '\r') {

			system("cls");

			if (counter == 0) {
				customerMenu();
			}
			else if (counter == 1) {
				adminMenu();
			}
			else if (counter == 2) {
				return;
			}
		}

		std::fill(std::begin(Set), std::end(Set), 7);
		Set[counter] = (counter == 2) ? 4 : 10;
	}


}





// ----------------------------------------------- Functions for ADMINISTRATOR options -------------------------------------------- //


// ----------------------------------------------  ADD BOOK
void addBooks()
{
	                                         // check if the maxRecord in full
	if (recordCount == maxRecord)
	{
		cout << "STORAGE IS FULL. CAN'T ADD MORE." << endl;
		return;
	}


	                                         // Display the buy books header design
	addBookHeader();


	string name, author;
	double price, quantity;
	int bookID;


	                                         // Prompt the user to enter book details
	gotoxy(30, 8);
	cout << "ENTER THE BOOK ID    :   ";

	cin >> bookID;
	cin.ignore();
	cout << "\n";

	gotoxy(30, 10);
	cout << "ENTER THE NAME       :   ";

	getline(cin, name);
	cout << "\n";

	gotoxy(30, 12);
	cout << "ENTER THE AUTHOR     :   ";

	getline(cin, author);
	cout << "\n";

	gotoxy(30, 14);
	cout << "ENTER THE PRICE      :   $";

	cin >> price;
	cout << "\n";

	gotoxy(30, 16);
	cout << "ENTER THE QUANTITY   :   ";

	cin >> quantity;

	                                        // Store the entered book information in respective arrays
	bookIDs[recordCount]     =      bookID;
	names[recordCount]       =      name;
	authors[recordCount]     =      author;
	prices[recordCount]      =      price;
	quantities[recordCount]  =      quantity;

	                                        // Increment the record count to move to the next index for the next book entry
	recordCount++;



	                                        // Display a success message after adding the book
	gotoxy(30, 23);
	cout << "[ The ";
	setColor(10); // light green
	cout << name;
	setColor(7); // white
	cout << " is successfully added. ]";




	                                              // Ask the user if they want to add more books after adding one
	char userInput;

	gotoxy(30, 20);
	cout << "Add another book? (Y/N): ";

	cin >> userInput;

	                                             // Check user input to determine whether to add more books or go back to the admin menu
	if (userInput == 'y' || userInput == 'Y')
	{
		system("cls"); 
		addBooks();
	}
	else
	{
		system("cls");
		adminMenu();
	}
}


// ----------------------------------------------  DISPLAY BOOK
void displayBooks()
{

	                                   // Check if there are no books available in the inventory
	if (recordCount == 0)
	{
		system("cls");

		                               // Display an "OUT OF STOCK" message to notify the user
		gotoxy(57, 23);
		cout << "OUT OF STOCK! :(";
		cout << "\n\n";

		adminMenu();
	}


	displayHeaderBookInfo();            // this is the header design of the book information

	displayBookInfo();                  // display all the informtion of the books


	int promptRow = 16 + recordCount;

	gotoxy(16, promptRow);

	system("pause");                    // press any key to continue...

	system("cls");

	adminMenu();                        // after pressing any key it will go back to admin menu
}

void displayHeaderBookInfo()
{

	cout

		<< "\n\n\t\t----------------------------------------------------------------------------------------------\n"
		<< setw(100)
		<< right
		<< left
		<< setw(15)
		<< "\t\tBook IDs"

		<< left
		<< setw(30)
		<< "Titles"

		<< left
		<< setw(30)
		<< "Authors"

		<< left
		<< setw(15)
		<< "Quantity"

		<< left
		<< setw(10)
		<< "Prices\n"

		<< "\t\t----------------------------------------------------------------------------------------------\n\n";
}

void displayBookInfo() 
{

	// Loop through each book in the recordCount

	for (int i = 0; i < recordCount; i++)
	{

		cout << "\t\t";
		cout

			<< left
			<< setw(13)
			<< bookIDs[i]

			<< left
			<< setw(30)
			<< names[i]

			<< left
			<< setw(31)
			<< authors[i]

			<< left
			<< setw(15)
			<< quantities[i]

			<< left
			<< setw(10)
			<< prices[i]

			<< endl;
	}
}


// ----------------------------------------------  MODIFY BOOK
void modifyBook()
{
	                                  // Check if there are any books available in the inventory
	if (recordCount == 0)
	{
		system("cls");

		                              // Display an "OUT OF STOCK" message to notify the user
		gotoxy(57, 23);
		cout << "OUT OF STOCK! :(";
		cout << "\n\n";

		adminMenu();
	}


	displayHeaderBookInfo();             // display all the books information
	displayBookInfo();


	char userInput;                      // Ask the user yes or no to modify a book

	int promptRow = 16 + recordCount;

	gotoxy(16, promptRow);
	cout << "Modify a book? (Y/N): ";
	cin >> userInput;

	                                             // Check if the user wants to modify a book
	if (userInput == 'y' || userInput == 'Y')
	{
		system("cls");

		modifyBookHeader();              // Display the header design for the MODIFY book function

		displayHeaderBookInfo();         // Display the header and information of all available books again
		displayBookInfo();

		modifyBookProcess();             // Execute the book modification process
	}
	else
	{
		system("cls");

		adminMenu();                     // Redirect the user back to the admin menu function if they choose not to modify a book
	}

}

void modifyBookProcess()
{

	int bookToModify;                                // ask user to enter the BookID


	int promptRow = 16 + recordCount;

	gotoxy(16, promptRow);
	cout << "Enter the book ID: ";
	cin >> bookToModify;



	system("cls");                                   // clear screen after entering the book ID

	modifyBookHeader();                              // this is the header design of the MODIFIY book function


	                                                 // Iterate through the existing records to find the book with the entered ID
	for (int i = 0; i < recordCount; i++)
	{

		if (bookIDs[i] == bookToModify)
		{
			                                         // Display the information of the book with the entered ID
			gotoxy(30, 8);
			cout << "[ 1 ]  MODIFY BOOK ID         :     " << bookIDs[i] << endl;

			gotoxy(30, 10);
			cout << "[ 2 ]  MODIFY BOOK NAME       :     " << names[i] << endl;

			gotoxy(30, 12);
			cout << "[ 3 ]  MODIFY BOOK AUTHOR     :     " << authors[i] << endl;

			gotoxy(30, 14);
			cout << "[ 4 ]  MODIFY BOOK PRICE      :     $" << prices[i] << endl;

			gotoxy(30, 16);
			cout << "[ 5 ]  MODIFY QUANTITY        :     " << quantities[i] << endl;

			gotoxy(30, 19);
			cout << "[ 6 ]  CANCEL";

			gotoxy(30, 21);
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

			cout << "\n\n\n";
		}
	}



	int modifyChoice;                                // ask user to enter the choice to modify

	do
	{
		gotoxy(30, 24);
		cout << "Enter your choice: ";
		cin >> modifyChoice;


		if (cin.fail())                              // Error handling: If input is not an integer, clear input buffer
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}


		switch (modifyChoice)
		{
		case 1:

			modifyBook_ID();
			break;

		case 2:

			modifyBook_Name();
			break;

		case 3:

			modifyBook_Author();
			break;

		case 4:

			modifyBook_Price();
			break;

		case 5:

			modifyBook_Quantitiy();
			break;

		case 6:

			system("cls");
			adminMenu();

			break;

		default:

			// Display an error message for invalid input
			cout << "SORRY, " << modifyChoice << " IS INVALID INPUT. PLEASE ENTER 1-5 ONLY!" << "\n\n";
		}

	} while (modifyChoice != 6);

}


void modifyBook_ID()
{
	int modify_BookID;

	                                          // Prompt user to enter the old book ID for modification
	gotoxy(30, 26);
	cout << "Enter the OLD book ID: ";
	cin.ignore();
	cin >> modify_BookID;

	                                          // Iterate through the existing book records to find the book with the specified ID
	for (int i = 0; i < recordCount; i++)
	{

		                                       // Check if the entered old book ID matches the ID in the current iteration
		if (modify_BookID == bookIDs[i])
		{

			                                     // Prompt the user to enter the new book ID
			gotoxy(30, 28);
			cout << "Enter the NEW book ID: ";

			cin >> bookIDs[i];


			                                       // Display a message indicating that the Book ID has been updated
			gotoxy(30, 30);
			cout << "[ The ";
			setColor(10); // light green
			cout << "Book ID";
			setColor(7); // white
			cout << " has been updated ]";

			                                  // Prompt the user to press any key to continue
			gotoxy(30, 33);
			system("pause");

			system("cls");
			                                  // Return to the admin menu
			adminMenu();
		}
	}
}

void modifyBook_Name()
{
	string modify_name;

	gotoxy(30, 26);
	cout << "Enter the OLD book title: ";                // enter book ID
	cin.ignore();
	getline(cin, modify_name);


	for (int i = 0; i < recordCount; i++)                // after entering the ID it iterates through the recordcount
	{
		if (modify_name == names[i])                     // display the book info of the entered ID
		{
			gotoxy(30, 28);
			cout << "Enter the NEW book title: ";

			getline(cin, names[i]);

			gotoxy(30, 30);
			cout << "[ The ";
			setColor(10); // light green
			cout << "book title";
			setColor(7); // white
			cout << " has been updated ]";


			gotoxy(30, 33);
			system("pause");

			system("cls");

			adminMenu();
		}
	}
}

void modifyBook_Author()
{
	string modify_BookAuthor;

	gotoxy(30, 26);
	cout << "Enter the OLD book author: ";                  // enter book ID
	cin.ignore();
	getline(cin, modify_BookAuthor);


	for (int i = 0; i < recordCount; i++)                 // after entering the ID it iterates through the recordcount
	{
		if (modify_BookAuthor == authors[i])              // display the book info of the entered ID
		{
			gotoxy(30, 28);
			cout << "Enter the NEW book author: ";

			getline(cin, authors[i]);

			gotoxy(30, 19);
			cout << "[ The ";
			gotoxy(30, 19);
			setColor(10); // light green
			cout << "book author";
			setColor(7); // white
			cout << " has been updated ]";


			gotoxy(30, 33);
			system("pause");
			system("cls");

			adminMenu();
		}
	}
}

void modifyBook_Price()
{
	int modify_BookPrice;

	gotoxy(30, 26);
	cout << "Enter the OLD book price: ";                   // enter book ID
	cin.ignore();
	cin >> modify_BookPrice;


	for (int i = 0; i < recordCount; i++)                  // after entering the ID it iterates through the recordcount
	{
		if (modify_BookPrice == prices[i])                 // display the book info of the entered ID
		{
			gotoxy(30, 28);
			cout << "Enter the NEW book price: ";

			cin >> prices[i];

			gotoxy(30, 30);
			cout << "[ The ";
			setColor(10); // light green
			cout << "book price";
			setColor(7); // white
			cout << " has been updated ]";


			gotoxy(30, 33);
			system("pause");

			system("cls");

			adminMenu();
		}
	}
}

void modifyBook_Quantitiy()
{
	int modify_BookQuantity;

	gotoxy(30, 26);
	cout << "Enter the OLD book quantity: ";                  // enter book ID
	cin.ignore();
	cin >> modify_BookQuantity;


	for (int i = 0; i < recordCount; i++)                    // after entering the ID it iterates through the recordcount
	{
		if (modify_BookQuantity == quantities[i])            // display the book info of the entered ID
		{
			gotoxy(30, 28);
			cout << "Enter the NEW book quantity: ";

			cin >> quantities[i];

			gotoxy(30, 30);
			cout << "[ The ";
			setColor(10); // light green
			cout << "book quantity";
			setColor(7); // white
			cout << " has been updated ]";


			gotoxy(30, 33);
			system("pause");

			system("cls");

			adminMenu();
		}
	}
}


// -----------------------------------------------  DELETE BOOK
void deleteBook()
{
	                                 // Check if there are any books available in the inventory
	if (recordCount == 0)
	{
		system("cls");

		                             // Display an "OUT OF STOCK" message to notify the user
		gotoxy(57, 23);
		cout << "OUT OF STOCK! :(";
		cout << "\n\n";

		adminMenu();
	}


	displayHeaderBookInfo();             // display all the books information
	displayBookInfo();


	                                     // Prompt the user to delete a book (Yes/No)
	char userInput;


	int promptRow = 16 + recordCount;
	gotoxy(16, promptRow);

	setColor(12);// ligth red
	cout << "Delete";
	setColor(7);// white
	cout << " a book ? (Y / N) : ";

	cin >> userInput;


	if (userInput == 'y' || userInput == 'Y')
	{
		system("cls");


		deleteBookHeader();

		                                 // Display header and information for all available books after deletion
		displayHeaderBookInfo();
		displayBookInfo();

		                                 // Proceed with the book deletion process
		deleteBookProcess();
	}
	else
	{
		system("cls");

		adminMenu();
	}

}

void deleteBookProcess()
{
	int bookToDelete;

	while (true)
	{

		int promptRow = 16 + recordCount;
		gotoxy(16, promptRow);
		cout << "Enter the book ID: ";

		cin >> bookToDelete;


	                       // Variable to track whether a book was successfully deleted
		bool foo = false;

		                                           // Iterate through the existing books to find the one to delete
		for (int i = 0; i < recordCount; i++)
		{
			                                       // Check if the entered book ID matches an existing book
			if (bookToDelete == bookIDs[i])
			{
				                                              // Move all subsequent book data one position earlier in the arrays
				for (int j = i; j < recordCount - 1; j++)
				{

					                                         // Shift the book ID, names, author, price & QTY at the current position one step earlier
					bookIDs[j]     =     bookIDs[j + 1];
					names[j]       =     names[j + 1];
					authors[j]     =     authors[j + 1];
					prices[j]      =     prices[j + 1];
					quantities[j]  =     quantities[j + 1];
				}

				                   // Decrement the record count to reflect the deleted book
				recordCount--;

				                   // Set the flag to indicate that a book was successfully deleted
				foo = true;

				break; 
			}
		}

		// Check if a book was successfully deleted
		if (foo)
		{
			system("cls");

			
			deleteBookHeader();


			// Display the updated list of books after deletion
			displayHeaderBookInfo();
			displayBookInfo();


			// Inform the user that the book was deleted successfully
			gotoxy(16, promptRow);
			cout << "Book ";
			setColor(12);// ligth red
			cout << "deleted";
			setColor(7); // white
			cout << " successfully";



			int promptRow = 20 + recordCount;
			gotoxy(16, promptRow);

			system("pause");            // Press any key to continue...
			system("cls");              // Clear screen

			adminMenu();

		}
		else
		{
			// Display an error message for an invalid book ID
			gotoxy(16, 19);
			setColor(12); // red
			cout << "INVALID ";
			setColor(7); // white
			cout << "BOOK ID. PLEASE";
			setColor(10); // green
			cout << "TRY AGAIN." << "\n";
			setColor(7); // white

		}
	}
}





// -------------------------------------------------------- FunctionS for COSTUMER -------------------------------------------------- //

void buyBooks()
{

	                                     // Check if there's a book available
	if (recordCount == 0)
	{
		system("cls");
		gotoxy(57, 23);
		cout << "OUT OF STOCK! :(";
		cout << "\n\n";

		                                // Redirect to the customer menu function
		customerMenu();
	}

	                                    // Display the buy books header design
	buyBooks_header();


	                                    // Display all the books information
	displayHeaderBookInfo();
	displayBookInfo();



	int promptRow = 16 + recordCount;
	gotoxy(16, promptRow);

	char customerInput;
	cout << "Buy a book? (Y/N): ";
	cin >> customerInput;

	                                                      // Check if the customer wants to buy a book
	if (customerInput == 'y' || customerInput == 'Y')
	{

		system("cls");
		                    // Proceed with the book buying process
		buyBookProcess();

	}
	else
	{

		system("cls");
		                    // Go back to the customer menu
		customerMenu();
	}
}

void buyBookProcess()
{

		                              // Display the buy books header design
	buyBooks_header();

	                                  // Display all the books information
	displayHeaderBookInfo();
	displayBookInfo();



	int bookToBuy, quantityToBuy;



	int promptRow = 0 + recordCount;

	promptRow += 16;
	gotoxy(16, promptRow);
	cout << "------------------------------------------------------------------------------------------------\n";


	promptRow += 3;
	gotoxy(50, promptRow);
	cout << "----- Your Order -----\n";


	promptRow += 2;
	gotoxy(16, promptRow);
	cout << "Enter the Book ID   :  ";
	cin >> bookToBuy;


	promptRow += 2;
	gotoxy(16, promptRow);
	cout << "Enter the Quantity  :  ";
	cin >> quantityToBuy;


	                                               // Store the selected book and quantity in the orderInfo array
	orderInfo[orderCount][0]  =  bookToBuy;
	orderInfo[orderCount][3]  =  quantityToBuy;
	orderCount++;


	                                               // Check if the selected book has sufficient stock
	for (int i = 0; i < recordCount; i++)
	{

		if (bookIDs[i] == bookToBuy)
		{

			if (quantities[i] < quantityToBuy)
			{
				                                   // Notify the user that the selected book is out of stock
				gotoxy(16, 30);

				cout << "Sorry, this book is ";
				setColor_BG(12, 0, false);
				cout << "out of stock! :(";
				setColor_BG(7, 0, false);



				gotoxy(16, 33);
				                     // Prompt the user to continue or buy another book                
				system("pause");
				system("cls");
				                     // Clear the screen and provide another chance to buy a book
				buyBookProcess();
			}
		}
	}

	                                 // After entering the order, ask the user if they want to buy more or proceed to checkout
	askUser_displayOrders();
}

void askUser_displayOrders()
{

	char buyMore;

	                                               // Prompt the user to decide whether to buy more books
	int promptRow_buyMore = 26 + recordCount;
	gotoxy(16, promptRow_buyMore);
	cout << "Do you want to buy more? (Y/N): ";
	cin >> buyMore;

	                                              // Check if the user wants to buy more books
	if (buyMore == 'y' || buyMore == 'Y')
	{

		system("cls");
		                       // Call the buyBookProcess function to continue buying more books
		buyBookProcess();
	}
	else
	{

		system("cls");
		                       // Display the user's current orders
		displayOrders();
	}
}

void displayOrders()  // This function is to display the ordered book of the user
{
	system("cls");                                             // Clear the screen



	// This display the "YOUR ORDER" design
	gotoxy(30, 1);
	setColor(15);// bright white
	cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n";
	setColor(7);// white

	gotoxy(56, 3);
	cout << "YOUR ORDERS\n";

	gotoxy(30, 5);
	setColor(15);// bright white
	cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";
	setColor(7);// white


	cout                                                      // This is the design header of bookIDs, title, author...

		<< "\n\n\t\t----------------------------------------------------------------------------------------------\n"

		<< right
		<< setw(20)
		<< left
		<< setw(15)
		<< "\t\tBook IDs"

		<< left
		<< setw(30)
		<< "Titles"

		<< left
		<< setw(30)
		<< "Authors"

		<< left
		<< setw(15)
		<< "Quantity"

		<< left
		<< setw(10)
		<< "Prices\n"

		<< "\t\t----------------------------------------------------------------------------------------------\n\n";

	for (int i = 0; i < orderCount; ++i)
	{

		int orderBookID = orderInfo[i][0];                     // Get the order book ID

		                                                       // Find the index of the order book ID in the original book arrays
		int bookIndex = -1;

		for (int j = 0; j < recordCount; j++)
		{

			if (bookIDs[j] == orderBookID)
			{

				bookIndex = j;
				break;
			}
		}

		                                                      // Display the order information along with the original book details
		if (bookIndex != -1)
		{
			cout << "\t\t";

			cout

				<< left << setw(13) << orderBookID
				<< left << setw(30) << names[bookIndex]
				<< left << setw(31) << authors[bookIndex]
				<< left << setw(15) << orderInfo[i][3]        // Quantity
				<< left << setw(10) << prices[bookIndex]
				<< endl;

			                                                  // Update quantities array

			quantities[bookIndex] -= orderInfo[i][3];         // Subtracting the quantity
		}
	}

	total_Amount();
}

void total_Amount()
{

	double total = 0.0;

	                                              // Calculate the total amount for the current order
	for (int i = 0; i < orderCount; i++) 
	{

		int orderBookID = orderInfo[i][0];        // Get the book ID from the order

		                                          // Find the index of the order book ID in the original book arrays
		int bookIndex = -1;

		for (int j = 0; j < recordCount; j++) 
		{

			if (bookIDs[j] == orderBookID) 
			{

				bookIndex = j;
				break;
			}
		}

		                                                    // If a match is found, update the total amount
		if (bookIndex != -1) 
		{
			total += orderInfo[i][3] * prices[bookIndex];
		}
	}

	                                                        // Display the total amount on the screen
	int promptRow_totalAmount = 17 + recordCount;
	gotoxy(16, promptRow_totalAmount);

	cout 
		<< "Total amount  :  "
		<< total;




	double cash;

	do
	{
		                                                      // Prompt the user to enter the cash amount
		int promptRow_enterCash = 19 + recordCount;
		gotoxy(16, promptRow_enterCash);

		cout << "Enter cash    $  ";
		cin >> cash;

		                                                       // Check if the entered cash is less than the total amount
		if (cash < total)
		{

			                                                   // Display an insufficient cash message and prompt for correct input
			int promptRow_insufficient = 27 + recordCount;
			gotoxy(16, promptRow_insufficient);

			setColor(12);// light red
			cout << "Insufficient cash. ";
			setColor(7);// white
			cout << "Please provide enough cash.\n";
		}

	} while (cash < total);


	double change = cash - total;

	                                              // Display the change to be returned
	int promptRow_change = 21 + recordCount;
	gotoxy(16, promptRow_change);

	cout << "Your change   $  " << change << endl;


	                                                          // Display a payment successful message
	int promptRow_paymentSuccessful = 24 + recordCount;
	gotoxy(16, promptRow_paymentSuccessful);

	setColor(10);// light green
	cout << "Payment successful!\n";
	setColor(7);// white


	                          // Ask the user for another transaction
	another_Transaction();
}

void another_Transaction()
{

	char transactionChoice;

	                                                              // Prompt the user to decide whether to perform another transaction
	int promptRow_pause = 30 + recordCount;
	gotoxy(16, promptRow_pause);

	cout << "Another transaction? (Y/N): ";
	cin >> transactionChoice;

	                                                              // Check if the user wants to perform another transaction
	if (transactionChoice == 'y' || transactionChoice == 'Y')
	{

		system("cls"); 

		                              // Reset order information before starting a new transaction
									  // Call this function to reset the orderInfo array and the orderCount
		resetOrderInfo();

		                              // Proceed with buying more books
		buyBookProcess();

	}
	else
	{

		system("cls");

		customerMenu();              // If no, it will go back to the admin menu function
	}
}

void resetOrderInfo()
{

	// This function is to reset the previous orders when proceeding to the another transaction



	                                                // Iterate through each order in the orderInfo array
	for (int i = 0; i < maxOrder; ++i) 
	{
		                                            // For each order, iterate through the book information in the MAX_BOOK_INFO array
		for (int x = 0; x < MAX_BOOK_INFO; ++x) 
		{
			                                        // Reset the value in the orderInfo array to 0
			orderInfo[i][x] = 0;
		}
	}

	orderCount = 0;
}





int main()
{
	system("cls");
	mainMenu();

	return 0;
}