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
#define FILE_PATH		"./inventory.txt"						// 入出力ファイルパス

// 入出力はDATA_SPLIT_STR区切りで行われる
#define DATA_SPLIT_STR	","								// 1行のデータ区切り文字
using InoutFormat		= VectorTemp<std::string>;		// 入出力形式
// 他クラスでDATA_SPLIT_STR区切りを意識させないために
// 読み込んだデータは多重のベクターとして出力する
using OneLineFileData	= VectorTemp<std::string>;		// 1行分のデータ
using FileData			= VectorTemp<OneLineFileData>;	// ファイル内容

class FileSystem
{
public:
	FileSystem();

	PROCESSES_RESULT load_file(FileData& fileData);		// ファイル読み込み
	PROCESSES_RESULT output_file(FileData& fileData);	// ファイル出力

private:
	void convert_inoutFormatToFileData(InoutFormat& input, FileData& output);	// 内部読み込み用に変換
	void convert_fileDataToInoutFormat(FileData& input, InoutFormat& output);	// ファイル出力用に変換
};