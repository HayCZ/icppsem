#pragma once

#include "platform.h"
#include "Value.h"
#include <string>

class DLL_SPEC BoolValue :
	public Value
{
public:
	BoolValue(bool value);
	// - vrací bool hodnotu
	bool get() const;
	virtual std::string serialize() const override;
private:
	bool _value;
};

Value* setBoolValue(const std::string& data, int& position);