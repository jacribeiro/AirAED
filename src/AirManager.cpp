//
// Created by Joao Ribeiro on 26/12/2022.
//

#include <queue>
#include "AirManager.h"


void AirManager::bfs(Airport airport) {
    for (auto a : airports){
        a.second.unvisit();
    }
    queue<Airport> q;
    q.push(airport);
    airport.visit();
    airport.setDistance(0);

    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto f : u.getFlights()){
            Airport a = airports.at(f.getDestination());
            if(!a.getvisited()){
                q.push(a);
                a.visit();
                a.setDistance(airport.getDistance() + 1);
            }
        }
    }
}

AirManager::AirManager(FileReader r) {
    this->reader = r;
    setAirlines(r.readAirlinesFile("CSV/airlines.csv"));
    setAirports(r.readAirportFile("CSV/airports.csv"));
}

void AirManager::setAirlines(unordered_map<std::string, Airline> airlines) {
    this->airlines = airlines;
}

void AirManager::setAirports(unordered_map<std::string, Airport> airports) {
    this->airports = airports;
}

