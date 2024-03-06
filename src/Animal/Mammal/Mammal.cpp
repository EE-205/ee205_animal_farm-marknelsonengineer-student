///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Mammals have more fun
///
/// @file   Mammal.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <string>

#include "../../config.h"
#include "Mammal.h"

using namespace std;


Mammal::Mammal( const Weight::t_weight newMaxWeight
              , const std::string_view newSpecies )
              : Animal( newMaxWeight, CLASSIFICATION_NAME, newSpecies )  // Delegating constructor
   {}  // Nothing else to do


Mammal::Mammal( const Color            newColor
              , const Gender           newGender
              , const Weight::t_weight newWeight
              , const Weight::t_weight newMaxWeight
              , const std::string_view newSpecies )
              : Animal( newGender, newWeight, newMaxWeight, CLASSIFICATION_NAME, newSpecies )  // Delegating constructor
              , color { newColor }  // Member initializer list
   {}  // Nothing else to do


void Mammal::dump() const noexcept {
   assert( validate() ) ;

   Animal::dump() ;

   FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << color << endl ;
}
