#include <iostream>
#include "src/Menu.h"

int main() {
    AirManager manager = AirManager();
    vector<string> route = manager.bestRoute2("JFK", "Paris");
    int i = 0;
    for (; i < route.size() - 1; i++) {
        cout << route[i] << " -> ";
    }
    cout << route[i] << endl;
}
