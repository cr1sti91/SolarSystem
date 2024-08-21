#include "AllAdditionAndFunctions.h"


const double real_dist_to_fict(const double realDist)
{
    return (realDist * FictEarthDistFromSun) / DistFromSun.at(CelestBodies::Earth); 
}

const sf::Vector2f dist_and_angle_to_pos(const double dist, const float angle)
{
    // Incepem din pozitia centrala a window-ului (pozitia initiala pentru soare)
    sf::Vector2f result(width/2, height/2); 

    result.x += dist * std::cos(angle); 
    result.y += dist * std::sin(angle); 

    return result; 
}

const sf::Color get_planet_color(const CelestBodies& planet)
{
    switch (planet)
    {
    case CelestBodies::Mercury:
        return sf::Color::White;
    case CelestBodies::Venus:
        return sf::Color::Yellow;
    case CelestBodies::Earth:
        return sf::Color::Cyan;
    case CelestBodies::Mars:
        return sf::Color::Red;
    case CelestBodies::Jupiter:
        return sf::Color::Red;
    case CelestBodies::Saturn:
        return sf::Color::Yellow;
    case CelestBodies::Uranus:
        return sf::Color::Cyan;
    case CelestBodies::Neptune:
        return sf::Color::Blue;    
    default: std::cerr << "ERROR::AllAdditionAndFunctions::getPlanetColor::Incorect planet!"; 
        return sf::Color::White; 
        break;
    }
}