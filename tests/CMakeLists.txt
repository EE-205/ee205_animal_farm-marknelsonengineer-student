###############################################################################
#  University of Hawaii, College of Engineering
#  Animal Farm - EE 205 - Spring 2024
#
## CMake file dedicated to Boost unit tests
##
## @see https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html
## @see https://www.jetbrains.com/help/clion/boost-test-support.html#add-boost-tests
##
## @file   CMakeLists.txt
## @author Mark Nelson <marknels@hawaii.edu>
###############################################################################

set (Boost_USE_STATIC_LIBS OFF)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

if (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message(STATUS "Generating unit tests using BOOST Unit Test Framework")

   set(SOURCE_FILES_GENERAL ../src/config.h ../src/Utility/Random.h ../src/Utility/Random.cpp ../src/Utility/Trim.h ../src/Utility/Trim.cpp ../src/Utility/Name.h ../src/Utility/Name.cpp ../src/Utility/Gender.h ../src/Utility/Gender.cpp)
   set(BOOST_TESTS          test_Animal.cpp test_Random.cpp test_Trim.cpp test_Name.cpp test_Gender.cpp)

   add_executable (All_Boost_Tests ${SOURCE_FILES_GENERAL} ${BOOST_TESTS})
   target_link_libraries (All_Boost_Tests ${Boost_LIBRARIES})

else (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message("BOOST Test needs to be installed to do unit testing")
endif (Boost_UNIT_TEST_FRAMEWORK_FOUND)
