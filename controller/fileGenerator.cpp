/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================
#include "fileGenerator.hpp"

#define NUMBER_OF_TWOS 9
#define NUMBER_OF_THREES 27
#define NUMBER_OF_FOURS 81
#define NUMBER_OF_ICONS 117

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
// int generateCSV( std::vector<TrafficController> informationVector )
//-----------------------------------------------------------------------
int generateCSV( std::vector<TrafficController> informationVector ) {
	// Some variables
	std::string fileName = "myfile.csv";
	std::ofstream output;
	int vectorLength = informationVector.size();
	int numberOfLights;
	
	// Open the file for writing
	output.open( fileName, std::ios_base::trunc );
	
	// Print to file
	if( output.is_open() ) {
		output << "CNN,STREET NAME,COLOR" << '\n';
		for( int i = vectorLength - 1; i >= 0; i-- ) {
			numberOfLights = informationVector[i].getNumberOfLights();
			for( int j = 0; j < numberOfLights; j++) {
				output << informationVector[i].getCNN() << ',';
				output << informationVector[i].getStreet( j ) << ',';
				switch( informationVector[i].getLight( j ).getState() ) {
					case 'r':
						output << "RED\n";
						break;
					case 'y':
						output << "YELLOW\n";
						break;
					case 'g':
						output << "GREEN\n";
						break;
					default:
						output << "\n";
						break;
				}				
			}
		}
	}
	else {
		return 1;
	}
	
	// Close the file
	output.close();
	
	// Return success
	return 0;
}

//-----------------------------------------------------------------------
// void generateCSV( std::vector<TrafficController> informationVector )
//-----------------------------------------------------------------------
int generateKML( std::vector<TrafficController> informationVector ) {
	// Some variables
	std::string fileName = "myfile.kml";
	std::ofstream output;
	int vectorLength = informationVector.size();
	int numberOfLights;
	
	// Open the file for writing
	output.open( fileName, std::ios_base::trunc );
	
	// Print to file
	if( output.is_open() ) {
		output << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
		output << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n";
		output << "<Document>\n";
		for( int i = 0; i < NUMBER_OF_TWOS; i++ ) {
			std::string colorString = colorCharacters( i, 2 );
			output << "\t<Style id=\"i2" << colorString << "\">\n";
			output << "\t\t<IconStyle id=\"i2" << colorString << "\">\n";
			output << "\t\t\t<Icon>\n";
			output << "\t\t\t\t<href>files/i2" << colorString << ".png</href>\n";
			output << "\t\t\t\t<scale>1.0</scale>\n";
			output << "\t\t\t</Icon>\n";
			output << "\t\t</IconStyle>\n";
			output << "\t</Style>\n\n";
		}
		for( int i = 0; i < NUMBER_OF_THREES; i++ ) {
			std::string colorString = colorCharacters( i, 3 );
			output << "\t<Style id=\"i3" << colorString << "\">\n";
			output << "\t\t<IconStyle id=\"i3" << colorString << "\">\n";
			output << "\t\t\t<Icon>\n";
			output << "\t\t\t\t<href>files/i3" << colorString << ".png</href>\n";
			output << "\t\t\t\t<scale>1.0</scale>\n";
			output << "\t\t\t</Icon>\n";
			output << "\t\t</IconStyle>\n";
			output << "\t</Style>\n\n";
		}
		for( int i = 0; i < NUMBER_OF_FOURS; i++ ) {
			std::string colorString = colorCharacters( i, 4 );
			output << "\t<Style id=\"i4" << colorString << "\">\n";
			output << "\t\t<IconStyle id=\"i4" << colorString << "\">\n";
			output << "\t\t\t<Icon>\n";
			output << "\t\t\t\t<href>files/i4" << colorString << ".png</href>\n";
			output << "\t\t\t\t<scale>1.0</scale>\n";
			output << "\t\t\t</Icon>\n";
			output << "\t\t</IconStyle>\n";
			output << "\t</Style>\n";
		}
		for( int i = vectorLength - 1; i >= 0; i-- ) {
			numberOfLights = informationVector[i].getNumberOfLights();
			
			output << "\t<Placemark>\n";
			output << "\t\t<name>" << informationVector[i].getCNN() << "</name>\n";
			
			output << "\t\t<description>";
			for( int j = 0; j < numberOfLights - 1; j++ ) {
				output << informationVector[i].getStreet( j ) << " and ";
			}
			output << informationVector[i].getStreet( numberOfLights - 1 ) << "</description>\n";
			
			output << "\t\t<styleUrl>#i" << numberOfLights;
			for( int j = 0; j < numberOfLights; j++ ) {
				output << informationVector[i].getLight( j ).getState();
			}
			output << "</styleUrl>\n";
			
			output << "\t\t<Point>\n";
			output << "\t\t\t<coordinates>" << informationVector[i].getCoordinate() << "</coordinates>\n";
			output << "\t\t</Point>\n";
			output << "\t</Placemark>\n";
		}
		output << "</Document>\n";
		output << "</kml>";
	}
	else {
		return 1;
	}
	
	// Close the file
	output.close();
	
	// Return success
	return 0;
}