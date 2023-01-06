#include <iostream>
#include "src/Menu.h"

int main() {
    Menu menu = Menu(AirManager(FileReader()));
    menu.show();
}
