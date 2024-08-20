#pragma once
#include "../../UtilityUnit/Utility.h"

#define ENTER_KYE_INPUT		'\n'
enum ENTER_ONLY_ENUM
{
	ENTER_ONLY_NON,
	ENTER_ONLY_TRUE
};

class UserInterface
{
public:
	UserInterface();

	UInt input_uInt(ENTER_ONLY_ENUM& isEnterOnly);
	void display(DisplayFormat& target);

private:
	String input_string();
	PROCESSES_RESULT contains_multibyte(const String& target);
};