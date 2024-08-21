#include "SolarSystemApp.h"

void SolarSystemApp::initBodiesMasses()
{
    this->m_bodiesMasses = TrueMasses;
}

void SolarSystemApp::initPlanets()
{
    this->m_planets.push_back(new Planet(CelestBodies::Mercury));
    this->m_planets.push_back(new Planet(CelestBodies::Venus));
    this->m_planets.push_back(new Planet(CelestBodies::Earth));
    this->m_planets.push_back(new Planet(CelestBodies::Mars));
    this->m_planets.push_back(new Planet(CelestBodies::Jupiter));
}

void SolarSystemApp::initSun()
{
    this->m_sun = new Sun(); 
}

void SolarSystemApp::drawShapes() const
{
    this->m_window->clear(); 

    // - - - - - - - - - - - - - - - - - - - - - - - 
    for (const auto& planet : this->m_planets)
    {
        this->m_window->draw(*planet->getShape()); 

        for (const auto& point : planet->getTrailRef())
        {
            this->m_window->draw(*point); 
        }
    }

    // Afisarea soarelui
    this->m_window->draw(*this->m_sun->getShape()); 
    // - - - - - - - - - - - - - - - - - - - - - - - 

    this->m_window->display(); 
}


void SolarSystemApp::update()
{
    for (auto planet : this->m_planets)
    {
        space::gravitationalAttraction(m_sun, planet); 
    }
}


SolarSystemApp::SolarSystemApp(const short p_width, const short p_height, const std::string& p_name)
    : m_window(new sf::RenderWindow(sf::VideoMode(p_width, p_height), p_name, 
                                    sf::Style::Close | sf::Style::Titlebar)) 
{
    this->initBodiesMasses(); 
    this->initSun();
    this->initPlanets(); 
}

SolarSystemApp::~SolarSystemApp()
{
    //Stergem window-ul
    delete this->m_window; 

    //Stergem planetele
    for (auto& planet : this->m_planets)
    {
        delete planet; 
    }
}

void SolarSystemApp::run() 
{
    while(this->m_window->isOpen())
    {
        this->drawShapes(); 

        while (this->m_window->pollEvent(this->m_event))
	    {
            if (this->m_event.type == sf::Event::Closed || this->m_event.key.code == sf::Keyboard::Escape)
            {
                this->m_window->close();
            }
        }

        this->update(); 
    }
}
