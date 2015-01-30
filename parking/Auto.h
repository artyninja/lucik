#pragma once
class Auto {

protected:
	char * owner;
	char * model;
	char * number;
public:
	virtual ~Auto() {};

	virtual char* getOwner() = 0;
	virtual char* getModel() = 0;
	virtual char* getNumber() = 0;
};

