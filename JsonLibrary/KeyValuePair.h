#pragma once
#include "platform.h"
#include <string>
#include "Value.h"

class Value;

// - definuje p�r kl�� (�et�zec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class DLL_SPEC KeyValuePair {
public:
	KeyValuePair();
	KeyValuePair(std::string key, Value* value);
	// - vr�t� kl��
	std::string getKey() const;
	// - vr�t� hodnotu
	Value* getValue() const;
private:
	std::string _key;
	Value* _value;
};