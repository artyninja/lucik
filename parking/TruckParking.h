#pragma once
#include "CommonParking.h"
class TruckParking : public CommonParking
{
public:
	TruckParking();
	TruckParking(char * _name, char* _address, int _hourlyRate);
	~TruckParking();
	void addAuto(Auto *);
};

