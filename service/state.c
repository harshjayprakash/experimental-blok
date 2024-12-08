#include "state.h"

void bkStateInit(bkState* state)
{
	if (!state) return;
	state->user = (bkSquare){ { 0, 0 }, { 15, 15 } };
	state->showInterface = 1;
}

void bkStateFree(bkState* state)
{
	if (!state) return;
}
