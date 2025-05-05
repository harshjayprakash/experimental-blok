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

void blokStateInit(State *pState, const VectorII scale);

void blokStateFree(State *pState);

void blokStateMoveBox(Square *pBox, const Direction direction);

int blokStateBoxMovableInDirection(State *pState, const Direction direction);

#endif // _BLOK_STATE_H_