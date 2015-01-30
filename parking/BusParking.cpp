#include "BusParking.h"
#include "ParkingCar.h"
#include "ParkingCarBus.h"
#include "ParkingCarTruck.h"
#include <iostream>

BusParking::BusParking() {

}

BusParking::BusParking(char * _name, char* _address, int _hourlyRate) : CommonParking(_name, _address, _hourlyRate) {

}

BusParking::~BusParking() {

}

bool BusParking::checkGetOutPassanger(Auto * automobil) {
	ParkingCarBus * tempBusAuto = dynamic_cast<ParkingCarBus *>(automobil);
	bool flag = false;
	if (tempBusAuto) {
		if (tempBusAuto->getPassangersValue() > 0) {
			flag = true;
		}
	}


	return flag;
}

void BusParking::addAuto(Auto *automobil) {
	ParkingCarBus* tempAutoBus = dynamic_cast<ParkingCarBus *>(automobil);
	ParkingCarTruck* tempAutoTruck = dynamic_cast<ParkingCarTruck *>(automobil);

	if (tempAutoBus) {
		if (checkGetOutPassanger(automobil)) {
			tempAutoBus->turnPassangers();
			std::cout << "Высадка пассажиров!";
		}
	}

	if (tempAutoTruck) {
		std::cout << "Извините, но грузовик не может парковатся сдесь!";
		return;
	}


	count++;
	Auto ** temp = new Auto*[count];

	for (int i = 0; i < count - 1; i++) {
		temp[i] = automobils[i];
	}

	if (tempAutoBus) {
		automobils[count - 1] = tempAutoBus;
	}
	else {
		automobils[count - 1] = automobil;
	}
}
