#ifndef CSUBSYSTEM_H
#define CSUBSYSTEM_H

//---CSubsystem----------------------------------------------------------------
// Base class for all robot subsystems.
// Every subsystem must be able to run one cycle and report its current state.
class CSubsystem
{
  public:
    virtual void RunCycle() = 0;
    virtual void ReportState() = 0;
};

#endif