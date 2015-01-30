#pragma once
#include <exception>
class InputFromFileException : public  std::exception {
public:
	InputFromFileException();
	~InputFromFileException();
};

