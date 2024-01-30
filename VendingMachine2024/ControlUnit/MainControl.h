#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// メイン制御クラス
// ・データのやりとりや命令を中継するクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../UtilityUnit/Utility.h"
#include "ExternalUnit/ExternalControl.h"

class MainControl
{
public:
	MainControl();
	~MainControl();

	PROCESSES_RESULT create();		// 自クラスを含む各制御クラスの作成

	SegmentData get_segmentData(SegmentType& segmentType);

private:
	ExternalControl* _externalControl;				// 外部制御クラス
};


inline SegmentData MainControl::get_segmentData(SegmentType& segmentType)
{
	return _externalControl->get_segmentData( segmentType );
}