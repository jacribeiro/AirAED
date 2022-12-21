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
    unordered_map<string, Airline> readAirlinesFile();
    unordered_map<string, Airport> readAirportFile();
    readFlightsFile();

};


#endif //PROJ2_FILEREADER_H
