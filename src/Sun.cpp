#include "Sun.h"

void Sun::setShapeProperties()
{
    this->m_shape->setFillColor(sf::Color::Yellow); // In mod implicit, soarele va fi galben

    //La moment soarele are pozitie nemiscata in centrul window-ului
    this->m_shape->setOrigin(Rays.at(CelestBodies::Sun), Rays.at(CelestBodies::Sun)); 
    this->m_shape->setPosition(width/2, height/2);  
} 


Sun::Sun() : m_mass(TrueMasses.at(CelestBodies::Sun)), 
             m_shape(new sf::CircleShape(Rays.at(CelestBodies::Sun)))
{
    this->setShapeProperties(); 
}

// Setters
void Sun::setMass(const double newMass)
{
    this->m_mass = newMass; 
}


// Getters
const sf::CircleShape* Sun::getShape() const
{
    return this->m_shape; 
}

const double Sun::getMass() const
{
    return this->m_mass; 
}
