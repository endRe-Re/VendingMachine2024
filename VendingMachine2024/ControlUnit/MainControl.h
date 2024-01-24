#pragma once
#include "../UtilityUnit/Utility.h"

class ExternalControl;

class MainControl
{
public:
	MainControl();

	PROCESSES_RESULT create();		// 自クラスを含む各制御クラスの作成

private:
	ExternalControl* _externalControl;				// データ管理クラス
};