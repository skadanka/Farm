/*
 * SheepFarm.cpp
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#include "SheepFarm.h"
using namespace std;

int const SheepFarm::whatIsell = 1;
int const SheepFarm::whatIBuy = 0;
int const SheepFarm::productCost = 2;

void SheepFarm::printRecipet(int ID, int amount, int cost, int sellerID)const{
	cout << "Sheep farm(" << ID << ") bought " << amount << " milk for "
	<< cost << " dollars from Cow farm(" << sellerID << ")" << endl;
}

void SheepFarm::BuyAnimals(int amount=0){
	int buying =0;
	Sheep *sheep;
	if(!amount){
		while(Money >= Sheep::getCost()){
			sheep = new Sheep;
			if(!sheep) exit;
			Animals.push_back(sheep);
			buying += 1;
			Money -= Sheep::getCost();
		}
		if(buying > 0)
			cout << "Sheep farm("<< ID<<") bought " << buying << " sheeps for " << buying*5 << " dollars"<<endl;
		return;
	}
	for(int i =0; i < 3;Animals.push_back(new Sheep()), i++);
}

void SheepFarm::printFarm(){
	cout << "Farm Id: " << ID << ", type: Sheep farm, Money: " << Money <<", Animals: "
			<< Animals.size() <<" sheep, ";
	Farm::printFarm();
}

bool SheepFarm::BeMyClient(Farm &client){
	if(!client.possiableClient(*this))
		return false;
	std::cout<< "Sheep farm("<< ID<<") Added Chicken farm("<<client.getMyID() <<") to his client list" << endl;
	return true;
}

