#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 外部制御クラス
// ・外部からの入出力を取りまとめるクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"
#include "DataMng.h"
#include "UserInterface.h"

class ExternalControl
{
public:
	ExternalControl();
	~ExternalControl();

	PROCESSES_RESULT create();		// 自クラスを含む各制御クラスの作成

	void display(DisplayFormat& target);
	UInt input_uInt(ENTER_ONLY_ENUM& isEnterOnly);

	SegmentData get_segmentData(SegmentType& segmentType);	// 指定種別のデータ取得

private:

	DataMng*		_dataMng;				// データ管理クラス
	UserInterface*	_userInterface;
};

inline void ExternalControl::display(DisplayFormat& target)
{
	_userInterface->display( target );
}
inline UInt ExternalControl::input_uInt(ENTER_ONLY_ENUM& isEnterOnly)
{
	return _userInterface->input_uInt( isEnterOnly );
}

inline SegmentData ExternalControl::get_segmentData(SegmentType& segmentType)
{
	return _dataMng->get_segmentData( segmentType );
}