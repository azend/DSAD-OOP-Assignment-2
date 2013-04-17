#ifndef _TESTMEMBER_H_
#define _TESTMEMBER_H_

#include <stdio.h>

#include "Member.h"

int main(void)
{
	unsigned char testAddr1[IBUTTON_BYTES] = { 1, 2, -127, 1024, 52, 6, 7 };
    unsigned char testAddr2[8] = { 6, 6, 8, 9, 5, 8, 78, 90 };
    unsigned char testAddr3[4] = { 7, 9, 7, 5 };
	unsigned char * testAddr4 = NULL;
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
    
    /*
    Testing the mutators
    */
    printf("\tTesting setters..... \n\n")
    
    /* Normal Tests */
    printf ("\tNormal Tests..... All should pass\n");
    //firstname
	testResult = azend.SetFirstName(firstName);
    if (testResult == true){
        printf ("\tResult 1 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 1 - FAIL\n");
    }
    //lastname
    testResult = azend.SetLastName(lastName);
    if (testResult == true){
        printf ("\tResult 2 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 2 - FAIL\n");
    }
    //ibutton
    testResult = azend.SetiButtonAddr(testAddr1);
    if (testResult == true){
        printf ("\tResult 3 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 3 - FAIL\n");
    }
    
    /* Error Tests */
    printf ("\tError Tests...... All should fail.\n");
    //firstname high
	testResult = azend.SetFirstName("01234567890123456789012345678901234");
    if (testResult == true){
        printf ("\tResult 1 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 1 - FAIL\n");
    }
    //lastname high
    testResult = azend.SetLastName("holygadimtrappedinacrappyc++programgetmethehelloutofhere");
    if (testResult == true){
        printf ("\tResult 2 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 2 - FAIL\n");
    }
    //firstname zero
	testResult = azend.SetFirstName("");
    if (testResult == true){
        printf ("\tResult 1 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 1 - FAIL\n");
    }
    //lastname zero
    testResult = azend.SetLastName("");
    if (testResult == true){
        printf ("\tResult 2 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 2 - FAIL\n");
    }
    //ibutton high
    testResult = azend.SetiButtonAddr(testAddr2);
    if (testResult == true){
        printf ("\tResult 3 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 3 - FAIL\n");
    }
    //ibutton low
    testResult = azend.SetiButtonAddr(testAddr3);
    if (testResult == true){
        printf ("\tResult 3 - PASS\n")
        testResult = false;
    }
    else {
        printf ("\tResult 3 - FAIL\n");
    }
    
    /*
    Testing the accessors
    */
    //
    printf("\tTesting accessors......  \n\n");
    //Getting First Name
    newFirstName = azend.GetFirstName();
	printf("The new firstname is: %s\n", newFirstName);
    //Getting Last Name
    newLastName = azend.GetLastName();
    printf("The new lastname is: %s\n", newLastName);
    //Getting iButton Address
    newAddr = azend.GetiButtonAddr();
    for (int i = 0; i < IBUTTON_BYTES; i++){
        printf("%c", newAddr[i]);
    }
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
#endif

