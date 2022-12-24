/*
 * SheepFarm.h
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#ifndef SHEEPFARM_H_
#define SHEEPFARM_H_

#include "Farm.h"
#include "Sheep.h"

class SheepFarm: public Farm {
public:
	SheepFarm(){BuyAnimals(3); Money = 10;}
	virtual void BuyAnimals(int amount);
	void printRecipet(int ID, int amount, int cost, int sellerID)const;
	int const WhatProductsYouSell(){return whatIsell;}
	virtual const int WhatProductsIBuy(){return whatIBuy;};

	void printFarm();
	bool BeMyClient(Farm &client);
	const int getProductCost(){ return productCost;}
private:
	static int const whatIsell;
	static int const whatIBuy;
	static int const productCost;
};


#endif /* SHEEPFARM_H_ */
