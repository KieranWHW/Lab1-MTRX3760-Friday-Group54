// A clock model
//
// This program models a simple clock that keeps a time in minutes and can
// advance, report, and reset it. main() creates one plain clock and steps it
// forward by a minute.
//
// Edit this file directly to build the version asked for in the handout.
//
// Copyright (c) Donald Dansereau, 2026

//--Includes-------------------------------------------------------------------
#include <iostream>
#include <string>


//---CClock--------------------------------------------------------------------

class CClock
{
public:

    CClock( const std::string& aName, int aStartMinutes );

    void Tick();

    int GetTime();

    void Reset();

    void Report();


private:

    std::string mName;

    int mStartMinutes;

    int mCurrentMinutes;
};


//---CAlarmClock---------------------------------------------------------------
// Alarm clock inherits normal clock behaviour from CClock.

class CAlarmClock : public CClock
{
public:

    CAlarmClock( const std::string& aName, int aStartMinutes );

    void SetAlarm( int aAlarmMinutes );

    bool IsRinging();


private:

    int mAlarmMinutes;
};


//---main----------------------------------------------------------------------

int main()
{
    CClock clock( "Kitchen", 419 );

    clock.Tick();

    std::cout << "Plain clock:" << std::endl;
    clock.Report();


    std::cout << std::endl;


    // Separate alarm clock object.
    CAlarmClock alarmClock( "Kitchen", 420 );

    // Set the alarm
    alarmClock.SetAlarm( 430 );


    std::cout << "Alarm clock advancing:" << std::endl;

    // Starting time.
    alarmClock.Report();


    // Tick until the alarm time is reached.
    while( !alarmClock.IsRinging() )
    {
        alarmClock.Tick();

        // Show each advancement.
        alarmClock.Report();
    }


    std::cout << "ALARM!" << std::endl;


    // Reset comes from CClock.
    alarmClock.Reset();

    std::cout << std::endl;
    std::cout << "Alarm clock after reset:" << std::endl;

    alarmClock.Report();


    // Original clock remains unchanged.
    std::cout << std::endl;
    std::cout << "Plain clock is still:" << std::endl;

    clock.Report();


    return 0;
}


//---CClock Implementation-----------------------------------------------------

CClock::CClock(
    const std::string& aName,
    int aStartMinutes
)
:
    mName( aName ),
    mStartMinutes( aStartMinutes ),
    mCurrentMinutes( aStartMinutes )
{
}


void CClock::Tick()
{
    ++mCurrentMinutes;
}


int CClock::GetTime()
{
    return mCurrentMinutes;
}


void CClock::Reset()
{
    mCurrentMinutes = mStartMinutes;
}


void CClock::Report()
{
    int hours = ( mCurrentMinutes / 60 ) % 24;

    int minutes = mCurrentMinutes % 60;


    std::cout
        << mName
        << " "
        << ( hours < 10 ? "0" : "" )
        << hours
        << ":"
        << ( minutes < 10 ? "0" : "" )
        << minutes
        << std::endl;
}


//---CAlarmClock Implementation-----------------------------------------------

CAlarmClock::CAlarmClock(
    const std::string& aName,
    int aStartMinutes
)
:
    CClock( aName, aStartMinutes ),
    mAlarmMinutes( -1 )
{
}


void CAlarmClock::SetAlarm( int aAlarmMinutes )
{
    mAlarmMinutes = aAlarmMinutes;
}


bool CAlarmClock::IsRinging()
{
    return GetTime() == mAlarmMinutes;
}
