#include "MoneyStock.h"

MoneyStock::MoneyStock()
: _buyer(nullptr)
{
}

MoneyStock::~MoneyStock()
{
	if( _seller != nullptr ){
		delete _seller;
	}
	if( _buyer != nullptr ){
		delete _buyer;
	}
}

PROCESSES_RESULT MoneyStock::create(GoodsInfoVec& goodsInfoVec)
{
	// �݌ɂ̐���
	PROCESSES_RESULT retVal = create_stocker( goodsInfoVec, _seller );
	if( retVal == FALSE ){
		return FALSE;
	}
	// �w�����͗̈�̂ݍ쐬���Ă���
	_buyer = new GoodsMng;
	if( _buyer == nullptr ){
		return FALSE;
	}
	return TRUE;
}
