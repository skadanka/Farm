/*
 * Farm.h
 *
 *  Created on: Dec 29, 2021
 *      Author: ise
 */

#ifndef FARM_H_
#define FARM_H_
using namespace std;
#include <vector>
#include "Animal.h"
#include <iostream>
#include <map>

class Farm {
private:
	static int numOfFarms;
//	map<int,class Farm*> clients;
protected:
	int ID;
	int Money;
	int products[3]; // Array[milk, wool, eggs] mutal for all
	int sumOfAges;
	vector <Animal*> Animals;
	virtual const int WhatProductsYouSell()=0;
	virtual const int WhatProductsIBuy()=0;

public:

	Farm();
	virtual ~Farm();
	Farm (const Farm &other);
	/* each animal.age = animal production.
	 * IDEA*** static int age for each farm. the production would be the age.
	 * updating the age of all animals mean age=age+amountOfAnimals
	 */
	void updateFarmProducts(){products[WhatProductsYouSell()]+= sumOfAges;}
	/* within given Farm(this) is the buyer we going to our seller
		and ask if the canshopProdcuts is the Products the sellers offers
		if so we go shopping products till
		-Our money is done return true; means we wont go to buy from the next seller in the list
		-The products at seller are done: means we will go to the next farm in the list for shopping
		till money is done.
	*/
	bool goShopProducts(Farm &seller);

	/* we shop for animals based on our farm type
	 * till we can't buy no more
	 * 	shopping Related animals to the Farm
	 * all animals bought age 0; (0 production)
	 * Cow cost 10$
	 * Sheep cost 5$
	 * Chicken cost 3$
	 */
	virtual void BuyAnimals(int amount)=0;
	/*
	 * update the age and check with virtual function upadateAge() that deter
	 * if the animal reached is leave age (dead) if so we remove the animal and decreese
	 * the animals production
	 * if  still alive we celebrate her birthday and 1 product to our production cycle
	 */
	void updateAllAges();
	/* we print the recipet after we done shopping at seller
	 * " *FarmType* farm *Farm.ID* bought *amount* *sellerProducts* dollars
	 * 		from *sellerFarmType*  farm *SellerID*"
	 */
	virtual void printRecipet(int ID, int amount, int cost, int sellerID)const=0;

	// void Print()const;

	// check if you sell what i want to buy
	bool possiableClient(Farm &seller);
	// Lets shake hands on it, virtual method, different "shake" for each couple
	virtual bool  BeMyClient(Farm &client)=0;
	// print The farm
	//Farm Id: 3 type: Chicken Farm, Money: 11, Animals: 6 chickens, Products: Milk[0], Wool[0], Eggs[0]
	virtual void printFarm();

	// Return ID
	int getMyID(){return ID;}

	// Add money by given amount
	void AddMoney(int money) {Money += money;}
	virtual const int getProductCost()=0;
};

#endif /* FARM_H_ */
