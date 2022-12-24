/*
 * Cow.h
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#ifndef COW_H_
#define COW_H_

#include "Animal.h"

class Cow: public Animal {
public:
	Cow(): Animal(){};
	~Cow(){};
	virtual const int milkCost(){return 3;};
	virtual const int woolCost(){return 0;}
	virtual const int eggCost(){return 0;};
	static int const getCost(){return _cost;}
	static int getLeave(){return _leave;}
	bool updateAge(){return ++_age == _leave;}
private:
	static const int _cost = 10;
	static const int _leave = 10;
};

#endif /* COW_H_ */
