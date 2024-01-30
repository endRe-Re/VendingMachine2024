#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 外部制御クラス
// ・外部からの入出力を取りまとめるクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"
#include "DataMng.h"


class ExternalControl
{
public:
	ExternalControl();
	~ExternalControl();

	PROCESSES_RESULT create();		// 自クラスを含む各制御クラスの作成

	SegmentData get_segmentData(SegmentType& segmentType);

private:

	DataMng*		_dataMng;				// データ管理クラス
};

inline SegmentData ExternalControl::get_segmentData(SegmentType& segmentType)
{
	return _dataMng->get_segmentData( segmentType );
}