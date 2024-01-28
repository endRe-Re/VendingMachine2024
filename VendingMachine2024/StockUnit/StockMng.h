#pragma once
#include "MoneyStock.h"
#include "DrinkStock.h"

class Stock;

using StockVec = VectorTemp<Stock*>;

enum GOODS_INDEX
{
	DRINK_INDEX	= 0,
	MONEY_INDEX
};

class StockMng
{
public:
	StockMng();

	PROCESSES_RESULT create(GoodsInfoVec& drinkInfoVec, GoodsInfoVec& moneyInfoVec);
	PROCESSES_RESULT create_forBuyerMoney(GoodsInfoVec& moneyInfoVec);

private:
	StockVec _stockVec;
};