//
//  main.cpp
//  testDoorEventFileIO
//
//  Created by Ian Campbell on 2013-04-19.
//  Copyright (c) 2013 Ian Campbell. All rights reserved.
//

#include <iostream>
#include <string>
#include "DoorEvent.h"

int main(void){
    
    int error = 0;
    int i = 0;
    int j = 0;
    unsigned char testButton[10][IBUTTON_BYTES] =
    {
        {23,54,23,43,65,34,23},
        {45,23,34,45,23,34,87},
        {56,23,45,23,45,56,23},
        {54,34,23,76,45,65,34},
        {45,23,56,23,76,34,54},
        {23,65,34,75,34,65,34},
        {42,23,76,34,34,75,34},
        {45,23,86,45,45,34,65},
        {45,23,65,87,45,56,34},
        {23,34,56,87,34,54,65}
    };
    std::string pressEnter;
    
    DoorEvent testDoorEvent;
    
    printf("Starting tests on DoorEvent File IO.\n");
    
    //Creating the log file
    printf("\tCreating the log file: \n");
    error = testDoorEvent.ClearLog();
    if (error == 0){
        printf("\t\tLog file sucessfully created.\n");
    }
    else {
        printf("\t\tERROR\n");
    }
    printf("\n\n");
    
    //Normal Use, Writting 10 Events to the Log
    printf("\tNormal Event Testing\n");
    printf("\tWriting 10 iButton Events to the log\n");
    for (i = 0; i < 10; i++){
        testDoorEvent.SetAccessCode(testButton[i]);
        //Adding an entry
        error = testDoorEvent.WriteToLog();
        if (error == 0){
            printf("\t\tThe entry was sucessfully written.\n");
        }
        else {
            printf("\t\tERROR\n");
        }
    }
    printf("\tPress enter to continue\n");
    getline(std::cin, pressEnter);
    
    
    printf("\n\n");
    
    printf("\tTesting clearing the Log\n");
    //Clearing the log file
    printf("\tClearing the log file: \n");
    error = testDoorEvent.ClearLog();
    if (error == 0){
        printf("\t\tLog file sucessfully cleared.\n");
    }
    else {
        printf("\t\tERROR\n");
    }
    
    printf("\tPress enter to continue\n");
    getline(std::cin, pressEnter);
    
    printf("\n\n");
    
    printf("\tStress Testing Log Writes\n");
    for (j = 0; j < 200; j++){
        error = testDoorEvent.WriteToLog();
        if (error == 0 && (j % 10 == 0)){
            printf("\t\tThe last 10 entries were sucessfully written.\n");
        }
        else if (error != 0) {
            printf("\t\tERROR\n");
        }
    }
}

