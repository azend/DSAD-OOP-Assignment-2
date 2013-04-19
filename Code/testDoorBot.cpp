///
///\file testDoorBot.cpp
///\brief This is a test harness for testing all the methods in DoorBot
///
///
///

#include "DoorBot.h"

int main (int argc, const char * argv[]){
    
    std::string dbpath;///< A string for storing the path to the database.
    bool valid = false;///< To test whether or not a method as suceeded or not.
    std::string dbPathFalse[3] = {"/path/to/string", "path/to/sean's/house", "path/to/nowhaere"};

    
    //test the default constructor:
    DoorBot myDoorBot;
    dbpath = myDoorBot.GetDbPath;
    printf("The next line should be db.txt.\n");
    printf("%s\n", dbpath.c_str);
    
    //Path mutator test from a commandline arg
    if (argc == 2){
        printf("Testing the database path mutator with a cl argument\n");
        //test the path mutator:
        printf("You entered %s\n", argv[1]);
        valid = myDoorBot.SetDbPath(argv[1]);
        if (valid == true){
            dbpath = myDoorBot.GetDbPath;
            printf ("The new path is %s\n", dbpath.c_str);
        }
        else {
            printf ("ERROR: The path is dead Jim\n");
        }
    }
    
    //mutator test with paths that don't exist
    for (int i = 0; i < 3; i++){
        valid = myDoorBot.SetDbPath(dbPathFalse[i]);
        if (valid == true){
            
            printf
        }
    }
    
}


