#include "GoodsMng.h"

GoodsMng::GoodsMng()
{
}

void GoodsMng::regist_goodsData(GoodsName goodsName, GoodsData goodsData)
{
	if( _goodsDataUnmap.count(goodsName) != 0 ){
		goodsData._stock += _goodsDataUnmap[goodsName]._stock;
	}
	_goodsDataUnmap[goodsName]._value = goodsData._value;
	_goodsDataUnmap[goodsName]._stock = goodsData._stock;
}
