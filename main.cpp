#include "SolarSystemApp.h"

int main() 
{
    SolarSystemApp* app = new SolarSystemApp(width, height, windowName); 

    app->run(); 

    delete app; 

    return 0; 
}


