#include "ParkingCar.h"
#include <iostream>
#include <ctime>

ParkingCar::ParkingCar(char* _owner, char* _model, char* _number, char* _type) {
	owner = new char[strlen(_owner)];
	strcpy(owner, _owner);

	model = new char[strlen(_model)];
	strcpy(model, _model);

	number = new char[strlen(_number)];
	strcpy(number, _number);

	type = new char[strlen(_type)];
	strcpy(type, _type);

	inTime = time(0);
}

ParkingCar::~ParkingCar() {

}

double ParkingCar::getTime() {
	return inTime;
}

char* ParkingCar::getOwner() {
	char * temp = new char[strlen(owner)];
	strcpy(temp, owner);
	return temp;
}

char* ParkingCar::getModel() {
	char * temp = new char[strlen(model)];
	strcpy(temp, model);
	return temp;
}

char* ParkingCar::getNumber() {
	char * temp = new char[strlen(number)];
	strcpy(temp, number);
	return  temp;
}

char* ParkingCar::getType() {
	char * temp = new char[strlen(type)];
	strcpy(temp, type);
	return type;
}
