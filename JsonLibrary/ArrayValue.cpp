#include "ArrayValue.h"
#include "Deserializer.h"
#include "ObjectValue.h"
#include "StringValue.h"
#include <iostream>
#include <type_traits>

ArrayValue::ArrayValue()
{
}

ArrayValue::~ArrayValue()
{
	for (int i = 0; i < _elements.getSize(); i++)
	{
		deleteValue(_elements.getElementAt(i));
	}
}

void ArrayValue::append(Value* element)
{
	_elements.append(element);
}

int ArrayValue::getSize()
{
	return _elements.getSize();
}

Value* ArrayValue::getElementAt(int index)
{
	return _elements.getElementAt(index);
}

std::string ArrayValue::serialize() const
{
	std::string result = "[";
	for (int i = 0; i < _elements.getSize(); i++)
	{
		result += _elements.getElementAt(i)->serialize();

		if (i == _elements.getSize() - 1) {
			result += ']';
		}
		else {
			result += ',';
		}
	}
	return result;
}

Value* setArrayValue(const std::string& data, int& position) {
	ArrayValue* result = new ArrayValue{};

	position++;
	while (data[position] != ']')
	{
		Value* element = deserialize(data, position);
		result->append(element);
		if (data[position] != ',')
			break;

		position++;
	}

	position++;
	return result;
}