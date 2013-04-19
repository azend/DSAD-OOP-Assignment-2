#ifndef _MEMBERSTORE_H_
#define _MEMBERSTORE_H_

/**
 * @file MemberStore.h
 * @brief This file contains the member storage class.
 * @see MemberStore
 */


#include <set>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;

#include "Member.h"


class MemberStore {
	public:
        static const string kDefaultDbPath;
    
		MemberStore();
		virtual ~MemberStore();

		virtual void CreateMember ( const Member & newMember );
		
    virtual set<Member>::const_iterator FindMemberWithiButton ( const vector<unsigned char> & ibuttonAddr );
        virtual void DeleteMember ( set<Member>::const_iterator it );
        virtual void DeleteMember ( const Member & member );
        virtual void Clear ();

        virtual void LoadDb ( const string & path = kDefaultDbPath, const bool clearDbBeforeLoad = false );
        virtual void StoreDb ( const string & path = kDefaultDbPath );
        friend istream & operator>> (istream & is, MemberStore & store);
        friend ostream & operator<< (ostream & os, MemberStore & store);

	private:

		set<Member> members;
		string dbPath;

};


#endif
