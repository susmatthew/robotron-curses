/* game engine */

//
//

#include "roboengine.h"

#define REFRESH	1666	// roughly 60Hz
#define REDRAW	1000000	// every 10sec

void init_engine (void) 
{
	initscr();
	noecho();
	curs_set(FALSE);
	setlocale(LC_ALL,"");
	clear();
}

tick get_tick (bool paused)
{
	clock_t currTime;
	currTime = clock();
	if (currTime < 0) die("no clock");

	static bool wasPaused;
	static uint32_t pausedIn, pausedOut, tickOffset;
	uint32_t tickNow=0;

	tickNow=(uint32_t) (currTime/(CLOCKS_PER_SEC/100000));

	if (paused) {
		if (!wasPaused) pausedIn=tickNow;
		else pausedOut=tickNow;
	} else {
		if (pausedIn && (pausedIn != pausedOut)) tickOffset+=(pausedOut-pausedIn);
		pausedIn=pausedOut=0;
	}

	ticks tempTick;
	tempTick.trueTick=tickNow;
	tempTick.pausedTick=tickOffset;

	return  tempTick; // overflows every 80 years.
							// returns clocks per 10us
}

void get_input_device (char *dest)
{

char path[65];
const char *cmd = "grep -E 'Handlers|EV=' /proc/bus/input/devices | \
    	grep -B1 'EV=1[02]001[3Ff]' | \
    	grep -Eo 'event[0-9]+' ";

memset(dest, '\0', sizeof(dest));

FILE *fp = popen (cmd, "r");	// is there a safer way?

if (fgets(path, 17, fp) != NULL) {
	strcat(dest,"/dev/input/");
	strncat(dest,path,6);
	}

fclose(fp);

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
