#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 状態コントロールクラス
// ・状態の保存、状態ごとの処理を行うクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"

enum STATE_ENUM
{
	STATE_DEPOSIT_OR_AGGREGATE = 0,			// 入金or集計選択
	STATE_DEPOSIT,							// 入金
	STATE_AGGREGATE,						// 集計
	STATE_BUY_OR_FINISH,					// 購入or釣り銭取り出し(=終了)
	STATE_BUY,								// 購入
	STATE_FINISH,							// 釣り銭取り出し
	STATE_NUM								// 定義数
};
STATE_ENUM& operator++(STATE_ENUM& target) {
	target = static_cast<STATE_ENUM>(static_cast<int>(target) + 1);
	if( target == STATE_ENUM::STATE_NUM ){
		target = STATE_ENUM::STATE_DEPOSIT_OR_AGGREGATE;
	}
	return target;
}

#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_MENU		"入金か集計を選択"
#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_FIRST	"1.入金"
#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_SECOND	"2.集計"

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
	USER_SELECT_NUM					// 選択肢数
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
