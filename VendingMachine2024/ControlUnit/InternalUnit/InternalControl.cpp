#include "InternalControl.h"
#include "StateControl.h"

InternalControl::InternalControl()
: _stockMng(nullptr),
  _stateControl(nullptr)
{
}

PROCESSES_RESULT InternalControl::create(StockMng* stockMng)
{
	if( stockMng == nullptr ){
		return PROCESSES_FALSE;
	}
	_stockMng		= stockMng;
	_stateControl	= new StateControl();
	if( _stateControl == nullptr ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
}

void InternalControl::get_displayString(DisplayFormat& displayString)
{
	_stateControl->make_displayString( displayString );
}

//���͓��e���`�F�b�N���Ă��琳�����w��ł���Γǂݍ���Ŏ��ɑJ�ڂ�����
// �w�肪����Ă���΁A�ǂ��Ⴄ�̂����o�͕�����Ƃ��Đݒ肷��
INPUT_TYPE_ENUM InternalControl::read_userInput(UInt userInput, DisplayFormat& displayString)
{
	INPUT_TYPE_ENUM			retVal			= INPUT_TYPE_OK;
	INPUT_CHECK_TYPE_ENUM	inputChkType	= _stateControl->judge_inputCheckType();
	// ��ԓ���
	if( inputChkType == INPUT_CHECK_TYPE_STATE ){
		if( (USER_SELECT_NONE < userInput) && (userInput < USER_SELECT_NUM) ){
			_stateControl->trans_nextState( (USER_SELECT_ENUM)userInput );
		}
		else{
			retVal = INPUT_TYPE_RETRY;
		}
	}
	// ��������
	else if( inputChkType == INPUT_CHECK_TYPE_MONEY ){
	
	}
	// ���i����
	else if( inputChkType == INPUT_CHECK_TYPE_STOCK ){
	
	}
	else{}
	return retVal;
}
