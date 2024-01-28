#include "VendingMachine.h"
#include "ControlUnit/MainControl.h"
#include "UtilityUnit/Utility.h"

VendingMachine::VendingMachine()
: _mainControl(nullptr)
{

}

bool VendingMachine::activation()
{
	_mainControl = new MainControl();
	if(_mainControl == nullptr ){
		return false;
	}
	if(_mainControl->create() == FALSE ){
		return false;
	}

	delete _mainControl;
	return true;
}
