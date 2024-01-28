#pragma once
#include "../UtilityUnit/Utility.h"
#include <string>
#include <unordered_map>

using GoodsName	= std::string;
using Value		= unsigned long;									// âøíl
using Stock		= unsigned long;									// ç›å…

struct GoodsData{
	Value	_value;		// âøíl
	Stock	_stock;		// ç›å…
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