#include "Stock.h"

Stock::Stock()
: _seller(nullptr)
{
}

Stock::~Stock()
{
	delete _seller;
	_seller = nullptr;
}

PROCESSES_RESULT Stock::create(GoodsInfoVec& goodsInfoVec)
{
	return create_stocker( goodsInfoVec, _seller );
}

PROCESSES_RESULT Stock::create_stocker(GoodsInfoVec& goodsInfoVec, GoodsMng* goodsMng)
{
	goodsMng = new GoodsMng;
	if( goodsMng == nullptr ){
		return PROCESSES_FALSE;
	}
	for( auto goodsInfo : goodsInfoVec){
		goodsMng->regist_goodsData( goodsInfo._name, goodsInfo._data );
	}
	return PROCESSES_TRUE;
}
