#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 内部制御クラス
// ・自動販売機の内部処理を行うクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"
#include "StateControl.h"

class StockMng;

class InternalControl
{
public:
	InternalControl();

	PROCESSES_RESULT create(StockMng* stockMng);
	USER_INPUT_ENUM ct(DisplayFormat& didplayFormat);

private:
	StockMng*		_stockMng;
	StateControl*	_stateControl
};