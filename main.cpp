#include <iostream>
#include "src/FileReader.h"

int main() {
    FileReader reader = FileReader();
    unordered_map<string, Airline> airlines = reader.readAirlinesFile("CSV/airlines.csv");

}
