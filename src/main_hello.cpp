///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Animal Farm - EE 205 - Spring 2024
//
/// A generic Hello World program in Animal Farm
///
/// @file   main_hello.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

/// The traditional entry point for applications
///
/// For most C programs, the actual entry point is a CRT0 function called
/// `_start()`, which later calls main().
///
/// The main() function is called at program startup, after all objects with
/// static storage duration are initialized.  It is the designated entry point
/// to a program that is executed in a hosted environment (that is, with an
/// operating system).
///
/// The Linux ABI, under a chapter called "Stack State" has a good explanation
/// of what happens between `_start()` and main().
///
/// @see https://en.cppreference.com/w/c/language/main_function
/// @see https://en.wikipedia.org/wiki/Crt0
///
/// @return The program's return value
int main() {
   cout << "Hello, World!\n";

   return 0;
}
