#pragma once
#include <vector>
#include <string>
//! ��������
enum PROCESSES_RESULT
{
	PROCESSES_FALSE	= false,		// ���s
	PROCESSES_TRUE	= true			// ����
};

template<class T>
using VectorTemp = std::vector<T>;

using DisplayFormat = VectorTemp<std::string>;		// ��ʕ\���`��
using UInt			= unsigned int;
using String		= std::string;

static const UInt UINT_INIT		= 0;
static const UInt NO_EXIST_KEY	= 0;

class Utility
{
public:
	Utility();


};