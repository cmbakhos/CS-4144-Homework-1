/*=======================================================================
*	Christopher Bakhos (cmb524)
*	CS 4414 - Homework 1
*	September 27, 2021
*///=====================================================================

// Code gotten from http://www.cplusplus.com/reference/functional/greater/
// and modified by me to fit my needs
/*
template <class T> struct less {
  bool operator() (const T& x, const T& y) const {return x<y;}
  typedef T first_argument_type;
  typedef T second_argument_type;
  typedef bool result_type;
};
*/

struct controllerCompare {
	bool operator() (const TrafficController& x, const TrafficController& y) const { return x.getLight( 0 ).getK() < y.getLight( 0 ).getK(); }
};