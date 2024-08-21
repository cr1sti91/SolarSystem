#ifndef PLANET_H
#define PLANET_H

#include "AllAdditionAndFunctions.h"

struct Vector2d
{
    double x; 
    double y; 
}; 

class Planet
{
private: 
    double m_mass; 
    double m_distFromSun; 
    CelestBodies m_planetName; 

    Vector2d m_realVelocity;     
    Vector2d m_fictVelocity; 

    sf::CircleShape* m_shape; 
    sf::Clock m_clock; 
    sf::Time m_lapse; 
    std::vector<sf::CircleShape*> m_trail;  // pentru a păstra urmele orbitei


    // Private setters
    void setShapeProperties(); 

public: 
    Planet(const CelestBodies p_planetName); 
    ~Planet(); 

    void updatePosition(); 

    // Setters
    void setPosition(const float p_x, const float p_y);
    void addVelocity(const double v_x, const double v_y);  
    void setMass(const double newMass); 
    void setLapse(const sf::Time& newTime); 
    
    // Getters
    const double getMass() const; 
    const double getDistFromSun() const; 
    const sf::CircleShape* getShape() const; 
    const sf::Clock& getClock() const;
    const sf::Time& getLapse() const; 

    // Setters that works as getters
    std::vector<sf::CircleShape*>& getTrailRef(); 
}; 

#endif //PLANET_H