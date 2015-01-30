#include "CommonParking.h"
#include "ParkingCar.h"
#include "ParkingCarBus.h"
#include <iostream>
#include <ctime>
#include <conio.h>


CommonParking::CommonParking() {

}

CommonParking::CommonParking(char * _name, char* _address, int _hourlyRate) {
	name = new char [strlen(_name)];
	strcpy(name, _name);

	address = new char[strlen(_address)];
	strcpy(address, _address);

	count = 0;

	hourlyRate = _hourlyRate;

	automobils = new Auto* [count];
}


CommonParking::~CommonParking() {
	for (int i = 0; i < count; i++) {
		delete automobils[i];
	}
}

Auto* CommonParking::getAuto(int number) {
	return automobils[number - 1];
}

void CommonParking::addAuto(Auto* automobil) {
	
	ParkingCarBus * tempAutoBus = dynamic_cast<ParkingCarBus *>(automobil);
	
	if (tempAutoBus) {
		std::cout << "К сожалению, автобусы не могут парковаться на этой парковке!";
	}
	else {
		count++;
		Auto ** temp = new Auto*[count];

		for (int i = 0; i < count - 1; i++) {
			temp[i] = automobils[i];
		}

		automobils[count - 1] = automobil;
	}
}

void CommonParking::deleteAuto(int index) {

	std::cout << "Плата за парковку: " << (((time(0) - dynamic_cast<ParkingCar*>(automobils[index])->getTime())) / 60) * hourlyRate << std::endl;
	int temp_count = -1;
	Auto ** temp = new Auto*[count - 1];

	for (int i = 0; i < count; i++) {
		if (i != index) {
			temp_count++;
			temp[temp_count] = automobils[i];
		}
	}
	automobils = temp;
	count--;
	std::cout << "Нажмите любую клавишу для выхода...";
	_getch();
}

void CommonParking::getAutoList() {
	std::cout << "Всего машин на парковке: " <<count << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < count; i++) {
		std::cout << "Владелец:" << automobils[i]->getOwner() << std::endl;
		std::cout << "Модель:" << automobils[i]->getModel() << std::endl;
		std::cout << "Номер:" << automobils[i]->getNumber() << std::endl;
		std::cout << "Время на парковке:" << (( time(0) - dynamic_cast<ParkingCar*>(automobils[i])->getTime())) << std::endl;
		std::cout <<  std::endl;
		std::cout << std::endl;
	}
}

char* CommonParking::getName() {
	char * temp = new char[strlen(name)];
	strcpy(temp, name);
	return temp;
}

char* CommonParking::getAddress() {
	char * temp = new char[strlen(address)];
	strcpy(temp, address);
	return temp;
}

int CommonParking::getHourlyRate() {
	return hourlyRate;
}

int CommonParking::getAutoCount() {
	return count;
}
