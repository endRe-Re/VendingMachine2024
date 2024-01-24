#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// データ管理クラス
// ・ファイルシステムクラスとセグメント管理クラスの中間にたち、
// 　相互変換や別クラスとデータのやりとりを取りまとめるクラス
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

	PROCESSES_RESULT create();										// 下位クラスのインスタンス生成

private:
	PROCESSES_RESULT create_segmentMng(FileData& fileData);																// セグメント管理クラスへの情報登録
	PROCESSES_RESULT convert_fileDataToSegmentRegistVec(FileData& fileData, SegmentRegistVec& segmentRegistVec);		//
	void convert_fileDataToSegmentRegistFormat(FileData& forOneSegment, SegmentRegistFormat& segmentRegistFormat);		//

	FileSystem*		_fileSystem;			// ファイルシステムクラス
	SegmentMng*		_segmentMng;			// セグメント管理クラス
};