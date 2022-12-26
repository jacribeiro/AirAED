//
// Created by Joao Ribeiro on 21/12/2022.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "FileReader.h"

unordered_map<string, Airline> FileReader::readAirlinesFile(string fname) {
    unordered_map<string, Airline> airlines;
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        // Read the first line and discard
        getline(file, line);
        string code, name, nickname, country;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, code, ',');
            getline(inputString, name, ',');
            getline(inputString, nickname, ',');
            getline(inputString, country, ',');
            Airline a1 = Airline(code, name, nickname, country);
            airlines.insert({code, a1});
        }
    } else {
        cout << "Could not open airlines file" << endl;
    }
    return airlines;
}

unordered_map<string, Airport> FileReader::readAirportFile(string fname) {

}
