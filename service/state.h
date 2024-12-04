#ifndef __BLOK_STATE_H
#define __BLOK_STATE_H

#include "../model/object/square.h"

typedef struct bkState
{
	bkSquare user;
} bkState;

void bkStateInit(bkState* state);

void bkStateFree(bkState* state);

#endif // !__BLOK_STATE_H
