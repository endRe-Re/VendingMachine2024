#pragma once
#include "../../UtilityUnit/Utility.h"

class StockMng;

class InternalControl
{
public:
	InternalControl();

	PROCESSES_RESULT create(StockMng* stockMng);

private:
	StockMng*	_stockMng;
};