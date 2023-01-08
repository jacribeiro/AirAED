#include <iostream>
#include "src/Menu.h"

int main() {
    AirManager manager = AirManager(FileReader());
    Menu m = Menu(manager);
    m.show();
}
