///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Comprehensive test of the Trim class
///
/// @file   test_Trim.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
/// @NOLINTBEGIN

#include <boost/test/unit_test.hpp>

#include "../src/Utility/Trim.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Trim )

   BOOST_AUTO_TEST_CASE( test_Trim_Left ) {
      BOOST_CHECK_EQUAL( trim_left( "" ), "" );
      BOOST_CHECK_EQUAL( trim_left( "A" ), "A" );
      BOOST_CHECK_EQUAL( trim_left( "AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim_left( "ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_left( " " ), "" );
      BOOST_CHECK_EQUAL( trim_left( " A" ), "A" );
      BOOST_CHECK_EQUAL( trim_left( " AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim_left( " ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_left( "\t " ), "" );
      BOOST_CHECK_EQUAL( trim_left( "\t A" ), "A" );
      BOOST_CHECK_EQUAL( trim_left( "\t AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim_left( "\t ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_left( " \t\f\n\r\v " ), "" );
      BOOST_CHECK_EQUAL( trim_left( " \t\f\n\r\v A  " ), "A  " );
      BOOST_CHECK_EQUAL( trim_left( " \t\f\n\r\v AB  " ), "AB  " );
      BOOST_CHECK_EQUAL( trim_left( " \t\f\n\r\v ABC  " ), "ABC  " );
   }

   BOOST_AUTO_TEST_CASE( test_Trim_Right ) {
      BOOST_CHECK_EQUAL( trim_right( "" ), "" );
      BOOST_CHECK_EQUAL( trim_right( "A" ), "A" );
      BOOST_CHECK_EQUAL( trim_right( "AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim_right( "ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_right( " " ), "" );
      BOOST_CHECK_EQUAL( trim_right( "A " ), "A" );
      BOOST_CHECK_EQUAL( trim_right( "AB " ), "AB" );
      BOOST_CHECK_EQUAL( trim_right( "ABC " ), "ABC" );

      BOOST_CHECK_EQUAL( trim_right( " \t" ), "" );
      BOOST_CHECK_EQUAL( trim_right( "A \t" ), "A" );
      BOOST_CHECK_EQUAL( trim_right( "AB \t" ), "AB" );
      BOOST_CHECK_EQUAL( trim_right( "ABC \t" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_right( " \t\f\n\r\v " ), "" );
      BOOST_CHECK_EQUAL( trim_right( " A \t\f\n\r\v " ), " A" );
      BOOST_CHECK_EQUAL( trim_right( " AB \t\f\n\r\v " ), " AB" );
      BOOST_CHECK_EQUAL( trim_right( " ABC \t\f\n\r\v " ), " ABC" );
   }


   BOOST_AUTO_TEST_CASE( test_Trim ) {
      BOOST_CHECK_EQUAL(trim_edges(""), "" );
      BOOST_CHECK_EQUAL(trim_edges("A"), "A" );
      BOOST_CHECK_EQUAL(trim_edges("AB"), "AB" );
      BOOST_CHECK_EQUAL(trim_edges("ABC"), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges(" "), "" );
      BOOST_CHECK_EQUAL(trim_edges(" A"), "A" );
      BOOST_CHECK_EQUAL(trim_edges(" AB"), "AB" );
      BOOST_CHECK_EQUAL(trim_edges(" ABC"), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges("\t "), "" );
      BOOST_CHECK_EQUAL(trim_edges("\t A"), "A" );
      BOOST_CHECK_EQUAL(trim_edges("\t AB"), "AB" );
      BOOST_CHECK_EQUAL(trim_edges("\t ABC"), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges(" \t\f\n\r\v "), "" );
      BOOST_CHECK_EQUAL(trim_edges(" \t\f\n\r\v A"), "A" );
      BOOST_CHECK_EQUAL(trim_edges(" \t\f\n\r\v AB"), "AB" );
      BOOST_CHECK_EQUAL(trim_edges(" \t\f\n\r\v ABC"), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges("A "), "A" );
      BOOST_CHECK_EQUAL(trim_edges("AB "), "AB" );
      BOOST_CHECK_EQUAL(trim_edges("ABC "), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges("A \t"), "A" );
      BOOST_CHECK_EQUAL(trim_edges("AB \t"), "AB" );
      BOOST_CHECK_EQUAL(trim_edges("ABC \t"), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges("A \t\f\n\r\v "), "A" );
      BOOST_CHECK_EQUAL(trim_edges("AB \t\f\n\r\v "), "AB" );
      BOOST_CHECK_EQUAL(trim_edges("ABC \t\f\n\r\v "), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges(" A "), "A" );
      BOOST_CHECK_EQUAL(trim_edges(" AB "), "AB" );
      BOOST_CHECK_EQUAL(trim_edges(" ABC "), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges("\t A \t"), "A" );
      BOOST_CHECK_EQUAL(trim_edges("\t AB \t"), "AB" );
      BOOST_CHECK_EQUAL(trim_edges("\t ABC \t"), "ABC" );

      BOOST_CHECK_EQUAL(trim_edges(" \t\f\n\r\v A \t\f\n\r\v "), "A" );
      BOOST_CHECK_EQUAL(trim_edges(" \t\f\n\r\v AB \t\f\n\r\v "), "AB" );
      BOOST_CHECK_EQUAL(trim_edges(" \t\f\n\r\v ABC \t\f\n\r\v "), "ABC" );
   }

BOOST_AUTO_TEST_SUITE_END()
/// @NOLINTEND
