///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  ee205_animal_farm - EE 205 - Spr 2024
//
/// Random number utilities
///
/// @file   Animal.h
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////

#include "Random.h"

using namespace std;

std::random_device trueRNG;          ///< This is a real random number generator (if available)
std::mt19937 mersenneTwisterPRNG(0); ///< This is a seeded pseudorandom number generator
