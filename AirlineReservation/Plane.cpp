#include "stdafx.h"
#include <string>
#include <iostream>
#include "Plane.h"
#include <algorithm>
#include <iterator>
#include <array>
#include <cstdlib>

using namespace std;


namespace AirlineReservation {
	
	Plane::Plane(const std::string& name, int economySeats, int eCols)
		:mEconomySeats(economySeats), mPlaneName(name), mEconomyCols(eCols),
		mAvailableSeats(mEconomySeats) {
		//mPlaneSeats{mEconomySeats};
		int col = 1;
		int row = 0;
		for (int i = 0; i < mEconomySeats; i++)
		{
			//int rowCol = 1;
			char letters[] = "ABCDEFGHIJHI";
			Seat seat;
			mPlaneSeats.push_back(seat);
			if (i % mEconomyCols == 0 && i != 0) {
				col = 1;
				row++;
			}
			mPlaneSeats[i].seatNo = letters[row] + std::to_string(col);
			mPlaneSeats[i].seatIndex = i;
			col++;


		}
	}

	bool Plane::checkAvailabilityOfSeats()
	{
		if (mAvailableSeats > 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	int Plane::bookSeat(std::string& seat)
	{
		for (int i = 0; i < mPlaneSeats.size(); i++) {
			if ((mPlaneSeats[i].seatNo).compare(seat) == 0) {
				if (mPlaneSeats[i].isAvailable == true) {
					cout << "The seat has been reserved" << endl;
					mPlaneSeats[i].isAvailable = false;
					mAvailableSeats--;
					return i;
				}
				else {
					cout << "choose another one" << endl;
					return 0;
				}
			}
			else {
				cout << "Incorrect seat number" << endl;
				return 0;
			}
		}
	}

	void Plane::setEconomySeats(int noOfSeats)
	{
		mEconomySeats = noOfSeats;
	}
	int Plane::getEconomySeats() const
	{
		return mEconomySeats;
	}

	void Plane::setPlaneId(int PlaneNo)
	{
		mPlaneId = PlaneNo;
	}

	const std::string& Plane::getPlaneName() const
	{
		return mPlaneName;
	}

	void Plane::setPlaneName(const std::string& pName)
	{
		mPlaneName = pName;
	}

	int Plane::getPlaneId() const
	{
		return mPlaneId;
	}

	std::vector<Seat>& Plane::GetSeatsVector()
	{
		return mPlaneSeats;
	}
}