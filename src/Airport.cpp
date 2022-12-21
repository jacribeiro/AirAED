//
// Created by Joao Ribeiro on 17/12/2022.
//

#include "Airport.h"

Airport::Airport(string c, string n, string ct, string cy, float lat, float lon):
    code(c), name(n), city(ct), country(cy), latitude(lat), longitude(lon) {};

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