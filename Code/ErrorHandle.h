///
///\file ErrorHandle.h
///
///\class ErrorHandle
///\brief This class writes any wrong doings to an error log
///\author Ian and Verdi
///


#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string.h>

class ErrorHandle {
    
private:
    int errorLevel;///<This holds an integer that repressents horrible error monsters
    time_t currentTime;///<Some ctime stuff
    struct tm * timeStuff;///<A pointer to a ctime struct
    char timeString[9];///<A string that holds the current time in Hours:Minutes:Seconds
    
public:
    //constructors
    ErrorHandle();
    ErrorHandle(int errorLevel);
    //mutator
    void SetErrorLevel(int newErrorLevel);
    //accessor
    int GetErrorLevel();
    //write the error to an error log
    int WriteToErrorLog();
    //clear the error log
    int ClearErrorLog();
};

