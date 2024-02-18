#include "UserInterface.h"
#include <iostream>
#include <algorithm>
#include <regex>

UserInterface::UserInterface()
{
}

UInt UserInterface::input_uInt(ENTER_ONLY_ENUM& isEnterOnly)
{
	isEnterOnly		= ENTER_ONLY_NON;
	UInt	retVal	= UINT_INIT;
	String	input	= input_string();
	// エンターキーのみ
	if( input.empty() == true ){
		isEnterOnly = ENTER_ONLY_TRUE;
	}
	// 全角文字を含む
	else if( contains_multibyte(input) == true ){
	
	}
	// 半角数字のみ
	else if( std::all_of(input.cbegin(), input.cend(), isdigit) == true ){
		retVal = std::stoi( input );
	}
	// 半角数字以外を含む
	else{
	
	}
	return retVal;
}

void UserInterface::display(DisplayFormat& target)
{
	for( auto oneLine : target ){
		std::cout << oneLine << std::endl;
	}
}

String UserInterface::input_string()
{
	String	input;
	char	inputOneChar	= ' ';
	while( inputOneChar != ENTER_KYE_INPUT ){
		inputOneChar = std::cin.get();
		input += inputOneChar;
	}
	input.pop_back();
	return input;
}

PROCESSES_RESULT UserInterface::contains_multibyte(const String& target)
{
	std::regex			pattern("[^ -~｡-ﾟ]");
	PROCESSES_RESULT	retVal = PROCESSES_FALSE;
	if( regex_search(target, pattern) == true ){
		retVal = PROCESSES_TRUE;
	}
	return retVal;
}
