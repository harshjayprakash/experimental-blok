#include "state.h"

void bkStateInit(bkState* state)
{
	if (!state) return;
	state->user = (bkSquare){ { 0, 0 }, { 15, 15 } };
}

void bkStateFree(bkState* state)
{
	if (!state) return;
}
