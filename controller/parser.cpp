/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================

// Include
#include "parser.hpp"

// Define
#define COMMA_DELIMITER ','
#define QUOTE_DELIMITER '"'
#define SPACE_DELIMITER ' '

//-----------------------------------------------------------------------
// int controllerParser( std::string argument )
//-----------------------------------------------------------------------
int controllerParser( std::string argument ) {
	int output = 0;
	
	if( argument[0] != '-'  ) {
		return -1;
	}
	if( argument[1] != 't' ) {
		return -1;
	}
	if( argument[2] != '=' ) {
		return -1;
	}
	for( unsigned int i = 3; i < argument.size(); i++ ) {
		switch( argument[i] ) {
			case '0':
				output = ( output * 10 ) + 0;
				break;
			case '1':
				output = ( output * 10 ) + 1;
				break;
			case '2':
				output = ( output * 10 ) + 2;
				break;
			case '3':
				output = ( output * 10 ) + 3;
				break;
			case '4':
				output = ( output * 10 ) + 4;
				break;
			case '5':
				output = ( output * 10 ) + 5;
				break;
			case '6':
				output = ( output * 10 ) + 6;
				break;
			case '7':
				output = ( output * 10 ) + 7;
				break;
			case '8':
				output = ( output * 10 ) + 8;
				break;
			case '9':
				output = ( output * 10 ) + 9;
				break;
			default:
				return -1;
		}
	}
	
	return output;
}

//-----------------------------------------------------------------------
// std::string coordinateParser( std::string coordinate )
//-----------------------------------------------------------------------
std::string coordinateParser( std::string coordinate ) {
	std::string output = "";
	char currentCharacter;
	
	for( unsigned int i = 7; i < coordinate.size(); i++ ) {
		currentCharacter = coordinate[i];
		if( currentCharacter == SPACE_DELIMITER ) {
			output += COMMA_DELIMITER;
		}
		else {
			if( currentCharacter != ')' ) {
				output += currentCharacter;
			}
		}
	}
	
	return output;
}

//-----------------------------------------------------------------------
// std::vector<std::vector<std::string>> csvParserByColumn( int* columns, int numberOfColumns )
//-----------------------------------------------------------------------
// Pass in array of which columns you care about.
// [0, 3, 4, 6, 8, 12, 34]. Returns a vector of vectors of strings. A 2D
// grid of the columns and rows we care about.
std::vector<std::vector<std::string>> csvParserByColumn( int* columns, int numberOfColumns ) {
	// Create ifstream object and open the csv file
	std::ifstream csv;
	csv.open("Traffic_Signals_SF.csv");
	
	// Create a string vector to hold each line
	std::vector<std::string> lines;
	
	// Copy all the lines of the CSV into a vector
	int line = 0;
	while( csv.good() ) {
		lines.push_back("");
		getline( csv, lines[line] );
		//std::cout << lines[line] << std::endl;
		line++;
	}
	
	// Save size of lines vector so we have it
	int totalLines = lines.size();
	
	// Define a temporary vector to hold the individual cells
	std::vector<std::vector<std::string>> rows;
	
	// Push back as many empty strings as there are columns we want,
	// and do that for each row
	for( int i = 0; i < totalLines; i++ ) {
		rows.push_back( std::vector<std::string>() );
		for( int j = 0; j < numberOfColumns; j++ ) {
			rows[i].push_back("");
		}
	}
	
	// Loop through each individual line in the CSV
	for( line = 1; line < totalLines; line++ ) {
		// Define a few variables we care about
		int lineLength = lines[line].size();
		char currentCharacter;
		bool quotationOpen = false;
		int columnCount = 0;
		int k = 0;
		bool columnWanted = ( columnCount == columns[k] );
		std::string character;
		
		// Loop through the whole line
		for( int i = 0; i < lineLength; i++ ) {
			// Save the current character in the current line
			currentCharacter = lines[line][i];
			
			// The three cases are quotes, commas, and others
			switch( currentCharacter ) {
				case QUOTE_DELIMITER:
					// Flip whether we are in a quote or not
					quotationOpen = !quotationOpen;
					break;
				case COMMA_DELIMITER:
					// Check if we are outside a quote
					if( !quotationOpen ) {
						// Indicate we're on a new column
						columnCount++;
						// If we wanted the column we were previous on
						if( columnWanted ) {
							// Shift k to find the next column we want
							k++;
						}
						// Do we want this column now?
						columnWanted = ( columnCount == columns[k] );
					}
					else {
						// Counted as a normal character in a quote
						if( columnWanted ) {
							// Add it to return vector of vectors of strings
							rows[line][k] += currentCharacter;
						}
					}
					break;
				default:
					// Just add it if we want that column. Ignore otherwise
					if( columnWanted ) {
						// Add it to return vector of vectors of strings
						rows[line][k] += currentCharacter;
					}
					break;
			}
		}
	}
	
	return rows;
}