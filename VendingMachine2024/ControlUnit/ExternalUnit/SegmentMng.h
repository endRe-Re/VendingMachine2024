#pragma once
#include "../../UtilityUnit/Utility.h"

#include <vector>
#include <string>
#include <unordered_map>

typedef std::vector<std::string>	Record;			// 1行分のデータ
typedef std::vector<Record>			RecordVec;		// 複数行のデータ
//! 1塊(=セグメント)のデータ
struct SegmentData{
	Record		_sectionName;		// 値の説明
	RecordVec	_dataList;			// データ群
};

typedef std::string										SegmentType;		// セグメント種別
typedef std::vector<SegmentType>						SegmentTypeVec;		// セグメント種別の一覧
typedef std::unordered_map<SegmentType, SegmentData>	SegmentUnmap;		// 全データマップ

class SegmentMng
{
public:
	SegmentMng();

	PROCESSES_RESULT add_segment(SegmentType segmentType, SegmentData segmentData);

private:
	SegmentTypeVec	_segmentTypeVec;		// セグメント種別の一覧
	SegmentUnmap	_segmentUnmap;			// 全データマップ
};

