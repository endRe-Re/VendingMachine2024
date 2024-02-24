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

	PROCESSES_RESULT create(StockMng* stockMng);				// 
	void get_displayString(DisplayFormat& displayString);		// 
	PROCESSES_RESULT read_userInput(UInt userInput, DisplayFormat& displayString);		//

	CONTROL_TYPE_ENUM judge_controlTypeBaseState();				// 
	USER_INPUT_ENUM check_userInputForState();					// 

private:
	StockMng*		_stockMng;
	StateControl*	_stateControl;
};

inline CONTROL_TYPE_ENUM InternalControl::judge_controlTypeBaseState()
{
	return _stateControl->judge_controlTypeBaseState();
}

inline USER_INPUT_ENUM InternalControl::check_userInputForState()
{
	return _stateControl->check_userInputForState();
}