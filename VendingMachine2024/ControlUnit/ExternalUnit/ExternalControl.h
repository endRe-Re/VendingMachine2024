#pragma once
#include "../../UtilityUnit/Utility.h"
#include "SegmentMng.h"

class DataMng;

class ExternalControl
{
public:
	ExternalControl();

	PROCESSES_RESULT create();		// 自クラスを含む各制御クラスの作成

private:

	DataMng*		_dataMng;				// データ管理クラス
};