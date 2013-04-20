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

void DoorEvent::SetAccessCode(unsigned char newAccessCode[]){
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

unsigned char * DoorEvent::GetAccessCode(){
    return buttonAddr;
}

///
/// \brief <b>Brief Description</b> - This method gets the status from DoorEntry.
///
/// \return This method returns the status.
///


bool DoorEvent::GetStatus(){
    return status;
}

///
/// \brief <b>Brief Description</b> - This method gets the time string from DoorEntry.
///
/// \return This method returns the current time.
///


char * DoorEvent::GetTime(){
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


int DoorEvent::WriteToLog(){
    FILE * fp = NULL;
    int i = 0;
    
    //open the EventLog.txt in append mode 
    if (errorLevel == 0){
        if ((fp = fopen("EventLog.txt", "ab")) == NULL){
            errorLevel = 2;
        }
    }
    
    if (errorLevel == 0){
        if (status == true){
            for (i = 0; i < IBUTTON_BYTES; i++) {
                fprintf(fp, "%d ", buttonAddr[i]);
            }
            fprintf(fp, "Access Granted %s\n", timeString);
        }
        else if (status == false){
            for (i = 0; i < IBUTTON_BYTES; i++) {
                fprintf(fp, "%d ", buttonAddr[i]);
            }
            fprintf(fp, "Access Denied %s\n", timeString);
        }
    }
    //make sure to close the file 
    fclose(fp);
    return errorLevel;
}

///
/// \brief <b>Brief Description</b> - This method clears the Event Log
/// \details <b>Details</b>
///
/// This method overwrites all data held in the Event Log and Places a Generic Header on it 
///
/// \return This method does not return anything.
///

int DoorEvent::ClearLog(){
    FILE * fp = NULL;
    
    //Open EventLog.txt in write mode to wipe the data
    if (errorLevel == 0){
        if ((fp = fopen("EventLog.txt", "wb")) == NULL){
            errorLevel = 2;
        }
        //Add a simple header to the file 
        fprintf(fp, "Starting the Event Log....... \n");
        //make sure to close the file
        fclose(fp);
    }
    return errorLevel;
}