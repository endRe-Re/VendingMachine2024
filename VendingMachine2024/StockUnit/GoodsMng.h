#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �i�Ǘ��N���X
// �E�f�[�^�̈������̒�`��ۑ����Ă����N���X
// �E�N�����̏��ƂȂ�
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../UtilityUnit/Utility.h"
#include <string>
#include <unordered_map>

using GoodsName	= std::string;
using Value			= unsigned long;									// ���l
using StockNum		= unsigned long;									// �݌�

struct GoodsData{
	Value		_value;		// ���l
	StockNum	_stock;		// �݌�
};
using GoodsDataUnmap = std::unordered_map<GoodsName, GoodsData>;

class GoodsMng
{
public:
	GoodsMng();
	void regist_goodsData(GoodsName& goodsName, GoodsData& goodsData);

private:
	GoodsDataUnmap	_goodsDataUnmap;
};