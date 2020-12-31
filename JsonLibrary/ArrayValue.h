#pragma once

#include "platform.h"
#include "Value.h"
#include <string>
#include "DynamicArray.h"

class DLL_SPEC ArrayValue :
	public Value
{
public:
	ArrayValue();
	~ArrayValue();
	// - pøidá element na konec pole
	void append(Value* element);
	int getSize();
	Value* getElementAt(int index);
	virtual std::string serialize() const override;
private:
	// - atribut DynamicArray<Value*> pro uchování jednotlivých elementù v poli
	DynamicArray<Value*> _elements;
};

Value* setArrayValue(const std::string& data, int& position);