#ifndef SUN_H
#define SUN_H

#include "AllAdditionLibraries.h"

class Sun
{
private: 
    double m_mass; 
    sf::CircleShape* m_shape; 

    // Private methods
    void setShapeProperties(); 

public: 
    Sun(); 

    // Setters
    void setMass(const double newMass); 

    // Getters
    const sf::CircleShape* getShape() const; 
    const double getMass() const; 

}; 

#endif //SUN_H