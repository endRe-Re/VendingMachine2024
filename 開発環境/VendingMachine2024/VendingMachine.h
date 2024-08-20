#pragma once
#include "UtilityUnit/Utility.h"
#include "ControlUnit/MainControl.h"
#include "StockUnit/StockMng.h"

// 自動販売機で使用するセグメント種別
static const SegmentType USE_SEGMENT_TYPE_DRINK = "[Drink]";
static const SegmentType USE_SEGMENT_TYPE_MONEY = "[Money]";

class VendingMachine
{
public:
	VendingMachine();
	~VendingMachine();

	bool activation();				// 起動

private:
	PROCESSES_RESULT create();
	PROCESSES_RESULT create_stockMng();
	PROCESSES_RESULT convert_segmentDataToGoodsInfoVec(SegmentType SegmentType, GoodsInfoVec& goodsInfoVec);

	MainControl*	_mainControl;	//メイン制御クラス
	StockMng*		_stockMng;		//在庫管理クラス
};
