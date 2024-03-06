///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// Every Animal has a Weight in the world.
///
/// @file   Weight.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <ostream>
#include <string>

using namespace std::string_view_literals;


/// Every Animal has a Weight in the world.
///
/// C++ maintains Weight as a `float` (#t_weight), however, weights in the physical world
/// have certain constraints (i.e. you can't have a negative #weight -- and/or you
/// *may* have a maximum weight.)
///
/// By default, the weight is #UNKNOWN_WEIGHT (-1).  Once it's known, it can never
/// be un-known.
///
/// If the Weight has a maximum weight, then #weight must be `<=` it.  Also,
/// the #weight can never be `<= 0`.  #maxWeight is set in a constructor
/// and can not be changed.
///
/// Weight can can be expressed in different units of measure (#UnitOfWeight).
/// The Weight's unit of measure is set in a constructor and can not be changed.
/// It defaults to #POUND.  Other units of measure are the #KILO and #SLUG.
///
/// We are not implementing a complete numeric class, which would have
/// overrides for:  `*=  /=  %=  ++  --  +  -  *  /  >=  >  <=  !=` and `<=>`
///
/// @see https://en.wikipedia.org/wiki/Pound_(mass)
/// @see https://en.wikipedia.org/wiki/Kilogram
/// @see https://en.wikipedia.org/wiki/Slug_(unit)
///
class Weight {
public:  //////////////// Enumerations & Type Definitions //////////////////////

   /// A unit of measure for Weight
   enum UnitOfWeight { POUND  ///< @see https://en.wikipedia.org/wiki/Pound_(mass)
                      ,KILO   ///< @see https://en.wikipedia.org/wiki/Kilogram
                      ,SLUG   ///< @see https://en.wikipedia.org/wiki/Slug_(unit)
                     };

   /// The native datatype of the Weight class
   typedef float t_weight;

public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr t_weight UNKNOWN_WEIGHT = -1;    ///< When #weight is not known, return this.  To set an #UNKNOWN_WEIGHT, send this.

   static const constexpr t_weight KILOS_IN_A_POUND = 0.453592;   ///< The number of kilos in a #POUND.  @see https://en.wikipedia.org/wiki/Kilogram
   static const constexpr t_weight SLUGS_IN_A_POUND = 0.031081 ;  ///< The number of slugs in a #POUND.  @see https://en.wikipedia.org/wiki/Slug_(unit)

   static const constexpr std::string_view POUND_LABEL { "Pound"sv };  ///< Unit of measure for the #POUND.  @see https://en.wikipedia.org/wiki/Pound_(mass)
   static const constexpr std::string_view KILO_LABEL  { "Kilo"sv };   ///< Unit of measure for the #KILO.  @see https://en.wikipedia.org/wiki/Kilogram
   static const constexpr std::string_view SLUG_LABEL  { "Slug"sv };   ///< Unit of measure for the #SLUG.  @see https://en.wikipedia.org/wiki/Slug_(unit)

private:  ////////////////////// Member Variables //////////////////////////////
   // The order the member variables is important because it determines the order they are constructed (and known)
   enum UnitOfWeight unitOfWeight = POUND ;  ///< How the #weight is held and displayed.  Defaults to #POUND.
                                             ///< #UnitOfWeight can only be set when Weight is constructed.

   t_weight maxWeight{} ;   ///< The maximum weight.  The maximum weight can only be set when Weight is constructed.
   bool bHasMax = false ;   ///< `true` if Weight has a maximum weight defined.  Defaults to `false`.

   t_weight weight{} ;      ///< The weight.  It must always be `> 0`.  If #maxWeight is set then it must also be `<=` #maxWeight
   bool bIsKnown = false ;  ///< `true` if #weight is known.  Defaults to `false`.

public:   //////////////////////// Constructors ////////////////////////////////

   /// A default Weight (the #weight is #UNKNOWN_WEIGHT)
   Weight();

   /// A Weight with a #weight
   ///
   /// @param newWeight The #weight
   Weight( t_weight newWeight );

   /// A Weight with a #UnitOfWeight (the #weight is #UNKNOWN_WEIGHT)
   ///
   /// @param newUnitOfWeight The #UnitOfWeight
   Weight( UnitOfWeight newUnitOfWeight );

   /// A Weight with a #weight and #UnitOfWeight
   ///
   /// @param newWeight       The #weight
   /// @param newUnitOfWeight The #UnitOfWeight
   Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight );

   /// A Weight with a #weight and a #maxWeight
   ///
   /// @param newWeight    The #weight
   /// @param newMaxWeight The #maxWeight
   Weight( t_weight newWeight, t_weight newMaxWeight );

   /// A Weight with a #UnitOfWeight and a #maxWeight (the #weight is #UNKNOWN_WEIGHT)
   ///
   /// @param newUnitOfWeight The #UnitOfWeight
   /// @param newMaxWeight    The #maxWeight
   Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );

   /// A fully-qualified Weight with a #weight, #UnitOfWeight and #maxWeight
   ///
   /// @param newWeight       The #weight
   /// @param newUnitOfWeight The #UnitOfWeight
   /// @param newMaxWeight    The #maxWeight
   Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );


public:   /////////////////////////// Getters  /////////////////////////////////

   /// `true` if #weight is known
   ///
   /// @return `true` if #weight is known... `false` if not
   bool  isWeightKnown() const noexcept;

   /// `true` if #maxWeight is set
   ///
   /// @return `true` if #maxWeight is set... `false` if not
   bool  hasMaxWeight() const noexcept;

   /// Get the #weight in the Weight's units
   ///
   /// @return The #weight in the Weight's units
   t_weight getWeight() const noexcept;

   /// Get the #weight in the specified unit
   ///
   /// @param weightUnits The #UnitOfWeight to return
   ///
   /// @return The #weight in the specified unit
   t_weight getWeight( UnitOfWeight weightUnits ) const noexcept;

   /// Get #maxWeight
   ///
   /// @return #maxWeight if it's set or #UNKNOWN_WEIGHT if not
   t_weight getMaxWeight() const noexcept;

   /// Get the #UnitOfWeight for this Weight
   ///
   /// @return The #UnitOfWeight for this Weight
   UnitOfWeight getWeightUnit() const noexcept;


public:   /////////////////////////// Setters  /////////////////////////////////
   /// Set the #weight
   ///
   /// @param newWeight The #weight to set
   void setWeight( t_weight newWeight );

   /// Set the #weight in the specified unit
   ///
   /// @param newWeight   The #weight to set
   /// @param weightUnits The #UnitOfWeight for this #weight
   void setWeight( t_weight newWeight, UnitOfWeight weightUnits );


private:   ///////////////////// Private Methods ///////////////////////////////
   /// Set the #weight in the constructor
   ///
   /// @param newWeight The #weight to set
   void setInitialWeight( t_weight newWeight );

   /// Set #maxWeight in the constructor
   ///
   /// @param newMaxWeight The #maxWeight to set
   void setInitialMaxWeight( t_weight newMaxWeight );


public:   /////////////////////// Static Methods ///////////////////////////////
   // Static methods are `const` by default

   /// Convert a Gram (1/1000 of a #KILO) to #POUND.  This is good for Bird weights.
   ///
   /// @param gram A weight in grams
   /// @return A weight in pounds
   static constexpr t_weight fromGramToPound( t_weight gram )         noexcept { return fromKilogramToPound( (t_weight)( gram / 1000.0 ) ); }

   /// Convert #KILO to #POUND
   ///
   /// @param kilogram A weight in kilograms
   /// @return A weight in pounds
   static constexpr t_weight fromKilogramToPound( t_weight kilogram ) noexcept { return kilogram / KILOS_IN_A_POUND ; }

   /// Convert #POUND to #KILO
   ///
   /// @param pound A weight in pounds
   /// @return A weight in kilograms
   static constexpr t_weight fromPoundToKilogram( t_weight pound )    noexcept { return pound * KILOS_IN_A_POUND ; }

   /// Convert #SLUG to #POUND
   ///
   /// @param slug A weight in slugs
   /// @return A weight in pounds
   static constexpr t_weight fromSlugToPound( t_weight slug )         noexcept { return slug / SLUGS_IN_A_POUND ; }

   /// Convert #POUND to #SLUG
   ///
   /// @param pound A weight in pounds
   /// @return A weight in slugs
   static constexpr t_weight fromPoundToSlug( t_weight pound )        noexcept { return pound * SLUGS_IN_A_POUND ; }


   /// Convert fromWeight in fromUnit to a weight in toUnit
   ///
   /// @param fromWeight The source weight
   /// @param fromUnit   The target weight
   /// @param toUnit     The target unit of measure
   /// @return fromWeight in fromUnit to a weight in toUnit
   static t_weight convertWeight( t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit ) noexcept;


public:   /////////////////////// Public Methods ///////////////////////////////

   /// Check the Weight
   ///
   /// @param checkWeight A weight to check
   /// @return `true` if the Weight is valid... `false` if not
   bool isWeightValid( t_weight checkWeight ) const noexcept;

   /// Check Weight to ensure it's healthy
   ///
   /// @return `true` if the Weight is valid... `false` if not
   bool validate() const noexcept;

   /// Print the Weight class
   void dump() const noexcept;


public:   ////////////////////// Public Overrides //////////////////////////////

   /// Weights are equal when their #weight s are equal
   ///
   /// @param rhs_Weight A weight on the right side of a `==`
   /// @return `true` if the weights are equal
   bool operator==( const Weight& rhs_Weight ) const;


   /// Compare two Weights
   ///
   /// @param rhs_Weight A weight on the right side of the `<`
   /// @return `true` if the the rhs_Weight is < than the lhs_Weight
   bool operator<( const Weight& rhs_Weight ) const;


   /// Add to an existing Weight
   ///
   /// @param rhs_addToWeight A weight to add to the existing Weight
   /// @return The new Weight
   Weight& operator+=( t_weight rhs_addToWeight );


   /// Subtract from an existing Weight
   ///
   /// @param rhs_subtractFromWeight A weight to subtract from the existing Weight
   /// @return The new Weight
   Weight& operator-=( t_weight rhs_subtractFromWeight );
};


/// Output Weight as a formatted string
///
/// #### Output rules
///
///   - If #Weight::weight is unknown, print `Unknown`
///   - If Weight has a #Weight::maxWeight, print the #Weight::weight followed by ` out of ` and then #Weight::maxWeight
///   - Print the #Weight::UnitOfWeight.  If the last number that's printed is > 1, then make the unit plural by adding an `s`
///
/// #### Sample Output
///
/// Test vectors for Weight << override:
///     | Usage                                   | The Output              |
///     |-----------------------------------------|-------------------------|
///     | `Weight weight`                         | `Unknown`               |
///     | `Weight weight( 0.5 )`                  | `0.5 Pound`             |
///     | `Weight weight( 1 )`                    | `1 Pound`               |
///     | `Weight weight( 1.5 )`                  | `1.5 Pounds`            |
///     | `Weight weight( 1.5, Weight::KILO )`    | `1.5 Kilos`             |
///     | `Weight weight( 0.5, Weight::KILO, 1 )` | `0.5 out of 1 Kilo`     |
///     | `Weight weight( 0.5, Weight::KILO, 2 )` | `0.5 out of 2 Kilos`    |
///     | `Weight weight( Weight::KILO, 1 )`      | `Unknown out of 1 Kilo` |
///
/// @param lhs_stream The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_Weight The Weight to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return `Unknown Pounds` or `3.14 out of 20 Kilos`
std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) ;


/// Output the #Weight::UnitOfWeight as a formatted string
///
/// @param lhs_stream       The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_UnitOfWeight The weight-unit to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return `Pound`, `Kilo` or `Slug` as defined by #Weight::POUND_LABEL, #Weight::KILO_LABEL or #Weight::SLUG_LABEL
std::ostream& operator<<( std::ostream& lhs_stream, Weight::UnitOfWeight rhs_UnitOfWeight );
