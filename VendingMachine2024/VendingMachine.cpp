#include "VendingMachine.h"

VendingMachine::VendingMachine()
: _mainControl(nullptr),
  _stockMng(nullptr)
{

}

VendingMachine::~VendingMachine()
{
	delete _mainControl;
	delete _stockMng;
	_mainControl	= nullptr;
	_stockMng		= nullptr;
}

bool VendingMachine::activation()
{
	// ���C������N���X�쐬
	_mainControl = new MainControl();
	if( _mainControl == nullptr ){
		return false;
	}
	if( _mainControl->create() == FALSE ){
		return false;
	}

	// �݌ɊǗ��N���X�쐬
	_stockMng = new StockMng();
	if( _stockMng == nullptr ){
		return false;
	}
	if( create_stockMng() == FALSE ){
		return false;
	}
	
	return true;
}

PROCESSES_RESULT VendingMachine::create_stockMng()
{
	// ���ݕ����̎擾����݌ɂɐݒ肷��`�ւ̕ϊ�
	SegmentType		targetType	= USE_SEGMENT_TYPE_DRINK;
	SegmentData		segmentData = _mainControl->get_segmentData( targetType );
	GoodsInfoVec	drinkInfoVec;
	if( convert_segmentDataToGoodsInfoVec(segmentData, drinkInfoVec) == FALSE ){
		return FALSE;
	}
	// �������̎擾����݌ɂɐݒ肷��`�ւ̕ϊ�
	SegmentType		targetType	= USE_SEGMENT_TYPE_MONEY;
	SegmentData		segmentData = _mainControl->get_segmentData( targetType );
	GoodsInfoVec	moneyInfoVec;
	if( convert_segmentDataToGoodsInfoVec(segmentData, moneyInfoVec) == FALSE ){
		return FALSE;
	}
	// �݌ɊǗ��N���X�̍쐬�A�������ݒ�
	if( _stockMng->create(drinkInfoVec, moneyInfoVec) == FALSE ){
		return FALSE;
	}
	return TRUE;
}

PROCESSES_RESULT VendingMachine::convert_segmentDataToGoodsInfoVec(SegmentData& segmentData, GoodsInfoVec& goodsInfoVec)
{
	return TRUE;
}