#ifndef ALLADDITIONANDFUNCTIONS_H
#define ALLADDITIONANDFUNCTIONS_H

#include "AllAdditionLibraries.h"

const double real_dist_to_fict(const double realDist); 
const sf::Color get_planet_color(const CelestBodies& planet); 
const sf::Vector2f dist_and_angle_to_pos(const double dist, const float angle = 0); 

#endif //ALLADDITIONANDFUNCTIONS_H