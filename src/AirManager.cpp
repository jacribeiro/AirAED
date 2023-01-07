//
// Created by Joao Ribeiro on 26/12/2022.
//

#include <queue>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include "AirManager.h"

AirManager::AirManager(FileReader r) {
    this->reader = r;
    setAirlines(r.readAirlinesFile("CSV/airlines.csv"));
    setAirports(r.readAirportFile("CSV/airports.csv"));
    readFlightsFile("CSV/flights.csv");
}

unordered_map<string, Airport> AirManager::getAirports() {
    return airports;
}

unordered_map<string, Airline> AirManager::getAirlines() {
    return airlines;
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

int AirManager::bestRouteAirports(string origin, string destination) {
    bfs(airports.at(origin));
    return airports.at(destination).getDistance();
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

float haversine(float p1long, float p1lat, float p2long, float p2lat){
    return 2 * 6371 * asin(sqrt(pow(sin((p2lat - p1lat)/2),2) + cos(p2lat) * cos(p1lat) + pow(sin((p2long - p1long)/2),2)));
}
