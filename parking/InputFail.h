#pragma once
#include <exception>
class InputFail : public std::exception {
public:
	InputFail();
	~InputFail();
};

