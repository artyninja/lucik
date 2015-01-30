#pragma once
#include <exception>
class inputNullNumber :
	public std::exception
{
public:
	inputNullNumber();
	~inputNullNumber();
};

