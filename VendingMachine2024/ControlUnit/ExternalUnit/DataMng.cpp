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
	PROCESSES_RESULT	retVal = TRUE;
	FileData forOneSegment;
	for( auto it = fileData.begin(); retVal == TRUE; ){
		// ファイル終端に到達したため、1セグメントとして変換
		bool doConvert = false;
		if( it == fileData.end() ){
			doConvert = true;
		}
		if( doConvert == false ){
			size_t found = it[0][0].find("[");
			// 次のセグメントに到達したため、1セグメントとして変換
			if( (found != std::string::npos) && (forOneSegment.empty() == false) ){
				doConvert = true;
			}
		}
		if( doConvert == true ){
			// 登録用リストに1セグメント分のデータを登録する
			SegmentRegistFormat segmentRegistFormat;
			retVal = convert_fileDataToSegmentRegistFormat( forOneSegment, segmentRegistFormat );
			segmentRegistVec.push_back( segmentRegistFormat );
			forOneSegment.clear();
		}
		if( it == fileData.end() ){
			break;	// ファイル読み込み終了
		}
		forOneSegment.push_back( *it );
		++it;
	}
	return TRUE;
}

// 1セグメント分のファイルデータからセグメント登録用フォーマットへ変換する
PROCESSES_RESULT DataMng::convert_fileDataToSegmentRegistFormat(FileData& forOneSegment, SegmentRegistFormat& segmentRegistFormat)
{
	if( (unsigned long)forOneSegment.size() < SEGMENT_SIZE_MIN ){
		return FALSE;
	}
	auto convertPoint						= forOneSegment.begin();
	// セグメント種別とセクション名を取得
	segmentRegistFormat.first				= (*convertPoint)[0];
	++convertPoint;
	segmentRegistFormat.second._sectionName = (*convertPoint);
	++convertPoint;
	// データ部を取得
	for( convertPoint; convertPoint != forOneSegment.end(); ++convertPoint ){
		if( segmentRegistFormat.second._sectionName.size() != (*convertPoint).size() ){
			return FALSE;	// セクションネーム分データがない場合、エラー
		}
		segmentRegistFormat.second._dataList.push_back( *convertPoint );
	}
	return TRUE;
}
