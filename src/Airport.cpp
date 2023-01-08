//
// Created by Joao Ribeiro on 17/12/2022.
//

#include "Airport.h"
#include <utility>

using namespace std;

Airport::Airport(string c, string n, string ct, string cy, float lat, float lon):
    code(move(c)), name(move(n)), city(move(ct)), country(move(cy)), latitude(lat), longitude(lon) {};

string Airport::getCode() const {
    return this->code;
}

string Airport::getName() const {
    return this->name;
}

string Airport::getCity() const {
    return this->city;
}

string Airport::getCountry() const {
    return this->country;
}

float Airport::getLatitude() const {
    return this->latitude;
}

float Airport::getLongitude() const {
    return this->longitude;
}

void Airport::visit() {
    this->visited = true;
}

void Airport::unvisit() {
    this->visited = false;
}

bool Airport::getVisited() {
    return this->visited;
}

vector<Flight> Airport::getFlights() {
    return this->flights;
}

int Airport::getDistance() {
    return this->distance;
}

void Airport::setDistance(int d) {
    this->distance = d;
}

string Airport::getPrevious() {
    return this->previous;
}

void Airport::setPrevious(string previous) {
    this->previous = previous;
}

void Airport::addFlight(const Flight &flight) {
    flights.push_back(flight);
}

bool Airport::operator==(const Airport &a2) const {
    return this->code == a2.code;
}