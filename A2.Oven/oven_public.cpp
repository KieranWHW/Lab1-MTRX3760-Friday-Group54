// An oven temperature model (public-data version)
//
// This program models two ovens that warm up in steps and warn if they
// overheat. Each oven's data is stored in public member variables, and main()
// reads and changes the temperatures directly.
//
// Copyright (c) Donald Dansereau, 2026

//--Includes-------------------------------------------------------------------
#include <iostream>
#include <string>

//---COven---------------------------------------------------------------------
// COven holds an oven's name and current temperature. Both members are public,
// so any code can read or change them directly.
// the oven's label, e.g. "Reflow oven"
// current temperature, in whole degrees Celsius
class COven
{
  public:
    std::string mName;
    int mTemperatureTenthsC;
};

//---main----------------------------------------------------------------------
// Sets up two ovens, warms each in one-degree steps, checks each for
// overheating, and reports both. Every step reaches into the ovens' data
// directly.
int main()
{
  COven ReflowOven;
  ReflowOven.mName = "Reflow oven";
  ReflowOven.mTemperatureTenthsC = 200;

  COven CuringOven;
  CuringOven.mName = "Curing oven";
  CuringOven.mTemperatureTenthsC = 200;

  for( int i = 0; i < 5; ++i )
    ReflowOven.mTemperatureTenthsC += 10;

  for( int i = 0; i < 8; ++i )
    CuringOven.mTemperatureTenthsC += 10;

  if( ReflowOven.mTemperatureTenthsC >= 2500 )
    std::cout << "Warning: oven is overheating!" << std::endl;

  if( CuringOven.mTemperatureTenthsC >= 2500 )
    std::cout << "Warning: oven is overheating!" << std::endl;

  std::cout << ReflowOven.mName << " is at "
            << ReflowOven.mTemperatureTenthsC / 10.0 << "C" << std::endl;

  std::cout << CuringOven.mName << " is at "
            << CuringOven.mTemperatureTenthsC / 10.0 << "C" << std::endl;

  return 0;
}