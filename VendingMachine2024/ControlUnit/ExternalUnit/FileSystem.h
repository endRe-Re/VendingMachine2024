#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ファイルシステムクラス
// ・ファイルの読み書きを行う
// [読み込み]
// ・1行に複数データを表現する場合はカンマ区切りである必要がある
// 　例)aaa,bbb,ccc
// ・読み取り結果から空行は除く
// ・カンマ区切りのデータは1つずつ配列に格納する
// ・複数行の場合も配列で表現するため、2次元配列となる
// [出力]
// ・1行に複数データが存在する場合はカンマ区切りで出力する
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"

#include <vector>
#include <string>

using OneLineFileData	= VectorTemp<std::string>;
using FileData			= VectorTemp<OneLineFileData>;
using InoutFormat		= VectorTemp<std::string>;

#define FILE_PATH "./inventory.txt"
class FileSystem
{
public:
	FileSystem();

	PROCESSES_RESULT load_file(FileData& fileData);
	PROCESSES_RESULT output_file(FileData& fileData);

private:
	void convert_inoutFormatToFileData(InoutFormat& input, FileData& output);
	void convert_fileDataToInoutFormat(FileData& input, InoutFormat& output);
};