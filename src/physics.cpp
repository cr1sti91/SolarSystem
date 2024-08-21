#include "physics.h"

namespace space
{
    const double realDistToPixels(const double realDist)
    {
        // Un metru real este echivalent cu 'scale' pixeli
        const double scale = FictEarthDistFromSun / DistFromSun.at(CelestBodies::Earth); 
        return realDist * scale; 
    }

     const double pixDistToReal(const double fictDist)
    {
        const double scale = DistFromSun.at(CelestBodies::Earth) / FictEarthDistFromSun; 
        return fictDist * scale; 
    }

    const double realVelocityToFict(const double realVelocity)
    {
        // Un metru real este echivalent cu 'scale' pixeli
        const double scale = FictEarthVelocity / PlanetVelocity.at(CelestBodies::Earth); 
        return realVelocity * scale; 
    }

    void gravitationalAttraction(const Sun* sun, Planet* planet)
    {
        double gravAcceleration = (G * sun->getMass()) / std::pow(planet->getDistFromSun(), 2)
                                  * real_T_earth / fict_T_earth * (planet->getClock().getElapsedTime() 
                                  - planet->getLapse()).asSeconds();

        planet->setLapse(planet->getClock().getElapsedTime()); 
        
        sf::Vector2f pos_P = planet->getShape()->getPosition(); 
        sf::Vector2f pos_S = sun->getShape()->getPosition(); 

        double distance_x = pos_S.x - pos_P.x;
        double distance_y = pos_S.y - pos_P.y;
 
        double distance = std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
  
        double normalized_x = distance_x / distance;
        double normalized_y = distance_y / distance;

        planet->addVelocity(normalized_x * gravAcceleration, normalized_y * gravAcceleration); 
        planet->updatePosition(); 
    }
}; 