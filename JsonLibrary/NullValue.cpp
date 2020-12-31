#include "NullValue.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

std::string NullValue::serialize() const
{
	return "null";
}

Value* setNullValue(const std::string& data, int& position) {
	std::string result = data.substr(position, 4);
	if (result == "null") {
		position += 4;
		return new NullValue();
	}
	else {
		throw std::exception();
	}
}