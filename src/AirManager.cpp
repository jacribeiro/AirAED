//
// Created by johny on 26/12/2022.
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
            Airport a = f.getDestination();
            if(!a.getvisited()){
                q.push(a);
                a.visit();
                a.setDistance(airport.getDistance() + 1);
            }
        }
    }
}