#ifndef ALLADDITIONLIBRARIES_H
#define ALLADDITIONLIBRARIES_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <cstdint>
#include <cmath>
#include <unordered_map>
#include <iostream>

enum class CelestBodies
{
    Mercury, Venus, Earth, Mars, 
    Jupiter, Saturn, Uranus, Neptune, Sun
}; 

// Masele planetelor exprimate in kg
const std::unordered_map<CelestBodies, double> TrueMasses
{
    {CelestBodies::Mercury,  3.301e23},
    {CelestBodies::Venus,    4.867e24},
    {CelestBodies::Earth,    5.972e24},
    {CelestBodies::Mars,     6.417e23},
    {CelestBodies::Jupiter,  1.898e27},
    {CelestBodies::Saturn,   5.683e26},
    {CelestBodies::Uranus,   8.681e25},
    {CelestBodies::Neptune,  1.024e26}, 
    {CelestBodies::Sun,      1.988e30}
}; 


// Distanta planetelor de la soare exprimata in metri
const std::unordered_map<CelestBodies, double> DistFromSun
{
    {CelestBodies::Mercury,  57.91e9  },
    {CelestBodies::Venus,    108.21e9 },
    {CelestBodies::Earth,    149.4e9  },
    {CelestBodies::Mars,     227.94e9 },
    {CelestBodies::Jupiter,  778.33e9 },
    {CelestBodies::Saturn,   1429.4e9 },
    {CelestBodies::Uranus,   2870.99e9},
    {CelestBodies::Neptune,  4498.25e9}
}; 

const double FictEarthDistFromSun = 800; // Distanta fictiva de la pamant la soare
                                         // exprimata in pixeli; relativ ei vor fi 
                                         // calculate distantele altor planete


// Vitezele medii ale planetelor in jurul Soarelui exprimate in m/s
const std::unordered_map<CelestBodies, double> PlanetVelocity
{
    {CelestBodies::Mercury,  47870 },
    {CelestBodies::Venus,    35020 },
    {CelestBodies::Earth,    29780 },
    {CelestBodies::Mars,     24070 },
    {CelestBodies::Jupiter,  13070 },
    {CelestBodies::Saturn,   9690  },
    {CelestBodies::Uranus,   6810  },
    {CelestBodies::Neptune,  54309 }
}; 

const double FictEarthVelocity = 0.5; // Viteza fictiva a pamantului; 
                                    // relativ ei vor fi calculete vitezele
                                    // pentru alte planete


// Razele planetelor rapotate la raza soarelui 
// Pentru Mercury, Venus, Earth si Mars are loc scalarea cu 10
// Pentru Jupiter, Saturn, Uranus si Neptun are loc scalarea cu 5
const int n = 3; 
const std::unordered_map<CelestBodies, float> Rays
{
    // Pentru planete, valorile sunt coeficienti care vor fi aplicati razei soarelui
    {CelestBodies::Mercury, 0.035 * n},
    {CelestBodies::Venus,   0.087 * n},
    {CelestBodies::Earth,   0.091 * n},
    {CelestBodies::Mars,    0.049 * n},
    {CelestBodies::Jupiter, 0.503 * n}, 
    {CelestBodies::Saturn,  0.418 * n},
    {CelestBodies::Uranus,  0.182 * n},
    {CelestBodies::Neptune, 0.176 * n},

    // Raza soarelui este raza de referinta, in dependeta de care vor 
    // fi calculate razele planetelor
    {CelestBodies::Sun, 100}
}; 

const short width =  1792;
const short height = 1024;
const short frameLimit = 60;
const std::string windowName = "Solar System";


// Physics constants
const double G = 6.674e-11;                // Constanta gravitationala
const double real_T_earth = 31558149.504;  // Perioada de rotatie a pamantului [s]
const double fict_T_earth = 5;             // Perioada fictiva de rotatie a pamantului [s]



#endif //ALLADDITIONLIBRARIES_H