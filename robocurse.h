// robocurse.h
// variables and interface


/*
from http://www.arcade-museum.com/game_detail.php?game_id=9347 . notes added from GDC postmortem and observed gameplay.

Grunts (100 points) do not shoot but they will attack in large numbers.hunt the player. slow get faster.

Brains (500 points) can fire Cruise Missles (25 points) at you and turn humans into Progs (100 points). Seeks nearest human. every five waves is a 'brain wave.' Cruise missile seeks player 'randomly'. 

Spheroids (1000 points) can create Enforcers (150 points) which fire mines (sparks - 25 points) at you. Spark has random acceleration. follows the wall if it hits. Shot gets to you in a fixed amount of time + accelerates randomly.

Quarks(1000 points) will create Tanks (200 points) that will try to run over you or fire Bounce Bombs (25 points) at you. Relative or absolute aim. 

Hulks are indestructible and will kill humans as they approach. Your blaster will only halt them as long as you are shooting them. 'Random' pretty slow walk.

Obstacles such as Electrodes in your path can be removed by firing at them with your blaster.
Humans are worth an increasing point value. The first human scores 1000 points, the second is worth 2000 points and so on until the point value reaches 5000. The point value will remain at 5000 for all the remaining humans in the same wave. When the wave is completed or you have been killed, the points awarded for saving another human will be reset to 1000.

four shots active.

25000 pts. per dude

Waves end when all killable enemies are dead.

*/

#define MINY	48
#define MINX	160

#include <time.h>
#include <stdint.h>
#include <errno.h>
#include <ncurses.h>
#include <unistd.h>

// prototypes
void die(const char *);

typedef enum {
	grunt=0, hulk, brain, prog, spheroid, enforcer, 
	quark, tank, electrode, man, woman, child, avatar, 
	missle, mine, bomb, shot
} Names;

typedef enum {
	evil=1;
	good=1<<1;
	text=1<<2;
	player1=1<<3;
	player2=1<<4;
	player3=1<<5;
	player4=1<<6;	
} alignment;

#define NUM_ORIENTATIONS 8

typedef enum { up=0,upright,right,downright,down,downleft,left,upleft } orientations;

typedef struct {
	char *symbol[NUM_ORIENTATIONS];
	orientations orientation;
} symbols;

typedef struct {
	symbols symbol[10];
	uint32_t symbol_freq;
	uint32_ symbol_accum;
	uint8_t color[10];	// color 0 is invisible.
	uint32_t color_freq;
	uint32_t color_accum;
	uint8_t attribute[10];
	uint32_t att_freq;
	uint32_t color_accum;
} appearance;

typedef struct {
	alignment align;
	appearance look;
} types;

typedef struct {
	uint8_t y,x; // y is first in ncurses.
} location;

typedef struct {
	location pos_curr;
	location pos_old;
	location dest;
	uint32_t orth_speed, diag_speed;
	uint32_t speed_mod;
	uint32_t speed_accum;
	uint8_t mov_type;
	uint8_t mass;
	alignment collides_with; // alignment
} movements;

typedef struct {
	names name;
	uint32_t freq;	// 0-none, 1-transforms, 2-on collision, >1666 is freq.
	uint32_t freq_accum;
	alignment collision_type;
} makes;	

typedef struct {
	types type;
	movements movement;
	makes make[5];
} things;

extern things thing[TOTAL_THINGS];

// linked list of things.

typedef struct {
	entity *next;
	things thing;
} entity;

extern entity *head;
