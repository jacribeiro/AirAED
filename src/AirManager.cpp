//
// Created by Joao Ribeiro on 26/12/2022.
//

#include <queue>
#include <cmath>
#include "AirManager.h"

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

void AirManager::addFlight(string origin, const Flight& flight) {
    Airport airport = airports.at(origin);
    airport.addFlight(flight);
}

void AirManager::readFlightsFile(string fname) {

}

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

float haversine(float p1long, float p1lat, float p2long, float p2lat){
    return 2 * 6371 * asin(sqrt(pow(sin((p2lat - p1lat)/2),2) + cos(p2lat) * cos(p1lat) + pow(sin((p2long - p1long)/2),2)));
}
