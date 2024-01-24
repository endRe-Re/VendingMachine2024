#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 外部制御クラス
// ・外部からの入出力を取りまとめるクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"

class DataMng;

class ExternalControl
{
public:
	ExternalControl();

	PROCESSES_RESULT create();		// 自クラスを含む各制御クラスの作成

private:

	DataMng*		_dataMng;				// データ管理クラス
};