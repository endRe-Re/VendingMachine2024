#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �O������N���X
// �E�O������̓��o�͂����܂Ƃ߂�N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"
#include "DataMng.h"


class ExternalControl
{
public:
	ExternalControl();
	~ExternalControl();

	PROCESSES_RESULT create();		// ���N���X���܂ފe����N���X�̍쐬

	SegmentData get_segmentData(SegmentType& segmentType);

private:

	DataMng*		_dataMng;				// �f�[�^�Ǘ��N���X
};

inline SegmentData ExternalControl::get_segmentData(SegmentType& segmentType)
{
	return _dataMng->get_segmentData( segmentType );
}