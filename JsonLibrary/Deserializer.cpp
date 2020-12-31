#include "Deserializer.h"
#include "ArrayValue.h"
#include "BoolValue.h"
#include "NullValue.h"
#include "NumberValue.h"
#include "ObjectValue.h"
#include "StringValue.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

Value* deserialize(const std::string& data, int& position) {
	switch (data[position])
	{
	case '{':
		return setObjectValue(data, position);
	case '[':
		return setArrayValue(data, position);
	case '"':
		return setStringValue(data, position);
	case 'n':
		return setNullValue(data, position);
	case 't':
		return setBoolValue(data, position);
	case 'f':
		return setBoolValue(data, position);
	case '-':
		return setNumberValue(data, position);
	default:
		if (isdigit(data[position])) {
			return setNumberValue(data, position);
		}
		else {
			throw std::exception();
		}
	}
}

void deleteValue(Value* value)
{
	if (ArrayValue* casted = dynamic_cast<ArrayValue*>(value))
	{
		delete(casted);
	}
	else if (BoolValue* casted = dynamic_cast<BoolValue*>(value)) {
		delete(casted);
	}
	else if (NullValue* casted = dynamic_cast<NullValue*>(value)) {
		delete(casted);
	}
	else if (NumberValue* casted = dynamic_cast<NumberValue*>(value)) {
		delete(casted);
	}
	else if (ObjectValue* casted = dynamic_cast<ObjectValue*>(value))
	{
		delete(casted);
	}
	else if (StringValue* casted = dynamic_cast<StringValue*>(value)) {
		delete(casted);
	}
	else {
		delete(value);
	}
}
