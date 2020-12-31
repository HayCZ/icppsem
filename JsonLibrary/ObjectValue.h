#pragma once

#include "platform.h"
#include "KeyValuePair.h"
#include "DynamicArray.h"
#include "Value.h"

class DLL_SPEC ObjectValue : public Value
{
public:
	ObjectValue();
	~ObjectValue();
	// - p�id� kl��-element do objektu
	void append(const KeyValuePair& pair);
	Value* get(std::string key);

	template<class Type>
	Type* get(std::string key) {
		return (Type*)get(key);
	}

	virtual std::string serialize() const override;
private:
	DynamicArray<KeyValuePair> _elements;
	// - atribut DynamicArray<KeyValuePair> pro uchov�n� jednotliv�ch hodnot a kl��� v objektu
};

Value* setObjectValue(const std::string& data, int& position);