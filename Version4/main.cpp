#include <iostream>
#include <sstream>
using namespace std;
#include "Runway.h"
#include "Plane.h"
#include "Utility.h"
#include "Random.h"


void initialize(int &end_time, int &queue_limit,
                double &arrival_rate, double &departure_rate);
int introduction();
int main1();
int main2();
int main3();
int main4();



int main()
/*
Main program which includes 5 versions*/
{
    int variant = introduction();
    switch (variant) {
        case 1 :
            main1();
            break;
        case 2 :
            main2();
            break;
            
        case 3 :
            main3();
            break;
            
        case 4 :
            main4();
            break;
    
        default:
            cout << "Nothing was selected." << endl;
            break;
    }
    
    return 0;

}





int introduction()
{
    int variant;
    cout << "Select the program to run:" << endl;
    cout << "1.    Run P1 version of Airport simulator" << endl
         << "2.    Run P2 version of Airport simulator" << endl
         << "3.    Run P3 version of Airport simulator" << endl
         << "4.    Run P4 version of Airport simulator" << endl
         << "5.    Run P5 version of Airport simulator" << endl
         << "Your choice: "
    << flush;
    cin  >> variant;
    return variant;
}




int main1()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
      run, the expected number of planes arriving, the expected number
      of planes departing per time interval, and the
      maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
      the status of the runway at each time interval, and prints out a
      summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
   int end_time;            //  time to run simulation
   int queue_limit;         //  size of Runway queues
   int flight_number = 0;
   double arrival_rate, departure_rate;
   initialize(end_time, queue_limit, arrival_rate, departure_rate);
   Random variable;
   Runway small_airport(queue_limit);
   for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
      int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
      for (int i = 0; i < number_arrivals; i++) {
         Plane current_plane(flight_number++, current_time, arriving);
         if (small_airport.can_land(current_plane) != success)
            current_plane.refuse();
      }

      int number_departures= variable.poisson(departure_rate); //  current departure requests
      for (int j = 0; j < number_departures; j++) {
         Plane current_plane(flight_number++, current_time, departing);
         if (small_airport.can_depart(current_plane) != success)
            current_plane.refuse();
      }

      Plane moving_plane;
      switch (small_airport.activity(current_time, moving_plane)) {
        //  Let at most one Plane onto the Runway at current_time.
      case land:
         moving_plane.land(current_time);
         break;
      case takeoff:
         moving_plane.fly(current_time);
         break;
      case idle:
         small_airport.run_idle(0, current_time);
      }
   }
   small_airport.shut_down(end_time);
    return 0;
}



//Phase 2
int main2()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
      run, the expected number of planes arriving, the expected number
      of planes departing per time interval, and the
      maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
      the status of the runway at each time interval, and prints out a
      summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
   int end_time;            //  time to run simulation
   int queue_limit;         //  size of Runway queues
   int flight_number = 0;
   double arrival_rate, departure_rate;
   initialize(end_time, queue_limit, arrival_rate, departure_rate);
   Random variable;
   Runway runway_arrivals(queue_limit);
   Runway runway_departures(queue_limit);
   for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
      int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
      for (int i = 0; i < number_arrivals; i++) {
         Plane current_plane(flight_number++, current_time, arriving);
         if (runway_arrivals.can_land(current_plane) != success)
            current_plane.refuse();
      }

      int number_departures= variable.poisson(departure_rate); //  current departure requests
      for (int j = 0; j < number_departures; j++) {
         Plane current_plane(flight_number++, current_time, departing);
         if (runway_departures.can_depart(current_plane) != success)
            current_plane.refuse();
      }

      Plane plane_arrivals;
      switch (runway_arrivals.activity(current_time, plane_arrivals)) {
        //  Let at most one Plane onto the Runway at current_time.
      case land:
         plane_arrivals.land(current_time);
         break;
      case takeoff:
         cout << "IMPOSSIBLE to use this runway for takeoff!!!" << endl;
         break;
      case idle:
         runway_arrivals.run_idle(1, current_time);
      }
       
       Plane plane_departures;
       switch (runway_departures.activity(current_time, plane_departures)) {
         //  Let at most one Plane onto the Runway at current_time.
       case land:
          cout << "IMPOSSIBLE to use this runway for landing!!!" << endl;
          break;
       case takeoff:
          plane_departures.fly(current_time);
          break;
       case idle:
          runway_departures.run_idle(2, current_time);
       }
       
       
   }
    
    runway_arrivals.shut_down(end_time);
    runway_departures.shut_down(end_time);
    
    return 0;
}




//Phase 3
int main3()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
      run, the expected number of planes arriving, the expected number
      of planes departing per time interval, and the
      maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
      the status of the runway at each time interval, and prints out a
      summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
   int end_time;            //  time to run simulation
   int queue_limit;         //  size of Runway queues
   int flight_number = 0;
   double arrival_rate, departure_rate;
   initialize(end_time, queue_limit, arrival_rate, departure_rate);
   Random variable;
   Runway runway_arrivals(queue_limit);
   Runway runway_departures(queue_limit);
   for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
      int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
      for (int i = 0; i < number_arrivals; i++) {
         Plane current_plane(flight_number++, current_time, arriving);
          //if there departure runway queue is EMPTY then land the current plane on it
          if (runway_departures.arr_size() == 0 && runway_departures.dep_size() == 0)
              runway_departures.can_land(current_plane);
          
          //if DEP runway is not empty, then try to land on ARR runway, then on DEP runway
          //so I added 2 extra methods size of queue and queue limit (for correct statistics)
          else if (runway_arrivals.arr_size() < runway_arrivals.q_limit())
              runway_arrivals.can_land(current_plane);
               else if (runway_departures.can_land(current_plane) != success)
                 current_plane.refuse();
          
      }

       
      int number_departures= variable.poisson(departure_rate); //  current departure requests
      for (int j = 0; j < number_departures; j++) {
         Plane current_plane(flight_number++, current_time, departing);
          
          if (runway_arrivals.arr_size() == 0 && runway_arrivals.dep_size() == 0)
              runway_arrivals.can_depart(current_plane);
          
          else if (runway_departures.can_depart(current_plane) != success)
            current_plane.refuse();
      }

       
      Plane plane_arrivals;
      switch (runway_arrivals.activity(current_time, plane_arrivals)) {
        //  Let at most one Plane onto the Runway at current_time.
      case land:
         plane_arrivals.land(current_time);
         break;
      case takeoff:
         plane_arrivals.land(current_time);
         break;
      case idle:
         runway_arrivals.run_idle(1, current_time);
      }
       
       Plane plane_departures;
       switch (runway_departures.activity(current_time, plane_departures)) {
         //  Let at most one Plane onto the Runway at current_time.
       case land:
          plane_departures.land(current_time);
          break;
       case takeoff:
          plane_departures.land(current_time);
          break;
       case idle:
          runway_departures.run_idle(2, current_time);
       }
       
       
   }
    
    runway_arrivals.shut_down(end_time);
    runway_departures.shut_down(end_time);
    
    return 0;
}







//Phase 4
int main4()     //  Airport simulation program
/*
Pre:  The user must supply the number of time intervals the simulation is to
      run, the expected number of planes arriving, the expected number
      of planes departing per time interval, and the
      maximum allowed size for runway queues.
Post: The program performs a random simulation of the airport, showing
      the status of the runway at each time interval, and prints out a
      summary of airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize.
*/

{
   int end_time;            //  time to run simulation
   int queue_limit;         //  size of Runway queues
   int flight_number = 0;
   double arrival_rate, departure_rate;
   initialize(end_time, queue_limit, arrival_rate, departure_rate);
   Random variable;
   Runway runway_arrivals(queue_limit);
   Runway runway_departures(queue_limit);
    Runway runway_extra(queue_limit);
   for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
      int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
      for (int i = 0; i < number_arrivals; i++) {
         Plane current_plane(flight_number++, current_time, arriving);
          //if there departure runway queue is EMPTY then land the current plane on it
          if (runway_arrivals.arr_size() == 0)
              runway_arrivals.can_land(current_plane);
          else if (runway_arrivals.arr_size() == runway_arrivals.q_limit())
            {
                if (runway_extra.can_land(current_plane) != success)
                    current_plane.refuse();
            }
          else if (runway_extra.arr_size() + runway_extra.dep_size() > 0 )
              runway_arrivals.can_land(current_plane);
          else runway_extra.can_land(current_plane);
      }

       
       
       
      int number_departures= variable.poisson(departure_rate); //  current departure requests
      for (int j = 0; j < number_departures; j++) {
         Plane current_plane(flight_number++, current_time, departing);
          
          if (runway_departures.dep_size() == 0)
              runway_departures.can_depart(current_plane);
          
          else if (runway_arrivals.arr_size() < 2 && (runway_extra.arr_size() + runway_extra.dep_size() == 0))
                    runway_extra.can_depart(current_plane);
          else if (runway_departures.can_depart(current_plane) != success)
            current_plane.refuse();
      }

       
      Plane plane_arrivals;
      switch (runway_arrivals.activity(current_time, plane_arrivals)) {
        //  Let at most one Plane onto the Runway at current_time.
      case land:
         cout << "Runway 1: ";
         plane_arrivals.land(current_time);
         break;
      case takeoff:
         cout << "Impossible!!!" << endl;
         break;
      case idle:
         runway_arrivals.run_idle(1, current_time);
      }
       
       
       Plane plane_departures;
       switch (runway_departures.activity(current_time, plane_departures)) {
         //  Let at most one Plane onto the Runway at current_time.
       case land:
          cout << "Impossible!!!" << endl;
          break;
       case takeoff:
          plane_departures.fly(current_time);
          break;
       case idle:
          runway_departures.run_idle(2, current_time);
       }
       
       
       Plane plane_extra;
       switch (runway_extra.activity(current_time, plane_extra)) {
         //  Let at most one Plane onto the Runway at current_time.
       case land:
          plane_extra.land(current_time);
          break;
       case takeoff:
          plane_extra.fly(current_time);
          break;
       case idle:
          runway_extra.run_idle(3, current_time);
       }
       
       
   }
    
    runway_arrivals.shut_down(end_time);
    runway_departures.shut_down(end_time);
    runway_extra.shut_down(end_time);
    
    return 0;
}





void initialize(int &end_time, int &queue_limit,
                double &arrival_rate, double &departure_rate)
/*
Pre:  The user specifies the number of time units in the simulation,
      the maximal queue sizes permitted,
      and the expected arrival and departure rates for the airport.
Post: The program prints instructions and initializes the parameters
      end_time, queue_limit, arrival_rate, and departure_rate to
      the specified values.
Uses: utility function user_says_yes
*/

{
   cout << "This program simulates an airport with only one runway." << endl
        << "One plane can land or depart in each unit of time." << endl;
   cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time? " << flush;
   cin  >> queue_limit;

   cout << "How many units of time will the simulation run? " << flush;
   cin  >> end_time;

   bool acceptable;
   do {
      cout << "Expected number of arrivals per unit time? " << flush;
      cin  >> arrival_rate;
      cout << "Expected number of departures per unit time? " << flush;
      cin  >> departure_rate;
      if (arrival_rate < 0.0 || departure_rate < 0.0)
         cerr << "These rates must be nonnegative." << endl;
      else
         acceptable = true;

      if (acceptable && arrival_rate + departure_rate > 1.0)
         cerr << "Safety Warning: This airport will become saturated. " << endl;

   } while (!acceptable);
}
