#include "MainControl.h"
#include "InternalUnit/InternalControl.h"

MainControl::MainControl()
: _externalControl(nullptr)
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
	if(_externalControl == nullptr ){
		return FALSE;
	}
	if(_externalControl->create() == FALSE ){
		return FALSE;
	}

	_internalControl = new InternalControl();
	if(_internalControl == nullptr ){
		return FALSE;
	}
	if(_internalControl->create(stockMng) == FALSE ){
		return FALSE;
	}
	return TRUE;
}
