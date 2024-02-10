#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������N���X
// �E�����̔��@�̓����������s���N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"
#include "StateControl.h"

class StockMng;

class InternalControl
{
public:
	InternalControl();

	PROCESSES_RESULT create(StockMng* stockMng);
	USER_INPUT_ENUM get_displayString(DisplayFormat& displayString);

private:
	StockMng*		_stockMng;
	StateControl*	_stateControl;
};