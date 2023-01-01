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
    unordered_map<string, Airport> airports;
    string line;
    ifstream file(fname);
    if (file.is_open()) {
        // Read the first line and discard it
        getline(file, line);
        string code, name, city, country, temp;
        float lat, lon;
        while (getline(file, line)) {
            stringstream inputString(line);
            getline(inputString, code, ',');
            getline(inputString, name, ',');
            getline(inputString, city, ',');
            getline(inputString, country, ',');
            getline(inputString, temp, ',');
            lat = stof(temp);
            getline(inputString, temp, ',');
            lon = stof(temp);
            Airport a1 = Airport(code, name, city, country, lat, lon);
            airports.insert({code, a1});
        }
    } else {
        cout << "Could not open airports file" << endl;
    }
    return airports;
}
