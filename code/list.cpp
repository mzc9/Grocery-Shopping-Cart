/* ========================================================
 * Program:  list.cpp
 * Author: mzc
 * 
 * Description:  Definitions for List class.
 *               This class contains information about Item
 *               objects
 *  =======================================================
 */

#include <iostream>
#include<string>
#include "list.hpp"
#include "item.hpp"
using namespace std;

//Constructor

List::List() {

	capacity = increment;
	list = new Item *[capacity];
	numItems = 0;
}

void List::addItem(Item* item) {
//creates a temporary Item** tmp to hold values of array when the array needs
//to be expanded with the addition of items
	if (numItems == capacity) {
		capacity += increment;
		Item **tmp = list;
		list = new Item *[capacity];     	//dynamic allocation of array
		for (int index = 0; index < numItems; ++index) {
			list[index] = tmp[index];
		}
	}
	list[numItems++] = item;

}

void List::removeItem(Item* item) {
	for (int index = 0; index < numItems; ++index) {
		if (list[index] == item) {
			for (++index; index < numItems; ++index) {
				list[index - 1] = list[index];
			}
			break;
		}
	}
	--numItems;

}

//new function added as a result of test plan results

Item* List::findItem(const string & name) {
	for (int index = 0; index < numItems; ++index) {
		if (list[index] == name) {
			return list[index];
		}

	}
	return NULL;
}

//Destructor for list to prevent memory leak

//free dynamically allocated memory to prevent memory leak
//(not strictly needed, as we're about to exit anyhow, but included for completeness)

List::~List() {
	for (int index = 0; index < numItems; ++index) {
		delete list[index];
	}
	delete[] list;
}

