//
// Created by Joao Ribeiro on 17/12/2022.
//

#ifndef PROJ2_FLIGHT_H
#define PROJ2_FLIGHT_H

#include <string>
#include "Airline.h"
#include "Airport.h"

using namespace std;

class Flight {

    string destination;
    Airline airline;

public:
    /**
     * Creates a new Flight object
     * @param destination The destination airport
     * @param company The airline responsible for the flight
     */
    Flight(string airport, const Airline& company);

    /**
     * Returns the destination airport
     * @return the destination airport
     */
    string getDestination() const;

    /**
     * Returns the airline responsible for the flight
     * @return the airline responsible for the flight
     */
    Airline getAirline() const;
};


#endif //PROJ2_FLIGHT_H
