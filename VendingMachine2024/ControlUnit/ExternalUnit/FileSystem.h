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
#define FILE_PATH		"./inventory.txt"						// ���o�̓t�@�C���p�X

// ���o�͂�DATA_SPLIT_STR��؂�ōs����
#define DATA_SPLIT_STR	","								// 1�s�̃f�[�^��؂蕶��
using InoutFormat		= VectorTemp<std::string>;		// ���o�͌`��
// ���N���X��DATA_SPLIT_STR��؂���ӎ������Ȃ����߂�
// �ǂݍ��񂾃f�[�^�͑��d�̃x�N�^�[�Ƃ��ďo�͂���
using OneLineFileData	= VectorTemp<std::string>;		// 1�s���̃f�[�^
using FileData			= VectorTemp<OneLineFileData>;	// �t�@�C�����e

class FileSystem
{
public:
	FileSystem();

	PROCESSES_RESULT load_file(FileData& fileData);		// �t�@�C���ǂݍ���
	PROCESSES_RESULT output_file(FileData& fileData);	// �t�@�C���o��

private:
	void convert_inoutFormatToFileData(InoutFormat& input, FileData& output);	// �����ǂݍ��ݗp�ɕϊ�
	void convert_fileDataToInoutFormat(FileData& input, InoutFormat& output);	// �t�@�C���o�͗p�ɕϊ�
};