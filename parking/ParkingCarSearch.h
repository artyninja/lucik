#pragma once
#include "AutoSearch.h"
#include "Parking.h"
class ParkingCarSearch : public AutoSearch {
	Parking * parking;
public:
	ParkingCarSearch();
	ParkingCarSearch(Parking*);
	~ParkingCarSearch();

	void findByOwner(char*);
	void findByModel(char*);
	void findByNumber(char*);
};

