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
//#include "extended_queue.cpp"
using namespace std;


enum Plane_status {null, arriving, departing};

class Plane {
public:
   Plane();
   Plane(int flt, int time, Plane_status status);
   void refuse() const;
   void land(int time) const;
   void fly(int time) const;
   int started() const;

private:
   int flt_num;
   int clock_start;
   Plane_status state;
};



#endif /* Plane_hpp */
