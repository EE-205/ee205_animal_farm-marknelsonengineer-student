///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// A utility class for managing names on the farm
///
/// @file   Name.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <vector>


/// A utility class for managing Animal names
///
/// Names can come from several sources:
///
///    - #FROM_FILE:  A list of names in a file
///    - #FROM_SERIAL:  Monotonically generated names with an optional prefix and/or suffix
///
/// This class does not have setters.  Once it's instantiated, nothing needs
/// to change.
class Name {
public:  ////////////////////////// Type Definitions ///////////////////////////

   /// The type of name this class will serve
   enum NameType { FROM_FILE    ///< Names are randomly selected from a list of names in a file
                  ,FROM_SERIAL  ///< Names are monotonically generated from a serial number
                 };

   /// The datatype of the serial number
   typedef unsigned long serial_t;


public:   //////////////////////// Constants ///////////////////////////////////

   static serial_t maxSerial;   ///< The largest possible serial number


protected:  ///////////////////////// Member Variables /////////////////////////
   enum NameType nameType;  ///< Enum that determines how names are generated;

   std::string fileName;    ///< If #FROM_FILE, the source filename
   std::vector<std::string> names;  ///< If #FROM_FILE, the collection of names read from the file

   std::string serialPrefix;  ///< If #FROM_SERIAL, print this before the serial number
   std::string serialSuffix;  ///< If #FROM_SERIAL, print this after the serial number
   serial_t serial = 0;   ///< If #FROM_SERIAL, then this is the serial number


public:  // ///////////////////////// Constructors ////////////////////////////

   /// Construct a #FROM_FILE Name class
   ///
   /// @param newFilename The filename that contains the list of names
   Name( std::string_view newFilename );

   /// Construct a #FROM_SERIAL Name class
   ///
   /// @param newSerialPrefix Print this before the serial number
   /// @param newSerialSuffix Print this after the serial number
   Name( std::string_view newSerialPrefix, std::string_view newSerialSuffix );

public:  /////////////////////////// Public Methods ////////////////////////////

   /// Get the next name
   ///
   /// @return Return the next name from this Name object
   std::string getNextName();

   /// Erase and then re-load the names database or set the serial number to 0
   void reset();

   /// Return the number of unique names left
   serial_t remainingNames() noexcept;


public:  //////////////////////// Static Public Methods ////////////////////////


   /// Check if `newName` is valid
   ///
   /// The validation rules are:
   ///
   ///   - The name should not be empty.
   ///   - The name should be trimmed for whitespace (both left and right whitespace should be removed).
   ///   - The name should not start with a number or `-`.
   ///   - The name should not have any special characters except a `-`.  Allowed
   ///     characters are `A`-`Z`, `a`-`z`, `0`-`9`, space and `-`.
   ///   - The interior whitespace of the name should be trimmed.
   ///
   /// If the name is not valid, print an explanation and return `false`
   ///
   /// @param newName The name to check
   /// @return `true` if the name is valid.  `false` if it's not.
   static bool validateName( const std::string_view newName ) ;


   /// Return `true` if `newName` is not empty
   ///
   /// If not valid, print `The name should not be empty` and return `false`
   ///
   /// @param newName The Name to check
   ///
   /// @return `true` if newName is not empty... `false` if newName is empty
   static bool validateNotEmpty( const std::string_view newName ) ;


   /// Return `true` if `newName` is left and right trimmed for whitespace
   ///
   /// If not valid, print `The name should be trimmed for whitespace` and return `false`
   ///
   /// @param newName The Name to check
   ///
   /// @return `true` if newName's leading and trailing edges are trimmed... `false` if not
   static bool validateTrimmed( const std::string_view newName ) ;


   /// Return `true` if `newName` starts with an alphabetic character (`A` - `Z` or `a` - `z`)
   ///
   /// If not valid, print `The name should not start with a number or -` and return `false`
   ///
   /// @param newName The Name to check
   ///
   /// @return `true` if newName starts with `A`-`Z` or `a`-`z`... `false` if not
   static bool validateStartsWithAlpha( const std::string_view newName ) ;


   /// Return `true` if `newName` only contains `A` - `Z`, `a` - `z`, `0`-`9`, space and `-`
   ///
   /// If not valid, print `The name should not have any special characters` and return `false`
   ///
   /// @param newName The Name to check
   ///
   /// @return `true` if newName only contains valid characters... `false` if not
   static bool validateNoSpecialChars( const std::string_view newName ) ;
};
