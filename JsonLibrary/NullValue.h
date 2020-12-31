#pragma once

#include "platform.h"
#include <string>
#include "Value.h"

class DLL_SPEC NullValue : public Value
{
public:
	virtual std::string serialize() const override;
};

Value* setNullValue(const std::string& data, int& position);