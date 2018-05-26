/* ========================================================
 * Program:  item.hpp
 * Author: mzc
 * 
 * Description:  Definitions for Item class.
 *               This class contains information about item
 *               name, unit type, quantity to buy and unit
 *               price, extended price
 *  =======================================================
 */

#ifndef ASSIGNMENTS_ASSIGNMENT2_ITEM_HPP_
#define ASSIGNMENTS_ASSIGNMENT2_ITEM_HPP_

#include<string>

class Item {
private:
	std::string name;
	std::string unit;
	double quant;
	double price;

public:

	//Constructor

	Item(std::string, std::string, double, double);

	std::string getName();
	std::string getUnit();
	double getQuant();
	double getPrice();
	double getExtendedPrice();



	//OVERLOADED== OPERATOR

	friend bool operator== (Item*, std::string);

//DESTRUCTOR
	~Item() {}
};

#endif /* ASSIGNMENTS_ASSIGNMENT2_ITEM_HPP_ */
