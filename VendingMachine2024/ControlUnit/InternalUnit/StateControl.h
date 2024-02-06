#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��ԃR���g���[���N���X
// �E��Ԃ̕ۑ��A��Ԃ��Ƃ̏������s���N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"

enum STATE_ENUM
{
	STATE_DEPOSIT_OR_AGGREGATE = 0,			// ����or�W�v�I��
	STATE_DEPOSIT,							// ����
	STATE_AGGREGATE,						// �W�v
	STATE_BUY_OR_FINISH,					// �w��or�ނ�K���o��(=�I��)
	STATE_BUY,								// �w��
	STATE_FINISH,							// �ނ�K���o��
	STATE_NUM								// ��`��
};
STATE_ENUM& operator++(STATE_ENUM& target) {
	target = static_cast<STATE_ENUM>(static_cast<int>(target) + 1);
	if( target == STATE_ENUM::STATE_NUM ){
		target = STATE_ENUM::STATE_DEPOSIT_OR_AGGREGATE;
	}
	return target;
}

#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_MENU		"�������W�v��I��"
#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_FIRST	"1.����"
#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_SECOND	"2.�W�v"

enum USER_INPUT_ENUM
{
	USER_INPUT_NEED,
	USER_INPUT_NON
};

enum USER_SELECT_ENUM
{
	USER_SELECT_NONE		= 0,
	USER_SELECT_FIRST,
	USER_SELECT_SECOND,
	USER_SELECT_NUM					// �I������
};

class StateControl
{
public:
	StateControl();

	DisplayFormat make_displayString();
	USER_INPUT_ENUM check_userInput();
	void set_nextState(USER_SELECT_ENUM userSelect);

private:
	STATE_ENUM		_state;
};
