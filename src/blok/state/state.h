#ifndef BLOK_STATE_H
#define BLOK_STATE_H

#include "../model/direction.h"
#include "../model/dynlist.h"
#include "../model/square.h"

typedef struct _State
{
    TSquare box;
    TDynList obstructs;
} TObjectState;

int BlokStateInit(TObjectState *pState, const TVector2 scale);

int BlokStateFree(TObjectState *pState);

int BlokStateMoveBox(TObjectState *pState, TDirection direction);

int BlokStateIsBoxMovable(TObjectState *pState, TDirection direction);

int BlokStateAddObstruct(TObjectState *pState, const TVector2 point);

int BlokStateRemoveObstruct(TObjectState *pState, const TVector2 point);

int BlokStateClearObstructs(TObjectState *pState);

#endif /* BLOK_STATE_H */