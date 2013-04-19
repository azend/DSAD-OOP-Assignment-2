///
///\file TestDriver2
///\brief This driver runs a series of tests on the methods in the ErrorHandle class
///
///\author Ian & Verdi

#include <iostream>
#include "ErrorHandle.h"

int main(void){
    
    int errorTest = 0;
    int errorTestArray[9] = {2, 1, 0, 5, 6, 4, 0, 2, 0};
    int testArray[7] = {2, 1, 3, 2, 1, 2, 1};
    int i = 0;

    /******Testing the constructor******/
    printf("ErrorHandle Test Harness.\n\n");
    printf("\tTesting the default constructor.\n");
    ErrorHandle newErrorHandle;
    printf("\t'errorLevel' should be 0\n");
    errorTest = newErrorHandle.GetErrorLevel();
    printf("\t'errorLevel' is %d\n", errorTest);
    printf("\n");
    
    /******Testing the accessors and mutators******/
    //Normal Tests:
    printf("\tTesting the accessors and mutators.\n");
    printf("\t\tNormal Testing All Should Pass....\n");
    for (i = 0; i < 3; i++){
        printf("\t\tSending the mutator %d\n", errorTestArray[i]);
        newErrorHandle.SetErrorLevel(errorTestArray[i]);
        errorTest = newErrorHandle.GetErrorLevel();
        printf("\t\tThe accessor returned %d\n", errorTest);
        if (errorTest >= 0 && errorTest <= 2){
            printf("\t\tThis is a PASS condition\n");
        }
        else {
            printf("\t\tThis is a FAIL condition\n");
        }
    }
    //Fail Tests:
    printf("\t\tFail Testing All Should Fail....\n");
    for (i = 3; i < 6; i++){
        printf("\t\tSending the mutator %d\n", errorTestArray[i]);
        newErrorHandle.SetErrorLevel(errorTestArray[i]);
        errorTest = newErrorHandle.GetErrorLevel();
        printf("\t\tThe accessor returned %d\n", errorTest);
        if (errorTest >= 0 && errorTest <= 2){
            printf("\t\tThis is a PASS condition\n");
        }
        else {
            printf("\t\tThis is a FAIL condition\n");
        }
    }
    //Boundery Tests
    printf("\t\tBoundary Testing All Should Pass....\n");
    for (i = 6; i < 9; i++){
        printf("\t\tSending the mutator %d\n", errorTestArray[i]);
        newErrorHandle.SetErrorLevel(errorTestArray[i]);
        errorTest = newErrorHandle.GetErrorLevel();
        printf("\t\tThe accessor returned %d\n", errorTest);
        if (errorTest >= 0 && errorTest <= 2){
            printf("\t\tThis is a PASS condition\n");
        }
        else {
            printf("\t\tThis is a FAIL condition\n");
        }
    }
    printf("\n");
    
    /*****Creating A New Log File*****/
    printf("\t\tCreating a New Log File.\n");
    errorTest = newErrorHandle.ClearErrorLog();
    if (errorTest == 0) {
        printf("\t\tThe Log was successfully created\n");
    }
    else {
        printf("\t\tERROR\n");
    }
    printf("\n");
    
    /*****Write some errors to the file*******/
    printf("\t\tWriting some errors to the file....\n");
    for (i = 0; i < 7; i++){
        newErrorHandle.SetErrorLevel(testArray[i]);
        errorTest = newErrorHandle.WriteToErrorLog();
        if (errorTest == 0) {
            printf("\t\tThe Log was successfully written\n");
        }
        else {
            printf("\t\tERROR\n");
        }
    }
    
    return 0;
}

