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
	if( create() == FALSE ){
		return false;
	}
	
	return true;
}

PROCESSES_RESULT VendingMachine::create()
{
	// メイン制御クラス作成
	_mainControl = new MainControl();
	if( _mainControl == nullptr ){
		return FALSE;
	}
	if( _mainControl->create() == FALSE ){
		return FALSE;
	}

	// 在庫管理クラス作成
	_stockMng = new StockMng();
	if( _stockMng == nullptr ){
		return FALSE;
	}
	if( create_stockMng() == FALSE ){
		return FALSE;
	}
	return TRUE;
}

PROCESSES_RESULT VendingMachine::create_stockMng()
{
	// 飲み物情報の取得から在庫に設定する形への変換
	GoodsInfoVec drinkInfoVec;
	if( convert_segmentDataToGoodsInfoVec(USE_SEGMENT_TYPE_DRINK, drinkInfoVec) == FALSE ){
		return FALSE;
	}
	// お金情報の取得から在庫に設定する形への変換
	GoodsInfoVec moneyInfoVec;
	if( convert_segmentDataToGoodsInfoVec(USE_SEGMENT_TYPE_MONEY, moneyInfoVec) == FALSE ){
		return FALSE;
	}
	// 在庫管理クラスの作成、初期情報設定
	if( _stockMng->create(drinkInfoVec, moneyInfoVec) == FALSE ){
		return FALSE;
	}
	return TRUE;
}

PROCESSES_RESULT VendingMachine::convert_segmentDataToGoodsInfoVec(SegmentType targetType, GoodsInfoVec& goodsInfoVec)
{
	SegmentData segmentData = _mainControl->get_segmentData( targetType );
	
	for( auto dataRecord : segmentData._dataList ){
		GoodsInfo	info;
		if( targetType == USE_SEGMENT_TYPE_DRINK ){
			info._data._value = std::stoi( dataRecord[1] );
			info._data._stock = std::stoi( dataRecord[2] );
		}
		if( targetType == USE_SEGMENT_TYPE_MONEY ){
			info._data._value = std::stoi( dataRecord[0] );
			info._data._stock = std::stoi( dataRecord[1] );
		}
		info._name = dataRecord[0];
		goodsInfoVec.push_back( info );
	}
	return TRUE;
}