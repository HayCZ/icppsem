#pragma once

#include "Value.h"
#include <string>

Value* deserialize(const std::string& data, int& position);
void deleteValue(Value* value);