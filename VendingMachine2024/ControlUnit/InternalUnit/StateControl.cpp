#include "StateControl.h"

StateControl::StateControl()
: _state(STATE_ENUM::STATE_DEPOSIT_OR_AGGREGATE)
{

}

void StateControl::make_displayString(DisplayFormat& didplayFormat)
{
	didplayFormat.clear();
	if( _state == STATE_ENUM::STATE_DEPOSIT_OR_AGGREGATE ){
		didplayFormat.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_MENU );
		didplayFormat.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_FIRST );
		didplayFormat.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_SECOND );
	}

}

USER_INPUT_ENUM StateControl::check_userInput()
{
	USER_INPUT_ENUM retVal = USER_INPUT_NON;
	if( _state == STATE_ENUM::STATE_DEPOSIT_OR_AGGREGATE ){
		retVal = USER_INPUT_NEED;
	}
	return retVal;
}

// ���[�U�[�̓��͂ɂ���ď�Ԃ����֑J�ڂ�����
// �J�ڃp�^�[���͈ȉ�3��
// �E�I��s�v�ł��̂܂܎��ɑJ�ڂ���P�[�X
// �E�@��I����1���ɑJ�ڂ���P�[�X
// �E�A��I����2���ɑJ�ڂ���P�[�X
// ���������ɂȂ邩��STATE_ENUM�̏��ԂɈˑ�����
void StateControl::trans_nextState(USER_SELECT_ENUM userSelect)
{
	unsigned long addCount = 0;
	do{
		// operator++�̓�����������
		// enum class�Ŏ����\�Ȃ͂������A�C���N���[�h��Œ�`�ς݂Ɣ��f����A
		// �G���[�������������ߒf�O
		switch( _state ){
		case STATE_DEPOSIT_OR_AGGREGATE:
			_state = STATE_DEPOSIT;
			break;
		case STATE_DEPOSIT:
			_state = STATE_AGGREGATE;
			break;
		case STATE_AGGREGATE:
			_state = STATE_AGGREGATE;	//�����I���̂��ߎ��ɐi�܂Ȃ�
			break;
		case STATE_BUY_OR_OUTPUT_CHANGE:
			_state = STATE_BUY;
			break;
		case STATE_BUY:
			_state = STATE_OUTPUT_CHANGE;
			break;
		case STATE_OUTPUT_CHANGE:
			_state = STATE_DEPOSIT_OR_AGGREGATE;
			break;
		default:
			break;
		}
		++addCount;
	}
	while( (USER_SELECT_ENUM)addCount < userSelect );
}

CONTROL_TYPE_ENUM StateControl::judge_controlTypeBaseState()
{
	CONTROL_TYPE_ENUM retVal = CONTROL_TYPE_ENUM::CONTROL_TYPE_CONTINUE;
	if( _state == STATE_AGGREGATE ){
		retVal = CONTROL_TYPE_ENUM::CONTROL_TYPE_FINISH;
	}
	return retVal;
}