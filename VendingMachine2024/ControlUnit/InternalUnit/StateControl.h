#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��ԃR���g���[���N���X
// �E��Ԃ̕ۑ��A��Ԃ��Ƃ̏������s���N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
enum STATE_ENUM
{
	STATE_DEPOSIT_OR_AGGREGATE = 0,			// ����or�W�v�I��
	STATE_DEPOSIT,							// ����
	STATE_AGGREGATE,						// �W�v
	STATE_BUY_OR_FINISH,					// �w��or�ނ�K���o��(=�I��)
	STATE_BUY,								// �w��
	STATE_FINISH							// �ނ�K���o��
};

class StateControl
{
public:
	StateControl();

private:
	STATE_ENUM		_state;
};