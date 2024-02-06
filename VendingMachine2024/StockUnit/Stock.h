#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 在庫管理基底クラス
// ・在庫管理の基本的動作を定義しておくクラス
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "GoodsMng.h"

//! 在庫品情報
struct GoodsInfo
{
	GoodsName _name;	// 名称
	GoodsData _data;	// データ部
};
using GoodsInfoVec = VectorTemp<GoodsInfo>;		// 在庫品情報ベクター

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