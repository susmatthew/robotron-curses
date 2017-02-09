// robocurse.h
// variables and interface


/*
from http://www.arcade-museum.com/game_detail.php?game_id=9347

Grunts (100 points) do not shoot but they will attack in large numbers.

Brains (500 points) can fire Cruise Missles (25 points) at you and turn humans into Progs (100 points).

Spheroids (1000 points) can create Enforcers (150 points) which fire guided mines (25 points) at you.

Quarks(1000 points) will create Tanks (200 points) that will try to run over you or fire Bounce Bombs (25 points) at you.

Hulks are indestructible and will kill humans as they approach. Your blaster will only halt them as long as you are shooting them.

Obstacles such as Electrodes in your path can be removed by firing at them with your blaster.
Humans are worth an increasing point value. The first human scores 1000 points, the second is worth 2000 points and so on until the point value reaches 5000. The point value will remain at 5000 for all the remaining humans in the same wave. When the wave is completed or you have been killed, the points awarded for saving another human will be reset to 1000.

components:
type -- bad, good, big, color, symbol, duration (disappears, ends round alive, etc.)
	(!bad && !good implies neutral)
	(no color/no symbol implies invisible)
	(big for text/scoring)
	
translation -- mov_type, location, max_speed (freq,) mass, collides_with

creation -- _type, condition (freq, collision w/), transformation

*/

#define NUMTHINGS	17
#include <time.h>
#include <stdint.h>
#include <errno.h>

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
} alignment;

typedef struct {
	alignment type;
	char	*symbol;
	
} unit_type;

typedef struct {
	uint8_t speed;
	uint8_t mov_type;
	uint8_t mass;
	alignment collides_with; // alignment
} movement;


typedef struct {
	Names Name;
	char Symbol;
	uint16_t Value;
	uint8_t	X,Y,Dloc; //
} entity;
