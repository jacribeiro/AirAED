#include <iostream>
#include "src/FileReader.h"

int main() {
    FileReader reader = FileReader();
    unordered_map<string, Airport> airports = reader.readAirportFile("CSV/airports.csv");

}
