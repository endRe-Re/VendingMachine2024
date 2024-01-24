#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �t�@�C���V�X�e���N���X
// �E�t�@�C���̓ǂݏ������s��
// [�ǂݍ���]
// �E1�s�ɕ����f�[�^��\������ꍇ�̓J���}��؂�ł���K�v������
// �@��)aaa,bbb,ccc
// �E�ǂݎ�茋�ʂ����s�͏���
// �E�J���}��؂�̃f�[�^��1���z��Ɋi�[����
// �E�����s�̏ꍇ���z��ŕ\�����邽�߁A2�����z��ƂȂ�
// [�o��]
// �E1�s�ɕ����f�[�^�����݂���ꍇ�̓J���}��؂�ŏo�͂���
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