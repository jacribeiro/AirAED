//
// Created by johny on 26/12/2022.
//

#include "AirManager.h"

AirManager::AirManager(FileReader r) {
    this->reader = r;
    setAirlines(r.readAirlinesFile("CSV/airlines.csv"));
    setAirports(r.readAirportFile("CSV/airports.csv"));
    this->graph = createGraph();
}

void AirManager::setAirlines(unordered_map<std::string, Airline> airlines) {
    this->airlines = airlines;
}

void AirManager::setAirports(unordered_map<std::string, Airport> airports) {
    this->airports = airports;
}

AirGraph AirManager::createGraph() {
    AirGraph graph = AirGraph();
    return graph;
}
