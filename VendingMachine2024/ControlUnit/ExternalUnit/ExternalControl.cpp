#include "ExternalControl.h"
#include "DataMng.h"

ExternalControl::ExternalControl()
: _dataMng(nullptr)
{
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


