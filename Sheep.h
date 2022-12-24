/*
 * Sheep.h
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#ifndef SHEEP_H_
#define SHEEP_H_

#include "Animal.h"

class Sheep: public Animal {


public:
	Sheep():Animal(){};
	~Sheep(){};
	virtual const int milkCost(){return 0;};
	virtual const int woolCost(){return 2;}
	virtual const int eggCost(){return 0;};
	static int getCost(){return _cost;}
	static int getLeave(){return _leave;}
	bool updateAge(){return ++_age == _leave;}
private:
	static const int _cost = 5;
	static const int _leave = 5;
};

#endif /* SHEEP_H_ */
