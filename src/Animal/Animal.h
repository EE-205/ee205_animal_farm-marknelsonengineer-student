///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Where the Wild Things Are
///
/// @file   Animal.h
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "../Utility/Gender.h"
#include "../Utility/Weight.h"
#include "../config.h"


/// A class that encompasses all Animals on the farm.
///
/// This class should be the parent class of all of the Animals on the farm.
/// It contains 1 abstract method `speak()` that each Animal must implement
/// before it can be instantiated.
///
/// Animals understand things I don't know -- they know languages not made of words
///
/// @see https://en.wikipedia.org/wiki/Animal
/// @see https://en.wikipedia.org/wiki/Taxonomy_(biology)
class Animal {
public:   //////////////////////// Constants ///////////////////////////////////

   /// The scientific name of the Animal Kingdom.
   static const constexpr std::string_view KINGDOM_NAME { "Animalia" } ;

private:  ///////////////////// Member Variables //////////////////////////////
   std::string species;                     ///< The Animal's biological species
   std::string classification;              ///< The Animal's biological classification
   Gender gender = Gender::UNKNOWN_GENDER;  ///< The Animal's gender.  Scientifically, not all Animals have a gender, but all Animals on Animal Farm have a gender.
   Weight weight;                           ///< The weight of the Animal

public:   /////////////////////// Constructors ////////////////////////////////
   /// Create an Animal with the *minimum* required fields
   ///
   /// @param newMaxWeight Must be a valid weight per Weight::isWeightValid
   /// @param newClassification Must be a valid name per Name::validateName
   /// @param newSpecies Must be a valid name per Name::validateName
   Animal( const Weight::t_weight newMaxWeight
          ,const std::string_view newClassification
          ,const std::string_view newSpecies
          );

   /// Create an Animal, populating *all* of the member variables
   ///
   /// @param newGender The Gender of the Animal
   /// @param newWeight Must be a valid weight per Weight::isWeightValid
   /// @param newMaxWeight Must be a valid weight per Weight::isWeightValid
   /// @param newClassification Must be a valid name per Name::validateName
   /// @param newSpecies Must be a valid name per Name::validateName
   Animal( const Gender           newGender
          ,const Weight::t_weight newWeight
          ,const Weight::t_weight newMaxWeight
          ,const std::string_view newClassification
          ,const std::string_view newSpecies
          );

public:   ///////////////////// Getters & Setters /////////////////////////////

   /// Get the kingdom, which is `Animalia`
   ///
   /// @return `Animalia`
   std::string_view getKingdom()        const noexcept;

   /// Get the classification
   ///
   /// @return The classification
   std::string_view getClassification() const noexcept;

   /// Get the species
   ///
   /// @return The species
   std::string_view getSpecies()        const noexcept;

   /// Get The Animal's Gender
   ///
   /// @return The Animal's Gender
   Gender           getGender()         const noexcept;

   /// Get the Animal's Weight
   ///
   /// @return The Animal's Weight
   Weight::t_weight getWeight() const noexcept;

   /// Set the Animal's Weight
   ///
   /// @param newWeight The new Weight for the Animal
   void             setWeight( const Weight::t_weight newWeight );


protected:  ////////////////////// Protected Methods ///////////////////////////

   /// Set the Animal's Gender
   ///
   /// This is protected as users of this class should not be able to arbitrarily
   /// reassign the gender of an Animal.
   ///
   /// @param newGender The new Gender for the Animal
   void setGender( const Gender newGender );


public:   ////////////////////////// Abstract Methods //////////////////////////
   /// Ask the Animal to say something.  This method is virtual and abstract.
   ///
   /// @return The thing the Animal says
   virtual std::string_view speak() const noexcept = 0;

   /// Get the Animal's Name
   ///
   /// @return The Animal's Name
   virtual std::string_view getName() const noexcept = 0;


public:   /////////////////////////// Public Methods ///////////////////////////

   /// Return one-line of information about this Animal
   ///
   /// @return A brief, one-line description of this Animal
   std::string info()  const noexcept;

   /// Output the contents of this object (and its parents, if any)
   virtual void dump() const noexcept;

   /// Check to see if the Animal object is valid
   ///
   /// If it's not, print the reason why, but don't throw an exception
   ///
   /// @return `true` if the object is valid... `false` if not
   bool validate()     const noexcept;


public:  ///////////////////////// Operator Overrides //////////////////////////
   /// Compare two Animals with `<`
   ///
   /// @param rhs_animal The Animal we are being compared with
   /// @return `true` if we are "less than" rhs_animal
   bool operator< ( const Animal& rhs_animal ) const;

   /// Compare two Animals with `<=`
   ///
   /// @param rhs_animal The Animal we are being compared with
   /// @return `true` if we are "less than or equal to" rhs_animal
   bool operator<=( const Animal& rhs_animal ) const;

   /// Compare two Animals with `>`
   ///
   /// @param rhs_animal The Animal we are being compared with
   /// @return `true` if we are "greater than" rhs_animal
   bool operator> ( const Animal& rhs_animal ) const;

   /// Compare two Animals with `>=`
   ///
   /// @param rhs_animal The Animal we are being compared with
   /// @return `true` if we are "greater than or equal to" rhs_animal
   bool operator>=( const Animal& rhs_animal ) const;

//   bool operator< ( const Node& rhs_node ) const override;  ///< Override the virtual `<` comparison between two Nodes
//   bool operator<=( const Node& rhs_node ) const override;  ///< Override the virtual `<=` comparison between two Nodes
//   bool operator> ( const Node& rhs_node ) const override;  ///< Override the virtual `>` comparison between two Nodes
//   bool operator>=( const Node& rhs_node ) const override;  ///< Override the virtual `>=` comparison between two Nodes
};
