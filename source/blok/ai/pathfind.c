#include "pathfind.h"
#include <math.h>

double blokPathFindCalculateHeuristic(
    const VectorII ep,
    const VectorII sp)
{
    double dx = pow(ep.x - sp.x, 2);
    double dy = pow(ep.y - sp.y, 2);

    return sqrt(dx + dy);
}