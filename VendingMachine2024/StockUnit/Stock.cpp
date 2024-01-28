#include "Stock.h"

Stock::Stock()
: _seller(nullptr)
{
}

Stock::~Stock()
{
	if( _seller != nullptr ){
		delete _seller;
	}
}

PROCESSES_RESULT Stock::create(GoodsInfoVec& goodsInfoVec)
{
	return create_stocker( goodsInfoVec, _seller );
}

PROCESSES_RESULT Stock::create_stocker(GoodsInfoVec& goodsInfoVec, GoodsMng* goodsMng)
{
	goodsMng = new GoodsMng;
	if( goodsMng == nullptr ){
		return FALSE;
	}
	for( auto goodsInfo : goodsInfoVec){
		goodsMng->regist_goodsData( goodsInfo._name, goodsInfo._data );
	}
	return TRUE;
}
