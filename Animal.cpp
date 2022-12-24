/*
 * Animal.cpp
 *
 *  Created on: Dec 29, 2021
 *      Author: ise
 */

#include "Animal.h"

int Animal::FarmProductCost(){
	return milkCost()+woolCost()+eggCost();
}
