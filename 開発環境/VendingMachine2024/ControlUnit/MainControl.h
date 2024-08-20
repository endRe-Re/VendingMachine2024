#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���C������N���X
// �E�f�[�^�̂��Ƃ�▽�߂𒆌p����N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../UtilityUnit/Utility.h"
#include "ExternalUnit/ExternalControl.h"
#include "InternalUnit/InternalControl.h"

class StockMng;

class MainControl
{
public:
	MainControl();
	~MainControl();

	PROCESSES_RESULT create(StockMng* stockMng);		// ���N���X���܂ފe����N���X�̍쐬
	PROCESSES_RESULT start_control();
	void start_controlForInputNeed();

	SegmentData get_segmentData(SegmentType& segmentType);

private:
	ExternalControl* _externalControl;				// �O������N���X
	InternalControl* _internalControl;				// ��������N���X
};


inline SegmentData MainControl::get_segmentData(SegmentType& segmentType)
{
	return _externalControl->get_segmentData( segmentType );
}