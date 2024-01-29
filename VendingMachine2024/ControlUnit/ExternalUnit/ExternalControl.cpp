#include "ExternalControl.h"

ExternalControl::ExternalControl()
: _dataMng(nullptr)
{
}

ExternalControl::~ExternalControl()
{
	delete _dataMng;
	_dataMng = nullptr;
}

PROCESSES_RESULT ExternalControl::create()
{
	_dataMng = new DataMng();
	if( _dataMng == nullptr ){
		return FALSE;
	}
	if( _dataMng->create() == FALSE ){
		return FALSE;
	}


	return TRUE;
}


