#pragma once
#include "UtilityUnit/Utility.h"
#include "ControlUnit/MainControl.h"
#include "StockUnit/StockMng.h"

// �����̔��@�Ŏg�p����Z�O�����g���
static const SegmentType USE_SEGMENT_TYPE_DRINK = "[Drink]";
static const SegmentType USE_SEGMENT_TYPE_MONEY = "[Money]";

class VendingMachine
{
public:
	VendingMachine();
	~VendingMachine();

	bool activation();				// �N��

private:
	PROCESSES_RESULT create();
	PROCESSES_RESULT create_stockMng();
	PROCESSES_RESULT convert_segmentDataToGoodsInfoVec(SegmentType SegmentType, GoodsInfoVec& goodsInfoVec);

	MainControl*	_mainControl;	//���C������N���X
	StockMng*		_stockMng;		//�݌ɊǗ��N���X
};
