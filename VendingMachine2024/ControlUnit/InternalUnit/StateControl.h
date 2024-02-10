#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 状態コントロールクラス
// ・状態の保存、状態ごとの処理を行うクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../UtilityUnit/Utility.h"

//! 状態列挙体
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

#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_MENU		"入金か集計を選択"
#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_FIRST	"1.入金"
#define DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_SECOND	"2.集計"

//! ユーザーの入力が必要かどうか
enum USER_INPUT_ENUM : unsigned long
{
	USER_INPUT_NEED,
	USER_INPUT_NON
};

//! ユーザーが選択した選択肢を示す列挙体
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

	void make_displayString(DisplayFormat& didplayFormat);
	USER_INPUT_ENUM check_userInput();
	void trans_nextState(USER_SELECT_ENUM userSelect);

private:
	STATE_ENUM		_state;
};
