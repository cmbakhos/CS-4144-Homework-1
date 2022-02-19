/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================
#include <vector>
#include <string>
#include <iostream>

#include "parser.hpp"
#include "TrafficLight.hpp"

class TrafficController {
	public:
		// Default constructor
		TrafficController();
		
		// Setup and simulation
		int addLights( std::vector<std::string> lightInformation, int k );
		void setSimulation();
		void evaluateLight();
		
		// Getters
		std::string getCNN() const { return cnn; }
		std::string getCoordinate() const { return coordinate; }
		std::string getStreet( unsigned int street ) const;
		TrafficLight getLight( unsigned int light ) const;
		int getEventTime() const { return timeOfNextEvent; }
		int getCurrentLight() const { return currentLight; }
		int getNumberOfLights() const { return numberOfLights; }
		
		// Debug
		void printLights();
		
		// Overloads
		bool operator==( const TrafficController& controller ) const;
		bool operator<( const TrafficController& controller ) const;
		bool operator>( const TrafficController& controller ) const;

	private:
		// String variables from CSV
		std::string cnn;
		std::vector<std::string> streets;
		std::string coordinate;
		
		// Operational variables
		int numberOfLights;
		int numberOfStreets;
		
		int currentLight;
		int timeOfNextEvent;
		std::vector<TrafficLight> lights;
};