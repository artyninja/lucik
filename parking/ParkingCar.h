#pragma once
#include "Auto.h"

class ParkingCar : public Auto {
protected:
	char * type;
	double inTime;
public:
	ParkingCar(char *, char *, char*, char*);
	~ParkingCar();

	char * getOwner();
	char * getModel();
	char * getNumber();
	char * getType();
	double getTime();
};

