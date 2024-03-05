///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// General string-trimming functions
///
/// @file   Trim.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

extern std::string_view trim_left( std::string_view inString ) noexcept;

/// Remove all trailing whitespace from `inString`
extern std::string_view trim_right( std::string_view inString ) noexcept;

/// Remove all leading and trailing whitespace from `inString`
extern std::string_view trim_edges( std::string_view inString ) noexcept;
