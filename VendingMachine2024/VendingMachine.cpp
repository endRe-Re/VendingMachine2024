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
	// �K�v���̍쐬
	if( create() == PROCESSES_FALSE ){
		return false;
	}
	// ���C������J�n
	_mainControl->start_control();
	return true;
}

PROCESSES_RESULT VendingMachine::create()
{
	// �݌ɊǗ��N���X�쐬
	_stockMng = new StockMng();
	if( _stockMng == nullptr ){
		return PROCESSES_FALSE;
	}
	// ���C������N���X�쐬
	_mainControl = new MainControl();
	if( _mainControl == nullptr ){
		return PROCESSES_FALSE;
	}
	if( _mainControl->create(_stockMng) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}

	if( create_stockMng() == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
}

PROCESSES_RESULT VendingMachine::create_stockMng()
{
	// ���ݕ����̎擾����݌ɂɐݒ肷��`�ւ̕ϊ�
	GoodsInfoVec drinkInfoVec;
	if( convert_segmentDataToGoodsInfoVec(USE_SEGMENT_TYPE_DRINK, drinkInfoVec) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	// �������̎擾����݌ɂɐݒ肷��`�ւ̕ϊ�
	GoodsInfoVec moneyInfoVec;
	if( convert_segmentDataToGoodsInfoVec(USE_SEGMENT_TYPE_MONEY, moneyInfoVec) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	// �݌ɊǗ��N���X�̍쐬�A�������ݒ�
	if( _stockMng->create(drinkInfoVec, moneyInfoVec) == PROCESSES_FALSE ){
		return PROCESSES_FALSE;
	}
	return PROCESSES_TRUE;
}

PROCESSES_RESULT VendingMachine::convert_segmentDataToGoodsInfoVec(SegmentType targetType, GoodsInfoVec& goodsInfoVec)
{
	SegmentData segmentData = _mainControl->get_segmentData( targetType );
	
	for( auto dataRecord : segmentData._dataList ){
		GoodsInfo	info;
		if( targetType == USE_SEGMENT_TYPE_DRINK ){
			info._data._value = std::stoi( dataRecord[1] );
			info._data._stock = std::stoi( dataRecord[2] );
		}
		if( targetType == USE_SEGMENT_TYPE_MONEY ){
			info._data._value = std::stoi( dataRecord[0] );
			info._data._stock = std::stoi( dataRecord[1] );
		}
		info._name = dataRecord[0];
		goodsInfoVec.push_back( info );
	}
	return PROCESSES_TRUE;
}