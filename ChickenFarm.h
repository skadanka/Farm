/*
 * ChickenFarm.h
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#ifndef CHICKENFARM_H_
#define CHICKENFARM_H_

#include "Farm.h"
#include "Chicken.h"

class ChickenFarm: public Farm {
public:
	ChickenFarm();
	~ChickenFarm(){};
	void BuyAnimals(int amount);
	int const WhatProductsYouSell(){return whatIsell;}
	void printRecipet
			(int ID, int amount, int cost, int sellerID)const;
	void printFarm();
	bool BeMyClient(Farm &client);
	const int getProductCost(){ return productCost;}
	virtual const int WhatProductsIBuy(){return whatIBuy;}

private:
	static const int whatIsell;
	static const int whatIBuy;
	static const int productCost;
};


#endif /* CHICKENFARM_H_ */
