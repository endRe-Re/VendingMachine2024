#pragma once

class MainControl;

class VendingMachine
{
public:
	VendingMachine();

	bool activation();				// �N��

private:
	MainControl* _mainControl;		//���C������N���X

};
