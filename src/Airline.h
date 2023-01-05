//
// Created by Joao Ribeiro on 17/12/2022.
//

#ifndef PROJ2_AIRLINE_H
#define PROJ2_AIRLINE_H

#include <string>

using namespace std;


class Airline {
    string code;
    string name;
    string nickname;
    string country;

public:
    /**
     * Creates a new Airline object
     * @param c The unique ICAO code for the airline
     * @param n The official name of the airline
     * @param nn The airline's nickname, in the industry
     * @param cy The airline's country of origin
     */
    Airline(string c, string n, string nn, string cy);

    /**
     * Returns the ICAO code for the airline
     * @return the ICAO code for the airline
     */
    string getCode() const;

    /**
     * Returns the offcial name of the airline
     * @return the official name of the airline
     */
    string getName() const;

    /**
     * Returns the nickname of the airline
     * @return the nickname of the airline
     */
    string getNickname() const;

    /**
     * Returns the airline's country of origin
     * @return the airline's country of origin
     */
    string getCountry() const;

    /**
     * Equality comparator for Airline objects
     * @param a2 The Airline object to compare to
     * @return True if Airline objects are equal, false otherwise
     */
    bool operator == (const Airline& a2) const;
};


#endif //PROJ2_AIRLINE_H
