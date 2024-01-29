#include "GoodsMng.h"

GoodsMng::GoodsMng()
{
}

void GoodsMng::regist_goodsData(GoodsName& goodsName, GoodsData& goodsData)
{
	// ìoò^çœÇ›ÇÃèÍçáÅAç›å…ÇÃí«â¡
	if( _goodsDataUnmap.count(goodsName) != NO_EXIST_KEY){
		goodsData._stock += _goodsDataUnmap[goodsName]._stock;
	}
	_goodsDataUnmap[goodsName]._value = goodsData._value;
	_goodsDataUnmap[goodsName]._stock = goodsData._stock;
}
