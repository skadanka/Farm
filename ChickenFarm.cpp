/*
 * ChickenFarm.cpp
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#include "ChickenFarm.h"
using namespace std;

int const ChickenFarm::whatIsell = 2;
int const ChickenFarm::whatIBuy = 1;
int const ChickenFarm::productCost = 1;

void ChickenFarm::printRecipet(int ID, int amount, int cost, int sellerID)const{
	cout << "Chicken farm(" << ID << ") bought " << amount << " wool for "
				<< cost << " dollars from Sheep farm(" << sellerID << ")" << endl;
}
ChickenFarm::ChickenFarm(){
	BuyAnimals(3);
	Money=10;
}


void ChickenFarm::BuyAnimals(int amount=0){
	int buying =0;
	Chicken *chicken;
	if(!amount){
		while( Money >= Chicken::getCost()){
			chicken = new Chicken();
			if(!chicken) exit;
			Animals.push_back(chicken);
			buying += 1;
			Money -= Chicken::getCost();
		}

		if(buying > 0)
			cout << "Chicken farm("<< ID<<") bought " << buying << " chickens for " << buying*3 << " dollars"<<endl;
		return;

	}
	for(int i =0; i < 3;Animals.push_back(new Chicken()), i++);
}


void ChickenFarm::printFarm(){
	cout << "Farm Id: " << ID << ", type: Chicken Farm, Money: " << Money <<", Animals: "
			<< Animals.size() <<" chickens, ";
	Farm::printFarm();
}

bool ChickenFarm::BeMyClient(Farm &client){
	if(!client.possiableClient(*this))
		return false;
	cout<< "Chicken farm("<< ID<<") Added Cow farm("<< client.getMyID() <<") to his client list" << endl;
		return true;

}
