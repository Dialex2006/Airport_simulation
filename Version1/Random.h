//
//  Random.hpp
//  Testing
//
//  Created by Dmitrii Bacherikov on 10.11.2021.
//

#ifndef Random_h
#define Random_h

#include <stdio.h>
#include<limits.h>
#include<time.h>
#include <cmath>


class Random {
public:
   Random(bool pseudo = true);
    double random_real();
    int random_integer(int low, int high);
    int poisson(double mean);
//    Declare random-number generation methods here.
 private:
   int reseed(); //  Re-randomize the seed.
   int seed,
       multiplier, add_on; //  constants for use in arithmetic operations
};




#endif /* Random_hpp */
