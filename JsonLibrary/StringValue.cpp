#include "StringValue.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

StringValue::StringValue(std::string value)
{
	for (int i = 0; i < value.length(); i++)
	{
		_value += value[i];
	}
}

std::string StringValue::get() const
{
	return _value;
}
std::string StringValue::serialize() const
{
	std::string escaped;

	for (int i = 0; i < _value.length(); i++)
	{
		if (_value[i] == '\"' || _value[i] == '\\' || _value[i] == '\?')
		{
			escaped += '\\';
		}
		escaped += _value[i];
	}

	return '"' + escaped + '"';
}

Value* setStringValue(const std::string& data, int& position) {
	std::string result;
	bool escaped = false;

	position++;
	while (data[position] != '"' || escaped)
	{
		if (data[position] != '\\' || escaped) {
			result += data[position];
		}

		escaped = data[position] == '\\';

		position++;
	}

	if (data[position] == '"') {
		position++;
	}

	StringValue* stringValue = new StringValue{ result };

	return stringValue;
}