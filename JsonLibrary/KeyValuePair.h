#pragma once
#include "platform.h"
#include <string>
#include "Value.h"

class Value;

// - definuje pár klíè (øetìzec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class DLL_SPEC KeyValuePair {
public:
	KeyValuePair();
	KeyValuePair(std::string key, Value* value);
	// - vrátí klíè
	std::string getKey() const;
	// - vrátí hodnotu
	Value* getValue() const;
private:
	std::string _key;
	Value* _value;
};