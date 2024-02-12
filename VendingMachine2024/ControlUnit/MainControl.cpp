#include "MainControl.h"
#include "InternalUnit/InternalControl.h"

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
		return FALSE;
	}
	if( _externalControl->create() == FALSE ){
		return FALSE;
	}

	_internalControl = new InternalControl();
	if( _internalControl == nullptr ){
		return FALSE;
	}
	if( _internalControl->create(stockMng) == FALSE ){
		return FALSE;
	}
	return TRUE;
}

PROCESSES_RESULT MainControl::start_control()
{
	while( _internalControl->judge_controlType() == CONTROL_TYPE_CONTINUE ){
		// ƒƒjƒ…[o—Í
		DisplayFormat displayString;
		USER_INPUT_ENUM userInputType = _internalControl->get_displayString( displayString );
		_externalControl->display( displayString );
	}
	return TRUE;
}
