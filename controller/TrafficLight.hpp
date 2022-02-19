/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================
class TrafficLight {
	public:
		// Constructor
		TrafficLight( int k );
		
		// Getters
		int getK() const { return k; }
		int getGreenTime() const { return greenTime; }
		int getYellowTime() const { return yellowTime; }
		char getState() const { return state; }
		
		// Setters
		void setGreenTime( int time );
		void setYellowTime( int time );
		void setState( char color );
		
		// Overloads
		bool operator==( const TrafficLight& light ) const;
		bool operator<( const TrafficLight& light ) const;
		bool operator>( const TrafficLight& light ) const;
		
	private:	
		// The number of the light
		int k;
		
		// The time for a specific color of the cycle
		int greenTime;
		int yellowTime;
		
		// The current state
		char state;
};