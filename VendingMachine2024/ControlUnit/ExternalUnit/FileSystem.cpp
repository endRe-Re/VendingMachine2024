#include "FileSystem.h"

#include <fstream>
#include <iostream>
#include <sstream>

FileSystem::FileSystem()
{
}

PROCESSES_RESULT FileSystem::load_file(FileData& fileData)
{
	std::ifstream ifs( FILE_PATH );
	if( ifs.fail() ){
		std::cerr << "Failed to open file." << std::endl;
		return FALSE;
	}
	InoutFormat	inputData;
	std::string	oneLine;
	while( std::getline(ifs, oneLine) ){
		inputData.push_back( oneLine );
	}
	convert_inoutFormatToFileData( inputData, fileData );
	return TRUE;
}

PROCESSES_RESULT FileSystem::output_file(FileData& fileData)
{
	InoutFormat output;
	convert_fileDataToInoutFormat( fileData, output );
	return TRUE;
}

void FileSystem::convert_inoutFormatToFileData(InoutFormat& input, FileData& output)
{
	for( auto targetLine : input ){
		std::stringstream	targetLineStream{ targetLine };
		std::string			word;
		OneLineFileData		oneLineOutput;
		while( std::getline(targetLineStream, word, DATA_SPLIT_STR) ){
			oneLineOutput.push_back( word );
		}
		if( oneLineOutput.empty() == true ){
			continue;
		}
		output.push_back( oneLineOutput );
	}
}

void FileSystem::convert_fileDataToInoutFormat(FileData& input, InoutFormat& output)
{
}
