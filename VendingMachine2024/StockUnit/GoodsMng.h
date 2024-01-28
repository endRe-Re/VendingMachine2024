#pragma once
#include "../UtilityUnit/Utility.h"
#include <string>
#include <unordered_map>

using GoodsName	= std::string;
using Value		= unsigned long;									// ���l
using Stock		= unsigned long;									// �݌�

struct GoodsData{
	Value	_value;		// ���l
	Stock	_stock;		// �݌�
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