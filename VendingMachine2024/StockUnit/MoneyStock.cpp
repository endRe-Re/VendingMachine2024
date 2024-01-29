#include "MoneyStock.h"

MoneyStock::MoneyStock()
: _buyer(nullptr)
{
}

MoneyStock::~MoneyStock()
{
	delete _seller;
	delete _buyer;
	_seller	= nullptr;
	_buyer	= nullptr;
}

PROCESSES_RESULT MoneyStock::create(GoodsInfoVec& goodsInfoVec)
{
	// ç›å…ÇÃê∂ê¨
	PROCESSES_RESULT retVal = create_stocker( goodsInfoVec, _seller );
	if( retVal == FALSE ){
		return FALSE;
	}
	// çwì¸ë§ÇÕóÃàÊÇÃÇ›çÏê¨ÇµÇƒÇ®Ç≠
	_buyer = new GoodsMng;
	if( _buyer == nullptr ){
		return FALSE;
	}
	return TRUE;
}

