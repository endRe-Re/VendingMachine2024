#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 在庫管理クラス
// ・飲み物と金銭の情報をもち、管理するクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "MoneyStock.h"
#include "DrinkStock.h"

class Stock;

using StockVec = VectorTemp<Stock*>;

enum GOODS_INDEX_ENUM
{
	GOODS_INDEX_DRINK	= 0,
	GOODS_INDEX_MONEY
};

class StockMng
{
public:
	StockMng();
	~StockMng();

	PROCESSES_RESULT create(GoodsInfoVec& drinkInfoVec, GoodsInfoVec& moneyInfoVec);
	PROCESSES_RESULT create_forBuyerMoney(GoodsInfoVec& moneyInfoVec);

private:
	StockVec _stockVec;
};