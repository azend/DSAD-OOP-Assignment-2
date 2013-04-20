///
///\file TestDriver1
///\brief This driver runs a series of tests on the methods in the DoorEvent class
///
///\author Ian & Verdi

#include "DoorEvent.h"

int main(void){
    
    int i = 0;
    
    //Test Items
    unsigned char testiButton[7] = {23,34,32,34,23,54,45};
    unsigned char * recieveTestAddr = NULL;
    bool statTest[3] = {true, false ,true};
    bool getStat = false;
    char * getCurrentTime;
    int error = 0;


    printf("Begin Testing DoorEvent.\n\n");
    //testing the default constructor
    DoorEvent testDoorEvent;
    
    //Testing iButton mutator and accessor
    /*Since iButton code validation is done in a seperate class it is certain
      that the iButton will be valid. */
    printf("\tTesting the iButton setter and getter.....\n");
    printf("\t\tThe input is: 23 34 32 34 23 54 45\n");
    printf("\t\tThe getter recieved: ");
    testDoorEvent.SetAccessCode(testiButton);
    recieveTestAddr = testDoorEvent.GetAccessCode();
    for (i = 0; i < 7; i++){
        printf("%d ", recieveTestAddr[i]);
    }
    printf("\n\n");
    
    //Testing Set and Get Status:
    printf("\tTesting Set and Get Status\n");
    printf("\t\tThe input is: true false true\n");
    printf("\t\tThe output is: ");
    for (i = 0; i < 3; i++) {
        testDoorEvent.SetStatus(statTest[i]);
        getStat = testDoorEvent.GetStatus();
        if (getStat == true) {
            printf("true ");
        }
        else {
            printf("false ");
        }
    }
    printf("\n\n");
    
    //The current time is logged whenever a new instance of DoorEvent is created
    printf("\tTesting saving the current time\n");
    printf("\tAll output should be the same\n");
    for (i = 0; i < 6; i++) {
        DoorEvent timeDoorEvent;
        getCurrentTime = timeDoorEvent.GetTime();
        printf("\t\t%s\n", getCurrentTime);
        timeDoorEvent.~DoorEvent();
    }
    printf("\n\n");
    
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
    
    //Adding an entry
    printf("\tWriting an entry to the log.\n");
    error = testDoorEvent.WriteToLog();
    if (error == 0){
        printf("\t\tThe entry was sucessfully written.\n");
    }
    else {
        printf("\t\tERROR\n");
    }
    printf("\n\n");
    error = testDoorEvent.WriteToLog();
    error = testDoorEvent.WriteToLog();
    error = testDoorEvent.WriteToLog();
    error = testDoorEvent.WriteToLog();
    
    return 0;
}

