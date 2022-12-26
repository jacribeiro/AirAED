//
// Created by Joao Ribeiro on 17/12/2022.
//

#include "Airport.h"

#include <utility>

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