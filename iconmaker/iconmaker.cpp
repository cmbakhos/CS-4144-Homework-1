/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================

/*-----------------------------------------------------------------------
* Commands to compile
**-----------------------------------------------------------------------
* Generic File:
* g++ iconmaker.cpp pngwriter.cpp -o iconmaker -Wall -g -lpng -lz -DNO_FREETYPE -std=c++17
* 
* Executable File:
* g++ iconmaker.cpp pngwriter.cpp -o iconmaker.exe -Wall -g -lpng -lz -DNO_FREETYPE
*/

// Includes
#include <iostream>
#include <string>
#include "pngwriter.hpp"

// Define some helpful constants
#define NUMBER_OF_TWOS 9
#define NUMBER_OF_THREES 27
#define NUMBER_OF_FOURS 81

//-----------------------------------------------------------------------
// struct color_t
//-----------------------------------------------------------------------
// Struct of floats to hold RGB color.
struct color_t {
	float red;
	float green;
	float blue;
};

//-----------------------------------------------------------------------
// const char* colorCharacters( int number )
//-----------------------------------------------------------------------
// Treat number as a base ten number we want to convert to base three,
// then map base three number to the three colors.
const char* colorCharacters( int number, int digits ) {
	// Output string
	std::string output;
	
	// Variables for base conversion algorithm
	int quotient;
	int remainder;
	
	// Base conversion algorithm, except we want the preceeding zeros
	for( int i = 0; i < digits; i++ ) {
		quotient = number / 3;
		remainder = number % 3;
		number = quotient;
		
		// Map 0 to r, 1 to y, and 2 to g
		switch( remainder ) {
			case 0:
				output += 'r';
				break;
			case 1:
				output += 'y';
				break;
			case 2:
				output += 'g';
				break;
			default:
				std::cout << remainder << std::endl;
				break;
		}
	}
	
	// Return the output
	return output.c_str();
}

//-----------------------------------------------------------------------
// void stringToDrawing( pngwriter png, const char* colorString )
//-----------------------------------------------------------------------
// Parse the color string and draw the corresponding lines on the PNG.
void stringToDrawing( pngwriter& png, std::string colorString ) {
	// Obtain the number of streets there are
	int numberOfStreets = colorString.length();
	
	// An array of colors for the drawing
	color_t drawColor[4];
	
	// Check each letter, and assign a color based on that
	for( int i = 0; i < numberOfStreets; i++ ) {
		switch( colorString[i] ) {
			case 'r':
				drawColor[i] = { 1.0, 0.0, 0.0 };
				break;
			case 'y':
				drawColor[i] = { 1.0, 1.0, 0.0 };
				break;
			case 'g':
				drawColor[i] = { 0.0, 1.0, 0.0 };
				break;
			default:
				std::cout << colorString[0] << std::endl;
				break;
		}
	}
	
	// If there are only two streets, then we need two lines
	if( numberOfStreets == 2 ) {
		// Thick horizontal line - easier with for loops
		for( int i = 0; i < 6; i++ ) {
			png.line(1, 29 + i, 64, 29 + i, drawColor[0].red, drawColor[0].green, drawColor[0].blue);
		}
		
		// Thick vertical line - easier with for loops
		for( int i = 0; i < 6; i++ ) {
			png.line(29 + i, 1, 29 + i, 64, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		}
	}
	// If there are three streets, then we need three lines
	else if ( numberOfStreets == 3 ) {
		// Thick horizontal line - easier with for loops
		for( int i = 0; i < 6; i++ ) {
			png.line(1, 29 + i, 64, 29 + i, drawColor[0].red, drawColor[0].green, drawColor[0].blue);
		}
		
		// Thick negative line - harder with for loops
		png.line(1, 61, 61, 1, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(1, 62, 62, 1, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(1, 63, 63, 1, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(1, 64, 64, 1, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(2, 64, 64, 2, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(3, 64, 64, 3, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(4, 64, 64, 4, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		
		// Thick positive line - harder with for loops
		png.line(1, 4, 61, 64, drawColor[2].red, drawColor[2].green, drawColor[2].blue);
		png.line(1, 3, 62, 64, drawColor[2].red, drawColor[2].green, drawColor[2].blue);
		png.line(1, 2, 63, 64, drawColor[2].red, drawColor[2].green, drawColor[2].blue);
		png.line(1, 1, 64, 64, drawColor[2].red, drawColor[2].green, drawColor[2].blue);
		png.line(2, 1, 64, 63, drawColor[2].red, drawColor[2].green, drawColor[2].blue);
		png.line(3, 1, 64, 62, drawColor[2].red, drawColor[2].green, drawColor[2].blue);
		png.line(4, 1, 64, 61, drawColor[2].red, drawColor[2].green, drawColor[2].blue);
	}
	// If there are four streets, then we need four lines
	else {
		// Thick horizontal line - easier with for loops
		for( int i = 0; i < 6; i++ ) {
			png.line(1, 29 + i, 64, 29 + i, drawColor[0].red, drawColor[0].green, drawColor[0].blue);
		}
		
		// Thick negative line - harder with for loops
		png.line(1, 61, 61, 1, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(1, 62, 62, 1, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(1, 63, 63, 1, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(1, 64, 64, 1, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(2, 64, 64, 2, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(3, 64, 64, 3, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		png.line(4, 64, 64, 4, drawColor[1].red, drawColor[1].green, drawColor[1].blue);
		
		// Thick vertical line - easier with for loops
		for( int i = 0; i < 6; i++ ) {
			png.line(29 + i, 1, 29 + i, 64, drawColor[2].red, drawColor[2].green, drawColor[2].blue);
		}
		
		// Thick positive line - harder with for loops
		png.line(1, 4, 61, 64, drawColor[3].red, drawColor[3].green, drawColor[3].blue);
		png.line(1, 3, 62, 64, drawColor[3].red, drawColor[3].green, drawColor[3].blue);
		png.line(1, 2, 63, 64, drawColor[3].red, drawColor[3].green, drawColor[3].blue);
		png.line(1, 1, 64, 64, drawColor[3].red, drawColor[3].green, drawColor[3].blue);
		png.line(2, 1, 64, 63, drawColor[3].red, drawColor[3].green, drawColor[3].blue);
		png.line(3, 1, 64, 62, drawColor[3].red, drawColor[3].green, drawColor[3].blue);
		png.line(4, 1, 64, 61, drawColor[3].red, drawColor[3].green, drawColor[3].blue);
	}
	//png.write_png();
}

//-----------------------------------------------------------------------
// int main()
//-----------------------------------------------------------------------
int main() {
	// Initialize array of PNGs. Some of these will be overwritten so we
	// only need as many as the number of streets with four
	pngwriter pngs[NUMBER_OF_FOURS];
	
	// Loop through each 2 street PNG, initializing
	for( int i = 0; i < NUMBER_OF_TWOS; i++ ) {
		// Obtain the color string for the name
		std::string colorString = colorCharacters( i, 2 );
		
		// Set the name of the PNG
		std::string pngName = "files/i2" + colorString + ".png";
		
		// Initialize the PNGs
		pngs[i] = pngwriter(64, 64, 1.0, pngName.c_str());
		
		stringToDrawing( pngs[i], colorString );
		
		// Write the PNGs to disk. Could alternatively use close();
		pngs[i].write_png();
	}
	
	// Loop through each 3 street PNG, initializing
	for( int i = 0; i < NUMBER_OF_THREES; i++ ) {
		// Obtain the color string for the name
		std::string colorString = colorCharacters( i, 3 );
		
		// Set the name of the PNG
		std::string pngName = "files/i3" + colorString + ".png";
		
		// Initialize the PNGs
		pngs[i] = pngwriter(64, 64, 1.0, pngName.c_str());
		
		stringToDrawing( pngs[i], colorString );
		
		// Write the PNGs to disk. Could alternatively use close();
		pngs[i].write_png();
	}
	
	// Loop through each 4 street PNG, initializing
	for( int i = 0; i < NUMBER_OF_FOURS; i++ ) {
		// Obtain the color string for the name
		std::string colorString = colorCharacters( i, 4 );
		
		// Set the name of the PNG
		std::string pngName = "files/i4" + colorString + ".png";
		
		// Initialize the PNGs
		pngs[i] = pngwriter(64, 64, 1.0, pngName.c_str());
		
		// Draw the lines based on the color string
		stringToDrawing( pngs[i], colorString );
		
		// Write the PNGs to disk. Could alternatively use close();
		pngs[i].write_png();
	}
	
	return 0;
}