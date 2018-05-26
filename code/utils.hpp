/* ============================================================================
 * Program:  utils.hpp
 * Author: 	mzc
 * 
 * Description:  Definitions for the utils functions.
 *               Functions created to handle input validations
 *
 *  ============================================================================
 */
#ifndef ASSIGNMENT2_UTILS_HPP_
#define ASSIGNMENT2_UTILS_HPP_

#include <string>
#include <istream>//to be able to use cin.eof functions


//function prototype to get input from user
int readInteger(const std::string &, int, int);
double readDouble(const std::string & prompt, double minD, double maxD);
bool validateWhitespaceToEol(std::istream&);


#endif /* ASSIGNMENT2_UTILS_HPP_ */
