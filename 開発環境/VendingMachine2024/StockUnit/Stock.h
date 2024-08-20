#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �݌ɊǗ����N���X
// �E�݌ɊǗ��̊�{�I������`���Ă����N���X
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "GoodsMng.h"

//! �݌ɕi���
struct GoodsInfo
{
	GoodsName _name;	// ����
	GoodsData _data;	// �f�[�^��
};
using GoodsInfoVec = VectorTemp<GoodsInfo>;		// �݌ɕi���x�N�^�[

class Stock
{
public:
	Stock();
	virtual ~Stock();

	virtual PROCESSES_RESULT create(GoodsInfoVec& goodsInfoVec);

protected:
	PROCESSES_RESULT create_stocker(GoodsInfoVec& goodsInfoVec, GoodsMng* goodsMng);

	GoodsMng* _seller;

private:
};