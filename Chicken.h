/*
 * Chicken.h
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#ifndef CHICKEN_H_
#define CHICKEN_H_

#include "Animal.h"

class Chicken: public Animal {
public:
	const int milkCost(){return 0;};
	const int woolCost(){return 0;}
	const int eggCost(){return 1;};
	Chicken(): Animal(){};
	Chicken(const Chicken &other){_age = other._age;}
	static int const getCost(){return _cost;}
	static int getLeave(){return _leave;}
	bool updateAge(){return ++_age == _leave;}
private:
	static const int _cost = 3;
	static const int _leave = 3;

};

#endif /* CHICKEN_H_ */

