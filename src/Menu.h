//
// Created by hp on 26/12/2022.
//

#ifndef PROJ2_MENU_H
#define PROJ2_MENU_H

#include <iostream>

using namespace std;
#include "AirManager.h"


class Menu {
    AirManager manager= AirManager();

public:
    /**
     * Default constructor for a Menu object
     */
    Menu();
    /**
    * Prints Instructions to the user
    */
    void show();
    /**
     * Prints The best route available between two places
     * @param manager Reference to a AirManager object that will perform the operation
     * @param departure string representing place of departure
     * @param destination string representing desired destination
     */
    void showBestRoute(AirManager &manager, string departure, string destination);
    /**
     * Prints all the available Information about an Airport
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airport string representing an airports name
     */
    void showAirportInformation(AirManager &manager, string airport);
    /**
     * Prints all the available flight related information about a Country
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airport string representing the nome of a country
     */
    void showCountryInformation(AirManager &manager, string country);
    /**
     * Prints all the available flight related information about an Airline
     * @param manager Reference to a AirManager object that will perform the operation
     * @param airline string representing the nome of an airline
     */
    void showAirlineInformation(AirManager &manager, string airline);
};


#endif //PROJ2_MENU_H
