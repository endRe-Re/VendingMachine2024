#include "MainControl.h"


MainControl::MainControl()
: _externalControl(nullptr)
{
}

MainControl::~MainControl()
{
	delete _externalControl;
	_externalControl = nullptr;
}

PROCESSES_RESULT MainControl::create()
{
	_externalControl = new ExternalControl();
	if(_externalControl == nullptr ){
		return FALSE;
	}
	if(_externalControl->create() == FALSE ){
		return FALSE;
	}

	return TRUE;
}
