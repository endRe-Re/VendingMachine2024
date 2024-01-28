#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// セグメント管理クラス
// ・データの扱い方の定義や保存しておくクラス
// ・起動時の情報となる
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"

#include <string>
#include <unordered_map>

using Record	= VectorTemp<std::string>;
using RecordVec	= VectorTemp<Record>;
//! 1塊(=セグメント)のデータ
struct SegmentData{
	Record		_sectionName;		// 値の説明
	RecordVec	_dataList;			// データ群
};

using SegmentType		= std::string;									// セグメント種別
using SegmentTypeVec	= VectorTemp<SegmentType>;
using SegmentUnmap		= std::unordered_map<SegmentType, SegmentData>;		// 全データマップ

#define SEGMENT_SIZE_MIN 3

class SegmentMng
{
public:
	SegmentMng();

	PROCESSES_RESULT add_segment(SegmentType segmentType, SegmentData segmentData);

private:
	SegmentTypeVec	_segmentTypeVec;		// セグメント種別の一覧
	SegmentUnmap	_segmentUnmap;			// 全データマップ
};

