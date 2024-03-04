///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  ee205_animal_farm - EE 205 - Spr 2024
//
/// A gender class... for educational use only.
/// This is not intended to be inclusive of all possible genders
///
/// @file   Animal.h
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////

#include <random>

#include "../config.h"
#include "Gender.h"

using namespace std;

/// Define a long-lasting (static) Random Number Generator (RNG) from the first
/// Gender (#Gender::UNKNOWN_GENDER) to the last Gender (#Gender::FEMALE)
static uniform_int_distribution<> genderRNG( (int) Gender::UNKNOWN_GENDER, (int) Gender::FEMALE );


Gender newRandomGender() {
   return (Gender) genderRNG( ANIMAL_FARM_RNG ) ;
}
