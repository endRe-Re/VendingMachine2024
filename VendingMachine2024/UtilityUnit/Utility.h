#pragma once
#include <vector>
//! 処理結果
enum PROCESSES_RESULT
{
	FALSE	= false,		// 失敗
	TRUE	= true			// 成功
};

template<class T>
using VectorTemp = std::vector<T>;

static const unsigned long NO_EXIST_KEY	= 0;

class Utility
{
public:
	Utility();


};