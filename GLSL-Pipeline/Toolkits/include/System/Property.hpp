#pragma once

#pragma region Property Types

#define Property(type, var)\
	__declspec(property(put = set_##var, get = get_ ##var)) type var;\
	typedef type type_##var

#define ReadonlyProperty(type, var)\
	__declspec(property(get = get_##var)) type var;\
	typedef const type type_##var

#define WriteonlyProperty(type, var)\
	__declspec(property(put = set_##var)) type var;\
	typedef type type_##var

#pragma endregion 

#pragma region Accessors

#define Get(var)\
	type_##var get_##var()

#define Set(var)\
	type_##var& set_##var(const type_##var& value)

#pragma endregion 

#pragma region Auto Properties

#define AutoProperty(type, var)\
	Property(type, var);\
	Get(var){ return var; }\
	Set(var){ var = value; return var; }

#define AutoReadonlyProperty(type, var)\
	ReadonlyProperty(type, var);\
	Get(var){ return var; }

#define AutoWriteonlyProperty(type, var)\
	WriteonlyProperty(type, var);\
	Set(var){ var = value; return var; }

#pragma endregion 