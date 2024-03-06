///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// A utility class for managing names on the farm
///
/// @file   Name.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////

#include <cassert>    // For assert
#include <ctype.h>    // For isspace
#include <fstream>    // For ifstream
#include <iostream>   // For cout
#include <limits>     // For numeric_limits
#include <stdexcept>  // For runtime_error

#include "Name.h"       // For obvious reasons

#include "../config.h"  // For nameRNG
#include "Trim.h"

using namespace std;


Name::serial_t Name::maxSerial = numeric_limits<Name::serial_t>::max();


Name::Name( string_view newFilename )
   : nameType { FROM_FILE }    // Member initializer list
   , fileName { newFilename }  // Member initializer list
   {
   reset();
}


Name::Name( string_view newSerialPrefix, string_view newSerialSuffix )
   : nameType { FROM_SERIAL }         // Member initializer list
   , serialPrefix { newSerialPrefix } // Member initializer list
   , serialSuffix { newSerialSuffix } // Member initializer list
   {
   reset();
}


std::string Name::getNextName() {
   if( nameType == FROM_FILE ) {
      if( names.empty() ) {
         reset();
      }

      /// Remove names as they get used
      uniform_int_distribution<>  nameRNG( 0, (int) names.size()-1 );
      const int nameIndex = nameRNG( ANIMAL_FARM_RNG );
      string theName = names[nameIndex];
      names.erase( names.begin()+nameIndex );

      return theName;
   }

   if( nameType == FROM_SERIAL ) {
      return serialPrefix + to_string(serial++) + serialSuffix;
   }

   assert( false );
   return string(); // Should never get here.
}


/// This method should be used with care... several Animal Farm
/// data structures (like BinarySearchTree) can't handle Nodes with the same name.
///
/// This has been added to facilitate unit testing.
void Name::reset() {
   if( nameType == FROM_FILE ) {
      names.clear();

      #ifdef DEBUG
         cout << "Loading names from [" << fileName << "]:  " ;
      #endif

      ifstream file( fileName, ios::in );
      if( !file.is_open() ) {
         throw( runtime_error( "Unable to open [" + fileName + "] for reading" ));
      }

      string line;
      while( getline( file, line )) {
         line = trim_edges( line );
         if( !Name::validateName( line ) ) {  /// As the names are loaded from the file, verify that each name is valid with validateName()
            continue;
         }
         names.push_back( std::move( line ));  // Use move semantics
      }

      #ifdef DEBUG
         cout << "Loaded " << to_string( names.size() ) << " names" << endl;
      #endif
   }

   if( nameType == FROM_SERIAL ) {
      serial = 0;
   }
}


/// @return If the nameType is:
///
///   - #FROM_FILE: Return the size of the names vector.
///   - #FROM_SERIAL: Return `max(serial_t) - serial` (the number of serial numbers left, which should be a very large number)
Name::serial_t Name::remainingNames() noexcept {
   switch( nameType ) {
      case FROM_FILE: return names.size();
      case FROM_SERIAL: return maxSerial - serial;
   }

   assert( false );
   return 0;  // Should never get here
}


bool Name::validateName( const std::string_view newName ) {

   if( !validateNotEmpty( newName )) { return false; }

   if( !validateTrimmed( newName )) { return false; }

   if( !validateStartsWithAlpha( newName )) { return false; }

   if( !validateNoSpecialChars( newName )) { return false; }

   return true;
}


/// @API{ string_view.empty, https://en.cppreference.com/w/cpp/string/basic_string_view/empty }
/// @hidecallergraph @hidecallgraph
bool Name::validateNotEmpty( const string_view newName ) {
   if( newName.empty() ) {
      cout << PROGRAM_NAME << ": The name should not be empty" << endl;
      return false;
   }

   return true;
}


/// @API{ isspace, https://en.cppreference.com/w/cpp/string/byte/isspace }
/// @hidecallergraph @hidecallgraph
bool Name::validateTrimmed( const string_view newName ) {
   if( newName.empty() ) {
      return true;  /// Empty strings are considered trimmed
   }

   if( isspace( *newName.begin() ) || isspace( *(newName.end()-1) ) ) {
      ///   If not valid, print `The name should be trimmed for whitespace` and return `false`
      cout << PROGRAM_NAME << ": The name should be trimmed for whitespace" << endl;
      return false;
   }

   return true;
}

/// @API{ isalpha, https://en.cppreference.com/w/cpp/string/byte/isalpha }
/// @hidecallergraph @hidecallgraph
bool Name::validateStartsWithAlpha( const string_view newName ) {
   if( !isalpha( *newName.begin() ) ) {
      ///   If not valid, print `The name should not start with a number or -` and return `false`
      cout << PROGRAM_NAME << ": The name should not start with a number or -" << endl;
      return false;
   }

   return true;
}


/// @API{ isalnum, https://en.cppreference.com/w/cpp/string/byte/isalnum }
/// @hidecallergraph @hidecallgraph
bool Name::validateNoSpecialChars( const string_view newName ) {
   for( auto i = newName.begin() ; i != newName.end() ; i++ ) {
      if( isalnum( *i ) || *i == ' ' || *i == '-' ) {
         continue;
      }

      // *i is not a valid character...
      // If not valid, print `The name should not have any special characters` and return `false`
      cout << PROGRAM_NAME << ": The name should not have any special characters" << endl;
      return false;
   }

   return true;
}
