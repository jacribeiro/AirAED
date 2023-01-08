//
// Created by Joao Ribeiro on 17/12/2022.
//

#ifndef PROJ2_AIRPORT_H
#define PROJ2_AIRPORT_H

#include "Flight.h"
#include <string>
#include <vector>

using namespace std;

/**
 * Represents an Airport
 */
class Airport {

    string code;
    string name;
    string city;
    string country;
    float latitude;
    float longitude;

    vector<Flight> flights;
    bool visited = false;
    int distance = 0;
    string previous;

public:
    /**
     * Creates a new Airport object
     * @param code The unique IATA code for the airport
     * @param name The official name of the airport
     * @param city The city where the airport is located
     * @param country The country where the airport is located
     * @param latitude The latitude coordinate for the airport
     * @param longitude The longitude coordinate for the airport
     */
    Airport(string c, string n, string ct, string cy, float lat, float lon);

    /**
     * Returns the IATA code for the airport
     * @return the IATA code for the airport
     */
    string getCode() const;

    /**
     * Returns the official name of the airport
     * @return the official name of the airport
     */
    string getName() const;

    /**
     * Returns the city where the airport is located
     * @return the city where the airport is located
     */
    string getCity() const;

    /**
     * Returns the country where the airport is located
     * @return the country where the airport is located
     */
    string getCountry() const;

    /**
     * Returns the latitude coordinate for the airport
     * @return the latitude coordinate for the airport
     */
    float getLatitude() const;

    /**
     * Returns the longitude coordinate for the airport
     * @return the longitude coordinate for the airport
     */
    float getLongitude() const;

    /**
     * Marks the Airport as visited
     */
    void visit();

    /**
     * Marks the airport as unvisited
     */
    void unvisit();

    /**
     * Returns the visited status of the airport
     * @return
     */
    bool getVisited();

    /**
     * Returns the vector of Flights that depart from this Airport
     * @return Vector of Flights that depart from this Airport
     */
    vector<Flight> getFlights();

    /**
     * Returns the distance this airport is after the most recent BFS
     * @return Distance this airport is after the most recent BFS
     */
    int getDistance();

    /**
     * Sets the distance of the airport
     * @param d The new distance to be set to the airport
     */
    void setDistance(int d);

    /**
     * Returns the code of the 'previous' airport, during a BFS
     * @return Code of the 'previous' airport, during a BFS
     */
    string getPrevious();

    /**
     * Sets the 'previous' airport
     * @param parent Airport code of the 'previous' airport
     */
    void setPrevious(string previous);

    /**
     * Adds a Flight to the Airport
     * @param flight A Flight object originating from this airport
     */
    void addFlight(const Flight& flight);

    /**
     * Equality comparator for Airport objects
     * @param a2 The Airport object to compare to
     * @return True if Airport objects are equal, false otherwise
     */
    bool operator == (const Airport& a2) const;
};


#endif //PROJ2_AIRPORT_H
