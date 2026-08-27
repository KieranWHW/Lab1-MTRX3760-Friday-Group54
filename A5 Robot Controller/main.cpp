#include "CDriveMotor.h"
#include "CLineDetector.h"
#include "CRobotController.h"

#include <iostream>

int main()
{
  CDriveMotor driveMotor;
  CLineDetector lineDetector;

  CSubsystem* subsystems[2] =
  {
    &driveMotor,
    &lineDetector
  };

  CRobotController controller( subsystems, 2 );

  for( int i = 0; i < 3; ++i )
  {
    std::cout << "Cycle " << i + 1 << std::endl;

    controller.RunCycle();

    std::cout << std::endl;
  }

  return 0;
}