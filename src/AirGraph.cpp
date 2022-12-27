//
// Created by johny on 26/12/2022.
//

#include <queue>
#include "AirGraph.h"

void AirGraph::bfs(Airport *airport) {
    for (auto a : airports){
        a.unvisit();
    }
    queue<Airport> q;
    q.push(*airport);
    airport->visit();

    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto f : u.getFlights()){
            auto *a = f.getDestination();
            if(!a.)
        }
    }
}