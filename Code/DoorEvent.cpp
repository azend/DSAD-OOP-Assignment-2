///
///\file DoorEvent.cpp
///

#include "DoorEvent.h"

///
/// \brief <b>Brief Description</b> - Brings in a new I button code
/// \details <b>Details</b>
///
/// This method clears the old code and sets the new I button code. 
///
/// \return This method does not return anything.
///

void DoorEvent::SetAccessCode(char newAccessCode[]){
    for (int i = 0; i < IBUTTON_BYTES; i++){
        buttonAddr[i] = newAccessCode[i];
    }
}

///
/// \brief <b>Brief Description</b> - This sets the status to pass or fail.
///
/// \return This method does not return anything.
///

void DoorEvent::SetStatus(bool newStatus){
    status = newStatus;
}

///
/// \brief <b>Brief Description</b> - This method sets the current time
/// \details <b>Details</b>
///
/// This method uses ctime library functions and structs to create a string containing the
/// current time.
///
/// \return This method does not return anything.
///

void  DoorEvent::SetTime(time_t newCurrentTime){
    currentTime = newCurrentTime;
    time(&currentTime);
    timeyWimeyStuff = localtime(&currentTime);
    strftime(timeString, sizeof(timeString), "%H:%M:%S", timeyWimeyStuff);
}

///
/// \brief <b>Brief Description</b> - This method gets the I button code from DoorEntry.
///
/// \return This method returns the I button code.
///

char DoorEvent::GetAccessCode(){
    return newAccessCode;
}

///
/// \brief <b>Brief Description</b> - This method gets the status from DoorEntry.
///
/// \return This method returns the status.
///


int DoorEvent::GetStatus(){
    return status;
}

///
/// \brief <b>Brief Description</b> - This method gets the time string from DoorEntry.
///
/// \return This method returns the current time.
///


char DoorEvent::GetTime(){
    return timeString;
}

///
/// \brief <b>Brief Description</b> - This method writes entry data to the entry log
/// \details <b>Details</b>
///
/// This method writes the ibutton code, whether or not the code passed or failed and the
/// time to the entry log.  It also uses errorLevel to keep track of any wrong doings.
///
/// \return This method does not return anything.
///


void DoorEvent::writeToLog(char * path){
    FILE * fp = NULL;
    
    //open the file that
    if (errorLevel == 0){
        if ((fp = fopen(path, "ab")) == NULL){
            errorLevel = 2;
        }
    }
    
    if (errorLevel == 0){
        if (status == true){
            fprintf(fp, "%s Access Granted %s\n", buttonAddr, timeString);//modify to remove string ref
        }
        else if (status == false){
            fprintf(fp, "%s Access Denied %s\n", buttonAddr, timeString);
        }
    }
    fclose(fp);
}