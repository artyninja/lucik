#pragma once
#include "ParkingCar.h"
class ParkingCarBus : public ParkingCar {
	int passangers;
public:
	ParkingCarBus(char*, char*, char*, char*, int);
	~ParkingCarBus();
	
	int getPassangersValue();
	bool turnPassangers();
};



