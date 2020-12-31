#include "api.h"
#include "KeyValuePair.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

KeyValuePair::KeyValuePair()
{
}

KeyValuePair::KeyValuePair(std::string key, Value* value)
{
	_key = key;
	_value = value;
}

std::string KeyValuePair::getKey() const
{
	return  _key;
}

Value* KeyValuePair::getValue() const
{
	return _value;
}