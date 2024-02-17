#include "MainControl.h"

MainControl::MainControl()
: _externalControl(nullptr),
  _internalControl(nullptr)
{
}

MainControl::~MainControl()
{
	delete _externalControl;
	_externalControl = nullptr;
}

PROCESSES_RESULT MainControl::create(StockMng* stockMng)
{
	_externalControl = new ExternalControl();
	if( _externalControl == nullptr ){
		return PROCESSES_FALSE;
	}
	if( _externalControl->create() == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}

	_internalControl = new InternalControl();
	if( _internalControl == nullptr ){
		return PROCESSES_FALSE;
	}
	if( _internalControl->create(stockMng) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
}

PROCESSES_RESULT MainControl::start_control()
{
	while( _internalControl->judge_controlTypeBaseState() == CONTROL_TYPE_CONTINUE ){
		// メニュー出力
		DisplayFormat	displayString;
		_internalControl->get_displayString( displayString );
		_externalControl->display( displayString );
		// ユーザー入力必要時の処理
		start_controlForInputNeed();
	}
	return PROCESSES_TRUE;
}

PROCESSES_RESULT MainControl::start_controlForInputNeed()
{
	USER_INPUT_ENUM userInputEnum = _internalControl->check_userInputForState();
	while( userInputEnum == USER_INPUT_NEED ){
		ENTER_ONLY_ENUM	isEnterOnly	= ENTER_ONLY_NON;
		UInt			userInput	= _externalControl->input_uInt( isEnterOnly );
		DisplayFormat displayString;
		userInputEnum = _internalControl->check_userInput( userInput, displayString );
	}
	return PROCESSES_TRUE;
}
