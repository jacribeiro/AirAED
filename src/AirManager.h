//
// Created by Joao Ribeiro on 26/12/2022.
//

#ifndef PROJ2_AIRMANAGER_H
#define PROJ2_AIRMANAGER_H


#include <unordered_map>
#include "FileReader.h"
#include "Airport.h"

class AirManager {
    unordered_map<string, Airport> airports;
    unordered_map<string, Airline> airlines;
    FileReader reader;

public:
    AirManager(FileReader r);
    void addAirport(Airport airport);
    void addFlight(Flight flight);
    void bfs(Airport airport);
    void setAirlines(unordered_map<string, Airline> airlines);
    void setAirports(unordered_map<string, Airport> airports);

};


#endif //PROJ2_AIRMANAGER_H
