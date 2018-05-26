/* ========================================================
 * Program:  shoppingitems.cpp
 * Author: mzc
 * 
 * Description:  Implementation for the ShoppingList class.
 *  =======================================================
 */

#include "shoppingCart.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include<limits.h>
#include<float.h>

#include <cctype>   // used for character testing function and for toupper
using namespace std;

int ShoppingCart::displayMenu() {
	int choice = 0;
	cout << "\nPlease select from the menu below: \n" << "\t1) Add an item\n"
			<< "\t2) Remove an item \n"
			<< "\t3) Display items in your Shopping Cart \n"
			<< "\t4) Exit the program\n" << endl;

	choice = readInteger("Your choice:", 1, 4);
	return choice;
}

bool ShoppingCart::applyChoice(int choice) {

	string name, unit;
	double quant;
	double price;

	switch (choice) {
	case 1: {
		cout << "What is the name of the item? ";

		getline(cin, name);

		cout << "What is the unit? ";

		getline(cin, unit);
//for input validation
		quant = readDouble("Quantity to buy? ", 0, DBL_MAX);

//for input validation
		price = readDouble("What is the unit price? ", 0, DBL_MAX);

//findItems() was added to improve the searching through the array to find matched items
		Item *item = items.findItem(name);
		if (item == NULL) {

			//create item from information received
			item = new Item(name, unit, quant, price);
			items.addItem(item);
			cout << "Item added to cart " << endl;

		} else {
			cout << "Item already in cart" << endl;

		}
	}
		break;

	case 2: {
		cout << "Which item do you want removed from cart? ";

		getline(cin, name);

		//checking if the item exists in List, USE OF THE OVERLOADED==OPERATOR
		Item *item = items.findItem(name);
		if (item != NULL) {
			items.removeItem(item);
			cout << "Item removed." << endl;
		} else
			cout << "Item not in cart " << endl;
	}
		break;

	case 3: {
		displayCart();

	}
		break;

	case 4: {
		cout << "Thank you for using The Shopping List Creator\nGoodbye! "
				<< endl;
		return false;

	}
		//break;

	}
	return true;
}
//calculate the sum of the array for only the extended price of items in the cart
//use of member functions of class Iter, a friend of List class
double ShoppingCart::totalPrice() {

	totals = 0;
	for (List::Iter it = items.begin(), eit = items.end(); it < eit; ++it) {
		Item* item = *it;
		totals += item->getExtendedPrice();

	}
	return totals;
}

void ShoppingCart::displayCart() {
	cout << "===============================================\n"
			<< "       Your Shopping Cart Items " << endl;
	cout << "================================================\n" << endl;
	for (List::Iter it = items.begin(), eit = items.end(); it < eit; ++it) {
		Item * item = *it;
		item->getName();
		cout << item->getQuant() << " " << item->getUnit() << '\t' << "of "
				<< item->getName() << '\t' << " @ $" << fixed << setprecision(2)
				<< item->getPrice() << " " << " per " << item->getUnit() << '\t'
				<< "totaling $" << fixed << setprecision(2)
				<< item->getExtendedPrice() << endl;

	}
	cout << "\nYour Shopping Cart total is $" << totalPrice() << endl;

}
//to allow the main function to run the program without access to other 
//functions within the different classes
void ShoppingCart::run() {

	int choice;

//displayMenu();
	do {
		choice = displayMenu();

	} while (applyChoice(choice));

}



