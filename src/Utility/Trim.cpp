///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// General string-trimming functions
///
/// There are *so many ways* to implement string trimming...
///
///   - Maximize clarity and understandability
///   - Maximize efficiency
///   - Use an advanced C++ feature
///
/// This implementation is designed to try to balance all three.
///
/// @file   Trim.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <string>  // For string_view

#include "Trim.h"  // For obvious reasons

using namespace std;


/// Get the first non-whitespace character starting from the left.
///
/// @API{ isspace, https://en.cppreference.com/w/cpp/string/byte/isspace }
///
/// This function is static... so it can be private to Trim.cpp
///
/// @param inString The string to analyze
///
/// @return The index to the first character that's not a "space" according to isspace
static size_t get_left_start_char( const string_view inString ) noexcept {
   size_t i = 0;
   while( i < inString.size() && isspace( inString[i] ) ) {
      i++;
   }

   return i;
}


/// Get the last non-whitespace character in the string
///
/// @API{ isspace, https://en.cppreference.com/w/cpp/string/byte/isspace }
///
/// This function is static... so it can be private to Trim.cpp
///
/// @param inString The string to analyze
///
/// @return The index to the last character that's not a "space" according to isspace
static size_t get_right_start_char( const string_view inString ) noexcept {
   size_t i = inString.size();
   while( i > 0 ) {
      if( isspace( inString[i-1] )) {
         i--;
      } else {
         break;
      }
   }

   return i;
}


/// Remove all leading whitespace from `inString`
///
/// @API{ isspace, https://en.cppreference.com/w/cpp/string/byte/isspace }
/// @API{ substr, https://en.cppreference.com/w/cpp/string/basic_string/substr }
///
/// @param inString The string to trim
///
/// @return A string_view of a left-trimmed string
string_view trim_left( const string_view inString ) noexcept {
   return inString.substr( get_left_start_char( inString ), inString.size() );
}


/// Remove all trailing whitespace from `inString`
///
/// @API{ isspace, https://en.cppreference.com/w/cpp/string/byte/isspace }
/// @API{ substr, https://en.cppreference.com/w/cpp/string/basic_string/substr }
///
/// @param inString The string to trim
///
/// @return A string_view of a right-trimmed string
std::string_view trim_right( const std::string_view inString ) noexcept {

   return( inString.substr( 0, get_right_start_char( inString ) ) );
}

/// Trim whitespace from both the leading and trailing edges but
/// do not modify the interior of the string
///
/// @param inString The string to trim
///
/// @return A string_view of a left & right-trimmed string
std::string_view trim_edges( const std::string_view inString ) noexcept {
   const size_t left_start_char = get_left_start_char( inString );
   const size_t right_start_char = get_right_start_char( inString );

   return( inString.substr( left_start_char, right_start_char - left_start_char ) );
}
