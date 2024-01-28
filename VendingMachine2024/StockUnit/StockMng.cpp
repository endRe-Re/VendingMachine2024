#include "StockMng.h"

StockMng::StockMng()
{
}

PROCESSES_RESULT StockMng::create(GoodsInfoVec& drinkInfoVec, GoodsInfoVec& moneyInfoVec)
{
	// ���ݕ��݌ɃN���X�̍쐬
	_stockVec[DRINK_INDEX] = new DrinkStock();
	if( _stockVec[DRINK_INDEX] == nullptr ){
		return FALSE;
	}
	if( _stockVec[DRINK_INDEX]->create(drinkInfoVec) == FALSE ){
		return FALSE;
	}
	// �����݌ɃN���X�̍쐬
	_stockVec[MONEY_INDEX] = new MoneyStock();
	if( _stockVec[MONEY_INDEX] == nullptr){
		return FALSE;
	}
	if( _stockVec[MONEY_INDEX]->create(moneyInfoVec) == FALSE ){
		return FALSE;
	}

	return TRUE;
}

PROCESSES_RESULT StockMng::create_forBuyerMoney(GoodsInfoVec& moneyInfoVec)
{
	return TRUE;
}
