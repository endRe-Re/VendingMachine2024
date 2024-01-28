#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �Z�O�����g�Ǘ��N���X
// �E�f�[�^�̈������̒�`��ۑ����Ă����N���X
// �E�N�����̏��ƂȂ�
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"

#include <string>
#include <unordered_map>

using Record	= VectorTemp<std::string>;
using RecordVec	= VectorTemp<Record>;
//! 1��(=�Z�O�����g)�̃f�[�^
struct SegmentData{
	Record		_sectionName;		// �l�̐���
	RecordVec	_dataList;			// �f�[�^�Q
};

using SegmentType		= std::string;									// �Z�O�����g���
using SegmentTypeVec	= VectorTemp<SegmentType>;
using SegmentUnmap		= std::unordered_map<SegmentType, SegmentData>;		// �S�f�[�^�}�b�v

#define SEGMENT_SIZE_MIN 3

class SegmentMng
{
public:
	SegmentMng();

	PROCESSES_RESULT add_segment(SegmentType segmentType, SegmentData segmentData);

private:
	SegmentTypeVec	_segmentTypeVec;		// �Z�O�����g��ʂ̈ꗗ
	SegmentUnmap	_segmentUnmap;			// �S�f�[�^�}�b�v
};

