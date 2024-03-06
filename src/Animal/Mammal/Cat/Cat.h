///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// All things Cat
///
/// @file   Cat.h
/// @author Mark Nelson <marknels@hawaii.edu>
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "../../../Utility/Name.h"
#include "../../../config.h"
#include "../Mammal.h"

/// Felis Catus
///
class Cat : public Mammal {
public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view SPECIES_NAME { "Felis Catus" };  ///< The scientific name for a Cat
   static const constexpr Weight::t_weight MAX_WEIGHT { 40 };  ///< The maximum weight a Cat

public:  ////////////////////////// Static Members /////////////////////////////
   static Name names;                ///< A list of potential Cat names

protected:  ///////////////////////// Member Variables /////////////////////////
   std::string name ;                ///< The name of the Cat
   bool        isCatFixed = false ;  ///< `true` if the Cat is fixed/neutered

public:  //////////////////////////// Constructors /////////////////////////////

   /// Create a Cat with the minimum fields necessary to have a valid Cat
   ///
   /// This constructor is declared to be `explicit`, so you can't do silly
   /// things like `Cat newCat = "Bella";` ... instead, you need to construct
   /// a Cat properly like `Cat newCat( "Bella" );`
   ///
   /// @param newName Must be a valid name per Name::validateName
   explicit Cat( const std::string_view newName ) ;

   /// Create a Cat, populating *all* of the member variables
   ///
   /// @param newName    The Name of the Cat
   /// @param newColor   The Color of the Cat
   /// @param newIsFixed Is the Cat neutered
   /// @param newGender  The Cat's Gender
   /// @param newWeight  The Cat's Weight
   Cat( const std::string_view newName
       ,const Color            newColor
       ,const bool             newIsFixed
       ,const Gender           newGender
       ,const Weight::t_weight newWeight
   );

   /// Delete a Cat object
   virtual ~Cat();

public:  ////////////////////////// Getters & Setters //////////////////////////

   /// Get the Cat's name
   ///
   /// @return The Cat's name
   std::string_view getName() const noexcept override;


   /// Set the Cat's name
   ///
   /// @param newName The Cat's new name.  It must be valid per Name::validateName.
   void setName( const std::string_view newName );

   /// Return `true` if the Cat is fixed/neutered
   ///
   /// @return `true` if the Cat is fixed/neutered
   bool isFixed() const noexcept ;

   /// Spay or neuter the Cat
   void fixCat() noexcept ;


public:  /////////////////////////// Public Methods ////////////////////////////

   /// Say `Meow`
   ///
   /// @return `Meow`, of course
   std::string_view speak() const noexcept override;

   /// Output the contents of this object (and its parents)
   void dump() const noexcept override;

   /// Check to see if the Cat object is valid
   ///
   /// @return `true` if the cat is valid... `false` if not
   bool validate() const noexcept override;

public:  /////////////////////// Static Public Methods /////////////////////////
   // Static methods are `const` by default

   /// Generate a new, random Animal (Cat)
   /// @pattern Factory Method
   ///
   /// #### Internal
   /// This function will use `new` to create a random Cat (Animal) on the heap.
   /// Be sure to `delete` the Animal when it's no longer needed
   ///
   /// @return A new, random Animal (Cat)
   static Animal& newRandomAnimal() ;


   /// Generate a new, random Cat
   ///
   /// @pattern Factory Method
   ///
   /// #### Internal
   /// This function will use `new` to create a random Cat on the heap.
   /// Be sure to `delete` the Cat when it's no longer needed
   ///
   /// @return A new, random Cat
   static Cat& newRandomCat() ;


public:  ///////////////////////// Operator Overrides //////////////////////////


   /// Compare two Cats with `<`
   ///
   /// @anchor Cat_comparison
   /// The `this` member is the left side of the operator.
   ///
   /// @param rhs_cat `rhs` stands for Right Hand Side and is the right side of the operator.
   ///
   /// @return `true` if `this` < `rhs_cat`
   bool operator< ( const Cat& rhs_cat ) const;

   /// Compare two Cats with `<=`
   ///
   /// @param rhs_cat `rhs` stands for Right Hand Side and is the right side of the operator.
   /// @return `true` if `this` <= `rhs_cat`
   bool operator<=( const Cat& rhs_cat ) const;

   /// Compare two Cats with `>`
   ///
   /// @param rhs_cat `rhs` stands for Right Hand Side and is the right side of the operator.
   /// @return `true` if `this` >= `rhs_cat`
   bool operator> ( const Cat& rhs_cat ) const;

   /// Compare two Cats with `>=`
   ///
   /// @param rhs_cat `rhs` stands for Right Hand Side and is the right side of the operator.
   /// @return `true` if `this` >= `rhs_cat`
   bool operator>=( const Cat& rhs_cat ) const;

// bool operator< ( const Node& rhs_node ) const override;  ///< Override the virtual `<` comparison between two Nodes
// bool operator> ( const Node& rhs_node ) const override;  ///< Override the virtual `>` comparison between two Nodes
// bool operator<=( const Node& rhs_node ) const override;  ///< Override the virtual `<=` comparison between two Nodes
// bool operator>=( const Node& rhs_node ) const override;  ///< Override the virtual `>=` comparison between two Nodes
};
