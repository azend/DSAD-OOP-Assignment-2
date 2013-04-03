#ifndef _DOOREVENT_H_
#define _DOOREVENT_H_
///
///\file DoorEvent.h
///

///
///
///\class DoorEvent
///\brief This class creates an entry event stores the access code, whether or not it passed or failed and the time.
///
///

#include<iostream>
#include<ctime>

class DoorEvent {
private:
    unsigned char buttonAddr[IBUTTON_BYTES];
    int status;
    time_t currentTime;
    
public:
    //constructor/destructor
    DoorEvent()
    ~DoorEvent()
    //mutators
    void SetAccessCode(unsigned char[] newAccessCode);
    void SetStatus(int newStatus);
    void SetTime(time_t newCurrentTime);
    //accessors
    unsigned char GetAccessCode(void);
    int GetStatus(void);
    time_t GetTime(void);
};

#endif
