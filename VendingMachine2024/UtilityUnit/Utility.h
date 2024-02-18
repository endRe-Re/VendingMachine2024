#pragma once
#include <vector>
#include <string>
//! 処理結果
enum PROCESSES_RESULT
{
	PROCESSES_FALSE	= false,		// 失敗
	PROCESSES_TRUE	= true			// 成功
};

template<class T>
using VectorTemp = std::vector<T>;

using DisplayFormat = VectorTemp<std::string>;		// 画面表示形式
using UInt			= unsigned int;
using String		= std::string;

static const UInt UINT_INIT		= 0;
static const UInt NO_EXIST_KEY	= 0;

class Utility
{
public:
	Utility();


};