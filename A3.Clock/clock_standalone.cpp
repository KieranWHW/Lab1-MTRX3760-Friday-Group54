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


//---CClock---------------------------------------------------------------------

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
// Standalone version.
// Does NOT inherit from CClock.

class CAlarmClock
{
public:

    CAlarmClock( const std::string& aName, int aStartMinutes );

    void Tick();

    int GetTime();

    void Reset();

    void Report();

    void SetAlarm( int aAlarmMinutes );

    bool IsRinging();


private:

    std::string mName;

    int mStartMinutes;

    int mCurrentMinutes;

    int mAlarmMinutes;
};


//---main----------------------------------------------------------------------

int main()
{
    // The original plain clock.
    CClock clock( "Kitchen", 419 );

    clock.Tick();

    std::cout << "Plain clock:" << std::endl;
    clock.Report();


    std::cout << std::endl;


    // A separate alarm clock.
    // It is also called Kitchen, but is a completely separate object.
    CAlarmClock alarmClock( "Kitchen", 420 );

    // Set the alarm
    alarmClock.SetAlarm( 430 );


    std::cout << "Alarm clock advancing:" << std::endl;

    // Show its starting time.
    alarmClock.Report();


    // Advance one minute at a time until the alarm rings.
    while( !alarmClock.IsRinging() )
    {
        alarmClock.Tick();

        // Report every tick so we can SEE it advancing.
        alarmClock.Report();
    }


    std::cout << "ALARM!" << std::endl;

    // Reset the alarm clock back to its original starting time.
    alarmClock.Reset();

    std::cout << std::endl;
    std::cout << "Alarm clock after reset:" << std::endl;

    alarmClock.Report();


    // Show that the original plain clock was not affected.
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
    mName( aName ),
    mStartMinutes( aStartMinutes ),
    mCurrentMinutes( aStartMinutes ),
    mAlarmMinutes( -1 )
{
}


void CAlarmClock::Tick()
{
    ++mCurrentMinutes;
}


int CAlarmClock::GetTime()
{
    return mCurrentMinutes;
}


void CAlarmClock::Reset()
{
    mCurrentMinutes = mStartMinutes;
}


void CAlarmClock::Report()
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


void CAlarmClock::SetAlarm( int aAlarmMinutes )
{
    mAlarmMinutes = aAlarmMinutes;
}


bool CAlarmClock::IsRinging()
{
    return mCurrentMinutes == mAlarmMinutes;
}