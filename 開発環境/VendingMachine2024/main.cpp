#include "VendingMachine.h"

int main()
{
	VendingMachine* vendingMachine = new VendingMachine();
	vendingMachine->activation();
	delete vendingMachine;
	vendingMachine = nullptr;
	return 0;
}