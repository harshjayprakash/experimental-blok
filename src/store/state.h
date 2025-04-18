#ifndef _BLOK_STATE_H_
#define _BLOK_STATE_H_

#include "../model/direction.h"
#include "../model/square.h"
#include "../model/dynlist.h"

typedef struct _State {
    Square box;
    Square boxProjected;
    DynList obstructives;
} State;

void BlokStateInit(State *state, const VectorII scale);

void BlokStateFree(State *state);

void BlokStateMoveBox(Square *box, const Direction direction);

int BlokStateBoxMovableInDirection(State *state, const Direction direction);

#endif // _BLOK_STATE_H_