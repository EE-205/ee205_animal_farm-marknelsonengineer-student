///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Mammals have more fun
///
/// @file   Mammal.h
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../../Utility/Color.h"
#include "../Animal.h"


/// Mammals have more fun.
///
/// Mammals don't have anything to validate.
/// Comparing two Mammals is done at the Animal level using Classification.
class Mammal : public Animal {
public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view CLASSIFICATION_NAME { "Mammalia" };  ///< The scientific name for Mammals

protected:  ///////////////////////// Member Variables /////////////////////////
   Color color = Color::UNKNOWN_COLOR;  ///< The primary color of the Mammal

public:   /////////////////////// Constructors ////////////////////////////////
   /// Create a Mammal with the *minimum* required fields
   ///
   /// @param newMaxWeight Must be a valid weight per Weight::isWeightValid
   /// @param newSpecies   Must be a valid name per Name::validateName
   Mammal( const Weight::t_weight newMaxWeight
          ,const std::string_view newSpecies
   );

   /// Create a Mammal, populating *all* of the member variables
   ///
   /// @param newColor     The Mammal's primary color
   /// @param newGender    The Gender of the Animal
   /// @param newWeight    Must be a valid weight per Weight::isWeightValid
   /// @param newMaxWeight Must be a valid weight per Weight::isWeightValid
   /// @param newSpecies   Must be a valid name per Name::validateName
   Mammal( const Color            newColor
          ,const Gender           newGender
          ,const Weight::t_weight newWeight
          ,const Weight::t_weight newMaxWeight
          ,const std::string_view newSpecies
   );

public:  ////////////////////////// Getters & Setters //////////////////////////

   /// Get the Color of the Mammal
   ///
   /// @return The Color of the Mammal
   Color getColor() const noexcept { return color; }

   /// Set the color
   ///
   /// @param newColor The new Color for the Mammal
   void  setColor( const Color newColor ) noexcept { color = newColor; }

public:  /////////////////////////// Public Methods ////////////////////////////

   /// Output the contents of this object (and its parents)
   ///
   /// #### Sample Output
   /**@verbatim
   ======================================================
   Mammal              color               Unknown color
   @endverbatim */

   void dump() const noexcept override;
};
