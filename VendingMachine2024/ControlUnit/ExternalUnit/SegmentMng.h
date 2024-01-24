#pragma once
#include "../../UtilityUnit/Utility.h"

#include <vector>
#include <string>
#include <unordered_map>

typedef std::vector<std::string>	Record;			// 1�s���̃f�[�^
typedef std::vector<Record>			RecordVec;		// �����s�̃f�[�^
//! 1��(=�Z�O�����g)�̃f�[�^
struct SegmentData{
	Record		_sectionName;		// �l�̐���
	RecordVec	_dataList;			// �f�[�^�Q
};

typedef std::string										SegmentType;		// �Z�O�����g���
typedef std::vector<SegmentType>						SegmentTypeVec;		// �Z�O�����g��ʂ̈ꗗ
typedef std::unordered_map<SegmentType, SegmentData>	SegmentUnmap;		// �S�f�[�^�}�b�v

class SegmentMng
{
public:
	SegmentMng();

	PROCESSES_RESULT add_segment(SegmentType segmentType, SegmentData segmentData);

private:
	SegmentTypeVec	_segmentTypeVec;		// �Z�O�����g��ʂ̈ꗗ
	SegmentUnmap	_segmentUnmap;			// �S�f�[�^�}�b�v
};

