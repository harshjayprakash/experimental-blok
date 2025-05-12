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

int blokStateMoveBox2(State *pState, Direction direction);

int blokStateIsBoxMovable(State *pState, Direction direction);

int blokStateAddObstruct(State *pState, const VectorII point);

int blokStateRemoveObstruct(State *pState, const VectorII point);

int blokStateClearObstructs(State *pState);


#endif // _BLOK_STATE_H_