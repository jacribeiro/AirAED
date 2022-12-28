//
// Created by Joao Ribeiro on 17/12/2022.
//

#include "Flight.h"

Flight::Flight(Airport airport, Airline company): destination(airport), airline(company) {};

Airport Flight::getDestination() const {
    return this->destination;
}

Airline Flight::getAirline() const {
    return this->airline;
}