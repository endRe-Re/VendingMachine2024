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

// ユーザーの入力によって状態を次へ遷移させる
// 遷移パターンは以下3つ
// ・選択不要でそのまま次に遷移するケース
// ・①を選択で1つ次に遷移するケース
// ・②を選択で2つ次に遷移するケース
// ※次が何になるかはSTATE_ENUMの順番に依存する
void StateControl::trans_nextState(USER_SELECT_ENUM userSelect)
{
	unsigned long addCount = 0;
	do{
		// operator++の動きをさせる
		// enum classで実装可能なはずだが、インクルード先で定義済みと判断され、
		// エラーが発生したため断念
		switch( _state ){
		case STATE_DEPOSIT_OR_AGGREGATE:
			_state = STATE_DEPOSIT;
			break;
		case STATE_DEPOSIT:
			_state = STATE_AGGREGATE;
			break;
		case STATE_AGGREGATE:
			_state = STATE_AGGREGATE;	//処理終了のため次に進まない
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