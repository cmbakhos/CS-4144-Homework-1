/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================

/*-----------------------------------------------------------------------
* Commands to compile
**-----------------------------------------------------------------------
* Generic File:
* g++ controller.cpp TrafficController.cpp TrafficLight.cpp parser.cpp -o controller -Wall -g -std=c++17
*/

// Includes
#include <queue>

#include "fileGenerator.hpp"
#include "sortFunction.hpp"

// Define
#define NUMBER_OF_COLUMNS 7

//-----------------------------------------------------------------------
// int main()
//-----------------------------------------------------------------------
int main( int argc, char *argv[] ) {
	// std::cout << argc << '\n';
	if( argc != 2 ) {
		std::cout << "Please pass one argument in the form of -t=n, where n is a non-negative integer. Thanks :)" << '\n';
		return 1;
	}
	int t = controllerParser( argv[1] );
	if( t < 0 ) {
		std::cout << "Please pass one argument in the form of -t=n, where n is a non-negative integer. Thanks :)" << '\n';
		return 1;
	}
	
	// Create an initial priority queue to hold the traffic lights
	std::priority_queue<TrafficController, std::vector<TrafficController>, std::greater<TrafficController>> eventQueue;
	std::queue<TrafficController> controllerQueue;
	int k = 0;
	int totalControllers;
	int currentTime = 0;
	TrafficController top;
	
	// Parse the CSV. columns[] are the columns we care about from the
	// CSV
	int columns[] = {0, 3, 4, 6, 8, 12, 34};
	std::vector<std::vector<std::string>> parsed = csvParserByColumn( columns, NUMBER_OF_COLUMNS );
	
	// Push the traffic controllers onto the queue if GPS is present,
	// then add the traffic lights to each controller
	for( unsigned int i = 0; i < parsed.size(); i++ ) {
		if( parsed[i][5].compare("GPS") == 0 ) {
			controllerQueue.push( TrafficController() );
			k = controllerQueue.back().addLights( parsed[i], k );
			controllerQueue.back().setSimulation();
		}
	}
	
	// Put everything into the priority queue
	totalControllers = controllerQueue.size();
	for( int i = 0; i < totalControllers; i++ ) {
		top = controllerQueue.front();
		controllerQueue.pop();
		eventQueue.push( top );
	}
	
	// Simulate	
	top = eventQueue.top();
	currentTime = top.getEventTime();
	while( currentTime <= t ) {
		top.evaluateLight();
		//top.printLights();
		eventQueue.pop();
		eventQueue.push( top );
		top = eventQueue.top();
		currentTime = top.getEventTime();
	}
	
	std::cout << "\n\n\n\n\n";
	
	// Move from eventQueue to a sorted queue to a vector
	std::priority_queue<TrafficController, std::vector<TrafficController>, controllerCompare> sortedQueue;
	std::vector<TrafficController> controllerVector;
	for( int i = 0; i < totalControllers; i++ ) {
		top = eventQueue.top();
		eventQueue.pop();
		sortedQueue.push( top );
	}
	for( int i = 0; i < totalControllers; i++ ) {
		top = sortedQueue.top();
		sortedQueue.pop();
		controllerVector.push_back( top );
		top.printLights();
	}
	
	// File generation
	generateCSV( controllerVector );
	generateKML( controllerVector );
	
	return 0;
}