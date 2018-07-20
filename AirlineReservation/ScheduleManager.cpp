#include "stdafx.h"
#include "scheduleManager.h"
#include "flight.h"
#include "Passenger.h"
#include "Reservation.h"
#include<iostream>
#include<string>
#include <vector>
#include<unordered_map>
#include<ctime>
#include <fstream>
#include<conio.h>
#include<iomanip>

using std::string;
using namespace std;
namespace AirlineReservation {
	//variable declarations
	unsigned int pid = -1;
	string pfname, plname, paddress;
	string pcity;
	string pstate;
	string pzipcode;
	string pphonenumber;
	string pemailaddress;
	Passenger p;
	Flight f;
	
	void ScheduleManager::displayTicket(const Ticket& ticket)
	{
		cout << endl;
		cout << "Here's your ticket:" << endl;
		cout << "_____________________________________________________________________" << endl;
		cout << setw(8) << "FLIGHT" << setw(10) << "DATE" << setw(15) << "DEPART TIME"
			<< setw(20)  << "DEPARTURE AIRPORT\n";
		cout << "_____________________________________________________________________" << endl << endl;
		cout << setw(8) << ticket.getFlightNumber() << setw(10) << ticket.getFlightDate() << setw(15) << ticket.getDepartureTime() << setw(20) 
			<< ticket.getDeportAirport() << endl;
		cout << "_____________________________________________________________________" << endl << endl;
		cout << "        Name: " << ticket.getPassengerName() << "          Seat: " << ticket.getSeatNumber() << endl << endl;
		
	}

	void ScheduleManager::displayTicket(int reservationId)
	{

		std::unordered_map<int, Ticket>::const_iterator it = ALLTickets.find(reservationId);

		if (it != ALLTickets.end())
		{
			displayTicket(it->second);
		}

		else {
			cout << "Invalid reservation number. Please check your records and verify you have already checked-in." << endl << endl;
			
		}

	}

	void ScheduleManager::cancelReservationId(int reservationId)
	{
		bool foundreservation = false;
		for (unsigned int i = 0; i < mAllReservations.size(); i++) {
			if (mAllReservations[i].getReservedID() == reservationId) {

				//display flight chosen by user
				cout << "You chose to cancel reservation: " << endl;
				mAllReservations[i].display();
				Reservation cancelreservation = mAllReservations[i];
				foundreservation = true;
				break;
			}
		}
		if (foundreservation == false) {
			cout << "there is nothing to cancel" << endl;
		}
	}

	void ScheduleManager::passengerCheckin(int reservationId)
	{
		

		Reservation target;
		target.setReservedID(reservationId);

		auto it = std::find(mAllReservations.begin(), mAllReservations.end(), target);
		if (it != mAllReservations.end())
		{
			
			//add the ticket to the map
			ALLTickets.insert(std::make_pair(reservationId, *it));

			cout << endl << "You have been successfully checked in." << endl;

			//display ticket for the user
			displayTicket(*it);
		}

		else {
			cout << "Invalid reservation number. Please check your records and try check-in again.";
		}
	}

	void ScheduleManager::passengerDisplay(const Passenger& foundPassenger) const
	{
		cout << "          Name: " << foundPassenger.getFirstName() << " " << foundPassenger.getLastName() << endl;
		cout << "          Address: " << foundPassenger.getAddress() << " " << foundPassenger.getCity() << ", "
			<< foundPassenger.getState() << " " << foundPassenger.getZipCode() << endl;
		cout << "          Phone: " << foundPassenger.getPhoneNumber() << endl;
		cout << "          Email: " << foundPassenger.getEmailAddress() << endl;
	}
	void ScheduleManager::findPassengerInformation(string passengerEmail) const
	{
		//make a target for passenger comparisons
		Passenger target;
		target.setEmailAddress(passengerEmail);

		auto it = std::find(mAllPassengers.begin(), mAllPassengers.end(), target);
		if (it != mAllPassengers.end())
		{
			passengerDisplay(*it);
		}
		else {
			cout << "Invalid email address." << endl;

		}
		/*bool passengerFound = false;
		int count = 0;

		while (!passengerFound && count < mAllPassengers.size())
		{
			string email = mAllPassengers[count].getEmailAddress();
			if (!email.compare(passengerEmail))
			{
				cout << endl;
				cout << "          Name: " << mAllPassengers[count].getFirstName() << " " << mAllPassengers[count].getLastName() << endl;
				cout << "          Address: " << mAllPassengers[count].getAddress() << " " << mAllPassengers[count].getCity() << ", "
					<< mAllPassengers[count].getState() << " " << mAllPassengers[count].getZipCode() << endl;
				cout << "          Phone: " << mAllPassengers[count].getPhoneNumber() << endl;
				cout << "          Email: " << mAllPassengers[count].getEmailAddress() << endl << endl;
				passengerFound = true;
				

			}
			count++;	
		}

		if (!passengerFound) {
			cout << "Invalid email address." << endl;
		}
			
	*/	
	}

	Reservation ScheduleManager::reserveFlight()
	{
		int selectedFlightID;
		/*system("CLS");	
		cout << flush;
		cout << "_____________________________________________________________________" << endl << endl;
		cout << "                       K A L'S    A I R L I N E         " << endl;
		cout << "_____________________________________________________________________" << endl << endl;
		cout << "    R E S E R V E   A   F L I G H T         " << endl << endl << endl;*/
		//lets see all flights avaliable
		//displayAllFlights();
	//	cout << "Reserving Flight" << endl;
		//select a flight
		cout << "Make selection by Flight Number: ";
		cin >> selectedFlightID;
		
		//search for flight object of selected flight id, error not sure why
		bool foundflight = false;
		for (unsigned int i = 0; i < mAllFlights.size(); i++) {
			if (mAllFlights[i].getFlightId() == selectedFlightID) {

				//display flight chosen by user
				cout << "You chose Flight: "<<endl;
				mAllFlights[i].displayFlight();
				f = mAllFlights[i];
				foundflight = true;
				break;
			}
		}

		//flight was not found, user need to go back and pick correct flight 
		//still trying to write properly
		/*if (foundflight ==false) {
			cout << "This flight id doesn't exist!" << endl;
			cout << "Please enter the correct FlightId" << endl;
			return;
			
		} */
	

			//pick seat -need functions from Chtira
	
			//will give it a dummy seat for now
			string seatnumber = "1A";

			//get user details to create passenger;
			cout << "Let us get your personal details" << endl;
			cout << "Enter First Name: " << endl;
			cin >> pfname;
			cout << "Enter Last Name: " << endl;
			cin >> plname;
			cout << "Enter Address: " << endl;
			getline(cin.ignore(), paddress);
			cout << "Enter City: " << endl;
			cin >> pcity;
			cout << " Enter State: " << endl;
			cin >> pstate;
			cout << "Enter Zipcode: " << endl;
			cin >> pzipcode;
			cout << "Enter Phone Number: " << endl;
			cin >> pphonenumber;
			cout << "Enter Email Address: " << endl;
			cin >> pemailaddress;

			//call retrieveAllPassengers and get the last passenger ID used 
			pid = mAllPassengers.size() + 1;

			//add user input into Passenger object
			p.setID(pid); p.setFirstName(pfname); p.setLastName(plname); p.setAddress(paddress);
			p.setCity(pcity); p.setState(pstate); p.setZipCode(pzipcode); p.setPhoneNumber(pphonenumber);
			p.setEmailAddress(pemailaddress);

			//write new passenger into AllPassengers vector 
			mAllPassengers.push_back(p);

			//call retrieveAllReservations and get the last reservation ID used 

			auto rid = mAllReservations.size() + 1;

			//create reservation
			Reservation r = Reservation(rid, f, p, seatnumber);
			//add to all reservations
			mAllReservations.push_back(r);
			
		return r;
	}

	void ScheduleManager::addFlightInformation() {
		string tempDate,airplaneName, departureAirport, arrivalAirport, arrivalTime, departureTime, origin, destination, flightNumber;
		cout << "Enter Flight Number" << endl;
		cin >> flightNumber;
		cout << "Enter Airplane Name" << endl;
		cin >> airplaneName;
		cout << "Enter Origin " << endl;
		cin >> origin;
		cout << "Enter Destination " << endl;
		cin >> destination;
		cout << "Enter Date(MM/DD/YY)" << endl;
		cin >> tempDate;
		cout << "Enter Departure Time(HH:MMAM/PM)" << endl;
		cin >> departureTime;
		cout << "Enter Arrival Time(HH:MMAM/PM)" << endl;
		cin >> arrivalTime;
		cout << "Enter Departure airport " << endl;
		cin >> departureAirport;
		cout << "Enter Arrival airport " << endl;
		cin >> arrivalAirport;

		//cout
		Flight theFlight;
		//Flight theFlight(1,tempDate, "9:00PM", "11:00Am", "2A", "2B","la","ca");
		//theFlight.setAirrvalAirport(airportsEnum :: SEA);
		theFlight.setFlightId(mAllFlights.size() + 1);
		theFlight.setFlightNumber(flightNumber);
		theFlight.setAirplaneName(airplaneName);
		theFlight.setDate(tempDate);
		theFlight.setdepartureAirport(departureAirport);
		theFlight.setAirrvalAirport(arrivalAirport);
		theFlight.setArrivalTime(arrivalTime);
		theFlight.setDepartureTime(departureTime);
		theFlight.setOrigin(origin);
		theFlight.setDestination(destination);

		theFlight.addFlight();
		mAllFlights.push_back(theFlight);
		//writeFlightVectorToFile(mAllFlights);

	}

	void ScheduleManager::deleteFlight(int flightId)
	{
		if (mAllFlights.size() <= 0) {
			cout << "There are no flights to delete" << endl;
			return;
		}
		for (unsigned int i = 0; i < mAllFlights.size(); i++) {
			if (mAllFlights[i].getFlightId() == flightId) {
				mAllFlights.erase(mAllFlights.begin() + i);
				cout << "Flight with FlightId: " << flightId << " was successfully deleted" << endl;
				return;
			}
		}
		cout << "This flight id doesn't exist!" << endl;
		cout << "To go back to main menu enter'0'" << endl;
		cout << "Please enter the correct FlightId" << endl;

		cin >> flightId;
		if (flightId == 0)
			return;
		else
			deleteFlight(flightId);


	}

	/*void ScheduleManager::dummyFlightInformation() {
		Flight theFlight("10/08/2018", "10:10 AM", "9:00PM", "2A", "2B", "SEA", "LA");
		theFlight.setFlightId(mAllFlights.size() + 1);
		theFlight.addFlight();
		mAllFlights.push_back(theFlight);
	}
*/
	//Display all Flight Information

	void displayHeadersForTableFlights(string tableHeader) {

		
	}
	//Table Header
	void ScheduleManager::displayAllFlights() const {
	
		cout << "___________________________________________________________________________________________________________________" << endl << endl;
		cout << setw(9) << "ID" << setw(8) << "DATE" << setw(17) << "DEPART TIME"
			<< setw(15) << "ARRIVAL TIME" << setw(13) << "DEPARTURE" << setw(10) << "ARRIVAL" << setw(20) << "DEPART AIRPORT" << setw(22) << "ARRIVAL AIRPORT\n";
		cout << "___________________________________________________________________________________________________________________" << endl << endl;

		for (const auto& flight : mAllFlights) {
			flight.displayFlight();
		}
		cout << endl << "___________________________________________________________________________________________________________________" << endl << endl;
	}
	
	void ScheduleManager::writeFlightVectorToFile(vector<Flight> allFlights) {
		fstream myfile;
		myfile.open("Flight.txt", ios::out);
		myfile.write((char*)&allFlights, sizeof(allFlights));

		myfile.seekg(0);
		myfile.close();
	}

	void ScheduleManager::readFlightVectorFromFile() const {
		vector<Flight> allFlights;
		fstream myfile;
		myfile.open("Flight.txt", ios::in);
		myfile.read(reinterpret_cast<char *>(&allFlights), sizeof(mAllFlights));
		for (unsigned int i = 0; i < allFlights.size(); i++) {
			allFlights[i].displayFlight();
		}

	}

	vector<Flight> ScheduleManager::searchFlights(const string& date, const string& from, const string& to)  {
	
		vector<Flight> results;

		for (Flight& flight : mAllFlights) {
			if (flight.getDate()==date   &&
				flight.getOrigin() == from && flight.getDestination() == to) {
				results.push_back(flight);
			}
		}
		if (results.size() > 0)
			return results;

		throw logic_error("There are NO Flights available");
	
	}

	void ScheduleManager::uploadFlightsFromSource()  {
		Flight theFlight("08/10/18", "10:10 AM", "9:00PM", "SEA", "LAX", "Los Angeles Intl", "Tacoma Intl","BOING707","BO12");	
		theFlight.setFlightId(mAllFlights.size() + 1);
		theFlight.addFlight();
		mAllFlights.push_back(theFlight);

		Flight theFlight1("08/10/18", "11:10 AM", "10:00PM", "SEA", "LAX", "Los Angeles Intl", "Tacoma Intl", "BOING707", "A110");
		
		theFlight1.setFlightId(mAllFlights.size() + 1);
		theFlight1.addFlight();
		mAllFlights.push_back(theFlight1);

		Flight theFlight2("08/10/18", "11:10 AM", "11:00PM", "LAX", "SEA", "Tacoma Intl", "Los Angeles Intl", "BOING808", "BO12");
		
		theFlight2.setFlightId(mAllFlights.size() + 1);
		theFlight2.addFlight();
		mAllFlights.push_back(theFlight2);

		Flight theFlight3("08/11/18", "11:10 AM", "12:00PM", "LAX", "SEA", "Tacoma Intl", "Los Angeles Intl", "BOING666", "A110");
		theFlight3.setFlightId(mAllFlights.size() + 1);
		theFlight3.addFlight();
		mAllFlights.push_back(theFlight3);
	}

	void ScheduleManager::uploadAirportsFromSource() {
		airports.insert(std::pair<std::string, string>("JFK", "New York Jonh F Kennedy"));
		airports.insert(std::pair<std::string, string>("LGA", "New York La Guardia"));
		airports.insert(std::pair<std::string, string>("HNL", "Hawaii Inouye Intl"));
		airports.insert(std::pair<std::string, string>("LAX", "Los Angeles Intl"));	
		airports.insert(std::pair<std::string, string>("SEA", "Tacoma Intl"));
	}

	void ScheduleManager::displayAllAirports() {
		/*const char airport[][10] = { "SEA", "HYD", "DEL","DWT", "KOL","LA" };
		mAllFlights.push_back(theFlight);*/
	/*	cout << "    SEA Seattle Tacoma Intl" <<endl;
		cout << "    LAX Los Angeles Intl" << endl;
		cout << "    LGA New York La Guardia" << endl;
		cout << "    JFK New York JFK" << endl;
		cout << "    HNL Hawaii Inouye Intl." << endl;
		cout << "    ITO Hawaii Hilo Intl." << endl;
		cout << "    ORD Chicago O'Hare Intl." << endl;
		cout << "    LAS MacCarran Intl." << endl;*/
	
		cout << setw(8) << "CODE" << setw(18) << "AIRPORT"<<endl;
		for (const auto& a : airports)
		{
			std::cout <<setw(8) << a.first << setw(25) << a.second << endl;

		}
		/*std::map<std::string, string>::iterator it = airports.find("SEA");
		if (it != airports.end())
			printf("The number is %d\n", (*it).second);
		else
			printf("Error, the number is not found\n");*/

	}



	std::vector<Flight>  ScheduleManager::getAllFlights()  {
		return mAllFlights;
	}

}

