#include "CRobotController.h"

//---CRobotController Implementation------------------------------------------

// Creates a controller for the supplied subsystems.
CRobotController::CRobotController( CSubsystem* aSubsystems[],
                                    int aNumSubsystems )
  : mSubsystems( aSubsystems ),
    mNumSubsystems( aNumSubsystems )
{
}

//---
// Runs one cycle of every subsystem and reports each subsystem's state.
void CRobotController::RunCycle()
{
  for( int i = 0; i < mNumSubsystems; ++i )
  {
    mSubsystems[i]->RunCycle();
    mSubsystems[i]->ReportState();
  }
}