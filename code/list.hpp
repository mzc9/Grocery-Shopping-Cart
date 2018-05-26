/* ========================================================
 * Program:  list.hpp
 * Author: mzc
 * 
 * Description:  Definitions for List class.
 *               This class contains information about Item
 *               objects
 *  =======================================================
 */

#ifndef ASSIGNMENTS_ASSIGNMENT2_LIST_HPP_
#define ASSIGNMENTS_ASSIGNMENT2_LIST_HPP_

#include "item.hpp"

class List {
private:
	Item **list;
	static const int increment = 4; //grow by this value instead of reallocating the whole array
	int capacity; 					//starting capacity = 4; if capacity == numItems, build more space
	int numItems;					//number of items in the list

public:
//created an additional class that is associated with the List class with the use of inheritance
// this functionality was added so it was easier to iterate through the array
//to find objects

	class Iter {

	private:
		Item **current;

		Iter(Item **start) {
			current = start;
		}

	public:
		Item* operator*() {
			return *current;
		}
//overloaded operators to keep track of current items in the array
		Item* operator++() {
			return *++current;
		}

		bool operator<(Iter other) {
			return current < other.current;
		}

		friend class List;
	};

	//constructor for List class
	List();
	//Item* getItem(std::string);
	void addItem(Item*);
	void removeItem(Item*);
	Item* findItem(const std::string &);

//functions within the Iter class
	Iter begin() {
		return Iter(list);
	}
	Iter end() {
		return Iter(list + numItems);
	}

//	DESTRUCTOR
	~List();


};

#endif /* ASSIGNMENTS_ASSIGNMENT2_LIST_HPP_ */
