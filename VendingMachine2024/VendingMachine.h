#pragma once

class MainControl;

class VendingMachine
{
public:
	VendingMachine();

	bool activation();				// 起動

private:
	MainControl* _mainControl;		//メイン制御クラス

};
