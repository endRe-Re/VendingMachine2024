#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 品管理クラス
// ・データの扱い方の定義や保存しておくクラス
// ・起動時の情報となる
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../UtilityUnit/Utility.h"
#include <string>
#include <unordered_map>

using GoodsName	= std::string;
using Value			= unsigned long;									// 価値
using StockNum		= unsigned long;									// 在庫

struct GoodsData{
	Value		_value;		// 価値
	StockNum	_stock;		// 在庫
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