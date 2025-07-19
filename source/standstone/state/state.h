#ifndef ST_STATE_H
#define ST_STATE_H

#include "../model/direction.h"
#include "../model/square.h"
#include "../model/dynlist.h"

typedef struct _State
{
    TSquare box;
    TDynList obstructs;
} TObjectState;

int stStateInit(TObjectState *pState, const TVector2 scale);

int stStateFree(TObjectState *pState);

int stStateMoveBox(TObjectState *pState, TDirection direction);

int stStateIsBoxMovable(TObjectState *pState, TDirection direction);

int stStateAddObstruct(TObjectState *pState, const TVector2 point);

int stStateRemoveObstruct(TObjectState *pState, const TVector2 point);

int stStateClearObstructs(TObjectState *pState);

#endif /* ST_STATE_H */