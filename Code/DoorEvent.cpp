///
///\file DoorEvent.cpp
///

#include "DoorEvent.h"

DoorEvent::DoorEvent(){
    status = 0;
}

void DoorEvent::SetAccessCode(unsigned char newAccessCode[]){
    
}

void DoorEvent::SetStatus(int newStatus){
    status = newStatus;
}

void  DoorEvent::SetTime(time_t newCurrentTime){
    
}

unsigned char DoorEvent::GetAccessCode(unsigned	char newAccessCode[]){
    return newAccessCode;
}

int DoorEvent::GetStatus(){
    return status;
}

time_t DoorEvent::GetTime(){
    return currentTime;
}

