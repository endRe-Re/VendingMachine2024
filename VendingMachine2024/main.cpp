#include "VendingMachine.h"

int main()
{
	VendingMachine* vendingMachine = new VendingMachine();
	vendingMachine->activation();
	delete vendingMachine;
	return 0;
}