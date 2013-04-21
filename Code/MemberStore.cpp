#ifndef _MEMBERSTORE_CPP_
#define _MEMBERSTORE_CPP_

#include "MemberStore.h"


const string MemberStore::kDefaultDbPath = "db.txt";

MemberStore::MemberStore() {
    hasChanged = false;
}

MemberStore::~MemberStore() {

}


 void MemberStore::CreateMember ( const Member newMember, const bool quiet ) {
	#ifdef DEBUG
	//cout << "Adding a new member to the store... ";
	#endif

    members.emplace( newMember );
     
     hasChanged = true;
    
    #ifdef DEBUG
    //cout << "[DONE]" << endl;
    #endif
}


set<Member>::const_iterator MemberStore::FindMemberWithiButton ( const vector<unsigned char> & ibuttonAddr ) {
    
    set<Member>::const_iterator it = members.cbegin();
    while ( it != members.cend() ) {
        
        if ( it->Equals( ibuttonAddr ) ) {
            // Address found
            break;
        }
        
        it++;
    }
    
    return it;
}

vector<const Member*> MemberStore::FindMemberWithFirstName(const string &firstName) {
    vector<const Member*> results;
    
    set<Member>::const_iterator it = members.cbegin();
    while ( it != members.cend() ) {
        
        if ( it->GetFirstName().find(firstName) != string::npos ) {
            results.push_back(&*it);
            //results.push_back(&*it);
        }
        
        it++;
    }
    
    return results;
}

vector<const Member*> MemberStore::GetAllMembers () {
    vector<const Member*> vMembers;

    set<Member>::const_iterator it = members.cbegin();
    while ( it != members.cend() ) {
        
        vMembers.push_back(&*it);
        
        it++;
    }
    
    return vMembers;
}

const int MemberStore::CountMembers() {
    return int(members.size());
}

const bool MemberStore::CanHold( unsigned long numMembers) {
    return numMembers < members.max_size();
}

const bool MemberStore::HasChangedSinceLastSave() {
    return hasChanged;
}


void MemberStore::DeleteMember ( set<Member>::const_iterator it ) {
    members.erase(it);
    hasChanged = true;
}

void MemberStore::DeleteMember ( const Member & member ) {
    members.erase(member);
    hasChanged = true;
}

void MemberStore::Clear() {
    members.clear();
    hasChanged = true;
}

const bool MemberStore::LoadDb ( const string & path, const bool clearDbBeforeLoad ) {
    bool result = false;
    
    if ( clearDbBeforeLoad ) {
        members.clear();
    }
    
    ifstream db ( path, ifstream::in );
    
    if ( db ) {
        db >> *this;
		result = db.fail();
    }
    
    return result;
}

const bool MemberStore::StoreDb ( const string & path ) {
    bool result = false;
    
    ofstream db ( path, ofstream::out );
    
    if ( db ) {
        result = db << *this;
    }
    
    hasChanged = false;
    
    return result;
}

istream & operator>> ( istream & is, MemberStore & store ) {
    while ( is.good() ) {
        Member newMember;
        
        is >> newMember;

		// Check if it really is in fact good

		if ( is.good() ) {
			store.CreateMember( newMember, true );

			if ( is.fail() ) {
				// A record failed to parse.
				// As long as the stream has not ended or is bad, continue on
				is.clear();
			}
		}
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
