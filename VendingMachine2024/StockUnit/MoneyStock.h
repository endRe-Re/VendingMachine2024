#pragma once
#include "Stock.h"

class MoneyStock : public Stock
{
public:
	MoneyStock();
	~MoneyStock();

	PROCESSES_RESULT create_buyer(GoodsInfoVec& goodsInfoVec);



private:
	GoodsMng* _buyer;
};