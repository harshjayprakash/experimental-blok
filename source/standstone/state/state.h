#ifndef _BLOK_STATE_H_
#define _BLOK_STATE_H_

#include "../model/direction.h"
#include "../model/square.h"
#include "../model/dynlist.h"

typedef struct _State
{
    TSquare box;
    TDynList obstructs;
} TObjectState;

int blokStateInit(TObjectState *pState, const TVector2 scale);

int blokStateFree(TObjectState *pState);

int blokStateMoveBox(TObjectState *pState, TDirection direction);

int blokStateIsBoxMovable(TObjectState *pState, TDirection direction);

int blokStateAddObstruct(TObjectState *pState, const TVector2 point);

int blokStateRemoveObstruct(TObjectState *pState, const TVector2 point);

int blokStateClearObstructs(TObjectState *pState);

#endif /* _BLOK_STATE_H_ */