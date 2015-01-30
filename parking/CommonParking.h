#pragma once
#include "Parking.h"
class CommonParking : public Parking {

protected:
	char * name;
	char * address;
	int count;
	int hourlyRate;
	Auto ** automobils;

public:
	CommonParking();
	CommonParking(char * _name, char* _address, int _hourlyRate);
	~CommonParking();

	void addAuto(Auto *);
	void deleteAuto(int);
	void getAutoList();
	Auto * getAuto(int);

	char* getName();
	char* getAddress();
	int getHourlyRate();
	int getAutoCount();
};

