//
// Created by Joao Ribeiro on 17/12/2022.
//

#include "Airline.h"

Airline::Airline(string c, string n, string nn, string cy): code(c), name(n), nickname(nn), country(cy) {};

string Airline::getCode() const {
    return this->code;
}

string Airline::getName() const {
    return this->name;
}

string Airline::getNickname() const {
    return this->nickname;
}

string Airline::getCountry() const {
    return this->country;
}

bool Airline::operator==(const Airline &a2) const {
    return this->code == a2.code;
}