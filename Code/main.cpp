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
//#include "DoorBot.h"
#include "MemberStore.h"

//namespaces
using namespace std;

//Prototypes
void clearScreen();

void clearScreen() {
    //the saddest little function :-)
    int i = 0;
    int breakFlag = 0;
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
                            cout << "Press Enter to continue" << endl;
                            getline(cin, getInput);
                            getInput.clear();
                            
                            clearScreen();
                            
                            
                        }
                        else if (getInput == "2"){
                            cout << "Delete Member Wizard" << endl;
                            cout << "--------------------" << endl;                            
                            cout << "Please enter the name of the person you wish to delete" << endl;
                            cout << "Name:";
                            
                            getline(cin, getInput);
                            
                            //find the name
                            if (/*name not found*/){
                                cout << "Sorry, that name is not in the database" <<endl;
                            }
                            else {
                                //delete user
                                cout << "Member successfully deleted." << endl;
                            }
                            getInput.clear();
                            cout << "Press Enter to continue" << endl;
                            getline(cin, getInput);
                            getInput.clear();
                            clearScreen();
                            
                        }
                        else if (getInput == "3"){
                            cout << "WARNING: Are you sure you want to erase the database? (yes/no)" << endl;
                            getline(cin, getInput);
                            if (getInput == "yes" || getInput == "y" || getInput == "Yes" || getInput == "Y"){
                                //delete the set
                                cout << "Database erased successfully" << endl;
                                cout << "Press Enter to continue" << endl;
                                getline(cin, getInput);
                                getInput.clear();
                            }
                            clearScreen();
                        }
                        else if (getInput == "4"){
                            cout << "View Member Wizard" << endl;
                            cout << "------------------" << endl;
                            cout << "Please enter the name of the person you wish to view" << endl;
                            cout << "Name:";
                            
                            getline(cin, getInput);
                            
                            //find the name
                            if (/*name not found*/){
                                cout << "Sorry, that name is not in the database" <<endl;
                            }
                            else {
                                //display user
                                getInput.clear();
                            }
                            getInput.clear();
                            cout << "Press Enter to Continue" << endl;
                            getline(cin, getInput);
                            getInput.clear();
                            clearScreen();
                        }
                        else if (getInput == "5"){
                            cout << "Import New Database Wizard" << endl;
                            cout << "--------------------------" << endl;
                            cout << "Please type a valid path to a new database file." << endl;
                            cout << "Path: ";
                            getline(cin, getInput);
                            if (/*input is valid*/){
                                //new database
                            }
                            
                        }
                        else if (getInput == "6"){
                            cout << "Saving Database" << endl;
                            //save
                            clearScreen();
                        }
                        else if (getInput == "7"){
                            cout << "Saving Database" << endl;
                            store.~MemberStore;
                            cout << "Goodbye" << endl;
                            cout << "Press Enter to Continue" << endl;
                            getline(cin, getInput);
                            getInput.clear();
                            breakFlag = 1;
                            break;
                        }
                        else if (getInput == "8"){
                            //exit without saving
                            printf("\nGoodbye\n");
                            cout << "Press Enter to Continue" << endl;
                            getline(cin, getInput);
                            getInput.clear();
                            breakFlag = 1;
                            break;
                        }
                        else if (getInput == "9"){
                            cout << "The Cheater Wizard" << endl;
                            cout << "------------------" << endl;
                            //populate database
                            cout << "Success!" << endl;
                            cout << "Press Enter to Continue" << endl;
                            getline(cin, getInput);
                            getInput.clear();
                            clearScreen();                            
                        }
                        else if (getInput == "10"){
                            cout << "Printing Database....." << endl;
                            //print database
                            cout << "Press Enter to Continue" << endl;
                            getline(cin, getInput);
                            getInput.clear();
                            clearScreen();
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
                if (breakFlag == 1){
                    break;
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
