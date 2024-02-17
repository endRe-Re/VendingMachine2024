#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �O������N���X
// �E�O������̓��o�͂����܂Ƃ߂�N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"
#include "DataMng.h"
#include "UserInterface.h"

class ExternalControl
{
public:
	ExternalControl();
	~ExternalControl();

	PROCESSES_RESULT create();		// ���N���X���܂ފe����N���X�̍쐬

	void display(DisplayFormat& target);
	UInt input_uInt(ENTER_ONLY_ENUM& isEnterOnly);

	SegmentData get_segmentData(SegmentType& segmentType);	// �w���ʂ̃f�[�^�擾

private:

	DataMng*		_dataMng;				// �f�[�^�Ǘ��N���X
	UserInterface*	_userInterface;
};

inline void ExternalControl::display(DisplayFormat& target)
{
	_userInterface->display( target );
}
inline UInt ExternalControl::input_uInt(ENTER_ONLY_ENUM& isEnterOnly)
{
	return _userInterface->input_uInt( isEnterOnly );
}

inline SegmentData ExternalControl::get_segmentData(SegmentType& segmentType)
{
	return _dataMng->get_segmentData( segmentType );
}