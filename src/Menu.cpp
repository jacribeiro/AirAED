//
// Created by hp on 26/12/2022.
//

#include "Menu.h"
#include <iostream>
#include <iomanip>

using namespace std;

Menu::Menu(AirManager m): manager(m) {};

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
        cout << "\nHello, " << name << "!\nWhat would do you like to do today? (eg.: 4)\n";
        cout << "1. Check the Best Route Available.\n";
        cout << "2. Check Airport's Flight Information.\n";
        cout << "3. Check Airports Destinations by Number of Flights\n";
        cout << "4. Check Airport Statistics.\n";
        cout << "5. Check Countries Flight Information.\n";
        cout << "6. Check Country Statistics.\n";
        cout << "7. Check Airline Flight Information.\n";
        cout << "8. Check Airline Statistics.\n";
        cout << "9. Check Global Statistics.\n";
        cout << "10. Quit.\n";
        int n1;
        cin >> n1;
        string name1;
        string name2;
        int opt1 = 0, opt2 = 0;
        switch (n1) {
            case 1: {
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "-> Your Place of Departure" << "\n";
                cout << "(Choose the type of data you would like to insert) (ex.: a)" << "\n";
                cout << "a) Airport Code\n";
                cout << "b) City Name\n";
                cout << "c) Specific Coordinates (latitude and longitude)\n";
                char l1;
                cin >> l1;
                switch (l1) {
                    case ('a'): {
                        cout << "***Insert Airport Code (eg.: LIS)***\n";
                        cin >> name1;
                        opt1 = 1;
                        break;
                    }
                    case ('b'): {
                        cout << "***Insert City Name (eg.: Tokyo)***\n";
                        cin >> name1;
                        opt1 = 2;
                        break;
                    }
                    case ('c'): {
                        cout << "***Insert the specific Coordinates, separated by a comma (eg.: 47.833,02.902)***\n";
                        cin >> name1;
                        opt1 = 3;
                        break;
                    }
                }

                cout << "-> Your Desired Destination" << "\n";
                cout << "(Choose the type of data you would like to insert)(eg.: a )" << "\n";
                cout << "a) Airport Code\n";
                cout << "b) City Name\n";
                cout << "c) Specific Coordinates (latitude and longitude)\n";
                char l2;
                cin >> l2;
                switch (l2) {
                    case ('a'): {
                        cout << "***Insert Airport Code (eg.: JFK)***\n";
                        cin >> name2;
                        opt2 = 1;
                        break;
                    }
                    case ('b'): {
                        cout << "***Insert City Name (eg.: Paris)***\n";
                        cin >> name2;
                        opt2 = 2;
                        break;
                    }
                    case ('c'): {
                        cout << "***Insert the specific Coordinates, separated by a comma (eg.: 47.833,02.902)***\n";
                        cin >> name2;
                        opt2 = 3;
                        break;
                    }
                }
                showBestRoute(manager, name1, name2, {opt1, opt2});
                break;
            }
            case 2: {
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert Airport Code (eg.: JFK)***\n";
                cin >> name1;
                showAirportInformation(manager, name1);
                break;
            }
            case 3: {
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert Airport Code (eg.: JFK)***\n";
                cin >> name1;
                cout << "***Insert Number of Flights (eg.: 2)***\n";
                int n;
                cin >> n;
                showDestinationByNumFlights(manager, name1, n);
                break;
            }

            case 4: {
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert Airport Code (eg.: JFK)***\n";
                cin >> name1;
                showAirportStatistics(manager, name1);
                break;
            }
            case 5: {
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert the name of the Country (eg.: France)***\n";
                cin >> name1;
                cout << "***Choose the type of Information you're seeking (eg.: a)***\n";
                cout << "a) List of National Airports\n";
                cout << "b) List of the National Airlines\n";
                char l3;
                cin >> l3;
                switch (l3) {
                    case ('a'): {
                        showCountryAirports(manager, name1);
                        break;
                    }
                    case ('b'): {
                        showCountryAirlines(manager, name1);
                        break;
                    }
                }
                break;
            }
            case 6:{
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert the name of the Country (eg.: France)***\n";
                cin >> name1;
                showCountryStatistics(manager, name1);
                break;
            }
            case 7: {
                    cout << "***We will need you to provide the Following Information:***\n\n";
                    cout << "***Insert the code of the Airline (eg.: TAP)***\n";
                    cin >> name1;
                    showAirlineInformation(manager, name1);
                    break;
            }
            case 8: {
                cout << "***We will need you to provide the Following Information:***\n\n";
                cout << "***Insert the code of the Airline (eg.: TAP)***\n";
                cin >> name1;
                showAirlineStatistics(manager, name1);
                break;
            }
            case 9: {
                showGlobalStatistics(manager);
                break;
            }
            case 10: {
                    flag = false;
                    cout << "***You have successfully exited your Air Manager!***";
            }
        }
            cout << "\n\n***Would you like continue using the Schedule Manager?***" << '\n';
            cout << "->If you do insert y, if not insert n: ";
            char s; cin >> s;
            if (s == 'n' || s == 'N') {
                flag = false;
                break;
            }
        }
        cout << "\n***You have successfully exited your Schedule Manager!***";
    }
void Menu::showAirportInformation(AirManager &manager, string airport) {
    Airport v1 = manager.getAirportInformation(airport);
    vector<Flight> v2 = manager.getAirportDestinations(airport);
    cout <<"From the "<<v1.getName()<< " Airport ("<<v1.getCountry()<<") "<< "you can fly from "<<v1.getCity()<<" directly to these DESTINATIONS:\n";
    cout<<"===============================================================================\n";
    cout << left << setw(42) << "City (Country)" << left << setw(42) << "Airline"<<endl;
    cout<<"===============================================================================\n";
    for (auto x : v2){
        Airport a1 = manager.getAirportInformation(x.getDestination());
        Airline a2 = manager.getAirlineInformation(x.getAirline());
        cout << left << setw(42) << a1.getCity() + " ("+a1.getCountry()+")"
             << left << setw(42) << a2.getName()
             << endl;
    }
    cout<<"===============================================================================\n";

}
void Menu::showDestinationByNumFlights(AirManager manager, string airport, int n) {
    Airport v1 = manager.getAirportInformation(airport);
    cout <<"From the "<<v1.getName()<< " Airport ("<<v1.getCountry()<<") "<< "you can fly from "<<v1.getCity()<<" directly to these DESTINATIONS:\n";
    cout<<"===============================================================================\n";
    cout << left << setw(22) << "Country" << left << setw(22) << "City"<<endl;
    cout<<"===============================================================================\n";
    vector<Airport> v2 = manager.getDestinationByNumFlights(airport, n);
    for (auto x : v2){
        cout << left << setw(22) << x.getCountry()
             << left << setw(22) << x.getCity()
             << endl;
    }
    cout<<"===============================================================================\n";
}

void Menu::showBestRoute(AirManager &manager, string ori, string dest, pair<int, int> option) {
    vector<string> v = manager.bestRouteDistribution(ori, dest, option);
    cout << "==========================================================================\n";
    switch(option.first){
        case 1: {
            switch (option.second) {
                case 1: {
                    cout << "The best way to get from the " << ori << " airport to the " << dest << " airport is:\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;
                }
                case 2: {
                    cout << "The best way to get from the " << ori << " airport to the city of " << dest << " is:\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;
                }
                case 3: {
                    cout << "The best way to get from the " << ori << " airport to [" << dest << "] is:\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;
                }
            }
            break;
        }

        case 2: {
            switch(option.second) {
                case 1: {
                    cout << "The best way to get from the city of " << ori << " to the " << dest << " airport is:\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;
                }
                case 2: {
                    cout << "The best way to get from the city of " << ori << " to the city of " << dest << " is;\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;

                }
                case 3: {
                    cout << "The best way to get from the city of " << ori << " to [" << dest << "] is:\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;
                }
            }
            break;
        }

        case 3: {
            switch(option.second) {
                case 1: {
                    cout << "The best way to get from [" << ori << "] to the " << dest << " airport is:\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;
                }
                case 2: {
                    cout << "The best way to get from [" << ori << "] to the city of " << dest << " is:\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;
                }
                case 3: {
                    cout << "The best way to get from [" << ori << "] to [" << dest << "] is:\n";
                    for(auto s : v){
                        cout << ">" << s << " airport\n";
                    }
                    cout << "==========================================================================\n";
                    break;
                }
            }
            break;
        }
    }
}

void Menu::showCountryAirlines(AirManager &manager, string country){
        cout << "==========================================================================\n";
        vector<Airline> v1 = manager.getCountryAirline(country);
        cout << "The Airline(s) operating from " << country << ":\n";
        cout << "==========================================================================\n";
        for (auto a: v1) {
            cout << "---> " << a.getName() << " (" << a.getNickname() << ")" << '\n';
        }
        cout << "==========================================================================\n";
}

void Menu::showCountryAirports(AirManager &manager, string country){
        cout<<"==========================================================================\n";
        vector<Airport> v2 = manager.getCountryAirport(country);
        cout << "The Airports operating in " << country << ":\n";
        cout<<"==========================================================================\n";

        cout << left << setw(14) << "Airport Code" << left << setw(22) << "City" << left
             << setw(22)<< "Airport"<<'\n';
        cout<<"==========================================================================\n";
        for (int i = 0; i < v2.size(); i++)
        {
            cout << left << setw(14) << v2[i].getCode()
                 << left << setw(22) << v2[i].getCity()
                 << left << setw(22) << v2[i].getName()
                 << endl;
        }
        cout<<"==========================================================================\n";
}

void Menu::showAirportStatistics(AirManager &manager, string airport) {
    Airport a = manager.getAirportInformation(airport);
    int n_airlines = manager.getNumAirlinesByAirport(airport);
    int n_destinations = manager.getNumDestinationsByAirport(airport);
    int n_flights = manager.getNumFlightsByAirport(airport);
    cout<<"==========================================================================\n";
    cout<<"The "<<a.getName()<<" Airport"<<"("<<a.getCode()<<")"<<" Flight-related Statistics:\n";
    cout<<"==========================================================================\n";
    cout<<"Number of Flights ---> "<<n_flights<<endl;
    cout<<"Number of Destinations ---> "<<n_destinations<<endl;
    cout<<"Number of Airlines ---> "<<n_airlines<<endl;
    cout<<"==========================================================================\n";
}

void Menu::showCountryStatistics(AirManager manager, string country) {
    int n_airports = manager.getNumAirportsInCountry(country);
    int n_airlines = manager.getNumAirlinesByCountry(country);
    int n_destinations = manager.getNumDestinationsByCountry(country);
    int n_flights = manager.getNumFlightsByCountry(country);
    cout<<"==========================================================================\n";
    cout<<country<<"'s Flight-related Statistics:\n";
    cout<<"==========================================================================\n";
    cout<<"Number of National Airports ---> "<<n_airports<<endl;
    cout<<"Number of Flights ---> "<<n_flights<<endl;
    cout<<"Number of Destinations ---> "<<n_destinations<<endl;
    cout<<"Number of Airlines ---> "<<n_airlines<<endl;
    cout<<"==========================================================================\n";
}

void Menu::showAirlineInformation(AirManager &manager, std::string airline) {
    Airline a = manager.getAirlineInformation(airline);
    cout <<"Flying with "<<a.getName()<< " based in "<<a.getCountry()<<" you can fly to these DESTINATIONS:\n";
    cout<<"===============================================================================\n";
    cout << left << setw(42) << "City (Country)" << left<< setw(42) << "Airport"<<endl;
    cout<<"===============================================================================\n";
    vector<Airport> v = manager.getAirlineDestinations(airline);
    for (auto x : v){
        cout << left << setw(42) << x.getCity() + " ("+x.getCountry()+")"
             << left << setw(42) << x.getName() + " Airport"
             << endl;
    }
    cout<<"===============================================================================\n";
}

void Menu::showAirlineStatistics(AirManager &manager, std::string airline) {
    Airline a = manager.getAirlineInformation(airline);
    int n_airports = manager.getAirlineDestinations(airline).size();
    int n_countries = manager.getNumCountriesByAirline(airline);
    int n_flights = manager.getNumFlightsByAirline(airline);
    cout<<"==========================================================================\n";
    cout<<a.getName()<<"'s Flight-related Statistics:\n";
    cout<<"==========================================================================\n";
    cout<<"Number of Flights ---> "<<n_flights<<endl;
    cout<<"Number of Airports ---> "<<n_airports<<endl;
    cout<<"Number of Countries ---> "<<n_countries<<endl;
    cout<<"==========================================================================\n";
}

void Menu::showGlobalStatistics(AirManager manager) {
    int n_airports = manager.getAirports().size();
    int n_airlines = manager.getAirlines().size();
    //int n_countries = manager.getGlobalNumCountries();
    int n_flights = manager.getGlobalNumFlights();

    cout<<"==========================================================================\n";
    cout<<"This Network's Global Flight-related Statistics:\n";
    cout<<"==========================================================================\n";
    cout<<"Number of Flights ---> "<<n_flights<<endl;
    cout<<"Number of Airports ---> "<<n_airports<<endl;
    cout<<"Number of Airlines---> "<<n_airlines<<endl;
    cout<<"==========================================================================\n";

}








