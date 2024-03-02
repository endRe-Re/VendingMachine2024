#include "InternalControl.h"
#include "StateControl.h"

InternalControl::InternalControl()
: _stockMng(nullptr),
  _stateControl(nullptr)
{
}

PROCESSES_RESULT InternalControl::create(StockMng* stockMng)
{
	if( stockMng == nullptr ){
		return PROCESSES_FALSE;
	}
	_stockMng		= stockMng;
	_stateControl	= new StateControl();
	if( _stateControl == nullptr ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
}

void InternalControl::get_displayString(DisplayFormat& displayString)
{
	_stateControl->make_displayString( displayString );
}

//入力内容をチェックしてから正しい指定であれば読み込んで次に遷移させる
// 指定が違っていれば、どう違うのかを出力文字列として設定する
INPUT_TYPE_ENUM InternalControl::read_userInput(UInt userInput, DisplayFormat& displayString)
{
	INPUT_TYPE_ENUM			retVal			= INPUT_TYPE_OK;
	INPUT_CHECK_TYPE_ENUM	inputChkType	= _stateControl->judge_inputCheckType();
	// 状態入力
	if( inputChkType == INPUT_CHECK_TYPE_STATE ){
		if( (USER_SELECT_NONE < userInput) && (userInput < USER_SELECT_NUM) ){
			_stateControl->trans_nextState( (USER_SELECT_ENUM)userInput );
		}
		else{
			retVal = INPUT_TYPE_RETRY;
		}
	}
	// お金入力
	else if( inputChkType == INPUT_CHECK_TYPE_MONEY ){
	
	}
	// 商品入力
	else if( inputChkType == INPUT_CHECK_TYPE_STOCK ){
	
	}
	else{}
	return retVal;
}
