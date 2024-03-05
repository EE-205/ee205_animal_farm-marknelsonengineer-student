///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Random number utilities
///
/// @file   Random.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////

#include "Random.h"

using namespace std;

/// This is a real random number generator (if available)
std::random_device trueRNG;

/// This is a seeded pseudorandom number generator
/// @returns
std::mt19937 mersenneTwisterPRNG( 0 );
