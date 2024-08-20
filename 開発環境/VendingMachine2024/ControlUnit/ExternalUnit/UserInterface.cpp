#include "UserInterface.h"
#include <iostream>
#include <algorithm>
#include <regex>

UserInterface::UserInterface()
{
}

UInt UserInterface::input_uInt(ENTER_ONLY_ENUM& isEnterOnly)
{
	isEnterOnly			= ENTER_ONLY_NON;
	UInt retVal			= UINT_INIT;
	bool checkResult	= false;
	while( checkResult == false ){
		String			input = input_string();
		DisplayFormat	target;
		// �S�p�������܂�
		if( contains_multibyte(input) == PROCESSES_TRUE ){
			target.push_back("�S�p�����ɂ͔�Ή��ł�");
			target.push_back("�ē��͂��Ă�������");
		}
		// ���p�����ȊO���܂�
		else if( std::all_of(input.cbegin(), input.cend(), isdigit) == false ){
			target.push_back("�����݂̂���͂��Ă�������");
			target.push_back("�ē��͂��Ă�������");
		}
		// �G���^�[�L�[�̂�
		else if( input.empty() == true ){
			isEnterOnly = ENTER_ONLY_TRUE;
			checkResult = true;
		}
		// ���p�����̂�
		else{
			retVal		= std::stoi( input );
			checkResult	= true;
		}
		display( target );
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
	std::regex			pattern("[^ -~�-�]");
	PROCESSES_RESULT	retVal = PROCESSES_FALSE;
	if( regex_search(target, pattern) == true ){
		retVal = PROCESSES_TRUE;
	}
	return retVal;
}
