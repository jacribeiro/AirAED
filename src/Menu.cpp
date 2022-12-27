//
// Created by hp on 26/12/2022.
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
}
void Menu::show(){
    cout << "=================================\n";
    cout << "Welcome to your Air Manager!\n";
    cout << "=================================\n\n";
    string name;
    cout << "Insert your name:\t";
    cin >> name;
    bool flag = true;
    cout<<"\n\n*Warning*: Invalid inputs may cause the Ait Manager to shut down!\n\n";

}