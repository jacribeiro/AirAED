//
// Created by Joao Ribeiro on 26/12/2022.
//

#ifndef PROJ2_AIRMANAGER_H
#define PROJ2_AIRMANAGER_H


#include <unordered_map>
#include "FileReader.h"
#include "Airport.h"

class AirManager {
    unordered_map<string, Airport> airports;
    unordered_map<string, Airline> airlines;
    FileReader reader;

public:
    /**
     * Creates a new AirManager object
     * @param r A FileReader object, to be used by the AirManager
     */
    AirManager(FileReader r);

    /**
     * Sets the airlines that will be in the system
     * @param airlines Unordered_map of airlines to be added to the system
     */
    void setAirlines(unordered_map<string, Airline> airlines);

    /**
     * Sets the airports that will be in the system
     * @param airports Unordered_map of airports to be added to the system
     */
    void setAirports(unordered_map<string, Airport> airports);

    /**
     * Adds a Flight to the system
     * @param origin IATA code of the airport of origin
     * @param flight Flight object to be added
     */
    void addFlight(string origin, const Flight& flight);

    void readFlightsFile(string fname);

    void bfs(Airport airport);

    vector<Airport> getCountryInformation(string country);
};


#endif //PROJ2_AIRMANAGER_H
