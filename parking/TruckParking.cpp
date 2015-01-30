#include "TruckParking.h"
#include "ParkingCarBus.h"
#include "ParkingCarTruck.h"
#include <iostream>


TruckParking::TruckParking()
{
}

TruckParking::TruckParking(char * _name, char* _address, int _hourlyRate) : CommonParking(_name, _address, _hourlyRate){
	
}

void TruckParking::addAuto(Auto *automobil) {
	
	ParkingCarTruck* tempAutoTruck = dynamic_cast<ParkingCarTruck*>(automobil);
	ParkingCarBus* tempAutoBus = dynamic_cast<ParkingCarBus*>(automobil);
	Auto * tempAuto;

	if (tempAutoTruck) {
		if (tempAutoTruck->checkTrailerFull()) {
			std::cout << "Извините, но грузовик с прицепом не сможет заехать на стоянку." << std::endl;
			return;
		} else {
			tempAuto = tempAutoTruck;
		}
	}
	else if (tempAutoBus) {
		std::cout << "Извините, но автобусы не могут сдесь парковаться!";
		return;
	}
	else {
		tempAuto = automobil;
	}

	count++;
	Auto ** temp = new Auto*[count];
	
	for (int i = 0; i < count - 1; i++) {
		temp[i] = automobils[i];
	}

	automobils[count - 1] = tempAuto;

}



TruckParking::~TruckParking() {

}
