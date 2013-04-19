#ifndef _DOOREVENT_H_
#define _DOOREVENT_H_
///
///\file DoorEvent.h
///

///
///
///\class DoorEvent
///\brief <b>Brief Description</b>This class stores data from an entry event
///\details <b>Details</b>
///
/// This class store the data from an entry event, including: the access code,
/// the status and the time
///
///\author<i>Ian Campbell & Verdi R-D</i>
///


#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include "Member.h"

class DoorEvent {
private:
    unsigned char buttonAddr[IBUTTON_BYTES];///<This is where the i button value is stored
    bool status;///<indicates pass or fail
    time_t currentTime;///<
    struct tm * timeyWimeyStuff///<this guy is for Verdi's love of doctor who
    char timeString[9]///<string that holds the time
    int errorLevel;///<for file IO errors
    
public:
    //Constructor
    ///
	/// \brief <b>Brief Description</b> - This is the constructor
	/// \details <b>Details</b>
	///
    /// This initializes everything to zero and sets the current time
	///
	/// \return As this is a <i>constructor</i> Nothing is returned from the constuctor
	///
    DoorEvent(){
        errorLevel = 0;
        status = false;
        for (int i = 0; i < IBUTTON_BYTES; i++){
            buttonAddr[i] = 0;
        }
        time(&currentTime);
        timeyWimeyStuff = localtime(&currentTime);
        strftime(timeString, sizeof(timeString), "%H:%M:%S", timeyWimeyStuff);
    }
    //mutators
    void SetAccessCode(char newAccessCode[]);
    void SetStatus(int newStatus);
    void SetTime(time_t newCurrentTime);
    //accessors
    char GetAccessCode(void);
    bool GetStatus(void);
    char GetTime(void);
    //write door event to log
    void writeToLog(char * path);
};

#endif
