#pragma once

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

#include "platform.h"
#include <string>
#include "ArrayValue.h"
#include "BoolValue.h"
#include "KeyValuePair.h"
#include "DynamicArray.h"
#include "NullValue.h"
#include "NumberValue.h"
#include "ObjectValue.h"
#include "StringValue.h"
#include "Value.h"

class DLL_SPEC JSON
{
public:
	static Value* deserialize(const std::string& string);
	static std::string serialize(const Value* value);
};