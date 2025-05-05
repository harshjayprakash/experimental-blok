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

int blokStateInit(State *pState, const VectorII scale);

int blokStateFree(State *pState);

int blokStateMoveBox(Square *pBox, const Direction direction);

int blokStateBoxMovableInDirection(State *pState, const Direction direction);

#endif // _BLOK_STATE_H_