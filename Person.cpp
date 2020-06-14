#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <ctime>
#include <fstream>
#include "Person.h"
using namespace std;

class Person
{
public:
    string firstName;
    string lastName;
    string userName;
    string password;

    //default constructor
    Person() {

    }

    //parameterized constructor
    Person(string fname, string lname, string usrname, string pwd) {
        this->firstName = fname;
        this->lastName = lname;
        this->userName = usrname;
        this->password = pwd;
    }

    //Destructor
    ~Person() {

    }

    //Copy constructor
    Person(Person& object) {
        firstName = object.firstName;
        lastName = object.lastName;
        userName = object.userName;
        password = object.password;
    }

    //virtual function
    virtual void show() {
        cout << "-----------------------------------------\n";
        cout << "   First name: " << firstName << "\n";
        cout << "   Last name: " << lastName << "\n";
        cout << "   User name: " << userName << "\n";
        cout << "   Password: " << password << "\n";
    }

    //Method for displaying the current time
    void currentTime() {
        struct tm newtime;
        time_t now = time(0);
        localtime_s(&newtime, &now);

        int month = 1 + newtime.tm_mon;
        int date = newtime.tm_mday;
        int year = newtime.tm_year + 1900;
        int hour = newtime.tm_hour;
        int min = newtime.tm_min;
        int sec = newtime.tm_sec;

        if (date < 10 && month < 10) {
            cout << "   Date: 0" << date << "/0" << month << "/" << year << " Time: " << hour << ":" << min << ":" << sec<<" ";
        }
        else if (month < 10) {
            cout << "   Date: " << date << "/0" << month << "/" << year << " Time: " << hour << ":" << min << ":" << sec << " ";
        }
        else
        {
            cout <<"   Date: "<< date << "/" << month << "/" << year << " Time: " << hour << ":" << min << ":" << sec<<" ";
        }
    }
};

