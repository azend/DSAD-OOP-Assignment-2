#ifndef _MEMBERSTORE_H_
#define _MEMBERSTORE_H_

/**
 * @file MemberStore.h
 * @brief This file contains the member storage class.
 * @see MemberStore
 */


#include <set>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;

#include "Member.h"


class MemberStore {
public:
    static const string kDefaultDbPath; /**< Contains the default file path to the database file */
    
    /**
     * @brief Constructor.
     */
    MemberStore();
    
    /**
     * @brief Destructor.
     */
    virtual ~MemberStore();
    
    /**
     * @brief Takes a member object and adds it to the store.
     * @param newMember The new member to be added to the store.
     */
    virtual void CreateMember ( const Member newMember, const bool quiet = false );
    
    /**
     * @brief Searches the set to find a member with the same iButton keycode as the one passed in.
     * @param ibuttonAddr A vector of bytes to search for. This follows the same scheme as the address in Member does.
     @see Member
     */
    virtual set<Member>::const_iterator FindMemberWithiButton ( const vector<unsigned char> & ibuttonAddr );
    
    /**
     * @brief Searches the set to find a member with the same iButton keycode as the one passed in.
     * @param ibuttonAddr A vector of bytes to search for. This follows the same scheme as the address in Member does.
     @see Member
     */
    virtual vector<const Member*> FindMemberWithFirstName ( const string & firstName );
    
    /**
     * @brief Retrieves all of the objects in the store.
     * @return Returns a vector of Member objects
     * @see Member
     */
    virtual vector<const Member*> GetAllMembers();
    
    /**
     * @brief Counts the number of members in the store/
     * @return Returns the number of members found.
     */
    virtual const int CountMembers();
    
    /**
     * @brief Checks if the internal data structure can hold numMembers members.
     * @return Returns true if it can and false if it can't.
     */
    virtual const bool CanHold (unsigned long numMembers);
    
    /**
     * @brief Counts the number of members in the store/
     * @return Returns the number of members found.
     */
    virtual const bool HasChangedSinceLastSave();
    
    /**
     * @brief Deletes the member on the other end of the iterator.
     * @param it An iterator to the object in the set you'd like to destroy
     */
    virtual void DeleteMember ( set<Member>::const_iterator it );
    
    /**
     * @brief Deletes the member in the store
     * @param member A pointer to the object to delete
     */
    virtual void DeleteMember ( const Member & member );
    
    /**
     * @brief Wipes out any members currently stored in the store
     */
    virtual void Clear ();
    
    /**
     */
    
    virtual const bool LoadDb ( const string & path = kDefaultDbPath, const bool clearDbBeforeLoad = false );
    virtual const bool StoreDb ( const string & path = kDefaultDbPath );
    friend istream & operator>> (istream & is, MemberStore & store);
    friend ostream & operator<< (ostream & os, MemberStore & store);
    
private:
    
    set<Member> members;
    string dbPath;
    
    bool hasChanged;
    
};


#endif
