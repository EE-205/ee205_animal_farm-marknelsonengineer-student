///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Random number utilities
///
/// @file   Random.h
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <random>

/// Create 2 Random Number Generators (RNGs):
///    1. A true RNG           - Truly random
///    2. A pseudo-RNG or PRNG - Seems random, but the results are consistent
extern std::random_device trueRNG;          ///< This is a real random number generator (if available)
extern std::mt19937 mersenneTwisterPRNG;    ///< This is a seeded pseudorandom number generator
