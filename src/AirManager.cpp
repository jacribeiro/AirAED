//
// Created by Joao Ribeiro on 26/12/2022.
//

#include <queue>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <set>
#include "AirManager.h"

AirManager::AirManager() {
    readAirlinesFile("CSV/airlines.csv");
    readAirportsFile("CSV/airports.csv");
    readFlightsFile("CSV/flights.csv");
}

pair<float, float> sToCoord(string coord) {
    size_t comma = coord.find(',');
    string lat = coord.substr(0, comma);
    string lon = coord.substr(comma + 1, coord.size() - lat.size() - 1);
    return {stof(lat), stof(lon)};
}

float haversine(float p1long, float p1lat, float p2long, float p2lat){

    return 2.0 * 6371 * asin(sqrt(pow(sin((p2lat - p1lat)/2),2) + cos(p2lat) * cos(p1lat) + pow(sin((p2long - p1long)/2),2)));
}

unordered_map<string, Airport> AirManager::getAirports() {
    return airports;
}

unordered_map<string, Airline> AirManager::getAirlines() {
    return airlines;
}

void AirManager::readAirlinesFile(string fname) {
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        // Read the first line and discard
        getline(file, line);
        string code, name, nickname, country;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, code, ',');
            getline(inputString, name, ',');
            getline(inputString, nickname, ',');
            getline(inputString, country, ',');
            Airline a1 = Airline(code, name, nickname, country);
            airlines.insert({code, a1});
        }
    } else {
        cout << "Could not open airlines file" << endl;
    }
}

void AirManager::readAirportsFile(string fname) {
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        // Read the first line and discard it
        getline(file, line);
        string code, name, city, country, temp;
        float lat, lon;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, code, ',');
            getline(inputString, name, ',');
            getline(inputString, city, ',');
            getline(inputString, country, ',');
            getline(inputString, temp, ',');
            lat = stof(temp);
            getline(inputString, temp, ',');
            lon = stof(temp);
            Airport a1 = Airport(code, name, city, country, lat, lon);
            airports.insert({code, a1});
            if (cities.find(city) == cities.end()) {
                vector<string> a1 = {code};
                cities.insert({city, a1});
            } else {
                cities.at(city).push_back(code);
            }
        }
    } else {
        cout << "Could not open airports file" << endl;
    }
}

void AirManager::readFlightsFile(string fname) {
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        getline(file, line);
        string origin, destination, airline;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, origin, ',');
            getline(inputString, destination, ',');
            getline(inputString, airline, ',');
            Flight f1 = Flight(destination, airline);
            auto it = airports.find(origin);
            it->second.addFlight(f1);
        }
    } else {
        cout << "Could not open flights file" << endl;
    }
}

void AirManager::bfs(string origin) {
    for (auto a : airports){
        a.second.unvisit();
    }
    queue<string> q;
    q.push(origin);
    airports.at(origin).visit();
    airports.at(origin).setDistance(0);

    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto f : airports.at(u).getFlights()){
            string dest = f.getDestination();
            if(!airports.at(dest).getVisited()){
                q.push(airports.at(dest).getCode());
                airports.at(dest).visit();
                airports.at(dest).setDistance(airports.at(u).getDistance() + 1);
            }
        }
    }
}

void AirManager::bfs_path(string ori, string dest) {
    for (auto a: airports) {
        a.second.unvisit();
        a.second.setPrevious("");
    }
    queue<string> q;
    q.push(ori);
    airports.at(ori).visit();
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto f: airports.at(u).getFlights()) {
            string d = f.getDestination();
            if (!airports.at(d).getVisited()) {
                q.push(airports.at(d).getCode());
                airports.at(d).visit();
                airports.at(d).setDistance(airports.at(u).getDistance() + 1);
                airports.at(d).setPrevious(airports.at(u).getCode());
                if (d == dest) return;
            }
        }
    }
}

vector<string> AirManager::bestRouteDistribution(string ori, string dest, pair<int, int> option) {
    switch (option.first) {
        case 1:
            switch (option.second) {
                case 1:
                    return bestRoute(ori, dest);
                case 2:
                    return bestRoute2(ori, dest);
                case 3:
                    return bestRoute3(ori, dest);
            }
        case 2:
            switch (option.second) {
                case 1:
                    return bestRoute4(ori, dest);
                case 2:
                    return bestRoute5(ori, dest);
                case 3:
                    return bestRoute6(ori, dest);
            }
        case 3:
            switch (option.second) {
                case 1:
                    return bestRoute7(ori, dest);
                case 2:
                    return bestRoute8(ori, dest);
                case 3:
                    return bestRoute9(ori, dest);
            }

    }
}

vector<string> AirManager::bestRoute(string ori, string dest) {
    vector<string> route;
    bfs_path(ori, dest);
    while (dest != "") {
        route.insert(route.begin(), dest);
        dest = airports.at(dest).getPrevious();
    }
    return route;
}

vector<string> AirManager::bestRoute2(string ori, string city) {
    vector<string> route, aux;
    size_t bestSize = INT16_MAX;
    auto it = cities.at(city).begin();
    while (it != cities.at(city).end()) {
        aux = bestRoute(ori, (*it));
        if (aux.size() < bestSize) {
            route = aux;
            bestSize = route.size();
        }
        it++;
    }
    return route;
}

vector<string> AirManager::bestRoute3(string ori, string loc) {
    pair<float, float> coord = sToCoord(loc);
    string dest = nearestAirport(coord.first, coord.second);
    return bestRoute(ori, dest);
}

vector<string> AirManager::bestRoute4(string ori, string dest) {
    vector<string> route, aux;
    size_t bestSize = INT16_MAX;
    auto it = cities.at(ori).begin();
    while (it != cities.at(ori).end()) {
        aux = bestRoute((*it), dest);
        if (aux.size() < bestSize) {
            route = aux;
            bestSize = route.size();
        }
        it++;
    }
    return route;
}

vector<string> AirManager::bestRoute5(string ori, string dest) {
    vector<string> route, aux;
    size_t bestSize = INT16_MAX;
    auto itOri = cities.at(ori).begin();
    auto itDest = cities.at(dest).begin();
    while (itOri != cities.at(ori).end()) {
        while (itDest != cities.at(dest).end()) {
            aux = bestRoute((*itOri), (*itDest));
            if (aux.size() < bestSize) {
                route = aux;
                bestSize = route.size();
            }
            itDest++;
        }
        itDest = cities.at(dest).begin();
        itOri++;
    }
    return route;
}

vector<string> AirManager::bestRoute6(string ori, string dest) {
    vector<string> route, help;
    size_t bestSize = INT16_MAX;
    pair<float, float> aux = sToCoord(dest);
    string end = nearestAirport(aux.first, aux.second);
    auto it = cities.at(ori).begin();
    while (it != cities.at(ori).end()) {
        help = bestRoute((*it), dest);
        if (help.size() < bestSize) {
            route = help;
            bestSize = route.size();
        }
        it++;
    }
    return route;
}

vector<string> AirManager::bestRoute7(string ori, string dest) {
    pair<float, float> coords = sToCoord(ori);
    string ap = nearestAirport(coords.first, coords.second);
    vector<string> route = bestRoute(ap, dest);
    return route;
}

vector<string> AirManager::bestRoute8(string ori, string dest) {
    pair<float, float> coords = sToCoord(ori);
    string ap = nearestAirport(coords.first, coords.second);
    vector<string> route = bestRoute2(ap, dest);
    return route;
}

vector<string> AirManager::bestRoute9(string ori, string dest) {
    pair<float, float> coords_partida = sToCoord(ori);
    pair<float, float> coords_destino = sToCoord(dest);

    string ap_p = nearestAirport(coords_partida.first, coords_partida.second);
    string ap_d = nearestAirport(coords_destino.first, coords_destino.second);

    vector<string> route = bestRoute(ap_p, ap_d);
    return route;
}

vector<string> AirManager::getAirportsInCity(string city) {
    return cities.at(city);
}


vector<Airport> AirManager::getCountryAirport(string country) {
    vector<Airport> v;
    for (auto x : airports){
        if (x.second.getCountry() == country){
            v.push_back(x.second);
        }
    }
    return v;

}

vector<Airline> AirManager::getCountryAirline(string country) {
    vector<Airline> v;
    for (auto x : airlines){
        if (x.second.getCountry() == country){
            v.push_back(x.second);
        }
    }
    return v;
}

Airline AirManager::getAirlineInformation(string airlinecode) {
    auto x = airlines.at(airlinecode);
    return x;
}

vector<Flight> AirManager::getAirportDestinations(string airportcode) {
    vector<Flight> v;
    auto x = airports.at(airportcode);
    v = x.getFlights();
    return v;

}

Airport AirManager::getAirportInformation(string airportcode) {
    auto x = airports.at(airportcode);
    return x;
}

int AirManager::getNumAirlinesByAirport(string airport) {
    set<string> s;
    auto x = airports.at(airport);
    for (auto a: x.getFlights()){
        s.insert(a.getAirline());
    }
    return s.size();
}

int AirManager::getNumDestinationsByAirport(string airport) {
    set<string> s;
    auto x = airports.at(airport);
    for (auto a: x.getFlights()){
        s.insert(a.getDestination());
    }
    return s.size();
}

int AirManager::getNumFlightsByAirport(string airport) {
    set<string> s;
    auto x = airports.at(airport);
    return x.getFlights().size();
}

int AirManager::getNumAirportsInCountry(string country) {
    auto v = getCountryAirport(country);
    return v.size();
}

int AirManager::getNumDestinationsByCountry(string country) {
    set<string> s;
    auto v = getCountryAirport(country);
    for (auto x: v){
        for (auto a: getAirportDestinations(x.getCode())){
            s.insert(a.getDestination());
        }
    }
    return s.size();
}

int AirManager::getNumAirlinesByCountry(string country) {
    set<string> s;
    auto v = getCountryAirport(country);
    for (auto x: v){
        for (auto a: getAirportDestinations(x.getCode())){
            s.insert(a.getAirline());
        }
    }
    return s.size();
}

int AirManager::getNumFlightsByCountry(string country) {
    vector<string> s;
    auto v = getCountryAirport(country);
    for (auto x: v){
        for(auto f: x.getFlights()){
            s.push_back(f.getDestination());
        }
    }
    return s.size();
}

vector<Airport> AirManager::getAirlineDestinations(string airlinecode) {
     vector<Airport> v;
     set<string> s;
     for (auto x: airports){
         for (auto f : x.second.getFlights()){
             if (f.getAirline() == airlinecode) s.insert(x.second.getCode());
         }
     }
     for (auto x: s){
         Airport a = getAirportInformation(x);
         v.push_back(a);
     }
     return v;
}

int AirManager::getNumCountriesByAirline(string airline) {
    set<string> s;
    auto v = getAirlineDestinations(airline);
    for (auto x: v){
        s.insert(x.getCountry());
    }
    return s.size();
}

int AirManager::getNumFlightsByAirline(string airline) {
    vector<Flight> v;
    for (auto x: airports){
        for (auto f : x.second.getFlights()){
            if (f.getAirline() == airline) v.push_back(f);
        }
    }
    return v.size();
}

int AirManager::getGlobalNumCountries() {
    set<string> s;
    for (auto x : airports){
        s.insert(x.second.getCountry());
    }
    return s.size();
}

int AirManager::getGlobalNumFlights() {
    int cont = 0;
    for (auto a: airports){
        for (Flight f: a.second.getFlights()){
            cont++;
        }
    }
    return cont;
}

string AirManager::nearestAirport(float lat, float lon) {
    string nearest;
    float minDistance = numeric_limits<float>::max();
    for (auto a: this->airports) {
        float distance = haversine(lon, lat, a.second.getLongitude(), a.second.getLatitude());
        if (distance < minDistance) {
            minDistance = distance;
            nearest = a.second.getCode();
        }
    }
    return nearest;
}
