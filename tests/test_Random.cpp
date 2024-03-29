///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Comprehensive test of the Random class
///
/// @file   test_Random.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
/// @NOLINTBEGIN

#include <boost/test/unit_test.hpp>

#include <boost/test/tools/output_test_stream.hpp>

#include <iostream>
#include <stdexcept>

#include "../src/Utility/Random.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Random )

   BOOST_AUTO_TEST_CASE( test_Random ) {
      mersenneTwisterPRNG.seed( 0 );  // Reset the seed
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 2357136044 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 2546248239 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 3071714933 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 3626093760 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 2588848963 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 3684848379 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 2340255427 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 3638918503 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 1819583497 );
      BOOST_CHECK_EQUAL( mersenneTwisterPRNG(), 2678185683 );

      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
      BOOST_CHECK_NO_THROW( trueRNG() );
   }

BOOST_AUTO_TEST_SUITE_END()
/// @NOLINTEND
