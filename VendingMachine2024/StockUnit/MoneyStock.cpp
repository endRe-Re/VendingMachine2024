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

PROCESSES_RESULT MoneyStock::create_buyer(GoodsInfoVec& goodsInfoVec)
{
	// �݌ɂ̐���
	PROCESSES_RESULT retVal = create_stocker( goodsInfoVec, _buyer );
	if( retVal == FALSE ){
		return FALSE;
	}
	return TRUE;
}

