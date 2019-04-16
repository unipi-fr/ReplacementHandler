#ifndef GLOBALSH
#define GLOBALSH

#include "types.h"

extern bool b0, b1, b2, b3;
extern bool light0, light1, light2, light3;
extern bool lock0, lock1, lock2, lock3;

extern bool open, close;
extern bool isopen;
extern bool up, down, halt;

extern bool ishalt;
extern bool islock0, islock1, islock2, islock3;

extern bool is0, is1, is2, is3;

extern bool dir;

extern unsigned int pblsignal;
extern unsigned int pblstate;
extern unsigned int cabinsignal;
extern unsigned int cabinstate;
#endif // GLOBALSH
					

