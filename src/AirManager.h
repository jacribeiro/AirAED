//
// Created by johny on 26/12/2022.
//

#ifndef PROJ2_AIRMANAGER_H
#define PROJ2_AIRMANAGER_H


#include <unordered_map>
#include "Airport.h"

class AirManager {
    unordered_map<string, Airport> airports;

public:
    void addAirport(Airport airport);
    void addFlight(Flight flight);
    void bfs(Airport airport);

};


#endif //PROJ2_AIRMANAGER_H
