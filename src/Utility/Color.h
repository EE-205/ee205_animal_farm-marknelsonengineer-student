///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Color class enumeration
///
/// @file Color.h
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <string>

#include "../config.h"

/// Color class enumeration
enum class Color {
   UNKNOWN_COLOR=0  ///< The color is not known
  ,BLACK            ///< All black
  ,BROWN            ///< All brown
  ,WHITE            ///< White
  ,RED              ///< Red
  ,BLUE             ///< Blue
  ,GREEN            ///< Green
  ,GINGER           ///< Ginger
  ,CREAM            ///< Cream
  ,CINNAMON         ///< Cinnamon
  ,CALICO           ///< The calico cat is most commonly thought of as being 25% to 75% white with large orange and black patches; however, they may have other colors in their patterns.
} ;


/// Get a random Color
///
/// @return A random Color
extern Color newRandomColor();


/// Output Color as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_Color  The Color to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
///
/// @return `Unknown color`, `Black` or `Blue`.
inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ) {
   switch( rhs_Color ) {
      case Color::UNKNOWN_COLOR:
         lhs_stream << "Unknown color";
         break;
      case Color::BLACK:
         lhs_stream << "Black";
         break;
      case Color::BROWN:
         lhs_stream << "Brown";
         break;
      case Color::WHITE:
         lhs_stream << "White";
         break;
      case Color::RED:
         lhs_stream << "Red";
         break;
      case Color::BLUE:
         lhs_stream << "Blue";
         break;
      case Color::GREEN:
         lhs_stream << "Green";
         break;
      case Color::GINGER:
         lhs_stream << "Ginger";
         break;
      case Color::CREAM:
         lhs_stream << "Cream";
         break;
      case Color::CINNAMON:
         lhs_stream << "Cinnamon";
         break;
      case Color::CALICO:
         lhs_stream << "Calico";
         break;
      default:
         /// @throw out_of_range If the enum is not mapped to a string.
         throw std::out_of_range( PROGRAM_NAME ": Color not mapped to a string" );
   }

   return lhs_stream;
}
