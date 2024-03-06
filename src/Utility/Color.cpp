///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Color class enumeration
///
/// @file Color.h
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////

#include <random>

#include "../config.h"

#include "Color.h"

using namespace std;

/// Define a long-lasting (static) Random Number Generator (RNG) from the first
/// Color (Color::UNKNOWN_COLOR) to the last Color (Color::CALICO)
static uniform_int_distribution<> colorRNG( (int) Color::UNKNOWN_COLOR, (int) Color::CALICO );


Color newRandomColor() {
   return (Color) colorRNG( ANIMAL_FARM_RNG ) ;
}
