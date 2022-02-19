/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================
#include <fstream>
#include <vector>

// Controller parser function
int controllerParser( std::string argument );

// Coordinate parser function
std::string coordinateParser( std::string coordinate );

// CSV parser function
std::vector<std::vector<std::string>> csvParserByColumn( int* columns, int numberOfColumns );