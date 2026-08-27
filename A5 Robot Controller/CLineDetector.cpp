#include "CLineDetector.h"

#include <iostream>

//---CLineDetector Implementation---------------------------------------------

// Creates a line detector starting with a sensor value of zero.
CLineDetector::CLineDetector()
  : mSensorValue( 0 )
{
}

//---
// Runs one cycle of the line detector.
// For this simple model, the sensor value increases by 5 each cycle.
void CLineDetector::RunCycle()
{
  mSensorValue += 5;
}

//---
// Reports the current line detector reading.
void CLineDetector::ReportState()
{
  std::cout << "Line detector value: "
            << mSensorValue
            << std::endl;
}