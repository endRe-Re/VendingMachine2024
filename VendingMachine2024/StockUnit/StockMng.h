#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �݌ɊǗ��N���X
// �E���ݕ��Ƌ��K�̏��������A�Ǘ�����N���X
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