#include "cabin.h"
#include "types.h"
#include "globals.h"

void EE_lcd_putc (char);
void EE_lcd_goto (int, int);


static enum State {
	IDLE, TOOPEN, OPENED, TOCLOSE
};
static enum Signal {
	ABSENT, OPEN, CLOSE 
};

void CabinInit(Cabin *me){
	me->state_ = IDLE;
	isopen = 0; //cabin starts closed
}
void CabinTran_(Cabin *me, unsigned int dest)
{
	me->state_ = dest;
}
void CabinDisplay ( bool ispn ){

	EE_lcd_goto ( 6, 1 );
	if (ispn)
		EE_lcd_putc( 'O' );
	else 
		EE_lcd_putc( 'C' );

}

enum Signal CabinGetSignals(Cabin *me){
	switch ( me->state_ ){
		case IDLE:
			if (open)
				return OPEN;
			break;
		case TOOPEN:
				return ABSENT;
			break;
		case OPENED:
			if (close)
				return CLOSE;
			break;
		case TOCLOSE:
				return ABSENT;
			break;
	}
	return ABSENT;
}
void CabinDispatch(Cabin *me){

	enum Signal s = CabinGetSignals(me);
	switch ( me->state_ ){
		case IDLE:
			switch ( s ) {
				case OPEN:
					CabinTran_ ( me, TOOPEN );
					break;
			}
			break;	
		case TOOPEN: //WITHOUT GUARDS
					isopen = 1;
					CabinTran_ ( me, OPENED );
					CabinDisplay( isopen );
					break;
		case OPENED:
			switch ( s ) {
				case CLOSE:
					CabinTran_ ( me, TOCLOSE );
					break;
			}
			break;
		case TOCLOSE://WITHOUT GUARDS
					isopen = 0;
					CabinTran_ ( me, IDLE );
					CabinDisplay( isopen );
					break;
	}

}



					

