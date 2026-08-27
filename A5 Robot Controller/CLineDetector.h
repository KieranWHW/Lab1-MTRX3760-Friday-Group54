#ifndef CLINEDETECTOR_H
#define CLINEDETECTOR_H

#include "CSubsystem.h"

//---CLineDetector-------------------------------------------------------------
// A line detector subsystem whose sensor reading changes each cycle.
class CLineDetector : public CSubsystem
{
  public:
    CLineDetector();

    void RunCycle();
    void ReportState();

  private:
    int mSensorValue;
};

#endif