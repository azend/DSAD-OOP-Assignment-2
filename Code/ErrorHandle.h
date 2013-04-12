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
  int errorHandle;
  time_t currentTime;
  struct *tm timeStuff;
  char timeSting[];

 public:
  ErrorHandle();
  ErrorHandle(int errorLevel);
  void SetErrorLevel(int newErrorLevel);
  int GetErrorLevel();
  int WriteToErrorLog();
}
