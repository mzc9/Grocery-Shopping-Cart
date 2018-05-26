/* ====================================================================
 * Program: mainAssign2.cpp
 * Author: mzc
 * 
 * Description: As grocery shopping list, this program allows a user to
 *              to create a list, add & remove items and display
 *              a shopping list, along with a unit price per item
 *=======================================================================
 */

#include <iostream>
#include<string>
#include "item.hpp"
#include "list.hpp"
#include "shoppingCart.hpp"
using namespace std;

int main() {

	cout << "\nWelcome to The Shopping List Creator. \n"
			<< "You can add items to your list, "
			<< "remove items from your list, \n"
			<< "specify number of items to purchase & \n"
			<< "check the total price for today's list. " << endl;

//object of class ShoppingCart
	ShoppingCart cart;

	cart.run();


	return 0;
}

