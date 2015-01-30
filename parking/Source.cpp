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
		cout << "Файл не может быть открыт!";
		return 0;
	}
	catch (...) {
		cout << "Неизвесная ошибка!";
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
		cout << "-------АВТОСТОЯНКИ 0.1.3------\n";
		cout << "1. Информация об автостоянках. \n";
		cout << "2. Режим управления автостоянкой \n";
		cout << "0. Выход \n";
		cout << "Сделайте выбор: ";
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
	cout << "Список всех автостоянок в системе: \n";
	cout << endl;
	for (int i = 0; i < parkingsCount; i++) {
		cout << "Парковка # " << i << endl;
		cout << "Название: " << parkings[i]->getName() << endl;
		cout << "Адрес: " << parkings[i]->getAddress() << endl;
		cout << "Колво авто: " << parkings[i]->getAutoCount() << endl;
		cout << "Цена за час: " << parkings[i]->getHourlyRate() << endl;
		cout << endl;
	}
	cout << endl;
	cout << "Нажмите любую клавишу, что бы вернуться назад \n";
	_getch();
}

void parkingModeMenu(Parking** parkings, int parkingsCount) {
	while (true) {
		system("CLS");
		int choise;
		cout << "Выберите из списка какой стоянкой нужно управлять или введите 0 для выхода: " << endl;
		for (int i = 0; i < parkingsCount; i++) {
			cout << "# " << i+1 << " Название: " << parkings[i]->getName() << " Адрес: " << parkings[i]->getAddress() << endl;
		}
		cout << endl;
		cout << "Сделайте выбор: ";
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
		cout << "---Режим управления автостоянкой---" << endl;
		cout << endl;
		cout << "Информация об автостоянке: " << endl;
		cout << "Название: " << parking->getName() << endl;
		cout << "Адрес: " << parking->getAddress() << endl;
		cout << "Колво авто: " << parking->getAutoCount() << endl;
		cout << "Цена за час: " << parking->getHourlyRate() << endl;
		cout << endl;

		cout << "Доступные действия: " << endl;
		cout << "1. Добавить авто. " << endl;
		cout << "2. Удалить авто. " << endl;
		cout << "3. Список авто. " << endl;
		cout << "4. Поиск авто. " << endl;
		cout << "0. Выход " << endl;
		cout << endl;

		cout << "Cделайте выбор: ";
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
			
			cout << "Введите ФИО владельца: ";
			cin.ignore();
			getline(cin, _name);
			cout << "Введите модель авто: ";
			getline(cin, _model);
			cout << "Введите номер авто: ";
			getline(cin,_number);
			cout << "Введите тип авто (1 - легковая, 2 - грузовая, 3 - автобус: ";
			cin >> _type;
			if (_type == 2) {
				try {
					cout << "Если у грузовика прицеп? (0 - нет, 1 - да):";
					cin >> _isTrailer;

					if (_isTrailer != 0 && _isTrailer != 1) {
						throw InputFail();
					}
				}
				catch (InputFail &exc) {
					cout << "Вы ввели неправильный код!" << endl;
					cout << "Нажмите любую клавишу для продолжения...";
					_getch();
					return;
				}
			}
			if (_type == 3) {
				try {
				cout << "Введите количество пассажиров в автобусе: ";
				cin >> _passangers;
					if (_passangers < 0) {
						throw InputFail();
					}
				}
				catch (InputFail &exc) {
					cout << "Вы ввели неверный код!" << endl;
					cout << "Нажмите любую клавишу для продолжения...";
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

			cout << endl << "Нажмите любую клавишу что бы продолжить..." << endl;
			_getch();
		}

		if (choise == 2) {
			int indexAuto;
			for (int i = 1; i <= parking->getAutoCount(); i++) {
				cout << " # " << i << " Владелец:" << parking->getAuto(i)->getOwner() << " Модель:" << parking->getAuto(i)->getModel() << " Номер: " << parking->getAuto(i)->getModel() << endl;
			}
			cout << "Выберите номер авто, которое нужно удалить: ";
			cin >> indexAuto;
			try {
				if (parking->getAutoCount() == 0) {
					throw inputNullNumber();
				}
				parking->deleteAuto(indexAuto - 1);
			}
			catch (inputNullNumber &exc) {
				cout << "Машин на стоянке нет!" << endl;
				cout << "Нажмите любую клавишу для продолжения";
				_getch();
			}
			
		}

		if (choise == 3) {
			system("CLS");
			cout << "Список авто на парковке" << endl << endl;
			parking->getAutoList();
			cout << "Нажмите любую клавишу для выхода";
			_getch();
		}

		if (choise == 4) {
			while (true) {
				system("CLS");
				int findChoise;
				cout << "Выберите критерий поиска: " << endl;
				cout << "1. Поиск по владельцу" << endl;
				cout << "2. Поиск по модели" << endl;
				cout << "3. Поиск по номеру" << endl;
				cout << "0. Выход" << endl;
				cin >> findChoise;

				if (findChoise == 1) {
					system("CLS");

					string _name;

					cout << "Поиск по владельцу" << endl;
					cout << "Введите имя владельца: ";
					cin.ignore();
					getline(cin, _name);

					cout << "Результат: " << endl;
					ParkingCarSearch search(parking);
					search.findByOwner((char*)_name.c_str());
					_getch();
				}

				if (findChoise == 2) {
					system("CLS");

					string _model;

					cout << "Поиск по модели" << endl;
					cout << "Введите модель: ";
					cin.ignore();
					getline(cin, _model);

					cout << "Результат: " << endl;
					ParkingCarSearch search(parking);
					search.findByModel((char*)_model.c_str());
					_getch();
				}

				if (findChoise == 3) {
					system("CLS");

					string _number;

					cout << "Поиск по номеру" << endl;
					cout << "Введите номер: ";
					cin.ignore();
					getline(cin, _number);

					cout << "Результат: " << endl;
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

