#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <ctime>
#include <fstream>
#include "Person.h"
using namespace std;

class Customer :public Person //INHERITANCE
{
private:
    int days;
public:
    int customerID = rand() % 100 + 2020563;
    string destination;
    string location;
    double price =0;
    int numberOfDays = 0;

    Person p;

    //parameterized constructor
    Customer(string destination, string location, double price, int numberOfDays) {
        this->destination = destination;
        this->location = location;
        this->price = price;
        this->numberOfDays = numberOfDays;
    }

    //Copy constructor
    Customer(Customer& object) {
        customerID = object.customerID;
        firstName = object.firstName;
        lastName = object.lastName;
        userName = object.userName;
        password = object.password;
        destination = object.destination;
        location = object.location;
        price = object.price;
        numberOfDays = object.numberOfDays;
    }

    //print function
    void print() {
        this->Person::show();
        cout << "   Customer ID: " << customerID << "\n";
        cout << "   Destination: " << destination << "\n";
        cout << "   Location: " << location << "\n";
        cout << "   Price: N$" << price << "\n";
        cout << "   Number of days: " << numberOfDays << "\n";
        cout << "-----------------------------------------\n" << endl;
    }

    //monthly price calculation function and pointers
    double calculateMonthlyPrice(int* days, double* amount)
    {
        days = &numberOfDays;
        amount = &price;


        double totalPrice = (*days) * (*amount);
        //File input and output
        ofstream filestream("Customer.txt");
        if (filestream)
        {
            filestream << "\n-------------------------------------\n";
            filestream << "|          Grab a Taxi              | \n ";
            filestream << "------------------------------------\n";
            filestream << "    Customer ID   :" << customerID << "\n";
            filestream << "    First name    : " << firstName << "\n";
            filestream << "    Last name     : " << lastName << "\n";
            filestream << "    Username      : " << userName << "\n";
            filestream << "    Number of days:" << numberOfDays << "\n";
            filestream << "    Taxi fair     : N$" << price << "\n";
            filestream << "    Total price   : N$" << totalPrice << "\n";
            filestream << "     ", p.currentTime();
            filestream.close();
        }
        else
        {
            cout << "Failed to write to the specified file" << endl;
        }
        return totalPrice;
    }

    //Reading from a file (file output)
    void printReciept() 
    {
        string result;
        ifstream filestream("Customer.txt");

        if (filestream.is_open())
        {
            while (getline(filestream, result))
            {
                cout << result << endl;
            }
            filestream.close();
        }
        else
        {
            cout << "Failed to open the specified file" << endl ;
        }
    }

    //Operator overloading
    Customer() :days(0) {}
    void operator ++() {
        days = numberOfDays;
    }

    void printDays() {
        cout << "You have used this taxi for: " << days << " days" << endl;
    }
};

