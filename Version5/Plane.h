//
//  Plane.hpp
//  Testing
//
//  Created by Dmitrii Bacherikov on 10.11.2021.
//

#ifndef Plane_h
#define Plane_h

#include <stdio.h>
#include <iostream>
#include "Random.h"
//#include "extended_queue.cpp"
using namespace std;


enum Plane_status {null, arriving, departing, arriving_out_of_fuel};

class Plane {
public:
   Plane();
   Plane(int flt, int time, Plane_status status);
    Plane(int flt, int time, Plane_status status, int fuel_amount);
   void refuse() const;
   void land(int time) const;
   void fly(int time) const;
   int started() const;
    int fuel_amount() const;
    Plane_status getState() const;
    static int planes_crashed;  //adding a static variable for crashed planes
    

private:
   int flt_num;
   int clock_start;
   Plane_status state;
    int fuel;
    bool urgent;
    
};



#endif /* Plane_hpp */
