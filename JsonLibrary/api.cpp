#include "api.h"
#include "ObjectValue.h"
#include "Deserializer.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

#pragma region JSON

Value* JSON::deserialize(const std::string& string)
{
	int position = 0;
	return ::deserialize(string, position);
}

std::string JSON::serialize(const Value* value)
{
	return value->serialize();
}

#pragma endregion
