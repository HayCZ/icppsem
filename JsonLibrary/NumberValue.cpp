#include "NumberValue.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

NumberValue::NumberValue(double value)
{
	_value = value;
}

double NumberValue::get() const
{
	return _value;
}
std::string NumberValue::serialize() const
{
	return std::to_string(_value);
}

Value* setNumberValue(const std::string& data, int& position) {
	std::string result;
	while (true)
	{
		if (data[position] == '-' || data[position] == '.' || isdigit(data[position])) {
			result += data[position];
			position++;
		}
		else {
			return new NumberValue{ std::stof(result) };
		}
	}
}
