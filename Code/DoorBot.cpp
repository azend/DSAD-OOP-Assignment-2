#ifndef _DOORBOT_CPP_
#define _DOORBOT_CPP_

#include "DoorBot.h"

bool DoorBot::ValidateDbPath ( std::string path ) {
	bool result = false;

	// Try establishing a connection to the database
	std::ifstream pathFp ( path.c_str() );

	// Check if a connection was established
	if ( pathFp ) {
		// If it was, the path is valid
		result = true;
	}
	
	return result;
}

DoorBot::DoorBot() {
	dbPath = DEFAULT_DB_PATH;
}

DoorBot::~DoorBot() {

}

void DoorBot::Setup() {
	LoadMembers();
}


void DoorBot::LoadMembers() {
	// Establish a connection to the database (or file)
	MemberReader db ( GetDbPath().c_str() );
	Member jimmieTheBuffer;

	while ( !db ) {
		// Grab a member from the database
		db >> jimmieTheBuffer;

		// Stick it in our run-time set
		members.emplace(jimmieTheBuffer);
	}
}

void DoorBot::Loop() {
	// while (1) {
	// 	// Check if an iButton has been placed on the door lock
	// 	
	// 	// If it has, check the lock against our database of keys
	// 	
	// 	// If found in the db, let them in
	// 	// Otherwise, mock them
}

std::string DoorBot::GetDbPath () {
	return dbPath;
}

bool DoorBot::SetDbPath ( std::string newPath ) {
	bool result = false;

	if ( result = ValidateDbPath ( newPath ) ) {
		dbPath = newPath;
        result = true;
	}

	return result;
}

#endif
