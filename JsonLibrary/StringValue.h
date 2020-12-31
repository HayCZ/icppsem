#pragma once

#include "platform.h"
#include "Value.h"
#include <string>

class DLL_SPEC StringValue :
	public Value
{
public:
	StringValue(std::string value);
	std::string get() const;
	virtual std::string serialize() const override;
private:
	std::string _value;
};

Value* setStringValue(const std::string& data, int& position);