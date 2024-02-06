#include "StateControl.h"

StateControl::StateControl()
: _state(STATE_DEPOSIT_OR_AGGREGATE)
{

}

void StateControl::make_displayString(DisplayFormat& didplayFormat)
{
	didplayFormat.clear();
	if( _state == STATE_DEPOSIT_OR_AGGREGATE ){
		didplayFormat.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_MENU );
		didplayFormat.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_FIRST );
		didplayFormat.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_SECOND );
	}

}

USER_INPUT_ENUM StateControl::check_userInput()
{
	USER_INPUT_ENUM retVal = USER_INPUT_NON;
	if( _state == STATE_DEPOSIT_OR_AGGREGATE ){
		retVal = USER_INPUT_NEED;
	}
	return retVal;
}

void StateControl::trans_nextState(USER_SELECT_ENUM userSelect)
{
	unsigned long addCount = 0;
	do{
		++_state;
		++addCount;
	}
	while( (USER_SELECT_ENUM)addCount < userSelect );
}
