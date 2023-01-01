//
// Created by Joao Ribeiro on 21/12/2022.
//

#ifndef PROJ2_FILEREADER_H
#define PROJ2_FILEREADER_H


#include <unordered_map>
#include "Airport.h"
#include "Airline.h"

using namespace std;

class FileReader {
public:
    /**
     * Creates a map of the Airports in the system, indexed by their IATA code
     * @param fname The name of the file to be read
     * @return Map of the Airports in the system
     */
    unordered_map<string, Airline> readAirlinesFile(string fname);

    unordered_map<string, Airport> readAirportFile(string fname);
    void readFlightsFile(string fname);

};


#endif //PROJ2_FILEREADER_H
