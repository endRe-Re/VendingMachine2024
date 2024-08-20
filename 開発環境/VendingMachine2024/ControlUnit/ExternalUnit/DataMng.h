#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �f�[�^�Ǘ��N���X
// �E�t�@�C���V�X�e���N���X�ƃZ�O�����g�Ǘ��N���X�̒��Ԃɂ����A
// �@���ݕϊ���ʃN���X�ƃf�[�^�̂��Ƃ�����܂Ƃ߂�N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"
#include "FileSystem.h"
#include "SegmentMng.h"

using SegmentRegistFormat	= std::pair<SegmentType, SegmentData>;
using SegmentRegistVec		= VectorTemp<SegmentRegistFormat>;

constexpr auto SEGMENT_TYPE_STR = "[";

class FileSystem;
class SegmentMng;

class DataMng
{
public:
	DataMng();
	~DataMng();

	PROCESSES_RESULT create();										// ���ʃN���X�̃C���X�^���X����

	SegmentData get_segmentData(SegmentType& segmentType);			// �w���ʂ̃f�[�^�擾

private:
	PROCESSES_RESULT create_segmentMng(FileData& fileData);																// �Z�O�����g�Ǘ��N���X�ւ̏��o�^
	PROCESSES_RESULT convert_fileDataToSegmentRegistVec(FileData& fileData, SegmentRegistVec& segmentRegistVec);				// �o�^�p�t�H�[�}�b�g�ϊ�
	PROCESSES_RESULT convert_fileDataToSegmentRegistFormat(FileData& forOneSegment, SegmentRegistFormat& segmentRegistFormat);	// 1�Z�O�����g���o�^�p�t�H�[�}�b�g�ϊ�

	FileSystem*		_fileSystem;			// �t�@�C���V�X�e���N���X
	SegmentMng*		_segmentMng;			// �Z�O�����g�Ǘ��N���X
};

inline SegmentData DataMng::get_segmentData(SegmentType& segmentType)
{
	return _segmentMng->get_segmentData( segmentType );
}