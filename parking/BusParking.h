#pragma once
#include "CommonParking.h"

class BusParking : public CommonParking {
public:
	BusParking();
	BusParking(char * _name, char* _address, int _hourlyRate);
	~BusParking();
	bool checkGetOutPassanger(Auto *);
	void addAuto(Auto *);
};

