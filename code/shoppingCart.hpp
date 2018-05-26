/* ============================================================================
 * Program:  shoppingList.hpp
 * Author: mzc
 * 
 * Description:  Definitions for the ShoppingList class.
 *               This class contains information to acquire
 *               information of item name, unit type, quantity to buy and unit
 *               price, extended price
 *
 *  ============================================================================
 */

#ifndef ASSIGNMENTS_ASSIGNMENT2_SHOPPINGCART_HPP_
#define ASSIGNMENTS_ASSIGNMENT2_SHOPPINGCART_HPP_

#include "item.hpp"
#include "list.hpp"
#include "utils.hpp"

class ShoppingCart {

private:

	List items;


	int displayMenu();
	bool applyChoice(int);
	void displayCart();
	double totalPrice();

public:


//to get total price of all items of the shopping cart
	double totals;

	void run();

};

#endif /* ASSIGNMENTS_ASSIGNMENT2_SHOPPINGCART_HPP_ */
