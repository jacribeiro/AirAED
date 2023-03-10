//
// Created by Joao Ribeiro on 26/12/2022.
//

#ifndef PROJ2_AIRMANAGER_H
#define PROJ2_AIRMANAGER_H


#include <unordered_map>
#include "Airport.h"

class AirManager {
    unordered_map<string, Airport> airports;
    unordered_map<string, Airline> airlines;
    unordered_map<string, vector<string>> cities;

public:
    /**
     * Creates a new AirManager object
     * @param r A FileReader object, to be used by the AirManager
     */
    explicit AirManager();

    /**
     * Returns the airports that will be in the system (Complexity: O(1))
     * @return Unordered_map of airports in the system
     */
    unordered_map<string, Airport> getAirports();
    /**
     * Returns the airlines that will be in the system (Complexity: O(1))
     * @return Unordered_map of airlines in the system
     */
    unordered_map<string, Airline> getAirlines();

    /**
     * Reads the file containing the airlines, adding them to the system
     * @param fname The name of the file to be read
     */
    void readAirlinesFile(string fname);

    /**
     * Reads the file containing the airports, adding them to the system (Complexity: O(n))
     * @param fname The name of the file to be read
     */
    void readAirportsFile(string fname);

    /**
     * Reads the file containing the flights, adding them to the system (Complexity: O(n))
     * @param fname Name of the file containing the flights
     */
    void readFlightsFile(string fname);
    /**
     * parses through all airports nodes (Complexity: O(|V| + |E|))
     * @param airport Code of the original airport
     */
    void bfs(string airport);

    /**
     * parses through all airports nodes between ori airport and dest airport (Complexity: O(|V| + |E|))
     * @param ori string refering to origin airport
     * @param dest string refering to destiny airport
     */
    void bfs_path(string ori, string dest);

    vector<string> bestRouteDistribution(string ori, string dest, pair<int, int> option);

    /**
     * Calculates, through BFS, the shortest path between two given airports (Complexity: O(|V| + |E|))
     * @param ori Code of the origin airport
     * @param dest Code of the destination airport
     * @return A vector containing the best route to take, starting from the origin airport, and ending in the destination
     */
    vector<string> bestRoute(string ori, string dest);

    /**
     * Calculates, through BFS, the shortest path between an airport and a given city (Complexity: O(|V| + |E|))
     * @param ori Code of the origin airport
     * @param city City of the destination
     * @return A vector containing the best route to take, starting from the origin airport, and ending in the destination
     */
    vector<string> bestRoute2(string ori, string city);

    /**
     * Calculates, through BFS, the shortest path between an airport and a given location (Complexity: O(|V| + |E|))
     * @param ori Code of the origin airport
     * @param loc String of coordinates (in the format "lat,lon") for the destination
     * @return A vector containing the best route to take, starting from the origin airport, and ending in the destination
     */
    vector<string> bestRoute3(string ori, string loc);

    /**
     * Calculates, through BFS, the shortest path between a city and a given airport (Complexity: O(|V| + |E|))
     * @param ori City of origin
     * @param dest Code of the destination airport
     * @return A vector containing the best route to take, starting from the origin city, and ending in the destination
     */
    vector<string> bestRoute4(string ori, string dest);

    /**
     * Calculates, through BFS, the shortest path between two cities (Complexity: O(|V| + |E|))
     * @param ori City of origin
     * @param dest City of destination
     * @return A vector containing the best route to take, starting from the origin city, and ending in the destination
     */
    vector<string> bestRoute5(string ori, string dest);

    /**
     * Calculates, through BFS, the shortest path between a city and a location (Complexity: O(|V| + |E|))
     * @param ori City of origin
     * @param dest String of coordinates (in the format "lat,lon") for the destination
     * @return A vector containing the best route to take, starting from the origin city, and ending in the destination
     */
    vector<string> bestRoute6(string ori, string dest);

    /**
     * Calculates, through BFS, the shortest path between a location and a given airport (Complexity: O(|V| + |E|))
     * @param ori String of coordinates (in the format "lat,lon") for the origin
     * @param dest Code of the destination airport
     * @return A vector containing the best route to take, starting from the origin location, and ending in the destination
     */
    vector<string> bestRoute7(string ori, string dest);

    /**
     * Calculates, through BFS, the shortest path between a location and a given airport (Complexity: O(|V| + |E|))
     * @param ori String of coordinates (in the format "lat,lon") for the origin
     * @param dest City of destination
     * @return A vector containing the best route to take, starting from the origin location, and ending in the destination
     */
    vector<string> bestRoute8(string ori, string dest);

    /**
     * Calculates, through BFS, the shortest path between two locations (Complexity: O(n)) (Complexity: O(|V| + |E|))
     * @param ori String of coordinates (in the format "lat,lon") for the origin
     * @param dest String of coordinates (in the format "lat,lon") for the destination
     * @return A vector containing the best route to take, starting from the origin location, and ending in the destination
     */
    vector<string> bestRoute9(string ori, string dest);

    /**
     * Returns vector of airport codes of airports located in the given city (Complexity: O(1))
     * @param city City whose airports we want to get
     * @return Vector of airport codes of airports located in the given city
     */
    vector<string> getAirportsInCity(string city);

    /**
     * It creates a vector with all the Airports of a country (Complexity: O(n))
     * @param country string refering to country name
     * @return vector with all the Airports of a country
     */
    vector<Airport> getCountryAirport(string country);
    /**
     * It creates a vector with all the AirLines of a country (Complexity: O(n))
     * @param country string refering to country name
     * @return vector with all the AirLines of a country
     */
    vector<Airline> getCountryAirline(string country);
    /**
     * It creates an Airline Object with all the the information of given Airline (Complexity: O(n))
     * @param airlinecode string refering to airline code
     * @return Object with all the information of the AirLine
     */
    Airline getAirlineInformation(string airlinecode);
    /**
     * It creates a vector with all the Destinations you can fly to from the given Airport (Complexity: O(1))
     * @param airlinecode string refering to airline code
     * @return vector with all the Destinations you can fly to from the given Airport
     */
    vector<Flight> getAirportDestinations(string airlinecode);
    /**
     * Creates Airport Object with the given airportcode (Complexity: O(n))
     * @param airportcode string refering to airport code
     * @return  Airport Object with the given airportcode
     */
    Airport getAirportInformation(string airportcode);
    /**
     * Counts the number of airlines that fly from/to the given Airport (Complexity: O(1))
     * @param airport string refering to airport code
     * @return the number(int) of airlines that fly from/to the given Airport
     */
    int getNumAirlinesByAirport(string airport);
    /**
     * Counts the number of destinations you can fly from the given Airport (Complexity: O(n))
     * @param airport string refering to airport code
     * @return the number(int) of destinations you fly can from the given Airport
     */
    int getNumDestinationsByAirport(string airport);
    /**
     * Counts the number of flights from the given Airport (Complexity: O(1))
     * @param airport string refering to airport code
     * @return the number(int) of flights from the given Airport
     */
    int getNumFlightsByAirport(string airport);
    /**
     * Counts the number of National Airports (Complexity: O(n))
     * @param country string refering to country Name
     * @return the number(int) of National Airports
     */
    int getNumAirportsInCountry(string country);

    /**
    * Counts the number of destinations you can fly from the given Country (Complexity: O(n1*n2))
    * @param country string refering to country Name
    * @return the number(int) of destinations you can fly from the given Country
    */
    int getNumDestinationsByCountry(string country);
    /**
    * Counts the number of airlines you can fly from the given Country (Complexity: O(n1*n2))
    * @param country string refering to country Name
    * @return the number(int) of airlines you can fly from the given Country
    */
    int getNumAirlinesByCountry(string country);
    /**
    * Counts the number of flights you can fly from the given Country (Complexity: O(n1*n2))
    * @param country string refering to country Name
    * @return the number(int) of flights you can fly from the given Country
    */
    int getNumFlightsByCountry(string country);
    /**
     * Creates a vector of Airports you can fly to, using the given Airline (Complexity: O(n1*n2))
     * @param airlinecode string refering to specific Airline Code
     * @return a vector of Airports  you can fly to, using the given Airline
     */
    vector<Airport> getAirlineDestinations(string airlinecode);
    /**
     * Counts the number of countries you can fly to, using the given Airline (Complexity: O(n))
     * @param airline string refering to specific Airline Code
     * @return the number(int) of countries you can fly to, using the given Airline
     */
    int getNumCountriesByAirline(string airline);
    /**
     * Counts the number of flight you can take using the given Airline (Complexity: O(n1*n2))
     * @param airline string refering to specific Airline Code
     * @return the number(int) of flight you can take using the given Airline
     */
    int getNumFlightsByAirline(string airline);

    /**
     * Returns the number of Flights in this System (Complexity: O(n1*n2))
     * @return the number(int) of Flights in this System
     * @return the number(int) of Flights in this System
     */
    int getGlobalNumFlights();

    /**
     * Returns the code of the airport nearest to the given coordinates, according to the Haversine function(Complexity: O(n))
     * @param lat Latitude of location
     * @param lon Longitude of location
     * @return Code of the airport nearest to the given coordinates
     */
    string nearestAirport(float lat, float lon);
    /**
     * Creates a vector with the airports you can by taking at most n flights from the given Airport (Complexity: O(n))
     * @param airport string refering to specific Airport Code
     * @param n maximum number(int) of flights
     * @return vector with the airports you can by taking n flights from the given Airport
     */
    vector<Airport> getDestinationByNumFlights(string airport, int n);
};


#endif //PROJ2_AIRMANAGER_H
