#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��ԃR���g���[���N���X
// �E��Ԃ̕ۑ��A��Ԃ��Ƃ̏������s���N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"

//! ��ԗ񋓑�
enum STATE_ENUM
{
	STATE_DEPOSIT_OR_AGGREGATE = 0,			// ����or�W�v�I��
	STATE_DEPOSIT,							// ����
	STATE_AGGREGATE,						// �W�v
	STATE_END,								// �I���@�W�v��I���̂��߂��̈ʒu
	STATE_BUY_OR_OUTPUT_CHANGE,				// �w��or�ނ�K���o��
	STATE_BUY,								// �w��
	STATE_OUTPUT_CHANGE,					// �ނ�K���o��
	STATE_NUM								// ��`��
};

#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_MENU		"�������W�v��I��"
#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_FIRST	"1.����"
#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_SECOND	"2.�W�v"

//! ���[�U�[�̓��͂��K�v���ǂ���
enum USER_INPUT_ENUM
{
	USER_INPUT_NON,
	USER_INPUT_NEED,
};

//! ���[�U�[���I�������I�����������񋓑�
enum USER_SELECT_ENUM
{
	USER_SELECT_NONE		= 0,
	USER_SELECT_FIRST,
	USER_SELECT_SECOND,
	USER_SELECT_NUM					// �I������
};

//! ������
enum CONTROL_TYPE_ENUM
{
	CONTROL_TYPE_CONTINUE,			// �p��
	CONTROL_TYPE_FINISH				// �I��
};

//! ���̓`�F�b�N���
enum INPUT_CHECK_TYPE_ENUM
{
	INPUT_CHECK_TYPE_NONE,			// ���͕s�v
	INPUT_CHECK_TYPE_STATE,			// ��ԓ���
	INPUT_CHECK_TYPE_MONEY,			// ��������
	INPUT_CHECK_TYPE_STOCK			// ���i����
};

enum DISPLAY_TYPE_ENUM
{
	DISPLAY_TYPE_STATE_ONLY,
	DISPLAY_TYPE_AGGREGATE,
	DISPLAY_TYPE_OUTPUT_CHANGE
};

class StateControl
{
public:
	StateControl();

	void make_displayString(DisplayFormat& didplayFormat);
	USER_INPUT_ENUM check_userInputForState();
	void trans_nextState(USER_SELECT_ENUM userSelect);
	CONTROL_TYPE_ENUM judge_controlTypeBaseState();
	INPUT_CHECK_TYPE_ENUM judge_inputCheckType();
	DISPLAY_TYPE_ENUM judge_displayType();

private:
	STATE_ENUM		_state;
};
