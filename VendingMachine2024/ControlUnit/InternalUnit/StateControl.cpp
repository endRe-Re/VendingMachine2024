#include "StateControl.h"

StateControl::StateControl()
: _state(STATE_DEPOSIT_OR_AGGREGATE)
{

}

DisplayFormat StateControl::make_displayString()
{
	DisplayFormat retVal;
	if( _state == STATE_DEPOSIT_OR_AGGREGATE ){
		retVal.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_MENU );
		retVal.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_FIRST );
		retVal.push_back( DEPOSIT_OR_AGGREGATE_SELECT_OUTPUT_SECOND );
	}


	return retVal;
}

USER_INPUT_ENUM StateControl::check_userInput()
{
	USER_INPUT_ENUM retVal = USER_INPUT_NON;
	if( _state == STATE_DEPOSIT_OR_AGGREGATE ){
		retVal = USER_INPUT_NEED;
	}
	return retVal;
}

void StateControl::set_nextState(USER_SELECT_ENUM userSelect)
{
	unsigned long addCount = 0;
	do
	{
		++_state;
		++addCount;
	}
	while( (USER_SELECT_ENUM)addCount < userSelect );
}
