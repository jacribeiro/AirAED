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

    /**
     * Reads the file containing the flights, and adds them to the system
     * @param fname Name of the file containing the flights
     */
    void readFlightsFile(string fname);

    void bfs(Airport airport);

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
     * It creates a vector with all the Destinations you can fly to from the given Airport
     * @param airlinecode string refering to airline code
     * @return vector with all the Destinations you can fly to from the given Airport
     */
    vector<Flight> getAirportDestinations(string airlinecode);
    /**
     * Creates Airport Object with the given airportcode
     * @param airportcode string refering to airport code
     * @return  Airport Object with the given airportcode
     */
    Airport getAirportInformation(string airportcode);
    /**
     * Counts the number of airlines that fly from/to the given Airport
     * @param airport string refering to airport code
     * @return the number of airlines that fly from/to the given Airport
     */
    int getNumAirlinesByAirport(string airport);
    /**
     * Counts the number of destinations you can fly from the given Airport
     * @param airport string refering to airport code
     * @return the number of destinations you fly can from the given Airport
     */
    int getNumDestinationsByAirport(string airport);
    /**
     * Counts the number of flights from the given Airport
     * @param airport string refering to airport code
     * @return the number of flights from the given Airport
     */
    int getNumFlightsByAirport(string airport);
    /**
     * Counts the number of National Airports
     * @param country string refering to country Name
     * @return the number of National Airports
     */
    int getNumAirportsInCountry(string country);

    /**
    * Counts the number of destinations you can fly from the given Country
    * @param country string refering to country Name
    * @return the number of destinations you can fly from the given Country
    */
    int getNumDestinationsByCountry(string country);
    /**
    * Counts the number of airlines you can fly from the given Country
    * @param country string refering to country Name
    * @return the number of airlines you can fly from the given Country
    */
    int getNumAirlinesByCountry(string country);
    /**
    * Counts the number of flights you can fly from the given Country
    * @param country string refering to country Name
    * @return the number of flights you can fly from the given Country
    */
    int getNumFlightsByCountry(string country);
};


#endif //PROJ2_AIRMANAGER_H
