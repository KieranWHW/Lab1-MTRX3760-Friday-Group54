#ifndef CDRIVEMOTOR_H
#define CDRIVEMOTOR_H

#include "CSubsystem.h"

//---CDriveMotor---------------------------------------------------------------
// A drive motor subsystem whose speed changes as the controller runs cycles.
class CDriveMotor : public CSubsystem
{
  public:
    CDriveMotor();

    void RunCycle();
    void ReportState();

  private:
    int mSpeed;
};

#endif