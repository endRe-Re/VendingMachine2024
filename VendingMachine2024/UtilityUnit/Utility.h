#pragma once
#include <vector>
#include <string>
//! ��������
enum PROCESSES_RESULT
{
	FALSE	= false,		// ���s
	TRUE	= true			// ����
};

template<class T>
using VectorTemp = std::vector<T>;

using DisplayFormat = VectorTemp<std::string>;		// ��ʕ\���`��

static const unsigned long NO_EXIST_KEY	= 0;

class Utility
{
public:
	Utility();


};