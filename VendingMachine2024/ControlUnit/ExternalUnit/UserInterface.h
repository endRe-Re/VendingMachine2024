#pragma once
#include "../../UtilityUnit/Utility.h"

enum ENTER_ONLY_ENUM
{
	ENTER_ONLY_NON,
	ENTER_ONLY_TRUE
};

class UserInterface
{
public:
	UserInterface();

	UInt input_uInt(ENTER_ONLY_ENUM isEnterOnly);
	void display(DisplayFormat& target);

private:
};