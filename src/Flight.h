//
// Created by Joao Ribeiro on 17/12/2022.
//

#ifndef PROJ2_FLIGHT_H
#define PROJ2_FLIGHT_H

#include <string>
#include "Airline.h"

using namespace std;

class Flight {

    string destination;
    string airline;

public:
    /**
     * Creates a new Flight object
     * @param airport IATA code for the origin airport
     * @param airline ICAO code for the airline responsible for the flight
     */
    Flight(string airport, string airline);

    /**
     * Returns ICAO code for the destination airport(Complexity: O(1))
     * @return the ICAO code for the destination airport
     */
    string getDestination() const;

    /**
     * Returns the airline responsible for the flight(Complexity: O(1))
     * @return the airline responsible for the flight
     */
    string getAirline() const;
};


#endif //PROJ2_FLIGHT_H
