#ifndef _MEMBERSTORE_CPP_
#define _MEMBERSTORE_CPP_

#include "MemberStore.h"


const string MemberStore::kDefaultDbPath = "db.txt";

MemberStore::MemberStore() {
	#ifdef DEBUG
	cout << "MemberStore is now online." << endl;
	#endif
}

MemberStore::~MemberStore() {
	#ifdef DEBUG
	cout << "MemberStore is sinking!!1 Helpp meencsdocndioscndsioc *MemberStore drowns*" << endl;
	#endif
}


 void MemberStore::CreateMember ( const Member & newMember ) {
	#ifdef DEBUG
	cout << "Adding a new member to the store... ";
	#endif

    members.insert( newMember );
    
    #ifdef DEBUG
    cout << "[DONE]" << endl;
    #endif
}


set<Member>::const_iterator MemberStore::FindMemberWithiButton ( const vector<unsigned char> & ibuttonAddr ) {
    //return find ( members.begin(), members.end(), ibuttonAddr);
}


void MemberStore::DeleteMember ( set<Member>::const_iterator it ) {
    members.erase(it);
}

void MemberStore::DeleteMember ( const Member & member ) {
    members.erase(member);
}

void MemberStore::Clear() {
    members.clear();
}

void MemberStore::LoadDb ( const string & path, const bool clearDbBeforeLoad ) {
    if ( clearDbBeforeLoad ) {
        members.clear();
    }
    
    ifstream db ( path, ifstream::in );
    
    db >> *this;
}

void MemberStore::StoreDb ( const string & path ) {
    
    ofstream db ( path, ofstream::out );
    
    db << *this;
}

istream & operator>> ( istream & is, MemberStore & store ) {    
    while ( is.good() ) {
        Member newMember;
        
        is >> newMember;
        
        store.CreateMember(newMember);
    }
    
    return is;
}


ostream & operator<< ( ostream & os, MemberStore & store ) {
    for ( set<Member>::const_iterator it = store.members.begin(); it != store.members.end(); it++ ) {
        os << *it;
    }
    
    return os;
}


#endif
