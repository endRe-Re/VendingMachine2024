#include "InternalControl.h"

InternalControl::InternalControl()
: _stockMng(nullptr)
{
}

PROCESSES_RESULT InternalControl::create(StockMng* stockMng)
{
	_stockMng = stockMng;
	return TRUE;
}
