//
// Created by johny on 26/12/2022.
//

#ifndef PROJ2_AIRGRAPH_H
#define PROJ2_AIRGRAPH_H


#include <vector>
#include "Airport.h"
#include "Flight.h"

using namespace std;

class AirGraph {

    vector<Airport> airports;
    size_t n = airports.size();

    // adding a new 'node' to the graph
    void addAirport(Airport airport);

    //adding a new 'edge' to the graph
    void addFlight(Flight flight);


    void bfs(Airport *airport);
};


#endif //PROJ2_AIRGRAPH_H
