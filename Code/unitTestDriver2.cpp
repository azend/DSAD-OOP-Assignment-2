///
///\file TestDriver1
///\brief This driver runs a series of tests on the methods in the DoorEvent class
///
///\author Ian & Verdi

#include "DoorEvent.h"

int main(void){
    
    int i = 0;
    int j = 0;
    
    //Test Items
    //Normal
    unsigned char testButtonN[10][IBUTTON_BYTES] =
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
    //Boundary
    unsigned char testButtonB[3][IBUTTON_BYTES] =
    {
        {00,00,00,00,00,00,00},
        {255,255,255,255,255,255,255},
        {0,255,0,255,0,255,0},
    };

    unsigned char * recieveTestAddr = NULL;



    printf("Begin Testing DoorEvent.\n\n");
    //testing the default constructor
    DoorEvent testDoorEvent;
    
    
    //Testing iButton mutator and accessor
    /*Since iButton code validation is done in a seperate class it is certain
      that the iButton will be valid. */
    printf("\tTesting the iButton setter and getter.....\n");
    printf("\tNormal Testing\n");
    for (i = 0; i < 10; i++){
        printf("\t\tThe getter recieved: ");
        testDoorEvent.SetAccessCode(testButtonN[i]);
        recieveTestAddr = testDoorEvent.GetAccessCode();
        for (j = 0; j < 7; j++){
            printf("%d ", recieveTestAddr[j]);
        }
        printf("\n\n");
    }
    
    printf("\tTesting the iButton setter and getter.....\n");
    printf("\tBoundary Testing\n");
    for (i = 0; i < 3; i++){
        printf("\t\tThe getter recieved: ");
        testDoorEvent.SetAccessCode(testButtonB[i]);
        recieveTestAddr = testDoorEvent.GetAccessCode();
        for (j = 0; j < 7; j++){
            printf("%d ", recieveTestAddr[j]);
        }
        printf("\n\n");
    }

    printf("\n\n");
    
    return 0;
}

