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
	// 必要情報の作成
	if( create() == PROCESSES_FALSE ){
		return false;
	}
	// メイン制御開始
	_mainControl->start_control();
	return true;
}

PROCESSES_RESULT VendingMachine::create()
{
	// 在庫管理クラス作成
	_stockMng = new StockMng();
	if( _stockMng == nullptr ){
		return PROCESSES_FALSE;
	}
	// メイン制御クラス作成
	_mainControl = new MainControl();
	if( _mainControl == nullptr ){
		return PROCESSES_FALSE;
	}
	if( _mainControl->create(_stockMng) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}

	if( create_stockMng() == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
}

PROCESSES_RESULT VendingMachine::create_stockMng()
{
	// 飲み物情報の取得から在庫に設定する形への変換
	GoodsInfoVec drinkInfoVec;
	if( convert_segmentDataToGoodsInfoVec(USE_SEGMENT_TYPE_DRINK, drinkInfoVec) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	// お金情報の取得から在庫に設定する形への変換
	GoodsInfoVec moneyInfoVec;
	if( convert_segmentDataToGoodsInfoVec(USE_SEGMENT_TYPE_MONEY, moneyInfoVec) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	// 在庫管理クラスの作成、初期情報設定
	if( _stockMng->create(drinkInfoVec, moneyInfoVec) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
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
	return PROCESSES_TRUE;
}