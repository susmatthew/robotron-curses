/* game engine */

//
//

#include "roboengine.h"

#define REFRESH	1666
#define REDRAW	100000

void init_engine (void) 
{
	initscr();
	noecho();
	curs_set(FALSE);
	clear();
}

uint32_t get_tick (void)
{
	clock_t currTime;
	currTime = clock();
	if (currTime < 0) die("no clock");

	return (uint32_t) (currTime/(CLOCKS_PER_SEC/10000)); // overflows every 80 years.
}

void render (uint32_t sysTick)
{
	static uint32_t sysAccum=0;
	
	if ((sysTick-sysAccum)/REFRESH>0) {
		refresh();	//60.02Hz
		sysAccum+=REFRESH;
	}
	
	if ((sysTick-sysAccum)/REDRAW>0) {
		redrawwin();	// redraw every ten seconds
		sysAccum+=REDRAW;	
	}	
}

void Physics ()
{
}

void Movement ()
{
}

struct entity *Collision (struct entity *actor)
{
}
