#include "ParkingCarSearch.h"
#include <iostream>


ParkingCarSearch::ParkingCarSearch(Parking* _parking) {
	parking = _parking;
}


ParkingCarSearch::~ParkingCarSearch() {

}

void ParkingCarSearch::findByOwner(char* findStr) {
	int carCount = parking->getAutoCount();
	bool isFind = false;
	
	
	for (int i = 1; i <= carCount; i++) {
		if (_stricmp(parking->getAuto(i)->getOwner(), findStr) == 0) {
			Auto* temp = parking->getAuto(i);

			std::cout << "��������: " << temp->getOwner() << std::endl;
			std::cout << "������: " << parking->getAuto(i)->getModel() << std::endl;
			std::cout << "�����: " << parking->getAuto(i)->getNumber() << std::endl;
			
			isFind = true;
		}
	} 


	if (isFind == false) {
		std::cout << "������ �� �������!";
	}

	std::cout << "������� ����� ������� ��� ������" << std::endl;
}

void ParkingCarSearch::findByModel(char* findStr) {
	int carCount = parking->getAutoCount();
	bool isFind = false;


	for (int i = 1; i <= carCount; i++) {
		if (_stricmp(parking->getAuto(i)->getModel(), findStr) == 0) {
			Auto* temp = parking->getAuto(i);

			std::cout << "��������: " << temp->getOwner() << std::endl;
			std::cout << "������: " << parking->getAuto(i)->getModel() << std::endl;
			std::cout << "�����: " << parking->getAuto(i)->getNumber() << std::endl;

			isFind = true;
		}
	}


	if (isFind == false) {
		std::cout << "������ �� �������!";
	}

	std::cout << "������� ����� ������� ��� ������" << std::endl;
}

void ParkingCarSearch::findByNumber(char* findStr) {
	int carCount = parking->getAutoCount();
	bool isFind = false;


	for (int i = 1; i <= carCount; i++) {
		if (_stricmp(parking->getAuto(i)->getNumber(), findStr) == 0) {
			Auto* temp = parking->getAuto(i);

			std::cout << "��������: " << temp->getOwner() << std::endl;
			std::cout << "������: " << parking->getAuto(i)->getModel() << std::endl;
			std::cout << "�����: " << parking->getAuto(i)->getNumber() << std::endl;

			isFind = true;
		}
	}


	if (isFind == false) {
		std::cout << "������ �� �������!";
	}

	std::cout << "������� ����� ������� ��� ������" << std::endl;
}
