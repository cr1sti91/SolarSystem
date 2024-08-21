#include "planet.h"

void Planet::setShapeProperties()
{
    this->m_shape->setFillColor(get_planet_color(m_planetName)); 
    this->m_shape->setOrigin(this->m_shape->getRadius(), this->m_shape->getRadius());
    this->m_shape->setPosition(dist_and_angle_to_pos(real_dist_to_fict(this->m_distFromSun))); 
}

void Planet::setLapse(const sf::Time& newTime)
{
    this->m_lapse = newTime; 
} 

std::vector<sf::CircleShape*>& Planet::getTrailRef()
{
    return this->m_trail; 
}



const sf::Clock& Planet::getClock() const
{
    return this->m_clock; 
}

const sf::Time& Planet::getLapse() const
{
    return this->m_lapse; 
} 


Planet::Planet(const CelestBodies p_planetName)
    : m_distFromSun(DistFromSun.at(p_planetName)),  
      m_realVelocity{0, - PlanetVelocity.at(p_planetName)},
      m_fictVelocity{0, - FictEarthDistFromSun * PlanetVelocity.at(p_planetName) / DistFromSun.at(CelestBodies::Earth)},
      m_mass(TrueMasses.at(p_planetName)), m_planetName(p_planetName),
      m_shape(new sf::CircleShape(Rays.at(p_planetName) * Rays.at(CelestBodies::Sun)))
{
    this->setShapeProperties(); 
}

Planet::~Planet() 
{
    delete m_shape; 

    for (auto& point : this->m_trail)
    {
        delete point; 
    }
}

void Planet::updatePosition()
{
    this->m_shape->move(this->m_fictVelocity.x, this->m_fictVelocity.y); 

    this->m_trail.push_back(new sf::CircleShape(1)); 
    this->m_trail.at(this->m_trail.size() - 1)->setFillColor(sf::Color::Green); 
    this->m_trail.at(this->m_trail.size() - 1)->setPosition(this->m_shape->getPosition().x, this->m_shape->getPosition().y); 

    if (m_trail.size() > 500)  
    {
        m_trail.erase(m_trail.begin());
    }
} 


// Setters
void Planet::setPosition(const float p_x, const float p_y)
{
    this->m_shape->setPosition(p_x, p_y); 
}

void Planet::addVelocity(const double v_x, const double v_y)
{
    this->m_realVelocity.x += v_x; 
    this->m_realVelocity.y += v_y; 

    this->m_fictVelocity.x = FictEarthVelocity * m_realVelocity.x / PlanetVelocity.at(CelestBodies::Earth); 
    this->m_fictVelocity.y = FictEarthVelocity * m_realVelocity.y / PlanetVelocity.at(CelestBodies::Earth); 
}


void Planet::setMass(const double newMass)
{
    this->m_mass = newMass; 
}

// Getters  
const sf::CircleShape* Planet::getShape() const
{
    return this->m_shape; 
}

const double Planet::getMass() const
{
    return this->m_mass; 
} 

const double Planet::getDistFromSun() const
{
    return this->m_distFromSun; 
}
