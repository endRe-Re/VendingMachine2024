#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// メイン制御クラス
// ・データのやりとりや命令を中継するクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../UtilityUnit/Utility.h"
#include "ExternalUnit/ExternalControl.h"
#include "InternalUnit/InternalControl.h"

class StockMng;

class MainControl
{
public:
	MainControl();
	~MainControl();

	PROCESSES_RESULT create(StockMng* stockMng);		// 自クラスを含む各制御クラスの作成
	PROCESSES_RESULT start_control();
	void start_controlForInputNeed();

	SegmentData get_segmentData(SegmentType& segmentType);

private:
	ExternalControl* _externalControl;				// 外部制御クラス
	InternalControl* _internalControl;				// 内部制御クラス
};


inline SegmentData MainControl::get_segmentData(SegmentType& segmentType)
{
	return _externalControl->get_segmentData( segmentType );
}