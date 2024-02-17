#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface()
{
}

UInt UserInterface::input_uInt(ENTER_ONLY_ENUM& isEnterOnly)
{
	UInt retVal = UINT_INIT;
	return retVal;
}

void UserInterface::display(DisplayFormat& target)
{
	for( auto oneLine : target ){
		std::cout << oneLine << std::endl;
	}
}
