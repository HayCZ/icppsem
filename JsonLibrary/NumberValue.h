#pragma once

#include "platform.h"
#include "Value.h"
#include <string>

class DLL_SPEC NumberValue :
	public Value
{
public:
	NumberValue(double value);
	// - vrací èíselnou hodnotu
	double get() const;
	virtual std::string serialize() const override;
private:
	double _value;
};

Value* setNumberValue(const std::string& data, int& position);