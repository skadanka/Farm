/*
 * CowsFarm.cpp
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#include "CowsFarm.h"
using namespace std;

int const CowsFarm::whatIsell = 0;
int const CowsFarm::whatIBuy = 2;
int const CowsFarm::productCost = 3;

void CowsFarm::printRecipet(int ID, int amount, int cost, int sellerID)const{
	cout << "Cow farm(" << ID << ") bought " << amount << " eggs for "
				<< cost << " dollars from Chicken farm(" << sellerID << ")" << endl;
}

void CowsFarm::BuyAnimals(int amount=0){
	int buying =0;
	Cow *cow;
	if(!amount){
		while(Money >= Cow::getCost()){
			cow = new Cow;
			if(!cow) exit;
			Animals.push_back(cow);
			buying += 1;
			Money -= Cow::getCost();
			}
		if(buying > 0)
			cout << "Cow farm("<< ID<<") bought " << buying << " cows for " << buying*10 << " dollars"<<endl;
		return;
		}

	for(int i =0; i < 3;Animals.push_back(new Cow()), i++);
}

void CowsFarm::printFarm(){
	cout << "Farm Id: " << ID << ", type: Cow farm, Money: " << Money <<", Animals: "
			<< Animals.size() <<" cows, ";
	Farm::printFarm();
}

bool CowsFarm::BeMyClient(Farm &client){
	if(!client.possiableClient(*this))
		return false;
	cout<< "Cow farm("<< ID<<") Added Sheep farm("<<client.getMyID()<<") to his client list" << endl;
	return true;
}
