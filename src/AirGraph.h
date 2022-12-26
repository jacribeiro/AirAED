//
// Created by johny on 26/12/2022.
//

#ifndef PROJ2_AIRGRAPH_H
#define PROJ2_AIRGRAPH_H


#include "Airport.h"
#include "Flight.h"

class AirGraph {
    // adding a new 'node' to the graph
    void addAirport(Airport airport);

    //adding a new 'edge' to the graph
    void addFlight(Flight flight);

};


#endif //PROJ2_AIRGRAPH_H
