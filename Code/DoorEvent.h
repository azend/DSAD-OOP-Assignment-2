#ifndef _DOOREVENT_H_
#define _DOOREVENT_H_
///
///\
///
///
///
///
///
#include<iostream>
#include<ctime>

class DoorEvent {
private:
    unsigned char accessCode[8];
    int status;
    time_t currentTime;
    
public:
    //constructor
    DoorEvent()
    //mutators
    void setAccessCode(unsigned char[] newAccessCode);
    void setStatus(int newStatus);
    void setTime(time_t newCurrentTime);
    //accessors
    unsigned char getAccessCode(void);
    int getStatus(void);
    time_t getTime(void);
};

#endif
