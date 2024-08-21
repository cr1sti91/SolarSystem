#include "planet.h"
#include "Sun.h"

namespace space
{
    const double realDistToPixels(const double realDist); 
    const double pixDistToReal(const double fictDist);
    const double realVelocityToFict(const double realVelocity); 
    void gravitationalAttraction(const Sun* sun, Planet* planet); 
}; 