//
//  PlaneQueue.hpp
//  Testing
//
//  Created by Dmitrii Bacherikov on 11.11.2021.
//

#ifndef Queue_h
#define Queue_h

#include "Plane.h"
#include <stdio.h>
#include "Utility.h"
#include <iostream>


typedef Plane Queue_entry;

const int maxqueue = 20; //  small value for testing

class Queue {
public:
   Queue();
   bool empty() const;
   Error_code serve();
   Error_code append(const Queue_entry &item);
   Error_code retrieve(Queue_entry &item) const;

protected:
   int count;
   int front, rear;
   Plane entry[maxqueue];
};





#endif /* Queue_hpp */
