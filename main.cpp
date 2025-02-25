#include <iostream>
#include <string>
#include "SpaceRoute.cpp"

using namespace std;

int main() {

    string mars = "Mars";
    string jupiter = "Jupiter";
    string saturn = "Saturn";
    string earth = "Earth";
    string venus = "Venus";

    SpaceRoute<string> voyagerRoute;

    voyagerRoute.addWaypointAtIndex(0,mars);
    voyagerRoute.print();


    return 0;
}