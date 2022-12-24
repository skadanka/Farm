/*
 * Market.h
 *
 *  Created on: Dec 29, 2021
 *      Author: ise
 */

#ifndef MARKET_H_
#define MARKET_H_

#include "Farm.h"
#include "CowsFarm.h"
#include "ChickenFarm.h"
#include "SheepFarm.h"
#include <vector>

class Market {
public:
	Market();
	~Market();
	std::vector<Farm*> Bastot;

	// understand how to define the Type of the Farm(cows,sheep, chickien)
	// create with default constructor
	/*----Creating new farms---- *ask and check inputs, start new*
	 * How many new cow farms will be added this year?
	 * 		if(input < 0) Insert valid number of cow farms
	 * How many new sheep farms will be added this year?
	 * 		if(input < 0) Insert valid number of sheep farms
	 * How many new chicken farms will be added this year?
	 * 		if(input < 0) Insert valid number of chicken farms
	 * ----Adding new farms to market----
	 */
	void CreateNewFarms();
	/* FirstPhase the Farms shop products Ordered By ID, Buy till:
	 * 			-No More Money
	 * 			-No More desired Products
	 * CowFarm -> Shop eggs(chickenFarm)
	 * SheepFarm-> Shop milk(CowsFarm)
	 * ChickenFarm-> Shop wool(SheepFarm)
	 * SecondPhase The Farm Shop Animals With all Current Money: Money%CurrentFarmType
	 *
	 */
	void openMarket();
	/* Create New Farms ( need further explanation)
	 * 		Update all Farm Production Production=Production+AmountOfAnimals
	 * 		Update all animalsAge=animalAge + 1;
	 * 		Add 10$ to all Farms
	 * 		*** Need to clear Dead Animals First, And Check if the Bought Animals age 0**
	 * 		openMarket();
	 */
	void nextYear();
	// Doing nextYear function without adding new Farms;
	void fastForwardYears();
	/*----Market Farms----
	 * Farm Id: 1, type: Cow farm,
	 * 	Money: 10, Animals: 4 cows, Products: Milk[0], Wool[0], Eggs[0]\n...
	 */
	void printMarketFarms();
	static int getYear();
private:
	static int years;

};

#endif /* MARKET_H_ */
