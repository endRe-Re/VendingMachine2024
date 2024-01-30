#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���C������N���X
// �E�f�[�^�̂��Ƃ�▽�߂𒆌p����N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../UtilityUnit/Utility.h"
#include "ExternalUnit/ExternalControl.h"

class MainControl
{
public:
	MainControl();
	~MainControl();

	PROCESSES_RESULT create();		// ���N���X���܂ފe����N���X�̍쐬

	SegmentData get_segmentData(SegmentType& segmentType);

private:
	ExternalControl* _externalControl;				// �O������N���X
};


inline SegmentData MainControl::get_segmentData(SegmentType& segmentType)
{
	return _externalControl->get_segmentData( segmentType );
}