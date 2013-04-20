/**
 *
 * @file Project.cpp
 *
 * @brief  <b>Brief</b>This file contains the main function
 * @details <b>Details</b>
 * This file allows the program to operate in 3 states.  The first state is the daemon.
 * This daemon runs until the an Ibutton key is detected.  It then compares it to a database
 * to determine if the user has access and unlocks the door.  [-admin] The second state is the
 * configuration state.  This state allows the administrator to modify the database that the daemon
 * uses. Because this state is modifying the database, the daemon will need to be restarted to see
 * the changes.  [--help] The third state is the help state and it gives a detailed statement on
 * usage.  All other arguments produce a usage statement.
 *
 * @author Ian Campbell and Verdi R-D
 */

#include <iostream>
#include <string>
#include "Member.h"
#include "DoorBot.h"
#include "MemberStore.h"

//namespaces
using namespace std;

//Prototypes
void clearScreen();

void clearScreen() {
    //the saddest little function :-)
    int i = 0;
    for (i = 0; i < 10; i++){
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
}

int main(int argc, char *argv[]) {
    
    bool status = false;
    std::string getInput("");
    
    //if there are no arguments start the daemon
    if (argc == 1){
        /*
         DoorBot mrRoboto;
         
         mrRoboto.SetDbPath("db.txt");
         
         mrRoboto.Setup();
         
         mrRoboto.Loop();
         */
        printf("We are a SCRUM agile dev team.  The daemon is scheduled for our next release.\n");
        printf("If you have any questions, please email DSAD-OOP@azend.org\n");
        printf("Thank You for choosing our software! Team Azend!\n");
    }
    //if -admin is present, start the configuration utility
    else if (argc == 2 ){
        if (strcmp(argv[1], "-admin") == 0){
            
            MemberStore store;
            
            printf("----Welcome to the Device Configuration Utility----\n\n");
            printf("The Daemon will need to be restarted if the database is updated.\n");
            printf("Do you wish to proceed (yes/no): ");
            while (1){
                //Get a yes or no from the user
                getline (cin, getInput);
                if (getInput == "n" || getInput == "no"){
                    printf("Goodbye!\n");
                    return 0;
                }
                else if (getInput == "y" || getInput == "yes"){
                    getInput.clear();
                    clearScreen();
                    //load a set from db.txt
                    while (1){
                        getInput.clear();
                        //print the menu interface
                        printf("---------MAIN MENU---------\n\n");
                        printf("1, Add a user\n");
                        printf("2, Delete a user\n");
                        printf("3, Delete entire database\n");
                        printf("4, Display a user\n");
                        printf("5, Copy a new user list from file\n");
                        printf("6, Save changes\n");
                        printf("7, Save changes and exit\n");
                        printf("8, Exit without saving\n");
                        printf("9, Carlo Special: Cheat and add a bunch of random users to database\n");
                        printf("10, Display the entire database\n\n");
                        printf("Please enter your choice: ");
                        //get a choice from the user
                        getline(cin, getInput);
                        cout << endl << endl;
                        
                        if (getInput == "1"){
                            //add a user to the set
                            //todo get firstname, lastname, ibutton address
                            //add to set
                            cout << "Add Member Wizard" << endl;
                            cout << "-----------------" << endl;
                            cout << endl;
                            
                            Member newMember;
                            
                            string firstName;
                            cout << "Please type the name the first name of the new member and press enter:" << endl;
                            cout << "Example: \"Verdi\" or \"Ian\" or \"Jeremy\" ( not including quotes )" << endl;
                            cout << "Name: ";
                            
                            getline(cin, firstName);
                            
                            while ( !newMember.SetFirstName(firstName) ) {
                                cout << "The name provided is invalid. Please try again." << endl;
                                cout << "Name: ";
                                
                                getline(cin, firstName);
                            }
                            
                            cout << endl;
                            
                            string lastName;
                            cout << "Please type the name the last name of the new member and press enter:" << endl;
                            cout << "Example: \"Johnson\" or \"Smith\" ( not including quotes )" << endl;
                            cout << "Name: ";
                            
                            getline(cin, lastName);
                            
                            while ( !newMember.SetLastName(lastName) ) {
                                cout << "The name provided is invalid. Please try again." << endl;
                                cout << "Name: ";
                                
                                getline(cin, lastName);
                            }
                            
                            cout << endl;
                            
                            string siButtonAddress;
                            vector<unsigned char> ibuttonAddr;
                            
                            cout << "You're almost done! Now all we need to know is the iButton address of the new members' keyfob:";
                            cout << "Example: \"00:11:22:33:44:55:66:77\" or \"1A:2B:3C:4D:5E:6F:7A\"" << endl;
                            cout << "iButton Address: ";
                            
                            getline( cin, siButtonAddress );
                            
                            unsigned char ibuttonBytes [IBUTTON_BYTES] = {0};
                            
                            while ( sscanf( siButtonAddress.c_str(), "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &ibuttonBytes[0], &ibuttonBytes[1], &ibuttonBytes[2], &ibuttonBytes[3], &ibuttonBytes[4], &ibuttonBytes[5], &ibuttonBytes[6]) != IBUTTON_BYTES ) {
                                cout << "The address sequence you've provided is invalid. Please try again." << endl;
                                
                                cout << "iButton Address: ";
                                getline( cin, siButtonAddress );
                            }
                            
                            for ( int i = 0; i < IBUTTON_BYTES; i++ ) {
                                ibuttonAddr.push_back( ibuttonBytes[i] );
                            }
                            
                            newMember.SetiButtonAddr(ibuttonAddr);
                            
                            cout << "The member was successfully created!" << endl;
                            cout << "Now adding the new member to the store... ";
                            store.CreateMember(newMember);
                            cout << "[DONE]" << endl;
                            
                            
                        }
                        else if (getInput == "2"){
                            //delete a user from the set
                            //todo delete a user from set
                        }
                        else if (getInput == "3"){
                            //delete the set
                            //todo delete the set
                        }
                        else if (getInput == "4"){
                            //display a user
                            //todo print the contents of the user to the screen
                        }
                        else if (getInput == "5"){
                            //open a new file and load it into the set
                            //todo 1, delete the old set, 2, get new dbpath from user, 3, load new db to set
                        }
                        else if (getInput == "6"){
                            //save changes to db.txt
                            //todo save set to db.txt
                        }
                        else if (getInput == "7"){
                            //save changes to db.txt and exit
                            //todo save set to db.txt and quit
                        }
                        else if (getInput == "8"){
                            //exit without saving
                            printf("\nGoodbye\n");
                            return 0;
                        }
                        else if (getInput == "9"){
                            //Carlo's cheat method that populates the set with randomness
                            //but still works
                            //todo generate a bunch of random users and load them into the set
                        }
                        else if (getInput == "10"){
                            //todo display the entire database
                        }
                        else {
                            clearScreen();
                            printf("Sorry, invalid input.  Please enter a number from the list.\n\n");
                        }
                    }
                }
                else {
                    getInput.clear();
                    printf("Sorry, that was not valid, please enter again (yes/no): ");
                }
            }
            
            
            
        }
        //If the help option is selected, print an extended usage blub.
        else if (strcmp(argv[1], "--help") == 0){
            printf("Beginning project without any options starts the iButton\n");
            printf("daemon.  Using -admin starts the program in configuration\n");
            printf("mode.  This allows the administrator to modify the master\n");
            printf("file that holds all the valid users.\n");
        }
        //If invalid print usage statement.
        else {
            printf("Usage: project [-admin] or [--help]\n");
        }
    }
    else {
        printf("Usage: project [-admin] or [--help]\n");
    }
    
	return 0;
}
