/*
 * Market.cpp
 *
 *  Created on: Dec 29, 2021
 *      Author: ise
 */

#include "Market.h"
#include "FarmExp.h"
using namespace std;

int Market::years = 0;

Market::Market() {
	// TODO Auto-generated constructor stub

}

Market::~Market(){
	vector<Farm*>::iterator it = Bastot.begin();
	while (it != Bastot.end()) {
		delete *it;
		it = Bastot.erase(it);
	}
	Bastot.clear();
}

void Market::CreateNewFarms(){
	bool InvalidInput = true;
	int cowsAmount, sheepAmount, chickenAmount;
	int Input;
	cout << "----Creating new farms----" << endl;
	while(InvalidInput){
		std::cout << "How many new cow farms will be added this year?" << endl;
		try{
			std::cin >> Input;
			if(Input < 0) {throw CowException();}
			cowsAmount = Input;
		}
		catch(exception &e){
			std::cout<<e.what() <<endl;
			continue;
		}


		std::cout << "How many new sheep farms will be added this year?" << endl;
		try{
			std::cin >> Input;
			if(Input < 0) {throw SheepException();}
			sheepAmount = Input;
		}
		catch(exception &e){
			std::cout<<e.what() <<endl;
			continue;
		}

		std::cout << "How many new chicken farms will be added this year?" << endl;
		try{
			std::cin >> Input;
			if(Input < 0) {throw ChickenException();}
			chickenAmount = Input;
		}
		catch(exception &e){
			std::cout<<e.what() <<endl;
			continue;
		}
		InvalidInput = false;
	}

	cout <<"----Adding new farms to market----" <<endl;
	int oldMarketSize = Bastot.size();
	CowsFarm *cowF;
	SheepFarm *sheepF;
	ChickenFarm *chickenF;
	for(int i = 0; i < cowsAmount; i++){
		cowF = new CowsFarm;
		if(!cowF) exit;
		Bastot.push_back(cowF);
	}
	for(int i = 0; i < sheepAmount;i++){
		sheepF = new SheepFarm;
		if(!sheepF) exit;
		Bastot.push_back(sheepF);
	}
	for(int i = 0; i < chickenAmount; i++){
		chickenF = new ChickenFarm;
		if(!chickenF) exit;
		Bastot.push_back(chickenF);
	}

	if(Bastot.end()== Bastot.begin()) return;

	std::vector<Farm*>::iterator it_Client;
	std::vector<Farm*>::iterator it_Seller;


	// we iterate over the Bastot vector, and the Market owner intredouce all the new
	// seller/clients to all Bastot present. we asl each one if he would be our client or our seller
	// do nothin seller doesn't sell what I Buy .
	for(it_Client = Bastot.begin() + oldMarketSize; it_Client != Bastot.end(); ++it_Client){
		for(it_Seller = Bastot.begin(); it_Seller != it_Client; ++it_Seller){
			(*it_Client)->BeMyClient(**it_Seller);
			(*it_Seller)->BeMyClient(**it_Client);
		}
	}

};


void Market::openMarket(){
	cout<<"----Begin Market----" <<endl;
	std::vector<Farm*>::iterator itShopping;
	std::vector<Farm*>::iterator itSeller;

	// All the Bastot updating their stocks based on the sum of Ages
	for(itShopping = Bastot.begin(); itShopping != Bastot.end(); ++itShopping )
		(*itShopping)->updateFarmProducts();

	// we OPEN our Market and let each client for oldest to newest.
	// stop shopping when itShopping money < The product he interested in
	for(itSeller = Bastot.begin(); itSeller != Bastot.end(); ++itSeller )
		for(itShopping = Bastot.begin(); itShopping != Bastot.end(); ++itShopping)
			if((*itShopping)->goShopProducts(**itSeller)){}
	cout<<"----Buy Animals----" << endl;
	for(itShopping = Bastot.begin(); itShopping != Bastot.end(); ++ itShopping)
		(*itShopping)->BuyAnimals(0);

	for(itShopping = Bastot.begin(); itShopping != Bastot.end(); ++ itShopping){
		(*itShopping)->AddMoney(10);
		(*itShopping)->updateAllAges();
	}

}

void Market::nextYear(){
	CreateNewFarms();
	openMarket();
	years++;
}

void Market::fastForwardYears(){
	int year =0;
	cout <<"How many years to fast forward?"<<endl;
	cin >> year;
	for(int i = 0; i < year; i++){
		openMarket();
		years++;
	}

}

void Market::printMarketFarms(){
	cout<<"----Market Farms----" << endl;
	std::vector<Farm*>::iterator itPrint;
	for(itPrint = Bastot.begin(); itPrint != Bastot.end(); ++ itPrint)
			(*itPrint)->printFarm();
}

int Market::getYear(){
	return Market::years;
}
