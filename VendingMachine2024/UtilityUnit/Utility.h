#pragma once
#include <vector>
#include <string>
//! ˆ—Œ‹‰Ê
enum PROCESSES_RESULT
{
	FALSE	= false,		// ¸”s
	TRUE	= true			// ¬Œ÷
};

template<class T>
using VectorTemp = std::vector<T>;

using DisplayFormat = VectorTemp<std::string>;		// ‰æ–Ê•\¦Œ`®

static const unsigned long NO_EXIST_KEY	= 0;

class Utility
{
public:
	Utility();


};