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
    AirManager();
    /**
     * Creates a new AirManager object
     * @param r A FileReader object, to be used by the AirManager
     */
    AirManager(FileReader r);

    /**
     * Adds an Airport to the system
     * @param airport The airport to be added to the system
     */
    void addAirport(Airport airport);

    /**
     * Adds a Flight to the system
     * @param flight The flight to be added to the system
     */
    void addFlight(Flight flight);

    
    void bfs(Airport airport);
    void setAirlines(unordered_map<string, Airline> airlines);
    void setAirports(unordered_map<string, Airport> airports);
    float haversine(float p1long, float p1lat, float p2long, float p2lat);

    /**
     * It creates a vector with all the Airports of a country
     * @param country string refering to country name
     * @return vector with all the Airports of a country
     */
    vector<Airport> getCountryAirport(string country);
    /**
     * It creates a vector with all the AirLines of a country
     * @param country string refering to country name
     * @return vector with all the AirLines of a country
     */
    vector<Airline> getCountryAirline(string country);
    /**
     * It creates an Airline Object with all the the information of given Airline
     * @param airlinecode string refering to airline code
     * @return Object with all the information of the AirLine
     */
    Airline getAirlineInformation(string airlinecode);
    /**
     * It creates a vector with all the Airports the given Airline flies to
     * @param airlinecode tring refering to airline code
     * @return vector with all the Airports the given Airline flies to
     */
    vector<Airport> getAirlineDestinations(string airlinecode);
};


#endif //PROJ2_AIRMANAGER_H
