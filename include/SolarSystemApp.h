#ifndef SOLARSYSTEMAPP_H
#define SOLARSYSTEMAPP_H

#include "AllAdditionAndFunctions.h"
#include "physics.h"


class SolarSystemApp
{
private:
    sf::RenderWindow* m_window;
    sf::Event m_event; 

    std::vector<Planet*> m_planets; 
    Sun* m_sun; 

    //Objects masses
    std::unordered_map<CelestBodies, double> m_bodiesMasses; 

    // Metode private
    void initBodiesMasses(); 
    void initPlanets(); 
    void initSun(); 

    // Metode

    void drawShapes() const; 
    void update(); 

public: 
    SolarSystemApp(const short p_width, const short p_height, const std::string& p_name); 
    ~SolarSystemApp(); 
    void run(); 

}; 

#endif //SOLARSYSTEMAPP_H