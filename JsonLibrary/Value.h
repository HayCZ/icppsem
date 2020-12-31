#pragma once
#include "platform.h"
#include <string>
#include <iostream>

class DLL_SPEC Value
{
public:
	// serializuje hodnotu do podoby JSON reprezentace
	virtual std::string serialize() const = 0;
};