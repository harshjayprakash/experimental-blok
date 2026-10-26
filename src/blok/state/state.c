#include "state.h"
#include "../model/vector.h"
#include <stdlib.h>

static int _BlokStateMoveBoxImpl(TSquare *pBox, TDirection direction)
{
    if (pBox == NULL)
    {
        return 0;
    }

    TVector2 dirv = BlokDirectionToVector(direction);
    TVector2 scaled = BlokVector2Multiply(dirv, pBox->size);
    TVector2 newpos = BlokVector2Offset(pBox->position, scaled);
    return BlokVector2Copy(&pBox->position, newpos);
}

int BlokStateInit(TObjectState *pState, const TVector2 scale)
{
    if (pState == NULL)
    {
        return 0;
    }

    pState->box.position = (TVector2){0, 0};
    pState->box.size = scale;

    return BlokDynArrInit(&pState->obstructs, 10);
}

int BlokStateFree(TObjectState *pState)
{
    if (pState == NULL)
    {
        return 0;
    }

    return BlokDynArrFree(&pState->obstructs);
}

int BlokStateMoveBox(TObjectState *pState, TDirection direction)
{
    if (pState == NULL)
    {
        return 0;
    }

    return _BlokStateMoveBoxImpl(&pState->box, direction);
}

int BlokStateIsBoxMovable(TObjectState *pState, TDirection direction)
{
    if (pState == NULL)
    {
        return 0;
    }

    TSquare projected = pState->box;
    if (!_BlokStateMoveBoxImpl(&projected, direction))
    {
        return 0;
    }

    TNode pos = {projected.position};
    if (BlokDynArrGetIndex(&pState->obstructs, &pos) == -1)
    {
        return 1;
    }

    return 0;
}

int BlokStateAddObstruct(TObjectState *pState, const TVector2 point)
{
    if (pState == NULL)
    {
        return -1;
    }

    TNode newPoint = {point};
    if (BlokDynArrExists(&pState->obstructs, &newPoint) == 1)
    {
        return -1;
    }

    return BlokDynArrAdd(&pState->obstructs, &newPoint);
}

int BlokStateRemoveObstruct(TObjectState *pState, const TVector2 point)
{
    if (pState == NULL)
    {
        return 0;
    }

    TNode removePoint = {point};
    return BlokDynArrRemove(&pState->obstructs, removePoint);
}

int BlokStateClearObstructs(TObjectState *pState)
{
    if (pState == NULL)
    {
        return 0;
    }

    return BlokDynArrClear(&pState->obstructs);
}