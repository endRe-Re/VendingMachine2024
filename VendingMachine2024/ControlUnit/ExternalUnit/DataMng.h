#pragma once
#include "../../UtilityUnit/Utility.h"
#include "FileSystem.h"

typedef std::pair<SegmentType, SegmentData>		SegmentRegistFormat;
typedef std::vector<SegmentType, SegmentData>	SegmentRegistVec;

class FileSystem;
class SegmentMng;

class DataMng
{
public:
	DataMng();
	~DataMng();

	PROCESSES_RESULT create();

private:
	PROCESSES_RESULT create_segmentMng(FileData& fileData);		// 
	void convert_fileDataToSegmentRegistVec(FileData& fileData, SegmentRegistVec& segmentRegistVec);

	FileSystem*		_fileSystem;
	SegmentMng*		_segmentMng;			// セグメント管理クラス
};