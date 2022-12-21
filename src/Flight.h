//
// Created by Joao Ribeiro on 17/12/2022.
//

#ifndef PROJ2_FLIGHT_H
#define PROJ2_FLIGHT_H

#include <string>

using namespace std;

class Flight {

    string origin;
    string destination;
    string airline;

public:
    /**
     * Creates a new Flight object
     * @param origin The IATA code for the origin airport
     * @param destination The IATA code for the destination airport
     * @param company The ICAO code for the airline responsible for the flight
     */
    Flight(string o, string d, string a);

    /**
     * Returns the IATA code for the origin airport
     * @return The IATA code for the origin airport
     */
    string getOrigin() const;

    /**
     * Returns the IATA code for the destination airport
     * @return the IATA code for the destination airport
     */
    string getDestination() const;

    /**
     * Returns the ICAO code for the airline responsible for the flight
     * @return the ICAO code for the airline responsible for the flight
     */
    string getAirline() const;
};


#endif //PROJ2_FLIGHT_H
