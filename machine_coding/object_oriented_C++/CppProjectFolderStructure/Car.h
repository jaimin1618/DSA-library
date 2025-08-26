#ifndef CAR_H
#define CAR_H

#include <string>   // Needed for std::string
using std::string; // Optional: or use std::string everywhere

class Car {
    string name;
public:
    void setName(string n);
    string getName();
};

#endif
