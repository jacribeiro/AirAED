#include <iostream>
#include "src/Menu.h"

int main() {
    AirManager manager = AirManager(FileReader());
    vector<string> route = manager.bestRouteAirports("GKA", "NAN");
    int i = 0;
    for (; i < route.size() - 1; i++) {
        cout << route[i] << " -> ";
    }
    cout << route[i] << endl;
}
