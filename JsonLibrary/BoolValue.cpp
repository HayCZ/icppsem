#include "BoolValue.h"

BoolValue::BoolValue(bool value)
{
	_value = value;
}

bool BoolValue::get() const
{
	return _value;
}

std::string BoolValue::serialize() const
{
	if (_value) {
		return "true";
	}
	else {
		return "false";
	}
}

Value* setBoolValue(const std::string& data, int& position) {
	std::string result;
	if (data[position] == 't') {
		result = data.substr(position, 4);
		position += 4;
		if (result == "true")
			return new BoolValue(true);
	}
	else if (data[position] == 'f') {
		result = data.substr(position, 5);
		position += 5;
		if (result == "false")
			return new BoolValue(false);
	}
	throw std::exception();
}