#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <ctime>
#include <fstream>
#include "Person.h"
#include "Customer.h"
using namespace std;

class Driver:public Person
{
public:
    int driverID = rand() % 100 + 2020415;
    int numberOfSeats = 0;
    int availableSeats = 0;
    int occupiedSeats = 0;
    string licenceNumber;
    

    //parameterized constructor
    Driver(int numberOfSeats, int availableSeats, int occupiedSeats,string licenceID) {
        this->numberOfSeats = numberOfSeats;
        this->availableSeats = availableSeats;
        this->occupiedSeats = occupiedSeats;
        this->licenceNumber = licenceID;
    }

    Driver() {
    
    }
    //copy constructor
    Driver(Driver& object) {
        driverID = object.driverID;
        licenceNumber = object.licenceNumber;
        firstName = object.firstName;
        lastName = object.lastName;
        userName = object.userName;
        password = object.password;
        numberOfSeats = object.numberOfSeats;
        availableSeats = object.availableSeats;
        occupiedSeats = object.occupiedSeats;
    }

    //method for printing the copy constructor
    void print() {
        this->Person::show();
        cout << "   Driver ID:  " << driverID << "\n";
        cout << "   Licence number: " << licenceNumber << "\n";
        cout << "   Number of seats: " << numberOfSeats << "\n";
        cout << "   Available seats: " << availableSeats << "\n";
        cout << "   Occupied seats: " << occupiedSeats << "\n";
        cout << "---------------------------------------" << endl;
    }
};

