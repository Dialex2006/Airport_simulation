//
//  Plane.cpp
//  Testing
//
//  Created by Dmitrii Bacherikov on 10.11.2021.
//

#include "Plane.h"


Plane::Plane(int flt, int time, Plane_status status)
/*
Post:  The Plane data members flt_num, clock_start,
       and state are set to the values of the parameters flt,
       time and status, respectively.
*/

{
   flt_num = flt;
   clock_start = time;
    state = status;
    fuel = 30;
   cout << "Plane number " << flt << " ready to ";
   if (state == arriving)
      cout << "land." << endl;
   else
      cout << "take off." << endl;
}



Plane::Plane(int flt, int time, Plane_status status, int fuel_amount = 30)
/*
Post:  The Plane data members flt_num, clock_start,
       and state are set to the values of the parameters flt,
       time and status, respectively.
*/

{
   flt_num = flt;
   clock_start = time;
   state = status;
   fuel = fuel_amount;
    
   if (state == arriving && fuel < 1)
        state = arriving_out_of_fuel;
    
   cout << "Plane number " << flt << " ready to ";
   if (state == arriving)
      cout << "land." << endl;
   else if (state == arriving_out_of_fuel)
       cout << "land URGENTLY because it is out of fuel!" << endl;
   else
      cout << "take off." << endl;
}






Plane::Plane()
/*
Post:  The Plane data members flt_num, clock_start,
       state are set to illegal default values.
*/
{
   flt_num = -1;
   clock_start = -1;
   state = null;
}


int Plane::fuel_amount() const
{
    return fuel;
}


Plane_status Plane::getState() const
{
    return state;
}




void Plane::refuse() const
/*
Post: Processes a Plane wanting to use Runway, when
      the Queue is full.
*/

{
   cout << "Plane number " << flt_num;
   if (state == arriving)
      cout << " directed to another airport" << endl;
   else
      cout << " told to try to takeoff again later" << endl;
}


int Plane::planes_crashed = 0;
void Plane::land(int time) const
/*
Post: Processes a Plane that is landing at the specified time.
*/

{
   int wait = time - clock_start;

    //we need to check if waiting time is more than fuel level when a plane arrived
    if (wait > fuel)
    {
        planes_crashed++;
        cout << time << ": Plane number " << flt_num << " crashed after "
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << " in the landing queue." << endl;
    }
    else
        cout << time << ": Plane number " << flt_num << " landed after "
            << wait << " time unit" << ((wait == 1) ? "" : "s")
            << " in the landing queue." << endl;
}


void Plane::fly(int time) const
/*
Post: Process a Plane that is taking off at the specified time.
*/

{
   int wait = time - clock_start;
   cout << time << ": Plane number " << flt_num << " took off after "
        << wait << " time unit" << ((wait == 1) ? "" : "s")
        << " in the takeoff queue." << endl;
}


int Plane::started() const
/*
Post: Return the time that the Plane entered the airport system.
*/
{
   return clock_start;
}
