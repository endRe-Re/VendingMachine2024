#pragma once
#include "../UtilityUnit/Utility.h"

class ExternalControl;

class MainControl
{
public:
	MainControl();

	PROCESSES_RESULT create();		// ���N���X���܂ފe����N���X�̍쐬

private:
	ExternalControl* _externalControl;				// �f�[�^�Ǘ��N���X
};