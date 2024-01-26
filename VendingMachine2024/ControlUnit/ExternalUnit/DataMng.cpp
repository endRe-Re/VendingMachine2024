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

// 受け取ったファイルデータをセグメント管理出来る形に変換して登録する
PROCESSES_RESULT DataMng::create_segmentMng(FileData& fileData)
{
	SegmentRegistVec segmentRegistVec;
	if( convert_fileDataToSegmentRegistVec(fileData, segmentRegistVec) == FALSE ){
		return FALSE;	// ファイル形式エラー
	}
	for( auto segmentRegist : segmentRegistVec ){
		_segmentMng->add_segment( segmentRegist.first, segmentRegist.second );
	}
	return TRUE;
}

// ファイルデータをセグメント登録できる形のvectorに変換する
// 呼び出し元では出力されたvector分登録処理を行う
// 1要素のfirseが第1引数、secondが第2引数となる
// 引数　fileData：ファイルデータ、segmentRegistVec：セグメント登録用リスト
PROCESSES_RESULT DataMng::convert_fileDataToSegmentRegistVec(FileData& fileData, SegmentRegistVec& segmentRegistVec)
{
	FileData forOneSegment;
	for( auto it = fileData.begin(); it != fileData.end(); ){
		// 種別のレコードではない場合、セクジョン名又はデータ部を見ているため、セグメントデータ内に登録
		// 登録開始時は種別のレコードを見るため、1セグメント登録用データが空の場合はデータ登録
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

// 1セグメント分のファイルデータからセグメント登録用フォーマットへ変換する
// この関数に渡る時点でフォーマットは担保されてなければならない
void DataMng::convert_fileDataToSegmentRegistFormat(FileData& forOneSegment, SegmentRegistFormat& segmentRegistFormat)
{
	auto convertPoint						= forOneSegment.begin();
	// セグメント種別とセクション名を取得
	segmentRegistFormat.first				= (*convertPoint)[0];
	++convertPoint;
	segmentRegistFormat.second._sectionName = (*convertPoint);
	++convertPoint;
	// データ部を取得
	for( convertPoint; convertPoint != forOneSegment.end(); ++convertPoint ){
		segmentRegistFormat.second._sectionName = *convertPoint;
	}
}
