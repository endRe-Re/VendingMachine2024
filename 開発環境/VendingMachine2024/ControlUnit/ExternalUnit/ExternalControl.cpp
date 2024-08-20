#include "ExternalControl.h"

ExternalControl::ExternalControl()
: _dataMng(nullptr),
  _userInterface(nullptr)
{
}

ExternalControl::~ExternalControl()
{
	delete _dataMng;
	_dataMng = nullptr;
	delete _userInterface;
	_userInterface = nullptr;
}

PROCESSES_RESULT ExternalControl::create()
{
	_dataMng = new DataMng();
	if( _dataMng == nullptr ){
		return PROCESSES_FALSE;
	}
	if( _dataMng->create() == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}

	_userInterface = new UserInterface();
	if( _userInterface == nullptr ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
}


