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
/// This method writes the I button code, whether or not the code passed or failed and the
/// time to the entry log.  It also uses errorLevel to keep track of any wrong doings.
///
/// \return This method does not return anything.
///


void DoorEvent::writeToLog(char * path){
    FILE * fp = NULL;
    long fileSize = 0;
    unsigned char * inputBuffer = {0};
    int i = 0; // only include if you use a loop
    
    //get the size of the file that is about to be manipulated
    if ((fp = fopen(path, "rb")) == NULL) {
        errorLevel = 2;
    }
    
    if (errorLevel == 0){
        //get the size of the file and then point it back to the start
        //bug!! will break if the file is bigger then 2gbs
        fseek(fp, 0L, SEEK_END);
        fileSize = ftell(fp);
        fseek(fp, 0L, SEEK_SET);
        fclose(fp);
    }
    
    //open the file that you are working on
    if (errorLevel == 0){
        if ((fp = fopen(path, "ab")) == NULL){
            errorLevel = 2;
        }
    }
    
    if (errorLevel == 0){
        if ((inputBuffer = (unsigned char*) malloc((fileSize + 1) * sizeof(unsigned char))) == NULL){
            //In case of malloc error, make sure you attempt to free up any resources you are using.
            errorLevel = 8;
            fclose(fp);
        }
        else if (errorLevel == 0){
            if (fread(inputBuffer, 1, fileSize, fp) == (unsigned int) fileSize){
                if (status == true){
                    fprintf(fp, "%s Access Granted %s\n", buttonAddr, timeString);//modify to remove string ref
                }
                else if (status == false){
                    fprintf(fp, "%s Access Denied %s\n", buttonAddr, timeString);
                }
            }
            else {
                //In case of read error, make sure you attempt to free up any resources you are using.
                errorLevel = 4;
                free(inputBuffer);
                fclose(fp);
            }
        }
    }
    
    free(inputBuffer);
    fclose(fp);
}