#pragma once
#include "Auto.h"
class Parking {

public:
	virtual ~Parking() {};

	virtual void addAuto(Auto *) = 0;
	virtual void deleteAuto(int) = 0;
	virtual void getAutoList() = 0;

	virtual char* getName() = 0;
	virtual char* getAddress() = 0;
	virtual int getHourlyRate() = 0;
	virtual int getAutoCount() = 0;
	virtual Auto* getAuto(int) = 0;
};
