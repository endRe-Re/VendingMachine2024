#include "InternalControl.h"
#include "StateControl.h"

InternalControl::InternalControl()
: _stockMng(nullptr),
  _stateControl(nullptr)
{
}

PROCESSES_RESULT InternalControl::create(StockMng* stockMng)
{
	if( _stockMng == nullptr ){
		return FALSE;
	}
	_stockMng		= stockMng;
	_stateControl	= new StateControl();
	if( _stateControl == nullptr ){
		return FALSE;
	}
	return TRUE;
}

USER_INPUT_ENUM InternalControl::ct(DisplayFormat& didplayFormat)
{
	_stateControl->make_displayString( didplayFormat );
	return _stateControl->check_userInput();
}
