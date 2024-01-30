#include "StockMng.h"

StockMng::StockMng()
{
}

StockMng::~StockMng()
{
	for( auto stock : _stockVec ){
		delete stock;
		stock = nullptr;
	}
}

PROCESSES_RESULT StockMng::create(GoodsInfoVec& drinkInfoVec, GoodsInfoVec& moneyInfoVec)
{
	// ���ݕ��݌ɃN���X�̍쐬
	_stockVec.emplace_back( new DrinkStock() );
	if( _stockVec[GOODS_INDEX_DRINK] == nullptr ){
		return FALSE;
	}
	if( _stockVec[GOODS_INDEX_DRINK]->create(drinkInfoVec) == FALSE ){
		return FALSE;
	}
	// �����݌ɃN���X�̍쐬
	_stockVec.emplace_back( new MoneyStock() );
	if( _stockVec[GOODS_INDEX_MONEY] == nullptr){
		return FALSE;
	}
	if( _stockVec[GOODS_INDEX_MONEY]->create(moneyInfoVec) == FALSE ){
		return FALSE;
	}

	return TRUE;
}

PROCESSES_RESULT StockMng::create_forBuyerMoney(GoodsInfoVec& moneyInfoVec)
{
	return TRUE;
}
