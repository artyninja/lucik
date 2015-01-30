#include "ParkingCarBus.h"


ParkingCarBus::ParkingCarBus(char* _owner, char* _model, char* _number, char* _type, int _passangers) : ParkingCar(_owner, _model, _number, _type) {
	passangers = _passangers;
}


ParkingCarBus::~ParkingCarBus() {
}

int ParkingCarBus::getPassangersValue() {
	return passangers;
}

bool ParkingCarBus::turnPassangers() {
	passangers = 0;
	return true;
}