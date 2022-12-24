/*
 * Animal.h
 *
 *  Created on: Dec 29, 2021
 *      Author: ise
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal {
protected:
	int _age;

public:
	/*
	 * int age;
	 * int Cost; [Cow 10$, Sheep 5$, Chicken 3$]
	 * int Leave; [Cow 10, Sheep 5, Chicken 3]
	 */
	virtual bool updateAge()=0;
	int Animalproduction()const{ return _age;}
	virtual const int milkCost()=0;
	virtual const int woolCost()=0;
	virtual const int eggCost()=0;
	int FarmProductCost();
	Animal():_age(0){};
	virtual ~Animal(){};
};

#endif /* ANIMAL_H_ */
