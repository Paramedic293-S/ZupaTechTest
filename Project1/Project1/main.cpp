#include <iostream>
#include <conio.h>

using namespace std;

int seatamount = 0; 

const int rows = 10;
const int columns = 10;

//Allows call of functions
void main();
void booking();

void generategrid(int array[][columns]);
void Print(int board[][columns], int row, int column);

//main function, offers initial UI to customer
void main()
{
	int spacesleft = 100; 

	printf("Welcome to the booking procedure for our next monthly developer meetup in Eastleigh. There are currently %d spaces available. \n \n", spacesleft);

	//Allows customer to select the amount of seats they want to book
	printf("How many seats do you wish to book? \n \n");
	scanf_s("%d", &seatamount);

	//If the customer selects more than four seats, returns an error message
	if (seatamount > 4)
	{
		printf("You can only book a max of 4 seats! Try lowering the number of seats you wish to book. \n \n");
	}
	//If the customer selects more seats than are available, returns an error message
	else if (seatamount > spacesleft)
	{
		printf("There are not enough seats available! Try lowering the number of seats you wish to book. \n \n");
	}
	//If correct criteria met, moves onto booking procedure
	else
	{
		booking();
	}
	
	_getch();
}

//Booking procedure
void booking()
{
	//Variables to store customers selections
	int initialrow = 0;
	int initialcolumn = 0;
	int selectedRowA;
	int selectedColumnA;
	int selectedRowB;
	int selectedColumnB;
	int selectedRowC;
	int selectedColumnC;
	int selectedRowD;
	int selectedColumnD;

	//variable to store the board
	int board[rows][columns];

	char userName;
	char emailAddress;

	//Runs a loop as long as seatamount is greater than 0
	do
	{
		printf("Seats numbered as 0 are taken, everything else is available \n \n");

		//Generates the grid and prints it
		generategrid(board);
		Print(board, initialrow, initialcolumn);

		//Takes in customer selection for row and column of their first seat
		printf("Please select the row (horizontal) of the first seat you wish to book \n \n");
		scanf_s("%d", &selectedRowA);

		printf("Please select the column (vertical) of the first seat you wish to book \n \n");
		scanf_s("%d", &selectedColumnA);

		//Ensures row selection is correct and not off by one
		selectedRowA -= 1;
		selectedColumnA -= 1;

		//If the picked seat has already been taken, returns a error message
		if (selectedRowA && selectedColumnA == 0)
		{
			printf("That seat has already been taken! Please pick a seat not indicated as 0!");
		}
		//Confirms booking, removes a seat from seatamount and changes seat to 0 on the grid, before printing newly changed grid
		else
		{
			printf("Seat A is booked! \n \n");
			seatamount--;
			board[selectedRowA][selectedColumnA] = board[selectedRowA][selectedColumnA] + 1 && board[selectedRowA][selectedColumnA] + 2 == 0;

			Print(board, rows, columns);
		}

		//Repeats procedure for seats B, C and D
		printf("Please select the row (horizontal) of the second seat you wish to book \n \n");
		scanf_s("%d", &selectedRowB);

		printf("Please select the column (vertical) of the second seat you wish to book \n \n");
		scanf_s("%d", &selectedColumnB);

		selectedRowB -= 1;
		selectedColumnB -= 1;

		if (selectedRowB && selectedColumnB == 0)
		{
			printf("That seat has already been taken! Please pick a seat not indicated as 0!");
		}
		else
		{
			printf("Seat B is booked! \n \n");
			seatamount--;
			board[selectedRowB][selectedColumnB] = board[selectedRowB][selectedColumnB] + 1 && board[selectedRowB][selectedColumnB] + 2 == 0;

			Print(board, rows, columns);
		}

		printf("Please select the row (horizontal) of the third seat you wish to book \n \n");
		scanf_s("%d", &selectedRowC);

		printf("Please select the column (vertical) of the third seat you wish to book \n \n");
		scanf_s("%d", &selectedColumnC);

		selectedRowC -= 1;
		selectedColumnC -= 1;

		if (selectedRowC && selectedColumnC == 0)
		{
			printf("That seat has already been taken! Please pick a seat not indicated as 0!");
		}
		else
		{
			printf("Seat C is booked! \n \n");
			seatamount--;
			board[selectedRowC][selectedColumnC] = board[selectedRowC][selectedColumnC] + 1 && board[selectedRowC][selectedColumnC] + 2 == 0;

			Print(board, rows, columns);
		}

		printf("Please select the row (horizontal) of the fourth seat you wish to book \n \n");
		scanf_s("%d", &selectedRowD);

		printf("Please select the column (vertical) of the fourth seat you wish to book \n \n");
		scanf_s("%d", &selectedColumnD);

		selectedRowD -= 1;
		selectedColumnD -= 1;

		if (selectedRowD && selectedColumnD == 0)
		{
			printf("That seat has already been taken! Please pick a seat not indicated as 0!");
		}
		else
		{
			printf("Seat D is booked! \n \n");
			seatamount--;
			board[selectedRowD][selectedColumnD] = board[selectedRowD][selectedColumnD] + 1 && board[selectedRowD][selectedColumnD] + 2 == 0;

			Print(board, rows, columns);
		}
	}
	while (seatamount > 0);

	//When seatamount is reduced to 0, asks for name and email address, and confirms booking before ending programme
	if (seatamount == 0)
	{
		printf("Please enter your full name \n \n");
		scanf_s("%c", &userName);

		printf("Please enter your email address \n \n");
		scanf_s("%c", &emailAddress);

		printf("The booking procedure is now complete, please make a note of your seat numbers!");

		return;
	}

}

//Creates the grid for the customer to view available seats
void generategrid(int array[][columns])
{

	//Sets rows to i and columns to j
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			//Populates grid with the number 1
			int numbergen = 1;
			array[i][j] = numbergen;
		}
	}
}

//Prints the grid
void Print(int board[][columns], int row, int column)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			//Prints the grid
			printf("%d ", board[i][j]);

		}
		printf("\n");
	}

	printf("\n");
}

