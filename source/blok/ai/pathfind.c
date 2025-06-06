#include "pathfind.h"
#include <math.h>

double blokPathFindCalculateHeuristic(
    const TVector2 ep,
    const TVector2 sp)
{
    double dx = pow(ep.x - sp.x, 2);
    double dy = pow(ep.y - sp.y, 2);

    return sqrt(dx + dy);
}