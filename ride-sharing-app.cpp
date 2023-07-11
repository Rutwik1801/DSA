#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// Problem Definition:
// Design a Ride sharing application where drivers can offer rides (origin, destination, no of seats), any rider
// can request rides (origin, destination, no of seats).
// There is an algo to choose to calculate Ride amount charged for a given ride based on distance and no of
// seats
// 1. When the ride closes, show the amount charged to the rider.
// 2. Ride amount if No of seats >= 2 : No of kilometers * No of seats * 0.75 * Amount Charged per KM
// 3. Ride amount if No of seats = 1 : No of kilometers * Amount Charged per KM
// The program should take as input two or more drivers and a set of riders requesting rides. Multiple rides
// can happen simultaneously.
// Assumptions :
// 1. Assume Amount charged per KM = 20
// 2. No of Kilometers = destination - origin
// 3. All values are Integer
// Test Case:
// A requesting for ride R1
// INPUT: A requests 50, 60, 1,
// OUTPUT: Ride Amount: 10 * 20 (Amount/Km) = 200
// A requesting for ride R1
// INPUT: A requests 50, 60, 2,
// OUTPUT: Ride Amount: 10 * 2 * 0.75 * 20 (Amount/Km) = 300
// Bonus:
// ● Upgrade the rider to a preferred rider if he has done in more than 10 rides.
// ● Preferred Rider amount if No of seats >= 2 : No of kilometers * No of seats * 0.5 * Amount
// Charged per KM
// ● Preferred Ride amount if No of seats = 1 : No of kilometers * Amount Charged per KM * 0.75
// Functionalities expected:
// ● Add Driver(name)
// ● Add Rider(name)
// ● Create Ride (id, origin, destination, no of seats)
// ● Create/Update Ride (id, origin, destination, no of seats)
// ● Withdraw Ride (id)
// ● Close ride and return ride amount charged
// Expectations:
// 1. Create the sample data yourself. You can put it into a file, test case or main driver program
// itself.
// 2. The code should be demo-able. Either by using the main driver program or test cases.
// 3. The code should be modular. The code should have the basic OO design. Please do not jam in
// the responsibilities of one class into another.
// 4. The code should be extensible. Wherever applicable, use interfaces and contracts between
// different methods. It should be easy to add/remove functionality without rewriting the entire
// codebase.
// 5. The code should handle edge cases properly and fail gracefully.
// 6. The code should be legible, readable and DRY.
// 7. Database integration is not required.
// Guidelines:
// 1. Please do not access the internet for anything EXCEPT syntax.
// 2. You are free to use the language and IDE of your choice.
// 3. The entire code should be your own

#include <iostream>
#include <vector>
using namespace std;

enum RideStatus {IDLE, CREATED, WITHDRAWN, COMPLETED};

class Ride
{
public:
	static const int AMT_PER_KM = 20;
	Ride();
	int calculateFare(bool);
	void setDest(int dest);
	int getId() const;
	void setId(int id);
	void setOrigin(int origin);
	RideStatus getRideStatus() const;
	void setRideStatus(RideStatus rideStatus);
	void setSeats(int seats);

private:
	int id;
	int origin, dest;
	int seats;
	RideStatus rideStatus;
};

class Person
{
public:
	string name;
};

class Driver: private Person
{
public:
	Driver(string);
};

class Rider: private Person
{
private:
	int id;
	vector<Ride> completedRides;
	Ride currentRide;
public:
	Rider(int, string);
	void createRide(int, int, int, int);
	void updateRide(int, int, int, int);
	void withdrawRide(int);
	int closeRide();
	int getId() const;
};

class System
{
private:
	int drivers;
	vector<Rider> riders;
public:
	System(int, vector<Rider>&);
	void createRide(int, int, int, int, int);
	void updateRide(int, int, int, int, int);
	void withdrawRide(int, int);
	int closeRide(int);
};

Ride::Ride()
{
	id = origin = dest = seats = 0;
	rideStatus = RideStatus::IDLE;
}

Driver::Driver(string name)
{
	this->name = name;
}

int Ride::calculateFare(bool isPriorityRider)
{
	int dist = dest - origin;
	if(seats < 2)
	{
		return dist * AMT_PER_KM * (isPriorityRider?0.75:1);
	}

	return dist * seats * AMT_PER_KM * (isPriorityRider?0.5:0.75);
}

// setters and getters for Ride
void Ride::setDest(int dest) {
	this->dest = dest;
}

int Ride::getId() const {
	return id;
}

void Ride::setId(int id) {
	this->id = id;
}

void Ride::setOrigin(int origin) {
	this->origin = origin;
}

RideStatus Ride::getRideStatus() const {
	return rideStatus;
}

void Ride::setRideStatus(RideStatus rideStatus) {
	this->rideStatus = rideStatus;
}

void Ride::setSeats(int seats) {
	this->seats = seats;
}
// -----------------------------------------
// constructor
Rider::Rider(int id, string name)
{
	this->id = id;
	this->name = name;
}

// rider functions
void Rider::createRide(int id, int origin, int dest, int seats)
{
	if (origin >= dest)
	{
		cout << "Wrong values of Origin and Destination provided. Can't create ride\n";
		return;
	}

	currentRide.setId(id);
	currentRide.setOrigin(origin);
	currentRide.setDest(dest);
	currentRide.setSeats(seats);
	currentRide.setRideStatus(RideStatus::CREATED);
}
void Rider::updateRide(int id, int origin, int dest, int seats)
{
	if (currentRide.getRideStatus() == RideStatus::WITHDRAWN)
	{
		cout << "Can't update ride. Ride was withdrawn\n";
		return;
	}
	if (currentRide.getRideStatus() == RideStatus::COMPLETED)
	{
		cout << "Can't update ride. Ride already complete\n";
		return;
	}

	createRide(id, origin, dest, seats);
}

void Rider::withdrawRide(int id)
{
	if (currentRide.getId() != id)
	{
		cout << "Wrong ride Id as input. Can't withdraw current ride\n";
		return;
	}
	if (currentRide.getRideStatus() != RideStatus::CREATED)
	{
		cout << "Ride wasn't in progress. Can't withdraw ride\n";
		return;
	}

	currentRide.setRideStatus(RideStatus::WITHDRAWN);
}
// ---------------------------------
// getter for rider
int Rider::getId() const {
	return id;
}

int Rider::closeRide()
{
	if (currentRide.getRideStatus() != RideStatus::CREATED)
	{
		cout << "Ride wasn't in progress. Can't close ride\n";
		return 0;
	}

	currentRide.setRideStatus(RideStatus::COMPLETED);
	completedRides.push_back(currentRide);
	return currentRide.calculateFare(completedRides.size() >= 10);
}

System::System(int drivers, vector<Rider>& riders)
{
	if(drivers < 2 || riders.size() < 2)
	{
		cout << "Not enough drivers or riders\n";
	}

	this->drivers = drivers;
	this->riders = riders;
}

void System::createRide(int riderId, int rideId, int origin, int dest, int seats)
{
	if(drivers == 0)
	{
		cout << "No drivers around. Can't create ride\n";
		return;
	}

	for(Rider &rider: riders)
	{
		if(rider.getId() == riderId)
		{
			rider.createRide(rideId, origin, dest, seats);
			drivers--;
			break;
		}
	}
}
void System::updateRide(int riderId, int rideId, int origin, int dest, int seats)
{
	for(Rider &rider: riders)
	{
		if(rider.getId() == riderId)
		{
			rider.updateRide(rideId, origin, dest, seats);
			break;
		}
	}
}
void System::withdrawRide(int riderId, int rideId)
{
	for(Rider &rider: riders)
	{
		if(rider.getId() == riderId)
		{
			rider.withdrawRide(rideId);
			drivers++;
			break;
		}
	}
}
int System::closeRide(int riderId)
{
	for(Rider &rider: riders)
	{
		if(rider.getId() == riderId)
		{
			drivers++;
			return rider.closeRide();
		}
	}
	return 0;
}

int main() {
	Rider rider(1, "Lucifer");
	Driver driver("Amenadiel");
	Rider rider1(2, "Chloe");
	Rider rider2(3, "Maze");

	vector<Rider> riders;
	riders.push_back(rider);
	riders.push_back(rider1);
	riders.push_back(rider2);
	System system(3, riders);

	rider.createRide(1, 50, 60, 1);
	cout << rider.closeRide() << endl;
	rider.updateRide(1, 50, 60, 2);
	cout << rider.closeRide() << endl;

	cout << "*****************************************************************" << endl;

	system.createRide(1, 1, 50, 60, 1);
	system.withdrawRide(1, 1);
	system.updateRide(1, 1, 50, 60, 2);
	cout << system.closeRide(1) << endl;

	cout << "*****************************************************************" << endl;

	system.createRide(1, 1, 50, 60, 1);
	system.updateRide(1, 1, 50, 60, 2);
	cout << system.closeRide(1) << endl;
	return 0;
}





