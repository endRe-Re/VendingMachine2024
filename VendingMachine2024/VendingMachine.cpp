#include "VendingMachine.h"

VendingMachine::VendingMachine()
: _mainControl(nullptr),
  _stockMng(nullptr)
{

}

VendingMachine::~VendingMachine()
{
	delete _mainControl;
	delete _stockMng;
	_mainControl	= nullptr;
	_stockMng		= nullptr;
}

bool VendingMachine::activation()
{
	// メイン制御クラス作成
	_mainControl = new MainControl();
	if( _mainControl == nullptr ){
		return false;
	}
	if( _mainControl->create() == FALSE ){
		return false;
	}

	// 在庫管理クラス作成
	_stockMng = new StockMng();
	if( _stockMng == nullptr ){
		return false;
	}
	if( create_stockMng() == FALSE ){
		return false;
	}
	
	return true;
}

PROCESSES_RESULT VendingMachine::create_stockMng()
{
	// 飲み物情報の取得から在庫に設定する形への変換
	SegmentType		targetType	= USE_SEGMENT_TYPE_DRINK;
	SegmentData		segmentData = _mainControl->get_segmentData( targetType );
	GoodsInfoVec	drinkInfoVec;
	if( convert_segmentDataToGoodsInfoVec(segmentData, drinkInfoVec) == FALSE ){
		return FALSE;
	}
	// お金情報の取得から在庫に設定する形への変換
	SegmentType		targetType	= USE_SEGMENT_TYPE_MONEY;
	SegmentData		segmentData = _mainControl->get_segmentData( targetType );
	GoodsInfoVec	moneyInfoVec;
	if( convert_segmentDataToGoodsInfoVec(segmentData, moneyInfoVec) == FALSE ){
		return FALSE;
	}
	// 在庫管理クラスの作成、初期情報設定
	if( _stockMng->create(drinkInfoVec, moneyInfoVec) == FALSE ){
		return FALSE;
	}
	return TRUE;
}

PROCESSES_RESULT VendingMachine::convert_segmentDataToGoodsInfoVec(SegmentData& segmentData, GoodsInfoVec& goodsInfoVec)
{
	return TRUE;
}