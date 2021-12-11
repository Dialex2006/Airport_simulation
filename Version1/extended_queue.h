

#ifndef extended_queue_h
#define extended_queue_h

#include "Queue.h"
#include "Utility.h"
#include <iostream>
using namespace std;


class Extended_queue: public Queue {
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry &item);

	void print();
};



#endif
