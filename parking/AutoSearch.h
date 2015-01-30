#pragma once
class AutoSearch
{
public:
	virtual ~AutoSearch() {};

	virtual void findByOwner(char*) = 0;
    virtual void findByModel(char*) = 0;
    virtual void findByNumber(char*) = 0;

};

