//
//  testMember.cpp
//  testMember
//
//  Created by Ian Campbell on 2013-04-18.
//  Copyright (c) 2013 Ian Campbell. All rights reserved.
//

///
///\file testMember.cpp
///\brief This file tests the methods contained in the member class
///
///
///

#include <stdio.h>
    
#include "Member.h"
    
int main(void){
    
    unsigned char testAddr1[IBUTTON_BYTES] = { 1, 2, 66, 78, 52, 6, 7 };
    unsigned char testAddr2[8] = { 6, 6, 8, 9, 5, 8, 78, 90 };
    unsigned char testAddr3[4] = { 7, 9, 7, 5 };
    unsigned char * testAddr4 = NULL;
    int arraySize[4] = {7, 8, 4, 0};
    std::string firstName("Ian");
    std::string lastName("Campbell");
    std::string errorFirstName("");
    std::string newFirstName;
    std::string newLastName;
    unsigned char newAddr[IBUTTON_BYTES] = {0};
    bool testResult = false;
        
        
    printf("Testing class Member:\n");
        
    /*
     Testing the default constructor
    */
    printf("\tTesting default constructor... \n\n");
    Member azend;
    Member otherMember;
        
    /*
    Testing the mutators
    */
    printf("\tTesting setters..... \n\n");
        
    /* Normal Tests */
    printf ("\tNormal Tests..... All should pass\n");
    //firstname
    testResult = azend.SetFirstName(firstName.c_str());
    if (testResult == true){
        printf ("\tResult 1 - PASS\n");
        testResult = false;
    }
    else {
        printf ("\tResult 1 - FAIL\n");
    }
    //lastname
    testResult = azend.SetLastName(lastName.c_str());
    if (testResult == true){
        printf ("\tResult 2 - PASS\n");
        testResult = false;
    }
    else {
        printf ("\tResult 2 - FAIL\n");
    }
    //ibutton
    testResult = azend.SetiButtonAddr(testAddr1, arraySize[0]);
    if (testResult == true){
        printf ("\tResult 3 - PASS\n");
        testResult = false;
    }
    else {
        printf ("\tResult 3 - FAIL\n");
    }
    
    /* Error Tests */
    printf ("\tError Tests...... All should fail.\n");
    //firstname high
    printf("\tThese values are too large to be valid\n");
    testResult = azend.SetFirstName("01234567890123456789012345678901234");
    if (testResult == true){
        printf ("\tResult 1 - PASS\n");
        testResult = false;
    }
    else {
        printf ("\tResult 1 - FAIL\n");
    }
    //lastname high
    testResult = azend.SetLastName("holygadimtrappedinacrappyc++programgetmethehelloutofhere");
    if (testResult == true){
        printf ("\tResult 2 - PASS\n");
        testResult = false;
    }
    else {
        printf ("\tResult 2 - FAIL\n");
    }
    //firstname zero
    printf("\tThese are empty strings therefore invalid\n");
    testResult = azend.SetFirstName("");
    if (testResult == true){
        printf ("\tResult 1 - PASS\n");
        testResult = false;
    }
    else {
        printf ("\tResult 1 - FAIL\n");
    }
    //lastname zero
    testResult = azend.SetLastName("");
    if (testResult == true){
        printf ("\tResult 2 - PASS\n");
        testResult = false;
    }
    else {
        printf ("\tResult 2 - FAIL\n");
    }
    //ibutton high
    printf("\tThis iButton Address is too large\n");
    testResult = azend.SetiButtonAddr(testAddr2, arraySize[1]);
    if (testResult == true){
        printf ("\tResult 3 - PASS\n");
        testResult = false;
    }
    else {
        printf ("\tResult 3 - FAIL\n");
    }
    //ibutton low
    printf("\tThis iButton Address is too small\n");
    testResult = azend.SetiButtonAddr(testAddr3, arraySize[2]);
    if (testResult == true){
        printf ("\tResult 3 - PASS\n\n");
        testResult = false;
    }
    else {
        printf ("\tResult 3 - FAIL\n\n");
    }
    
    /*
    Testing the accessors
    */
    //
    printf("\tTesting accessors......  \n\n");
    //Getting First Name
    newFirstName = azend.GetFirstName();
    printf("\tThe new firstname is: %s\n", newFirstName.c_str());
    //Getting Last Name
    newLastName = azend.GetLastName();
    printf("\tThe new lastname is: %s\n", newLastName.c_str());
    //Getting iButton Address
    /*newAddr = azend.GetiButtonAddr();
    for (int i = 0; i < IBUTTON_BYTES; i++){
        printf("%c", newAddr[i]);
    }*/
    printf("\n\n");
        
    /*
    Testing the iButton Comparison
    */
    /*
    printf("\tTesting iButton comparison..... \n\n");
    testResult = azend.CompareiButton(newAddr);
    if (testResult == true){
        printf("The buttons are the same! YAY!\n");
    }
    else if (testResult == false){
        printf("The buttons are not the same :-(\n");
    }
    */
        
    return 0;
}
