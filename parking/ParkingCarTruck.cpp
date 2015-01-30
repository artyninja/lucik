#include "ParkingCarTruck.h"


ParkingCarTruck::ParkingCarTruck(char* _owner, char* _model, char* _number, char* _type, bool _trailerFull) : ParkingCar(_owner, _model, _number, _type) {
	trailerFull = _trailerFull;
}


ParkingCarTruck::~ParkingCarTruck() {

}

bool ParkingCarTruck::checkTrailerFull() {
	return trailerFull;
}
