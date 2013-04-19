#ifndef _MEMBERSTORE_CPP_
#define _MEMBERSTORE_CPP_

#include "MemberStore.h"

MemberStore::kDefaultDbPath = "db.txt";

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

MemberStore::CreateMember ( Member newMember ) {
	#ifdef DEBUG
	cout << "Adding a new member to the store:" << endl;
	cout << "Validating member... ";
	#endif

	if ( ValidateMember( newMember ) ) {
		#ifdef DEBUG
		cout << "[DONE]" << endl;
		#endif

		#ifdef DEBUG
		cout << "Inserting verified member." << endl;
		#endif
		members.insert( newMember );
	}
	else {
		#ifdef DEBUG
		cout << "[FAIL]" << endl;
		#endif
	}
}

// Replace with vector

//Member::FindMemberWithiButton ( unsigned char * ibuttonAddress ) {
//	// find_if 
//}

MemberStore::UpdateMember ( Member newMember ) {
	#ifdef DEBUG
	cout << "@TODO Implement update member" << endl;
	#endif
}

MemberStore::DeleteMember ( Member newMember ) {
	#ifdef DEBUG
	cout << "@TODO Implement delete member" << endl;
	#endif
}

string MemberStore::GetDbPath() {
	return dbPath;
}

bool MemberStore::SetDbPath ( string newPath ) {
	if ( ValidateDbPath ( newPath ) ) {
		dbPath = newPath;
	}
}

#endif
