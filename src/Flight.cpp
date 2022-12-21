//
// Created by Joao Ribeiro on 17/12/2022.
//

#include "Flight.h"

Flight::Flight(string o, string d, string a): origin(o), destination(d), airline(a) {};

string Flight::getOrigin() const {
    return this->origin;
}

string Flight::getDestination() const {
    return this->destination;
}

string Flight::getAirline() const {
    return this->airline;
}