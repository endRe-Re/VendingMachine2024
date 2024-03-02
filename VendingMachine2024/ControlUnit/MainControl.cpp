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
	delete _internalControl;
	_internalControl = nullptr;
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
		USER_INPUT_ENUM userInputEnum = _internalControl->check_userInputForState();
		if( userInputEnum == USER_INPUT_NEED ){
			start_controlForInputNeed();	// ユーザー入力必要時の処理
		}
		else{
			DisplayFormat guideString;
			_internalControl->trans_nextStateForNonInput( guideString );
			_externalControl->display( displayString );
		}
	}
	return PROCESSES_TRUE;
}

void MainControl::start_controlForInputNeed()
{
	INPUT_TYPE_ENUM	inputCheckResult = INPUT_TYPE_RETRY;
	while( inputCheckResult == INPUT_TYPE_RETRY ){
		ENTER_ONLY_ENUM	isEnterOnly			= ENTER_ONLY_NON;
		UInt			userInput			= _externalControl->input_uInt( isEnterOnly );
		// 入力内容を読み込み、内容次第で次へ遷移させる
		// 指示内容かエラー内容が出力される
		DisplayFormat	guideString;
		INPUT_TYPE_ENUM	inputCheckResult	= _internalControl->read_userInput( userInput, guideString );
		_externalControl->display( guideString );	// 読み込んだ結果が表示される
	}
}
