// roboengine.h
#include <stdint.h>
#include <stdbool.h>
#include <ncurses.h>
#include <string.h>

typedef struct {
	uint32_t trueTime;
	uint32_t pausedTime;
} ticks;

extern ticks tick;

ticks get_tick (bool paused);
void init_engine ();
void get_input_device (char *dest);