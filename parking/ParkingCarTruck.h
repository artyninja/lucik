#pragma once
#include "ParkingCar.h"
class ParkingCarTruck : public ParkingCar {
	bool trailerFull;
public:
	ParkingCarTruck(char* _owner, char* _model, char* _number, char* _type, bool _trailerFull);
	~ParkingCarTruck();

	bool checkTrailerFull();
};

