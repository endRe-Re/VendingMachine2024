#pragma once
#include "../../UtilityUnit/Utility.h"

#include <vector>
#include <string>

typedef std::vector<std::string>				OneLineFileData;
typedef std::vector<OneLineFileData>			FileData;
typedef std::vector<std::string>				InoutFormat;

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