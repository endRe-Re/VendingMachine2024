#include "SegmentMng.h"
#include <iterator>

SegmentMng::SegmentMng()
{
}

PROCESSES_RESULT SegmentMng::add_segment(SegmentType& segmentType, SegmentData& segmentData)
{
	// �Z�O�����g��ʂƎw��Z�O�����g�̃X�N�V�������͖��o�^�̏ꍇ�̂ݓo�^
	if( std::find(_segmentTypeVec.begin(), _segmentTypeVec.end(), segmentType) == _segmentTypeVec.end() ){
		_segmentTypeVec.push_back( segmentType );
		_segmentUnmap[segmentType]._sectionName = segmentData._sectionName;
	}
	// �f�[�^����ǉ�����
	std::copy( segmentData._dataList.begin(), segmentData._dataList.end(), std::back_inserter(_segmentUnmap[segmentType]._dataList) );
	
	return TRUE;
}

SegmentData SegmentMng::get_segmentData(SegmentType& segmentType)
{
	SegmentData retVal;
	if( _segmentUnmap.count(segmentType) != NO_EXIST_KEY ){
		retVal = _segmentUnmap[segmentType];
	}

	return retVal;
}
