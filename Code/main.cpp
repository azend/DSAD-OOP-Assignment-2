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
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>

#include "Member.h"
//#include "DoorBot.h"
#include "MemberStore.h"

//namespaces
using namespace std;

//Prototypes
void clearScreen();

void pause () {
    string input;
    cout << endl << "Press ENTER to continue" << endl;
    getline( cin, input );
}

bool AskYesNoConfirmation ( string confirmation, bool defaultYes = true ) {
    bool result = defaultYes;
    bool valid = false;
    string input;
    
    cout << confirmation << " (";
    
    if ( defaultYes ) {
        cout << "Y/n";
    }
    else {
        cout << "y/N";
    }
    
    cout << ")" << endl;
    
    do {
        getline( cin, input );
        
        if ( input.length() <= 1 ) {
            if ( input.find("y") != string::npos|| input.find("Y") != string::npos ) {
                // Yes
                result = true;
                valid = true;
            }
            else if ( input.find("n") != string::npos|| input.find("N") != string::npos ) {
                // No
                result = false;
                valid = true;
            }
            else if ( input.length() > 0 ) {
                // Some other character
                cout << "That option was invalid. Please try again." << endl;
            }
            else {
                // Just pressed enter
                valid = true;
            }
        }        
    } while ( !valid );
    
    return result;
    
}

void clearScreen() {
    //the saddest little function :-)
    int i = 0;
    int breakFlag = 0;
    for (i = 0; i < 10; i++){
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
}

void AddMember (MemberStore & store) {
    
    string input;
    
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
    cout << "Example: \"00:11:22:33:44:55:66\" or \"1A:2B:3C:4D:5E:6F:7A\"" << endl;
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
    
    cout << endl;
    cout << "Now adding the new member to the store... ";
    store.CreateMember(newMember);
    cout << "[DONE]" << endl;
    
    pause();
    
    clearScreen();
}


void DeleteMember (MemberStore & store) {
    cout << "Delete Member Wizard" << endl;
    cout << "--------------------" << endl;
    cout << "Please enter the name of the person you wish to delete" << endl;
    cout << "Name: ";
    
    string searchTerms;
    getline(cin, searchTerms);
    
    vector<const Member*> results = store.FindMemberWithFirstName(searchTerms);
    
    //find the name
    if (results.size() == 0){
        cout << "Sorry, a member with the first name " << searchTerms << " is not in the database." <<endl;
    }
    else if (results.size() == 1) {
        //delete user
        cout << "Deleting member " << results.front()->GetFirstName() << " " << results.front()->GetLastName() << endl;
        
        if ( AskYesNoConfirmation("Are you sure you want to do this?", false) ) {
            store.DeleteMember(*(results.front()));
            cout << "Member successfully deleted." << endl;
        }
        else {
            cout << "Member deletion cancelled." << endl;
            cout << "Phew! That was a close one!" << endl;
        }
        
    }
    
    pause();
    clearScreen();
}

void EraseDatabase ( MemberStore & store ) {
    
    cout << "WARNING: Are you sure you want to erase the database? (yes/no)" << endl;
    
    if (AskYesNoConfirmation("WARNING: Are you sure you want to erase the database?", false)) {
        //delete the set
        
        store.Clear();
        
        cout << "Database erased successfully" << endl;
    }
    else {
        cout << "Member deletion cancelled." << endl;
        cout << "PHEW! That was a close one!" << endl;
    }
    
    pause();
    clearScreen();
}

void ViewMember ( MemberStore & store ) {
    
    string search;
    
    cout << "View Member Wizard" << endl;
    cout << "------------------" << endl;
    cout << "Please enter the name of the person you wish to view" << endl;
    cout << "Name: ";
    
    getline(cin, search);
    
    //find the name
    vector<const Member*> results = store.FindMemberWithFirstName(search);
    
    if (results.size() == 0){
        cout << "Sorry, that name is not in the database" <<endl;
    }
    else if (results.size() > 0) {
        //display user
        
        cout << results.size() << " results found:" << endl;
        cout << endl;
        cout << "iButton Keycode          F. Name     L. Name" << endl;
        cout << "--------------------------------------------" << endl;
        
        for ( vector< const Member*>::const_iterator it = results.cbegin(); it != results.cend(); it++ ) {
            
            cout << (*it)->GetiButtonAddrStr() << " " << (*it)->GetFirstName() << " " << (*it)->GetLastName() << endl;
            
        }
        
    }
    
    pause();
    clearScreen();
}

void LoadDatabase ( MemberStore & store ) {
    
    string path;
    
    cout << "Load Database Wizard" << endl;
    cout << "--------------------------" << endl;
    cout << "Please type a valid path to a new database file." << endl;
    cout << "Example: \"/etc/DoorBot/DoorUsers.txt\" or \"db.txt\"" << endl;
    cout << "Defaults to \"db.txt\" if no path is provided." << endl;
    cout << "Path: ";
    getline(cin, path);
    
    // Set defaults if the user did not specify a path
    if ( path.empty() ) {
        path = "db.txt";
    }
    
    cout << endl;
    cout << "Attempting to import database from file...";
    
    
    if (store.LoadDb(path)){
        cout << "[DONE]" << endl;
    }
    else {
        cout << "[FAIL]" << endl;
        cerr << "Attepted to open file \"" << path << "\". File resource could not be read." << endl;
    }
    
    pause();
    clearScreen();
}

void StoreDatabase ( MemberStore & store ) {
    
    string path;
    
    cout << "Store Database Wizard" << endl;
    cout << "--------------------------" << endl;
    cout << "Please type a valid path to a where you would like to save your database." << endl;
    cout << "Example: \"/etc/DoorBot/DoorUsers.txt\" or \"db.txt\"" << endl;
    cout << "Defaults to \"db.txt\" if no path is provided." << endl;
    cout << "Note: If the path specified already exists, it will be overwritten without warning." << endl;
    cout << "Path: ";
    getline(cin, path);
    
    // Set defaults if the user did not specify a path
    if ( path.empty() ) {
        path = "db.txt";
    }
    
    cout << endl;
    
    if ( store.CountMembers() > 100000 ) {
        cout << "Hey there big boy! You sure have a lot of records. This may take a bit longer than normal if you get what I mean." << endl;
    }
    
    cout << "Attempting to export database to file... ";
    cout.flush();
    
    if (store.StoreDb(path)){
        cout << "[DONE]" << endl;
    }
    else {
        cout << "[FAIL]" << endl;
        cerr << "Attepted to open file \"" << path << "\". File resource could not be written." << endl;
    }
    
    cout << endl;
    
    pause();   
    clearScreen();
}

bool ExitSavingChanges ( MemberStore & store ) {
    string path;
    bool storeSuccessful = false;
    
    cout << "Please type a valid path to a where you would like to save your database." << endl;
    cout << "Example: \"/etc/DoorBot/DoorUsers.txt\" or \"db.txt\"" << endl;
    cout << "Defaults to \"db.txt\" if no path is provided." << endl;
    cout << "Note: If the path specified already exists, it will be overwritten without warning." << endl;
    cout << "Path: ";
    getline(cin, path);
    
    // Set defaults if the user did not specify a path
    if ( path.empty() ) {
        path = "db.txt";
    }
    
    cout << endl;
    
    if ( store.CountMembers() > 100000 ) {
        cout << "Hey there big boy! You sure have a lot of records. This may take a bit longer than normal if you get what I mean." << endl;
    }
    
    cout << "Attempting to export database to file... ";
    cout.flush();
    
    if ( (storeSuccessful = store.StoreDb(path) ) ){
        cout << "[DONE]" << endl;
    }
    else {
        cout << "[FAIL]" << endl;
        cerr << "Attepted to open file \"" << path << "\". File resource could not be written." << endl;
    }
    
    pause();
    clearScreen();
    
    return storeSuccessful;
}

bool ExitDiscardingChanges ( MemberStore & store ) {
    bool result = false;
    
    if ( store.HasChangedSinceLastSave() ) {
        if ( AskYesNoConfirmation("Changes have been made since your last save. Are you sure you would like to discard these changes and exit?")) {
            cout << "Discarding changes. " << endl;
            
            result = true;
        }
        
    }
    else {
        cout << endl << "Goodbye!" << endl;
        result = true;
    }
    
    return result;
}

void CarloSpecial ( MemberStore & store ) {
    cout << "The Cheater Wizard" << endl;
    cout << "------------------" << endl;
    cout << "NOTE: This function may not output exactly the number of records it is told to input. The reason for is that the algorithm for generating members can, in large numbers, generate duplicates. Duplicate members will not be added to the store." << endl;
    cout << endl;
    
    string sNumRecords;
    unsigned long int numRecordsToGenerate = 0;
    
    cout << "Please enter the number of records you would like to generate:" << endl;
    cout << "Example: \"5\" or \"10000\". Please do not include any seperators such as \",\" native to your language." << endl;
    cout << "# of records: ";
    getline( cin, sNumRecords );
    cout << endl;
    
    numRecordsToGenerate = strtoul(sNumRecords.c_str(), NULL, 10);
    
    if ( numRecordsToGenerate > 0L && store.CanHold(numRecordsToGenerate) ) {
        cout << "Generating " << numRecordsToGenerate << " records. Please wait..." << endl;
        
        srand(time(NULL));
        
        for ( long int i = 0; i < numRecordsToGenerate; i++) {
            
            if ( numRecordsToGenerate > 1000 && ( i % ( numRecordsToGenerate / 10 ) ) == 0 && i > 0 ) {
                cout << i << " records done..." << endl;
            }
            
            Member newMember;
            vector<unsigned char> ibuttonAddr;
            stringstream firstName;
            stringstream lastName;
            
            for ( int ibuttonBytes = 0; ibuttonBytes < IBUTTON_BYTES; ibuttonBytes++ ) {
                ibuttonAddr.push_back(rand() % 256);
            }
            
            firstName << (i + 1) << " Hugh";
            lastName << "Man";
            
            
            newMember.SetiButtonAddr(ibuttonAddr);
            newMember.SetFirstName(firstName.str());
            newMember.SetLastName(lastName.str());
            
            store.CreateMember(newMember);
            
        }
        cout << "Success!" << endl;
    }
    else if ( numRecordsToGenerate >= store.CanHold(numRecordsToGenerate) ) {
        cout << "Were sorry but the current ram available, we can't store that many members." << endl;
    }
    else {
        cout << "Was that supposed to be a number?" << endl;
    }
    
    pause();
    clearScreen();
}

void GetAllMembers (MemberStore & store) {
    vector<const Member*> results = store.GetAllMembers();
    
    if (results.size() == 0){
        cout << "Sorry, there are no records in the database" <<endl;
    }
    else if (results.size() > 0) {
        //display user
        
        cout << results.size() << " results found:" << endl;
        cout << endl;
        cout << "iButton Keycode          F. Name     L. Name" << endl;
        cout << "--------------------------------------------" << endl;
        
        for ( vector< const Member*>::const_iterator it = results.cbegin(); it != results.cend(); it++ ) {
            
            cout << (*it)->GetiButtonAddrStr() << " " << (*it)->GetFirstName() << " " << (*it)->GetLastName() << endl;
            
        }
        
    }
    
    pause();
    clearScreen();
}


int main(int argc, char *argv[]) {
    
    cout << "      ___           ___           ___           ___           ___     \r\n     \/\\  \\         \/\\  \\         \/\\  \\         \/\\__\\         \/\\  \\    \r\n    \/::\\  \\        \\:\\  \\       \/::\\  \\       \/::|  |       \/::\\  \\   \r\n   \/:\/\\:\\  \\        \\:\\  \\     \/:\/\\:\\  \\     \/:|:|  |      \/:\/\\:\\  \\  \r\n  \/::\\~\\:\\  \\        \\:\\  \\   \/::\\~\\:\\  \\   \/:\/|:|  |__   \/:\/  \\:\\__\\ \r\n \/:\/\\:\\ \\:\\__\\ _______\\:\\__\\ \/:\/\\:\\ \\:\\__\\ \/:\/ |:| \/\\__\\ \/:\/__\/ \\:|__|\r\n \\\/__\\:\\\/:\/  \/ \\::::::::\/__\/ \\:\\~\\:\\ \\\/__\/ \\\/__|:|\/:\/  \/ \\:\\  \\ \/:\/  \/\r\n      \\::\/  \/   \\:\\~~\\~~      \\:\\ \\:\\__\\       |:\/:\/  \/   \\:\\  \/:\/  \/ \r\n      \/:\/  \/     \\:\\  \\        \\:\\ \\\/__\/       |::\/  \/     \\:\\\/:\/  \/  \r\n     \/:\/  \/       \\:\\__\\        \\:\\__\\         \/:\/  \/       \\::\/__\/   \r\n     \\\/__\/         \\\/__\/         \\\/__\/         \\\/__\/         ~~    " << endl;
    
    cout << endl;
    
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
            
            bool quit = false;
            MemberStore store;
            
            printf("----Welcome to the Device Configuration Utility----\n\n");
            printf("The Daemon will need to be restarted if the database is updated.\n");
            
            if ( AskYesNoConfirmation("Do you wish to proceed?") ) {
                
                string menuChoice;

                while (!quit){
                    //print the menu interface
                    printf("---------MAIN MENU---------\n\n");
                    printf("1, Add a user\n");
                    printf("2, Delete a user\n");
                    printf("3, Delete entire database\n");
                    printf("4, Display a user\n");
                    printf("5, Load Database From File\n");
                    printf("6, Save changes\n");
                    printf("7, Save changes and exit\n");
                    printf("8, Exit without saving\n");
                    printf("9, Carlo Special: Cheat and add a bunch of random users to database\n");
                    printf("10, Display the entire database\n\n");
                    printf("Please enter your choice: ");
                    //get a choice from the user
                    getline(cin, menuChoice);
                    cout << endl << endl;
                    
                    if (menuChoice == "1"){
                        AddMember(store);
                    }
                    else if (menuChoice == "2"){
                        DeleteMember(store);
                        
                    }
                    else if (menuChoice == "3"){
                        EraseDatabase(store);
                    }
                    else if (menuChoice == "4"){
                        ViewMember(store);
                    }
                    
                    else if (menuChoice == "5"){
                        LoadDatabase(store);
                    }
                    else if (menuChoice == "6"){
                        StoreDatabase(store);
                    }
                    else if (menuChoice == "7"){
                        quit = ExitSavingChanges(store);
                    }
                    else if (menuChoice == "8"){
                        //exit without saving
                        quit = ExitDiscardingChanges(store);
                    }
                    else if (menuChoice == "9"){
                        CarloSpecial(store);
                    }
                    else if (menuChoice == "10"){
                        GetAllMembers(store);

                    }                    
                    else {
                        cout << "That was not a valid menu choice." << endl;
                        pause();
                    }
                    
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

