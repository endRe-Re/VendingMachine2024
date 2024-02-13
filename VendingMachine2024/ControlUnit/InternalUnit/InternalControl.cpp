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

USER_INPUT_ENUM InternalControl::get_displayString(DisplayFormat& displayString)
{
	_stateControl->make_displayString( displayString );
	return _stateControl->check_userInput();
}