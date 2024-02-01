#pragma once

enum STATE_ENUM
{
	STATE_DEPOSIT_OR_AGGREGATE = 0,			// 入金or集計選択
	STATE_DEPOSIT,							// 入金
	STATE_AGGREGATE,						// 集計
	STATE_BUY_OR_FINISH,					// 購入or釣り銭取り出し(=終了)
	STATE_BUY,								// 購入
	STATE_FINISH							// 釣り銭取り出し
};

class StateControl
{
public:
	StateControl();

private:
	STATE_ENUM		_state;
};