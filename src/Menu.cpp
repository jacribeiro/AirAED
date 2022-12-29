//
// Created by hp on 26/12/2022.
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
}
void Menu::show() {
    cout << "=================================\n";
    cout << "Welcome to your Air Manager!\n";
    cout << "=================================\n\n";
    string name;
    cout << "Insert your name: \t";
    cin >> name;
    bool flag = true;
    cout << "\n\n*Warning*: Invalid inputs may cause the Air Manager to shut down!\n\n";
    while (flag) {
        cout << "\nHello, " << name << "!\nWhat would do you like to do today?\n";
        cout << "1. Check the Best Flight Available.\n";
        cout << "2. Check Airport Information.\n";
        cout << "3. Check Country Information.\n";
        cout << "4. Check Airline Information.\n";
        cout << "5. Quit.\n";
        int n1;
        cin >> n1;
        string name1;
        string name2;
        switch (n1) {
            case 1: {
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "-> Your Place of Departure" << "\n";
                cout << "(Choose the type of data you would like to insert)" << "\n";
                cout << "a) Airport Name\n";
                cout << "b) Country Name\n";
                cout << "c) Specific Coordinates (latitude and longitude)\n";
                char l1;
                cin >> l1;
                switch (l1) {
                    case ('a'): {
                        cout << "***Insert Airport Name***\n";
                        cin >> name1;
                    }
                    case ('b'): {
                        cout << "***Insert City Name***\n";
                        cin >> name1;
                    }
                    case ('c'): {
                        cout << "***Insert the specific Coordinates***\n";
                        cin >> name1;
                    }
                }

                cout << "-> Your Desired Destination" << "\n";
                cout << "(Choose the type of data you would like to insert)" << "\n";
                cout << "a) Airport Name\n";
                cout << "b) City Name\n";
                cout << "c) Specific Coordinates (latitude and longitude)\n";
                char l2;
                cin >> l2;
                switch (l2) {
                    case ('a'): {
                        cout << "***Insert Airport Name***\n";
                        cin >> name2;
                    }
                    case ('b'): {
                        cout << "***Insert City Name***\n";
                        cin >> name2;
                    }
                    case ('c'): {
                        cout << "***Insert the specific Coordinates***\n";
                        cin >> name2;
                    }
                }
                showBestRoute(manager, name1, name2);
            }
            case 2:{
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert Airport Name***\n";
                cin >> name1;
                showAirportInformation(manager, name1);
            }
            case 3:{
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert the name of the Country***\n";
                cin >> name1;

                showCountryInformation(manager, name1);
            }
            case 4:{
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert the name of the Country***\n";
                cin >> name1;

                showAirlineInformation(manager, name1);
            }
            case 5: {
                flag = false;
                cout << "***You have successfully exited your Air Manager!***";
                break;
            }
        }
    }
}

void Menu::showAirportInformation(AirManager &manager, string airport) {

}
void Menu::showBestRoute(AirManager &manager, std::string departure, std::string destination) {

}

void Menu::showCountryInformation(AirManager &manager, string country) {

}

void Menu::showAirlineInformation(AirManager &manager, string airline) {

}

