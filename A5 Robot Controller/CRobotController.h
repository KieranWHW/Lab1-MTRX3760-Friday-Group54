#ifndef CROBOTCONTROLLER_H
#define CROBOTCONTROLLER_H

#include "CSubsystem.h"

//---CRobotController----------------------------------------------------------
// The robot controller runs and reports all attached subsystems.
class CRobotController
{
  public:
    CRobotController( CSubsystem* aSubsystems[], int aNumSubsystems );

    void RunCycle();

  private:
    CSubsystem** mSubsystems;
    int mNumSubsystems;
};

#endif