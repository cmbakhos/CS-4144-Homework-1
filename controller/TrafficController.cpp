/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================
#include "TrafficController.hpp"

//-----------------------------------------------------------------------
// TrafficController::TrafficController()
//-----------------------------------------------------------------------
TrafficController::TrafficController() {}



//-----------------------------------------------------------------------
// int TrafficController::addLights( std::vector<std::string> lightInformation, int k )
//-----------------------------------------------------------------------
int TrafficController::addLights( std::vector<std::string> lightInformation, int k ) {
	// A few variables
	cnn = lightInformation[0];
	int index = 1;
	int return_k = k;
	
	// Loop through until an empty street
	while( ( lightInformation[index].compare("") != 0 ) && ( index < 5 ) ) {
		lights.push_back( TrafficLight( return_k ) );
		streets.push_back( lightInformation[index] );
		index++;
		return_k++;
	}
	
	coordinate = coordinateParser( lightInformation[6] );
	
	numberOfLights = lights.size();
	numberOfStreets = numberOfLights;
	
	return return_k;
}

//-----------------------------------------------------------------------
// void TrafficController::setSimulation()
//-----------------------------------------------------------------------
void TrafficController::setSimulation() {
	// First light
	currentLight = 0;
	
	// Set next event time to 0
	timeOfNextEvent = 0;
}

//-----------------------------------------------------------------------
// void TrafficController::evaluateLight()
//-----------------------------------------------------------------------
void TrafficController::evaluateLight() {
	char currentState = lights[currentLight].getState();
	switch( currentState ) {
		// If green, switch to yellow and set time for next event
		case 'g':
			lights[currentLight].setState('y');
			timeOfNextEvent += lights[currentLight].getYellowTime();
			break;
		// If yellow, switch to red, switch light, set next light green, 
		// time for next event
		case 'y':
			lights[currentLight].setState('r');
			currentLight = ( currentLight + 1 ) % numberOfLights;
			lights[currentLight].setState('g');
			timeOfNextEvent += lights[currentLight].getGreenTime();
			break;
		// If red, that means we are at time 0. We must set the current
		// state green, and set the time to be green time
		case 'r':
			lights[currentLight].setState('g');
			timeOfNextEvent += lights[currentLight].getGreenTime();
			
			break;
		// If something else, debug error statement
		default:
			std::cout << lights[currentLight].getState() << '\n';
			break;
	}
}



//-----------------------------------------------------------------------
// std::string TrafficController::getStreet( unsigned int street ) const
//-----------------------------------------------------------------------
std::string TrafficController::getStreet( unsigned int street ) const {
	street = street % numberOfStreets;
	return streets[street];
}

//-----------------------------------------------------------------------
// TrafficLight TrafficController::getLight( unsigned int light ) const
//-----------------------------------------------------------------------
TrafficLight TrafficController::getLight( unsigned int light ) const {
	light = light % numberOfLights;
	return lights[light];
}

//-----------------------------------------------------------------------
// void TrafficController::printLights()
//-----------------------------------------------------------------------
void TrafficController::printLights() {
	std::string output;
	std::cout << cnn << "; #lights: " << numberOfLights << "; ";
	for( int i = 0; i < numberOfLights; i++ ) {
		std::cout << streets[i] << ": ";
		if( currentLight == i ) {
			std::cout << lights[i].getState() << "; ";
		}
		else {
			std::cout << "r; ";
		}
	}
	std::cout << coordinate << '\n';
}

//-----------------------------------------------------------------------
// bool TrafficController::operator==( const TrafficController& controller ) const
//-----------------------------------------------------------------------
bool TrafficController::operator==( const TrafficController& controller ) const {
	return this->timeOfNextEvent == controller.timeOfNextEvent;
}

//-----------------------------------------------------------------------
// bool TrafficController::operator<( const TrafficController& controller ) const
//-----------------------------------------------------------------------
bool TrafficController::operator<( const TrafficController& controller ) const {
	return this->timeOfNextEvent < controller.timeOfNextEvent;
}

//-----------------------------------------------------------------------
// bool TrafficController::operator>( const TrafficController& controller ) const
//-----------------------------------------------------------------------
bool TrafficController::operator>( const TrafficController& controller ) const {
	return this->timeOfNextEvent > controller.timeOfNextEvent;
}