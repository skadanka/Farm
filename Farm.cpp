/*
 * Farm.cpp
 *
 *  Created on: Dec 29, 2021
 *      Author: ise
 */

#include "Farm.h"
using namespace std;

int Farm::numOfFarms = 0;

Farm::Farm(const Farm &other){
	Money = other.Money;
	sumOfAges = other.sumOfAges;
	ID = other.ID;
	Animals = other.Animals;
	for(int i =0; i< 3;products[i] = other.products[i], i++);
}

Farm::Farm() {
	// TODO Auto-generated constructor stub
	// Go shop some nice animals to Start with!
	Money = 30;
	sumOfAges = 0;
	ID = ++numOfFarms;
	for(int i =0; i< 3;products[i] = 0, i++);

}

Farm::~Farm(){

	for(Animal* animal : Animals)
		delete animal;

	Animals.clear();
}

void Farm::updateAllAges(){
	std::vector<Animal*>::iterator it;
	if(Animals.empty()) return;
	for(auto it = Animals.begin(); it != Animals.end();)
	{
		if(*it  && (*it)->updateAge()){
			sumOfAges -= ((*it)->Animalproduction()-1);
			delete *it;
			Animals.erase(it);
		}
		else{
			sumOfAges += 1;
			++it;
		}
	}
}

bool Farm::possiableClient(Farm &seller){
	return seller.WhatProductsYouSell() == WhatProductsIBuy();

}

bool Farm::goShopProducts(Farm &seller){
	if(!possiableClient(seller))
		return false;
	int cost = seller.getProductCost();
	int buying = 0;
	while(seller.products[WhatProductsIBuy()]>0 && Money >= cost){
		seller.Money+= cost;
		seller.products[WhatProductsIBuy()] -= 1;
		products[WhatProductsIBuy()] += 1;
		Money -= cost;
		buying++;
	}
	if(buying > 0)
		printRecipet(ID, buying, buying*cost, seller.ID);
	if(Money < cost) // still can buy from this farm products
		return true;
	return false; // still have money to buy from the next farm;
}

void Farm::printFarm()
{
	std::cout<<"Products: Milk["<<products[0]<<"], Wool[" <<products[1]
								<<"], Eggs[" <<products[2]<<"]"<<endl;
}
