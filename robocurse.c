/*

// robotron 2084 clone for linux written in C 
// Using ncurses and attempting to parse /dev
// for sweet WASD-ing. 

// today, ASCII robotron. Tomorrow, OpenGL?

// started 2.2.17

*/
#include "robocurse.h"

int main ()
{
	uint32_t tick;

	init_engine();

	while (1) {
	
	tick = get_tick();
	
	// check environment (screen size 80x24)
	// attract mode / game mode
	
	// call engine:
	//	controls
	// 	collisions

	// enemy logic / AI / update
	// player logic / update

	// scoring

	render(tick);
	}

	return 0;
}

void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}


