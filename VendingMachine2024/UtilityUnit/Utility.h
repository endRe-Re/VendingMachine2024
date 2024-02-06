#pragma once
#include <vector>
#include <string>
//! 処理結果
enum PROCESSES_RESULT
{
	FALSE	= false,		// 失敗
	TRUE	= true			// 成功
};

template<class T>
using VectorTemp = std::vector<T>;

using DisplayFormat = VectorTemp<std::string>;		// 画面表示形式

static const unsigned long NO_EXIST_KEY	= 0;

class Utility
{
public:
	Utility();


};