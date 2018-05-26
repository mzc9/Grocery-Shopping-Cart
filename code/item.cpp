/* ========================================================
 * Program:  item.cpp
 * Author: mzc
 * 
 * Description:  Implementation of Item class.
 *  =======================================================
 */

#include <iostream>
#include "item.hpp"
using namespace std;

Item::Item(string n, string u, double q, double p) {
	name = n;
	unit = u;
	quant = q;
	price = p;
}

string Item::getName() {

	return name;
}

string Item::getUnit() {

	return unit;
}

double Item::getQuant() {

	return quant;
}

double Item::getPrice() {

	return price;
}
//calculates the extended price of the item added to cart
double Item::getExtendedPrice() {

	return (quant * price);
}

//OVERLOADED==OPERATOR
bool operator==(Item* item, string name) {

	return item->getName() == name;

}

