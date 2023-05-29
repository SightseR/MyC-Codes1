/*
This is a program which helps the user to book a hotel room.
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>

using namespace std;

struct Roominfo				//This is the structure which collect booking data.
{
	string type;			//The room type (single or double).
	string name;			//Booking name.
	int noofdates;			//The number of nights staying.
	int roomnumber;			//Room number of booking.
	int book;				//This is boolean type "1" for confirmed booking and "0" for not booked rooms.
	int reservationnumber;	//This is the reservation number. This is between 9999 - 100000 and automatically generate the reservation number when the booking confirmed.
	double price;			//This is the final invoiced price of the room.
};

const int noofRoom = 401;	//There are 300 rooms in the hotel.
							//Room numbers starting from 101 and ends 400.
							//Room numbers 101 - 250 are single rooms.
							//Room numbers 251 - 400 are double rroms.

/*******************************************************/
void resetRoomNumbers(Roominfo room[])	// This function is for setting the boolean type of room bookings. 
										//At the begining all rooms setting to booking value as "0" by this function.
{

	for (int i = 101; i < noofRoom; i++)
	{
		room[i].book = 0;
	}
	
}

/*******************************************************/
void checkRoomNumbersSin(Roominfo room[])	//This function checks Single rooms list.
											//what are the booked rooms (booking value 1) and what are the not booked rooms (Booking value 0).
{
	
	cout << "Available single rooms: " << endl;

	for (int i = 101; i < (noofRoom - 150); i++)	//This loop creates a list of not booked single rooms (Booking value 0)
													//And prints a list.
	{
		if (room[i].book == 0)

			cout << i << ", ";

	}

	cout << endl;

	for (int i = 101; i < (noofRoom - 151); i++)	////This loop create a list of booked single rooms (Booking value 0)
													//And prints a list.
	{
		if (room[i].book == 1)

			cout << "Room number " << i << " reserved, " << endl;
	}

	cout << endl;

}

/*******************************************************/
void checkRoomNumbersDou(Roominfo room[])	//This function checks Double rooms list.
											//what are the booked rooms (booking value 1) and what are the not booked rooms (Booking value 0).
{
	cout << "Available double rooms: " << endl;

	for (int i = 251; i < noofRoom; i++)	//This loop creates a list of not booked double rooms (Booking value 0)
											//And prints a list.
	{
		if (room[i].book == 0)

			cout << i << ", ";

	}

	cout << endl;

	for (int i = 251; i < noofRoom; i++)	//This loop creates a list of booked double rooms (Booking value 0)
											//And prints a list.
	{
		if (room[i].book == 1)

			cout << "Room number " << i << " reserved, " << endl;
	}

	cout << endl;

}


/*******************************************************/
int bookSingleRoom(Roominfo room[], int reservationnum)	//This function process the whole booking part of Single rooms.
{
	int menu2roombook;
	string menu3;

Loop7:
	checkRoomNumbersSin(room);		//This function checks Single rooms list and prints the lists of -
									//what are the booked rooms (booking value 1) and what are the not booked rooms (Booking value 0).

	cout << endl;


	cout << "Enter the room number you want to book: ";	//Let user to input the room number from the list.
	cin >> menu2roombook;
	if (menu2roombook > 100 && menu2roombook < 251 && room[menu2roombook].book != 1)	//This condition checks the entered number is -
																						//within the Single rooms list and
																						//Within the not not booked list.
	{

		room[menu2roombook].type = "Single";					//Save the room type as "Single".
		room[menu2roombook].roomnumber = menu2roombook;			//Save the room	number user requested.
		cout << "Enter your full name: ";
		cin.ignore();
		getline(cin, room[menu2roombook].name);					//Save the full name of the booking.
		cout << "How many nights you are planning to stay? : ";
		cin >> room[menu2roombook].noofdates;					//Save the no of nights of the booking.
		cout << endl;

		int discountType = rand() % 3;	//Select the random discount for the final invoice.
		string discountMsg;				//Discount message.

		if (discountType == 1)	//Discount message for 10% off.
		{
			discountMsg = "You've been selected for an Exclusive Offer!!! Enjoy an Extra 10% off of your final invoice";
		}
		else if (discountType == 2)	//Discount message for 20% off.
		{
			discountMsg = "You've been selected for an Exclusive Offer!!! Enjoy an Extra 20% off of your final invoice";
		}
		else			//No discount message for 0% off.
		{
			discountMsg = "";
		}

		//Below calculation calculate the invoice amount with discount (Calc. = Room price * no of nights - (no of nights * discount%)
		room[menu2roombook].price = 100 * room[menu2roombook].noofdates - (100 * room[menu2roombook].noofdates * discountType*10 / 100);

	Loop8:
		//Here prints the booking details and ask the booking confirmation.
		cout << "Please check the information and confirm the booking:" << endl;
		cout << "Room no: " << menu2roombook << endl
			<< "Booking name: " << room[menu2roombook].name << endl
			<< "Room type: " << room[menu2roombook].type << endl
			<< "No of nights staying: " << room[menu2roombook].noofdates << endl
			<< discountMsg << endl
			<< "Final invoice amount: " << room[menu2roombook].price << " euros." << endl
			<< "\nPress 1 to confirm the booking, Press 2 to clear booking details and book again or Press 0 to go to main menu \nPress 1,2 or 0: ";
		cin >> menu3;
		cout << endl;

		if (menu3 == "1")	//1. Confirms the booking
		{
			room[menu2roombook].book = 1;
			room[menu2roombook].reservationnumber = reservationnum + 1;
			cout << "Room " << menu2roombook << " Booked!!!" << endl
				<< "Your reservation number is " << room[menu2roombook].reservationnumber << " ." << endl << endl;
			return 1;
		}

		else if (menu3 == "2")	//1. Cancel the booking and let user to choose another single room.
			goto Loop7;

		else if (menu3 == "0")	//1. Cancel the booking and take user back to the Main menu.
			return 0;


		else  //If user enters wrong number this will guide the user.
		{
			cout << "You've entered wrong number please try again!!!" << endl;
			goto Loop8;
		}

		
		cout << endl;

	}

	else  //If user enters wrong number this will guide the user.
	{
		cout << "You've entered wrong number please try again!!!" << endl;
		goto Loop7;
	}
} //END OF SINGLE ROOM BOOKING FUNCTION

/*******************************************************/
int bookDoubleRoom(Roominfo room[], int reservationnum)	//This function process the whole booking part of Double rooms.
{
	int menu2roombook;
	string menu3;

Loop7:
	checkRoomNumbersDou(room);		//This function checks Double rooms list and prints the lists of -
	//what are the booked rooms (booking value 1) and what are the not booked rooms (Booking value 0).

	cout << endl;


	cout << "Enter the room number you want to book: ";	//Let user to input the room number from the list.
	cin >> menu2roombook;
	if (menu2roombook > 250 && menu2roombook < 401 && room[menu2roombook].book != 1)	//This condition checks the entered number is -
		//within the Single rooms list and
		//Within the not not booked list.
	{

		room[menu2roombook].type = "Double";					//Save the room type as "Double".
		room[menu2roombook].roomnumber = menu2roombook;			//Save the room	number user requested.
		cout << "Enter your full name: ";
		cin.ignore();
		getline(cin, room[menu2roombook].name);					//Save the full name of the booking.
		cout << "How many nights you are planning to stay? : ";
		cin >> room[menu2roombook].noofdates;
		cout << endl;					//Save the no of nights of the booking.

		int discountType = rand() % 3;	//Select the random discount for the final invoice.
		string discountMsg;				//Discount message.

		if (discountType == 1)	//Discount message for 10% off.
		{
			discountMsg = "You've been selected for an Exclusive Offer!!! Enjoy an Extra 10% off of your final invoice";
		}
		else if (discountType == 2)	//Discount message for 20% off.
		{
			discountMsg = "You've been selected for an Exclusive Offer!!! Enjoy an Extra 20% off of your final invoice";
		}
		else			//No discount message for 0% off.
		{
			discountMsg = "";
		}

		//Below calculation calculate the invoice amount with discount (Calc. = Room price * no of nights - (no of nights * discount%)
		room[menu2roombook].price = 100 * room[menu2roombook].noofdates - (100 * room[menu2roombook].noofdates * discountType * 10 / 100);

	Loop8:
		//Here prints the booking details and ask the booking confirmation.
		cout << "Please check the information and confirm the booking:" << endl;
		cout << "Room no: " << menu2roombook << endl
			<< "Booking name: " << room[menu2roombook].name << endl
			<< "Room type: " << room[menu2roombook].type << endl
			<< "No of nights staying: " << room[menu2roombook].noofdates << endl
			<< discountMsg << endl
			<< "Final invoice amount: " << room[menu2roombook].price << " euros." << endl
			<< "\nPress 1 to confirm the booking, Press 2 to clear booking details and book again or Press 0 to go to main menu \nPress 1,2 or 0: ";
		cin >> menu3;
		cout << endl;

		if (menu3 == "1")	//1. Confirms the booking
		{
			room[menu2roombook].book = 1;
			room[menu2roombook].reservationnumber = reservationnum + 1;
			cout << "Room " << menu2roombook << " Booked!!!" << endl
				<< "Your reservation number is " << room[menu2roombook].reservationnumber << " ." << endl << endl;
			return 1;
		}

		else if (menu3 == "2")	//1. Cancel the booking and let user to choose another double room.
			goto Loop7;

		else if (menu3 == "0")  //If user enters wrong number this will guide the user.
			return 0;


		else
		{
			cout << "You've entered wrong number please try again!!!" << endl;
			goto Loop8;
		}

		cout << endl;

	}

	else  //If user enters wrong number this will guide the user.
	{
		cout << "You've entered wrong number please try again!!!" << endl;
		goto Loop7;
	}
} //END OF DOUBLE ROOM BOOKING FUNCTION


/*******************************************************/
/*******************************************************/

int main()
{
	string  mainmenu, menu1return, menu2roomtype, menu3searchtype, searchname;
	int returnvalue, searchnumber, reservationnum = 9999;

	Roominfo room[noofRoom];


	cout << "Welcome to the Grand Hotels!!!\n" << endl;


	resetRoomNumbers(room);		// This function is for setting the boolean type of room bookings. 
	//At the begining all rooms setting to booking value as "0" by this function.
	{


	Loop1:

		//Main Menu
		cout << "\n*** MAIN MENU *** \n"
			<< "What would you like to do?\n"
			<< "1. List of room types and rates\n"
			<< "2. Book a hotel room\n"
			<< "3. Search information of bookings\n"
			<< "4. Quit Grand Hotels\n" << endl;
		cout << "Enter number 1, 2, 3 or 4:  ";
		cin >> mainmenu;

	Loop2:
		if (mainmenu == "1") // List of room types and rates of the rooms Menu.
		{
			cout << left
				<< setw(17) << "\n*** MENU 1 ***\n"
				<< setw(17) << "Room types and prices per night:\n"
				<< setw(17) << "* Single Room" << "100 euros per night\n"
				<< setw(17) << "* double Room" << "150 euros per night\n\n"
				<< setw(17) << "Press 0 to go previous menu :  ";
		Loop3:
			cin >> menu1return;
			cout << endl;

			if (menu1return != "0")	  //If user enters wrong number this will guide the user.
			{
				cout << "You've entered wrong key!!! Press 0 to go previous menu :  ";
				goto Loop3;
			}

			else goto Loop1;
		}
		//End of Menu No. 1

	Loop4:
		if (mainmenu == "2")
		{
			// Book a hotel room Menu
			cout << "\n*** MENU 2 ***\n"
				<< "Select the room type:\n"
				<< "1. Single Room\n"
				<< "2. Double Room\n"
				<< "Press 0 to go previous menu :  \n"
				<< endl;
			cout << "Enter number 1, 2 or 0 :  ";
			cin >> menu2roomtype;
			cout << endl;

			if (menu2roomtype == "0")	//Return to previous menu
			{
				goto Loop1;
			}

			else if (menu2roomtype == "1")
			{
				returnvalue = bookSingleRoom(room, reservationnum);

				if (returnvalue == 0)	//Return to previous menu
					goto Loop1;

				else if (returnvalue == 1)
					reservationnum++;
			}

			else if (menu2roomtype == "2")
			{
				returnvalue = bookDoubleRoom(room, reservationnum);

				if (returnvalue == 0)	//Return to previous menu
					goto Loop1;

				else if (returnvalue == 1)
					reservationnum++;
			}

			else 	  //If user enters wrong number this will guide the user.
			{
				cout << "You've entered a wrong number!!! Try again." << endl
					<< endl;
				goto Loop4; // Return to " Book a hotel room Menu"
			}

		}
		//End of menu 2

		if (mainmenu == "3")
		{

		Loop5:
			//Search information of bookings Menu
			cout << "\n*** MENU 3 ***\n"
				<< "Select the room type:\n"
				<< "1. Search by Reservation Number\n"
				<< "2. Search by Name\n"
				<< "3. Search by Room Number\n"
				<< "Press 0 to go previous menu\n"
				<< endl;
			cout << "Enter number 1, 2, 3 or 0 :  ";
			cin >> menu3searchtype;


			if (menu3searchtype == "0")
			{
				goto Loop1;	//Return to previous menu
			}

			else if (menu3searchtype == "1")
			{

			Loop6:
				cout << "Enter reservation number or enter 0 to go back to the previous menu: ";
				cin >> searchnumber;
				cout << endl << endl;

				if (searchnumber == 0)
				{
					goto Loop5;	//Return to previous menu
				}

				else
				{
					for (int i = 101; room[i].reservationnumber != searchnumber + 1; i++)
					{

						if (room[i].reservationnumber == searchnumber)

						{	//Prints booking information
							cout << "Room no: " << room[i].roomnumber << endl
								<< "Booking name: " << room[i].name << endl
								<< "Room type: " << room[i].type << endl
								<< "No of nights staying: " << room[i].noofdates << endl
								<< "Reservation Number: " << room[i].reservationnumber << endl
								<< "Invoiced amount: " << room[i].price << endl
								<< endl;

							goto Loop1;	//Return to Main menu
						}


						else if (i == 401)	  //If user enters wrong number this will guide the user.
						{
							cout << "You've entered a wrong number!!! Try again." << endl
								<< endl;
							goto Loop6;	//Return to previous menu
						}

					}
				}

			}

			else if (menu3searchtype == "2")
			{
			Loop7:
				cout << "Enter full name or enter 0 to go back to the previous menu: ";
				cin.ignore();
				getline(cin, searchname);
				cout << endl << endl;

				if (searchname == "0")
					goto Loop5;	//Return to previous menu

				else
				{
					int namecalc = 100;
					do
					{
						namecalc++;

						if (namecalc == 401)	  //If user enters wrong name this will guide the user.
						{
							cout << "You've entered a wrong name!!!" << endl
								<< endl;
							goto Loop5;	//Return to previous menu
						}

					} while (room[namecalc].name != searchname);

					//Prints booking information
					cout << "Room no: " << room[namecalc].roomnumber << endl
						<< "Booking name: " << room[namecalc].name << endl
						<< "Room type: " << room[namecalc].type << endl
						<< "No of nights staying: " << room[namecalc].noofdates << endl
						<< "Reservation Number: " << room[namecalc].reservationnumber << endl
						<< "Invoiced amount: " << room[namecalc].price << endl
						<< endl;

					goto Loop1;	//Return to Main menu



				}


			}

			else if (menu3searchtype == "3")
			{
			Loop8:
				cout << "Enter room number or enter 0 to go back to the previous menu: ";
				cin >> searchnumber;
				cout << endl << endl;

				if (searchnumber == 0)
					goto Loop5;	//Return to previous menu

				else if (searchnumber < 401 && searchnumber > 100 && room[searchnumber].book == 1)

				{	//Prints booking information
					cout << "Room no: " << room[searchnumber].roomnumber << endl
						<< "Booking name: " << room[searchnumber].name << endl
						<< "Room type: " << room[searchnumber].type << endl
						<< "No of nights staying: " << room[searchnumber].noofdates << endl
						<< "Reservation Number: " << room[searchnumber].reservationnumber << endl
						<< "Invoiced amount: " << room[searchnumber].price << endl
						<< endl;

					goto Loop1;	//Return to Main menu
				}

				else	  //If user enters wrong number this will guide the user.
					cout << "You've entered a wrong number!!! Try again." << endl << endl;
				goto Loop8;	//Return to previous menu
			}

			else
				goto Loop5;	//Return to previous menu
		}
		//End of menu 3


		else if (mainmenu == "4")
		{
			return 0;
		}
		//End of menu 4


		else	  //If user enters wrong number this will guide the user.
		{
			cout << "You've entered a wrong number!!! Try again." << endl << endl;
			goto Loop1;	//Return to Main menu
		}

		return 0;

	}
}
