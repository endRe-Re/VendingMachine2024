#pragma once
#include "GoodsMng.h"

struct GoodsInfo
{
	GoodsName _name;
	GoodsData _data;
};
using GoodsInfoVec = VectorTemp<GoodsInfo>;

class Stock
{
public:
	Stock();
	virtual ~Stock();

	virtual PROCESSES_RESULT create(GoodsInfoVec& goodsInfoVec);

protected:
	PROCESSES_RESULT create_stocker(GoodsInfoVec& goodsInfoVec, GoodsMng* goodsMng);

	GoodsMng* _seller;

private:
};