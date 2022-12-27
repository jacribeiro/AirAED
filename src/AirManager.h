//
// Created by johny on 26/12/2022.
//

#ifndef PROJ2_AIRMANAGER_H
#define PROJ2_AIRMANAGER_H


#include <unordered_map>
#include "AirGraph.h"
#include "Airline.h"
#include "FileReader.h"

class AirManager {
    FileReader reader;
    unordered_map<string, Airline> airlines;
    unordered_map<string, Airport> airports;
    AirGraph graph;

public:
    AirManager(FileReader r);
    void setAirlines(unordered_map<string, Airline> airlines);
    void setAirports(unordered_map<string, Airport> airports);
    AirGraph createGraph();

};


#endif //PROJ2_AIRMANAGER_H
