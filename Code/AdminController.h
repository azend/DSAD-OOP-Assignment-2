//
//  AdminController.h
//  
//
//  Created by Ian Campbell on 2013-04-19.
//
//

#ifndef ____AdminController__
#define ____AdminController__

#include <iostream>
#include <set>
#include "Member.h"

class AdminController {
private:
    //The SET that stores Member objects
    set<Member> userDB;
    
public:
    //constructors
    AdminController();
    AdminController(char * newDBPath); //use this to open a new file and save it to the set
    //SET methods
    void DisplayUser(void);
    void AddUser(void);
    void DeleteUser(void);
    void DeleteSET(void);
    void SaveSETToFile(void);
    //Carlo's Cheater Method
    void AddTonsOfUsers(void);
    
    
};

#endif /* defined(____AdminController__) */
