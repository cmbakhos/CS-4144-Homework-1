/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================
#include "TrafficLight.hpp"

//-----------------------------------------------------------------------
// TrafficLight::TrafficLight( int k )
//-----------------------------------------------------------------------
TrafficLight::TrafficLight( int k ) {
	// Traffic light's absolute number
	this->k = k;
	
	// The light times
	if( k % 25 == 0 ) {
		greenTime = 90;
	}
	else if( k % 25 < 15 ) {
		greenTime = 60;
	}
	else {
		greenTime = 30;
	}
	yellowTime = 10;
	
	// Light's state
	state = 'r';
}

//-----------------------------------------------------------------------
// void TrafficLight::setState( char color )
//-----------------------------------------------------------------------
void TrafficLight::setState( char color ) {
	if( ( color == 'r' ) || ( color == 'y' ) || ( color == 'g' ) ) {
		state = color;
	}
}

//-----------------------------------------------------------------------
// bool operator==( const TrafficLight& light ) const
//-----------------------------------------------------------------------
bool TrafficLight::operator==( const TrafficLight& light ) const {
	return this->k == light.k;
}

//-----------------------------------------------------------------------
// bool operator<( const TrafficLight& light ) const
//-----------------------------------------------------------------------
bool TrafficLight::operator<( const TrafficLight& light ) const {
	return this->k < light.k;
}

//-----------------------------------------------------------------------
// bool operator>( const TrafficLight& light ) const
//-----------------------------------------------------------------------
bool TrafficLight::operator>( const TrafficLight& light ) const {
	return this->k > light.k;
}