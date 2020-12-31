#include "ObjectValue.h"
#include "Deserializer.h"
#include "StringValue.h"
#include <exception>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

ObjectValue::ObjectValue()
{

}

ObjectValue::~ObjectValue()
{
	for (int i = 0; i < _elements.getSize(); i++)
	{
		deleteValue(_elements.getElementAt(i).getValue());
	}
}

void ObjectValue::append(const KeyValuePair& pair)
{
	_elements.append(pair);
}

Value* ObjectValue::get(std::string key) {
	for (int i = 0; i < _elements.getSize(); i++) {
		auto keyPair = _elements.getElementAt(i);
		if (keyPair.getKey() == key) {
			return keyPair.getValue();
		}
	}
	throw std::exception();
}

std::string ObjectValue::serialize() const
{
	std::string result = "{";
	for (int i = 0; i < _elements.getSize(); i++)
	{
		result += '"' + _elements.getElementAt(i).getKey() + '"' + ':';
		result += _elements.getElementAt(i).getValue()->serialize();
		if (i < _elements.getSize() - 1) {
			result += ',';
		}
	}
	result += '}';
	return result;
}

Value* setObjectValue(const std::string& data, int& position) {
	ObjectValue* result = new ObjectValue{};

	position++;
	while (true)
	{
		Value* key = deserialize(data, position);
		position++;
		Value* value = deserialize(data, position);

		if (StringValue* casted = dynamic_cast<StringValue*>(key)) {
			result->append(KeyValuePair{ casted->get(), value });
			delete(casted);
		}
		else {
			throw std::exception();
		}

		position++;
		if (data[position - 1] == '}')
			break;

		if (data[position - 1] != ',')
			throw std::exception("Neoèekávaný znak.");
	}

	return result;
}