#include <iostream>
#include "src/Menu.h"

int main() {
    AirManager manager = AirManager();
    Menu m = Menu(manager);
    m.show();
}
