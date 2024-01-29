#include "DataMng.h"
#include "FileSystem.h"
#include "SegmentMng.h"

DataMng::DataMng()
: _fileSystem(nullptr),
  _segmentMng(nullptr)
{
}

DataMng::~DataMng()
{
	delete _fileSystem;
	delete _segmentMng;
	_fileSystem = nullptr;
	_segmentMng = nullptr;
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
	PROCESSES_RESULT	retVal = TRUE;
	FileData forOneSegment;
	for( auto it = fileData.begin(); retVal == TRUE; ){
		// �t�@�C���I�[�ɓ��B�������߁A1�Z�O�����g�Ƃ��ĕϊ�
		bool doConvert = false;
		if( it == fileData.end() ){
			doConvert = true;
		}
		if( doConvert == false ){
			size_t found = it[0][0].find("[");
			// ���̃Z�O�����g�ɓ��B�������߁A1�Z�O�����g�Ƃ��ĕϊ�
			if( (found != std::string::npos) && (forOneSegment.empty() == false) ){
				doConvert = true;
			}
		}
		if( doConvert == true ){
			// �o�^�p���X�g��1�Z�O�����g���̃f�[�^��o�^����
			SegmentRegistFormat segmentRegistFormat;
			retVal = convert_fileDataToSegmentRegistFormat( forOneSegment, segmentRegistFormat );
			segmentRegistVec.push_back( segmentRegistFormat );
			forOneSegment.clear();
		}
		if( it == fileData.end() ){
			break;	// �t�@�C���ǂݍ��ݏI��
		}
		forOneSegment.push_back( *it );
		++it;
	}
	return TRUE;
}

// 1�Z�O�����g���̃t�@�C���f�[�^����Z�O�����g�o�^�p�t�H�[�}�b�g�֕ϊ�����
PROCESSES_RESULT DataMng::convert_fileDataToSegmentRegistFormat(FileData& forOneSegment, SegmentRegistFormat& segmentRegistFormat)
{
	if( (unsigned long)forOneSegment.size() < SEGMENT_SIZE_MIN ){
		return FALSE;
	}
	auto convertPoint						= forOneSegment.begin();
	// �Z�O�����g��ʂƃZ�N�V���������擾
	segmentRegistFormat.first				= (*convertPoint)[0];
	++convertPoint;
	segmentRegistFormat.second._sectionName = (*convertPoint);
	++convertPoint;
	// �f�[�^�����擾
	for( convertPoint; convertPoint != forOneSegment.end(); ++convertPoint ){
		if( segmentRegistFormat.second._sectionName.size() != (*convertPoint).size() ){
			return FALSE;	// �Z�N�V�����l�[�����f�[�^���Ȃ��ꍇ�A�G���[
		}
		segmentRegistFormat.second._dataList.push_back( *convertPoint );
	}
	return TRUE;
}
