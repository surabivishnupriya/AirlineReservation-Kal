// AirlineReservation.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>


using namespace std;


int main()
{

	int optionSelected;
	string departure = "";
	string destination="";
	string departingDate="";
	while (1) {
		std::cout << "*********************************************************************" << std::endl;
		cout << "            W E L C O M E     T O   K A L'S    A I R L I N E         " << endl;
		cout << "*********************************************************************" << endl << endl;
		cout << "   Please select an  option:" << endl;
		cout << "	  1.-Search Flight Schedule" << endl;
		cout << "	  2.-Reserve Flight" << endl;
		cout << "	  3.-Check-In " << endl;
		cout << "	  4.-Search Reservation" << endl;
		cout << "	  0.-Exit" << endl;
		cout << "   Please select an  option: ";
		cin >> optionSelected;

		switch (optionSelected) {
		case 1:
			cout << "Fying from: ";
			cin >> departure;
			cout << "Flying to:";		
			cin >> destination;
			cout << "Departing Date: ";
			cin >> departingDate;		
			break;
		case 2:
			cout << "OPtion 2 Selected" << endl;
			break;
		case 3:
			cout << "OPtion 3 Selected" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Default Selected" << endl;
			break;
		}
		system("CLS");
		/*cout<< flush;*/

	}
	
	return 0;
}
