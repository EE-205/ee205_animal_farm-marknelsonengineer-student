///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Comprehensive test of the Animal class
///
/// @file   test_Animal.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
/// @NOLINTBEGIN

#define BOOST_TEST_MODULE Animal Farm Test Suite  /// In only one cpp file (by convention, the first file in alphabetical order)
#include <boost/test/unit_test.hpp>

#include <boost/test/tools/output_test_stream.hpp>

#include <string>
#include <stdexcept>

#include "../src/Animal/Animal.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Animal )

   // To instantiate Animal, we need a class that defines the pure virtual speak() method
   class AnimalTest : public Animal {
   public:
      AnimalTest() : Animal( 10, "Boo", "Boo Boo" ) {};
      AnimalTest( Gender newGender,  Weight::t_weight newWeight, Weight::t_weight newMaxWeight, const std::string& newClassification, const std::string& newSpecies ) : Animal( newGender, newWeight, newMaxWeight, newClassification, newSpecies ) {};

      std::string_view speak() const noexcept override {
         return "Test speak()"sv;
      }

      std::string_view getName() const noexcept override {
         return "Test getName()"sv;
      }
   };


   BOOST_AUTO_TEST_CASE( test_Animal_Min_Constructor ) {
      AnimalTest anAnimal;

      BOOST_CHECK_EQUAL( anAnimal.getKingdom(), "Animalia" );
      BOOST_CHECK_EQUAL( anAnimal.getClassification(), "Boo" );
      BOOST_CHECK_EQUAL( anAnimal.getSpecies(), "Boo Boo" );
      BOOST_CHECK_EQUAL( anAnimal.getGender(), Gender::UNKNOWN_GENDER );
      BOOST_CHECK_EQUAL( anAnimal.getWeight(), Weight::UNKNOWN_WEIGHT );
      BOOST_CHECK_THROW( anAnimal.setWeight( -1/1024 ), out_of_range );
      BOOST_CHECK_THROW( anAnimal.setWeight( 0 ), out_of_range );
      anAnimal.setWeight( 1.0/1024 );
      BOOST_CHECK_EQUAL( anAnimal.getWeight(), 1.0/1024 );
      anAnimal.setWeight( 10 );
      BOOST_CHECK_EQUAL( anAnimal.getWeight(), 10 );
      BOOST_CHECK_THROW( anAnimal.setWeight( 10.0001 ), out_of_range );
      #ifdef DEBUG
         // anAnimal.dump();
      #endif
      BOOST_CHECK_EQUAL( anAnimal.speak(), "Test speak()" );
      BOOST_CHECK_EQUAL( anAnimal.getName(), "Test getName()" );
      string infoString;
      BOOST_CHECK_NO_THROW( infoString = anAnimal.info() );
      cout << infoString << endl;
      BOOST_CHECK_NE( infoString.find( "AnimalTest "), string::npos );
      BOOST_CHECK_NE( infoString.find( "Boo Boo"), string::npos );
      BOOST_CHECK_NE( infoString.find( "Test getName() "), string::npos );
      BOOST_CHECK_NE( infoString.find( "Test speak()"), string::npos );
      BOOST_CHECK_EQUAL( anAnimal.validate(), true );
   }

   BOOST_AUTO_TEST_CASE( test_Animal_Max_Constructor ) {
      AnimalTest anAnimal( Gender::FEMALE, 5, 10, "Boo", "Boo Boo" );
      BOOST_CHECK_EQUAL( anAnimal.getKingdom(), "Animalia" );
      BOOST_CHECK_EQUAL( anAnimal.getClassification(), "Boo" );
      BOOST_CHECK_EQUAL( anAnimal.getSpecies(), "Boo Boo" );
      BOOST_CHECK_EQUAL( anAnimal.getGender(), Gender::FEMALE );
      BOOST_CHECK_EQUAL( anAnimal.getWeight(), 5.0 );
      #ifdef DEBUG
         // anAnimal.dump();
      #endif
      BOOST_CHECK_EQUAL( anAnimal.validate(), true );
   }

/*
   // This test exercises the non-Cat animal classes like Dog, et. al.
   BOOST_AUTO_TEST_CASE( test_Animal_Factory ) {
      for( int i = 0 ; i < 500 ; i++ ) {
         Animal& anAnimal = AnimalFactory::newRandomAnimal();
         BOOST_CHECK_EQUAL( anAnimal.validate(), true );
         BOOST_CHECK_EQUAL( anAnimal.speak().empty(), false );
         BOOST_CHECK_EQUAL( anAnimal.info().empty(), false );
      }
   }
*/

BOOST_AUTO_TEST_SUITE_END()
/// @NOLINTEND
