///
///\file ErrorHandle.cpp
///

#include "ErrorHandle.h>"

///
/// \brief <b>Brief Description</b> - This method is the default constructor
/// \details <b>Details</b>
///
/// This method sets errorLevel to zero and populates the time string
///
/// \return This method does not return anything.
///

ErrorHandle::ErrorHandle(){
    errorLevel = 0;
    time(&currentTime);
    timeStuff = localtime(&currentTime);
    strftime(timeString, sizeof(timeString), "%H:%M:%S", timeStuff);
}

///
/// \brief <b>Brief Description</b> - This method is the constructor with a errorLevel parameter.
/// \details <b>Details</b>
///
/// This method takes a new errorLevel as a parameter and error checks it to see
/// if it is valid.  It also populates the time string.
///
/// \return This method does not return anything.
///

ErrorHandle::ErrorHandle(int setError){
    /*******************************************/
    /////CHANGE THIS WHEN ADDING NEW ERRORS//////
    /*******************************************/
    if (setError > 0 && setError < 4){
        errorLevel = setError;
    }
    else {
        errorLevel = 3;
    }
    time(&currentTime);
    timeStuff = localtime(&currentTime);
    strftime(timeString, sizeof(timeString), "%H:%M:%S", timeStuff);
}

///
/// \brief <b>Brief Description</b> - This method is a mutator for errorLevel
/// \details <b>Details</b>
///
/// This method sets errorLevel to a new value after determaining that it is a
/// valid error.
///
/// \return This method does not return anything.
///

void ErrorHandle::SetErrorLevel(int newErrorLevel){
    /*******************************************/
    /////CHANGE THIS WHEN ADDING NEW ERRORS//////
    /*******************************************/
    if (newErrorLevel > 0 && newErrorLevel < 4){ 
        errorLevel = newErrorLevel;
    }
    else {
        errorLevel = 3;
    }
}

///
/// \brief <b>Brief Description</b> - This method is the accessor for errorLevel
///
/// \return This method returns errorLevel
///

int ErrorHandle::GetErrorLevel(){
    return  errorLevel;
}

///
/// \brief <b>Brief Description</b> - This method writes entries to the error log.
/// \details <b>Details</b>
///
/// This method uses errorLevel to determine what error took place and then prints that error
/// to the error log.
///
/// \return This method returns a special case errorLevel to show that the error Log could not
/// be opened.
///

//errorLevel 1 - db.txt is corrupted
//errorLevel 2 - cannot open EventLog.txt
//errorLevel 3 - invalid errorLevel
int ErrorHandle::WriteToErrorLog(){
    FILE * fp = NULL;
    if ((fp = fopen("ErrorLog.txt", "ab")) == NULL){
        errorLevel = 15; //A special case error when a log file is broken.
        return  errorLevel;
    }
    if (errorLevel == 1) {
        fprintf(fp, "ERROR: db.txt has been corrupted %s\n", timeString);
    }
    if (errorLevel == 2) {
        fprintf(fp, "ERROR: EventLog.txt cannot be opened %s\n", timeString);
    }
    if (errorLevel == 3) {
        fprintf(fp, "ERROR: Invalid Error Detected %s\n", timeString);
    }
    fclose(fp); // risky business :-)
    return errorLevel;
}

///
/// \brief <b>Brief Description</b> - This method clears all entries from the error log
/// \details <b>Details</b>
///
/// This method opens the error log up in write mode so that all entries are wiped out.
///
/// \return This method returns a special case errorLevel to show that the error Log could not
/// be opened.
///

int ErrorHandle::ClearErrorLog(){
    FILE * fp = NULL;
    if ((fp = fopen("ErrorLog.txt", "wb")) == NULL){
        errorLevel = 15; //A special case error when a log file is broken.
        return errorLevel; //muhahaha
    }
    fclose(fp);
}