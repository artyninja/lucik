#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <cstring>
#include <sstream> 
#include <ctime>

#include "Auto.h"
#include "Parking.h"
#include "AutoSearch.h"

#include "CommonParking.h"
#include "BusParking.h"
#include "TruckParking.h"

#include "ParkingCar.h"
#include "ParkingCarBus.h"
#include "ParkingCarTruck.h"

#include "ParkingCarSearch.h"

#include "InputFromFileException.h"
#include "inputNullNumber.h"
#include "InputFail.h"


using namespace std;

void mainMenu(Parking**, int);
void parkingsInfoMenu(Parking**, int);
void parkingModeMenu(Parking**, int);
void parkingModeOneMenu(Parking *, int);



int main() {

	setlocale(LC_ALL, "rus");

	int parkingCount;

	ifstream file;
	file.open("parkings.txt", ios::in);
	
	try {
		if (file.fail()) {
			throw InputFromFileException();
		}
	}
	catch (InputFromFileException &exc) {
		cout << "���� �� ����� ���� ������!";
		return 0;
	}
	catch (...) {
		cout << "���������� ������!";
		return 0;
	}


	string temp;
	getline(file, temp);
	stringstream convert(temp);
	convert >> parkingCount;

	Parking ** parkingArray = new Parking*[parkingCount];

	for (int i = 0; i < parkingCount; i++) {
		string temp;
		string name;
		string address;
		string rate;
		int _rate;

		getline(file, temp);
		getline(file, name);
		getline(file, address);
		getline(file, rate);

		stringstream convert(rate);
		convert >> _rate;

		if (strcmp(temp.c_str(), "common") == 0) {
			parkingArray[i] = new CommonParking((char*)name.c_str(), (char*)address.c_str(), _rate);
		}

		if (strcmp(temp.c_str(), "bus") == 0) {
			parkingArray[i] = new BusParking((char*)name.c_str(), (char*)address.c_str(), _rate);
		}

		if (strcmp(temp.c_str(), "truck") == 0) {
			parkingArray[i] = new TruckParking((char*)name.c_str(), (char*)address.c_str(), _rate);
		}	
	}

	file.close();

	mainMenu(parkingArray, parkingCount);

	delete parkingArray;

	system("pause");
	return 0;
}


void mainMenu(Parking ** parkings, int parkingsCount) {

	while (true) {
		int choise;
		system("CLS");
		cout << "-------����������� 0.1.3------\n";
		cout << "1. ���������� �� ������������. \n";
		cout << "2. ����� ���������� ������������ \n";
		cout << "0. ����� \n";
		cout << "�������� �����: ";
		cin >> choise;

		if (choise == 0) {
			break;
		}

		if (choise == 1) {
			parkingsInfoMenu(parkings, parkingsCount);
		}

		if (choise == 2) {
			parkingModeMenu(parkings, parkingsCount);
		}
	}

}

void parkingsInfoMenu(Parking ** parkings, int parkingsCount) {
	system("CLS");
	cout << "������ ���� ����������� � �������: \n";
	cout << endl;
	for (int i = 0; i < parkingsCount; i++) {
		cout << "�������� # " << i << endl;
		cout << "��������: " << parkings[i]->getName() << endl;
		cout << "�����: " << parkings[i]->getAddress() << endl;
		cout << "����� ����: " << parkings[i]->getAutoCount() << endl;
		cout << "���� �� ���: " << parkings[i]->getHourlyRate() << endl;
		cout << endl;
	}
	cout << endl;
	cout << "������� ����� �������, ��� �� ��������� ����� \n";
	_getch();
}

void parkingModeMenu(Parking** parkings, int parkingsCount) {
	while (true) {
		system("CLS");
		int choise;
		cout << "�������� �� ������ ����� �������� ����� ��������� ��� ������� 0 ��� ������: " << endl;
		for (int i = 0; i < parkingsCount; i++) {
			cout << "# " << i+1 << " ��������: " << parkings[i]->getName() << " �����: " << parkings[i]->getAddress() << endl;
		}
		cout << endl;
		cout << "�������� �����: ";
		cin >> choise;
		if (choise == 0) {
			break;
		}

		if (choise > 0 && choise <= parkingsCount) {
			parkingModeOneMenu(parkings[choise - 1], choise - 1);
		}
	}
}

void parkingModeOneMenu(Parking * parking, int parkingNumber) {
	while (true) {
		system("CLS");
		int choise = 0;
		cout << "---����� ���������� ������������---" << endl;
		cout << endl;
		cout << "���������� �� �����������: " << endl;
		cout << "��������: " << parking->getName() << endl;
		cout << "�����: " << parking->getAddress() << endl;
		cout << "����� ����: " << parking->getAutoCount() << endl;
		cout << "���� �� ���: " << parking->getHourlyRate() << endl;
		cout << endl;

		cout << "��������� ��������: " << endl;
		cout << "1. �������� ����. " << endl;
		cout << "2. ������� ����. " << endl;
		cout << "3. ������ ����. " << endl;
		cout << "4. ����� ����. " << endl;
		cout << "0. ����� " << endl;
		cout << endl;

		cout << "C������� �����: ";
		cin.get();
		cin >> choise;

		if (choise == 0) {
			break;
		}

		if (choise == 1) {
			system("CLS");
			string _name;
			string _model;
			string _number;

			int _type;
			int _isTrailer;
			int _passangers;
			
			cout << "������� ��� ���������: ";
			cin.ignore();
			getline(cin, _name);
			cout << "������� ������ ����: ";
			getline(cin, _model);
			cout << "������� ����� ����: ";
			getline(cin,_number);
			cout << "������� ��� ���� (1 - ��������, 2 - ��������, 3 - �������: ";
			cin >> _type;
			if (_type == 2) {
				try {
					cout << "���� � ��������� ������? (0 - ���, 1 - ��):";
					cin >> _isTrailer;

					if (_isTrailer != 0 && _isTrailer != 1) {
						throw InputFail();
					}
				}
				catch (InputFail &exc) {
					cout << "�� ����� ������������ ���!" << endl;
					cout << "������� ����� ������� ��� �����������...";
					_getch();
					return;
				}
			}
			if (_type == 3) {
				try {
				cout << "������� ���������� ���������� � ��������: ";
				cin >> _passangers;
					if (_passangers < 0) {
						throw InputFail();
					}
				}
				catch (InputFail &exc) {
					cout << "�� ����� �������� ���!" << endl;
					cout << "������� ����� ������� ��� �����������...";
					_getch();
					return;

				};
			}


			Auto * newAuto;

			if (_type == 2) {
				newAuto = new ParkingCarTruck((char*)_name.c_str(), (char*)_model.c_str(), (char*)_number.c_str(), "Truck", _isTrailer);
			} else if (_type == 3) {
				newAuto = new ParkingCarBus((char*)_name.c_str(), (char*)_model.c_str(), (char*)_number.c_str(), "Bus", _passangers);
			}
			else {
				newAuto = new ParkingCar((char*)_name.c_str(), (char*)_model.c_str(), (char*)_number.c_str(), "Car");
			}
			
			parking->addAuto(newAuto);

			cout << endl << "������� ����� ������� ��� �� ����������..." << endl;
			_getch();
		}

		if (choise == 2) {
			int indexAuto;
			for (int i = 1; i <= parking->getAutoCount(); i++) {
				cout << " # " << i << " ��������:" << parking->getAuto(i)->getOwner() << " ������:" << parking->getAuto(i)->getModel() << " �����: " << parking->getAuto(i)->getModel() << endl;
			}
			cout << "�������� ����� ����, ������� ����� �������: ";
			cin >> indexAuto;
			try {
				if (parking->getAutoCount() == 0) {
					throw inputNullNumber();
				}
				parking->deleteAuto(indexAuto - 1);
			}
			catch (inputNullNumber &exc) {
				cout << "����� �� ������� ���!" << endl;
				cout << "������� ����� ������� ��� �����������";
				_getch();
			}
			
		}

		if (choise == 3) {
			system("CLS");
			cout << "������ ���� �� ��������" << endl << endl;
			parking->getAutoList();
			cout << "������� ����� ������� ��� ������";
			_getch();
		}

		if (choise == 4) {
			while (true) {
				system("CLS");
				int findChoise;
				cout << "�������� �������� ������: " << endl;
				cout << "1. ����� �� ���������" << endl;
				cout << "2. ����� �� ������" << endl;
				cout << "3. ����� �� ������" << endl;
				cout << "0. �����" << endl;
				cin >> findChoise;

				if (findChoise == 1) {
					system("CLS");

					string _name;

					cout << "����� �� ���������" << endl;
					cout << "������� ��� ���������: ";
					cin.ignore();
					getline(cin, _name);

					cout << "���������: " << endl;
					ParkingCarSearch search(parking);
					search.findByOwner((char*)_name.c_str());
					_getch();
				}

				if (findChoise == 2) {
					system("CLS");

					string _model;

					cout << "����� �� ������" << endl;
					cout << "������� ������: ";
					cin.ignore();
					getline(cin, _model);

					cout << "���������: " << endl;
					ParkingCarSearch search(parking);
					search.findByModel((char*)_model.c_str());
					_getch();
				}

				if (findChoise == 3) {
					system("CLS");

					string _number;

					cout << "����� �� ������" << endl;
					cout << "������� �����: ";
					cin.ignore();
					getline(cin, _number);

					cout << "���������: " << endl;
					ParkingCarSearch search(parking);
					search.findByNumber((char*)_number.c_str());
					_getch();
				}
				
				if (findChoise == 0) {
					break;
				}
			}
		}
	}
}

