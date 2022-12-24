/*
 * CowsFarm.h
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#ifndef COWSFARM_H_
#define COWSFARM_H_

#include "Farm.h"
#include "Cow.h"

class CowsFarm: public Farm {
public:
	CowsFarm(){BuyAnimals(3);Money = 10;}
	~CowsFarm(){};
	void BuyAnimals(int amount);
	int const WhatProductsYouSell(){return whatIsell;}
	virtual const int WhatProductsIBuy(){return whatIBuy;};
	void printRecipet
			(int ID, int amount, int cost, int sellerID)const;
	void printFarm();
	bool BeMyClient(Farm &client);
	const int getProductCost(){ return productCost;}

private:
	static int const whatIsell;
	static int const whatIBuy;
	static const int productCost;
};

#endif /* COWSFARM_H_ */

