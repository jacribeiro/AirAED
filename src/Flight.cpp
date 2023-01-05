//
// Created by Joao Ribeiro on 17/12/2022.
//

#include "Flight.h"

#include <utility>

Flight::Flight(string airport, string airline): destination(std::move(airport)), airline(std::move(airline)) {};

string Flight::getDestination() const {
    return this->destination;
}

string Flight::getAirline() const {
    return this->airline;
}