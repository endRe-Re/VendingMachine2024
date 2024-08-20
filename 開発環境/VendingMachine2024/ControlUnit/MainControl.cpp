#include "MainControl.h"

MainControl::MainControl()
: _externalControl(nullptr),
  _internalControl(nullptr)
{
}

MainControl::~MainControl()
{
	delete _externalControl;
	_externalControl = nullptr;
	delete _internalControl;
	_internalControl = nullptr;
}

PROCESSES_RESULT MainControl::create(StockMng* stockMng)
{
	_externalControl = new ExternalControl();
	if( _externalControl == nullptr ){
		return PROCESSES_FALSE;
	}
	if( _externalControl->create() == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}

	_internalControl = new InternalControl();
	if( _internalControl == nullptr ){
		return PROCESSES_FALSE;
	}
	if( _internalControl->create(stockMng) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
}

PROCESSES_RESULT MainControl::start_control()
{
	while( _internalControl->judge_controlTypeBaseState() == CONTROL_TYPE_CONTINUE ){
		// ���j���[�o��
		DisplayFormat	displayString;
		_internalControl->get_displayString( displayString );
		_externalControl->display( displayString );
		USER_INPUT_ENUM userInputEnum = _internalControl->check_userInputForState();
		if( userInputEnum == USER_INPUT_NEED ){
			start_controlForInputNeed();	// ���[�U�[���͕K�v���̏���
		}
		else{
			DisplayFormat guideString;
			_internalControl->trans_nextStateForNonInput( guideString );
			_externalControl->display( displayString );
		}
	}
	return PROCESSES_TRUE;
}

void MainControl::start_controlForInputNeed()
{
	INPUT_TYPE_ENUM	inputCheckResult = INPUT_TYPE_RETRY;
	while( inputCheckResult == INPUT_TYPE_RETRY ){
		ENTER_ONLY_ENUM	isEnterOnly			= ENTER_ONLY_NON;
		UInt			userInput			= _externalControl->input_uInt( isEnterOnly );
		// ���͓��e��ǂݍ��݁A���e����Ŏ��֑J�ڂ�����
		// �w�����e���G���[���e���o�͂����
		DisplayFormat	guideString;
		INPUT_TYPE_ENUM	inputCheckResult	= _internalControl->read_userInput( userInput, guideString );
		_externalControl->display( guideString );	// �ǂݍ��񂾌��ʂ��\�������
	}
}
