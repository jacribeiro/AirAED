//
// Created by hp on 26/12/2022.
//

#ifndef PROJ2_MENU_H
#define PROJ2_MENU_H

#include <iostream>

using namespace std;
#include "AirManager.h"


class Menu {
    AirManager manager;

public:
    /**
     * Creates a new Menu object
     * @param m AirManager object to be used by the Menu
     */
    Menu(AirManager m);

    /**
    * Prints Instructions to the user
    */
    void show();

    /**
     * Prints The best route available between two places (Complexity: O(|V| + |E|))
     * @param manager Reference to a AirManager object that will perform the operation
     * @param ori string representing place of departure
     * @param dest string representing desired destination
     * @param option pair of integers indicating type of place in ori and dest (1 = airport code, 2 = city, 3 = coordinates)
     */
    void showBestRoute(AirManager &manager, string ori, string dest, pair<int, int> option);

    /**
     * Prints all the available Information about an Airport (Complexity: O(n))
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airport string representing an airports name
     */
    void showAirportInformation(AirManager &manager, string airport);

    /**
     * Prints the Airport information about a Country (Complexity: O(n))
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airport string representing the nome of a country
     */
    void showCountryAirports(AirManager &manager, string country);
    /**
     * Prints the Airline information about a Country (Complexity: O(n))
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airport string representing the nome of a country
     */

    void showCountryAirlines(AirManager &manager, string country);
    /**
     * Prints all the available flight related information about an Airline (Complexity: O(n))
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airline string representing the nome of an airline
     */
    void showAirlineInformation(AirManager &manager, string airline);
    /**
     * Prints all the available flight related statistics about an Airport (Complexity: O(n))
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airport string representing the nome of an airport
     */
    void showAirportStatistics(AirManager &manager, string airport);
/**
     * Prints all the available flight related statistics about a Country (Complexity: O(n1*n2))
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airport string representing the nome of a country
     */
    void showCountryStatistics(AirManager manager, string country);

    /**
     * Prints all the available flight related statistics about an Airline (Complexity: O(n1*n2))
     * @param manager reference to a AirManager object that will perform the operation
     * @param airline string representing the code of an airline
     */
    void showAirlineStatistics(AirManager &manager, string airline);
    /**
     * Prints all the available flight related statistics about an Airline (Complexity: O(n1*n2))
     * @param manager reference to a AirManager object that will perform the operation
     * @param airline string representing the code of an airline
     */
    void showGlobalStatistics(AirManager manager);

    /**
     * Prints the Cities/Countries that you can reach by taking a maximum of n flights from Given Airport (Complexity: O(n))
     * @param manager reference to a AirManager object that will perform the operation
     * @param airport string representing the code of an airport
     * @param n maximum number(int) of flights needed
     */
    void showDestinationByNumFlights(AirManager manager, string airport, int n);
};


#endif //PROJ2_MENU_H
