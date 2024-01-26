#include "DataMng.h"
#include "FileSystem.h"
#include "SegmentMng.h"
#include <iterator>

DataMng::DataMng()
: _fileSystem(nullptr),
  _segmentMng(nullptr)
{
}

DataMng::~DataMng()
{
	delete _fileSystem;
}

PROCESSES_RESULT DataMng::create()
{
	_fileSystem = new FileSystem();
	if( _fileSystem == nullptr ){
		return FALSE;
	}
	FileData fileData;
	if( _fileSystem->load_file(fileData) == FALSE ){
		return FALSE;
	}
	_segmentMng = new SegmentMng();
	if( _segmentMng == nullptr ){
		return FALSE;
	}
	if( create_segmentMng(fileData) == FALSE ){
		return FALSE;
	}

	return TRUE;
}

// �󂯎�����t�@�C���f�[�^���Z�O�����g�Ǘ��o����`�ɕϊ����ēo�^����
PROCESSES_RESULT DataMng::create_segmentMng(FileData& fileData)
{
	SegmentRegistVec segmentRegistVec;
	if( convert_fileDataToSegmentRegistVec(fileData, segmentRegistVec) == FALSE ){
		return FALSE;	// �t�@�C���`���G���[
	}
	for( auto segmentRegist : segmentRegistVec ){
		_segmentMng->add_segment( segmentRegist.first, segmentRegist.second );
	}
	return TRUE;
}

// �t�@�C���f�[�^���Z�O�����g�o�^�ł���`��vector�ɕϊ�����
// �Ăяo�����ł͏o�͂��ꂽvector���o�^�������s��
// 1�v�f��firse����1�����Asecond����2�����ƂȂ�
// �����@fileData�F�t�@�C���f�[�^�AsegmentRegistVec�F�Z�O�����g�o�^�p���X�g
PROCESSES_RESULT DataMng::convert_fileDataToSegmentRegistVec(FileData& fileData, SegmentRegistVec& segmentRegistVec)
{
	FileData forOneSegment;
	for( auto it = fileData.begin(); it != fileData.end(); ){
		// ��ʂ̃��R�[�h�ł͂Ȃ��ꍇ�A�Z�N�W���������̓f�[�^�������Ă��邽�߁A�Z�O�����g�f�[�^���ɓo�^
		// �o�^�J�n���͎�ʂ̃��R�[�h�����邽�߁A1�Z�O�����g�o�^�p�f�[�^����̏ꍇ�̓f�[�^�o�^
		int found = it[0][0].find( "[" );
		if( (found == std::string::npos) || (forOneSegment.empty() == true) ){
			forOneSegment.push_back( *it );
			++it;
			continue;
		}
		SegmentRegistFormat segmentRegistFormat;
		convert_fileDataToSegmentRegistFormat( forOneSegment, segmentRegistFormat );
		segmentRegistVec.push_back( segmentRegistFormat );
		forOneSegment.clear();
	}
	return TRUE;
}

// 1�Z�O�����g���̃t�@�C���f�[�^����Z�O�����g�o�^�p�t�H�[�}�b�g�֕ϊ�����
// ���̊֐��ɓn�鎞�_�Ńt�H�[�}�b�g�͒S�ۂ���ĂȂ���΂Ȃ�Ȃ�
void DataMng::convert_fileDataToSegmentRegistFormat(FileData& forOneSegment, SegmentRegistFormat& segmentRegistFormat)
{
	auto convertPoint						= forOneSegment.begin();
	// �Z�O�����g��ʂƃZ�N�V���������擾
	segmentRegistFormat.first				= (*convertPoint)[0];
	++convertPoint;
	segmentRegistFormat.second._sectionName = (*convertPoint);
	++convertPoint;
	// �f�[�^�����擾
	for( convertPoint; convertPoint != forOneSegment.end(); ++convertPoint ){
		segmentRegistFormat.second._sectionName = *convertPoint;
	}
}
