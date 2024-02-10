#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface()
{
}

void UserInterface::display(DisplayFormat& target)
{
	for( auto oneLine : target ){
		std::cout << oneLine << std::endl;
	}
}
