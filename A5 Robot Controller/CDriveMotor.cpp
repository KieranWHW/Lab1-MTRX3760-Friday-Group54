#include "CDriveMotor.h"

#include <iostream>

//---CDriveMotor Implementation-----------------------------------------------

// Creates a drive motor starting at zero speed.
CDriveMotor::CDriveMotor()
  : mSpeed( 0 )
{
}

//---
// Runs one cycle of the drive motor.
// For this simple model, the motor speed increases by 10 each cycle.
void CDriveMotor::RunCycle()
{
  mSpeed += 10;
}

//---
// Reports the current speed of the drive motor.
void CDriveMotor::ReportState()
{
  std::cout << "Drive motor speed: "
            << mSpeed
            << std::endl;
}