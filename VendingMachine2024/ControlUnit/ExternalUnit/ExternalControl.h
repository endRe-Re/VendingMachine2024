#pragma once
#include "../../UtilityUnit/Utility.h"
#include "SegmentMng.h"

class DataMng;

class ExternalControl
{
public:
	ExternalControl();

	PROCESSES_RESULT create();		// ���N���X���܂ފe����N���X�̍쐬

private:

	DataMng*		_dataMng;				// �f�[�^�Ǘ��N���X
};