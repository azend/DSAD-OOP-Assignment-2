#ifndef _MEMBER_CPP_
#define _MEMBER_CPP_

#include "Member.h"

bool Member::VerifyiButtonAddr ( unsigned char * ibuttonAddr ) { 
	bool result = false;

	if ( ibuttonAddr != NULL && (sizeof ibuttonAddr) == (sizeof unsigned char) * IBUTTON_BYTES ) {
		result = true;
	}

	return result;
}

Member::Member() {
	ibuttonAddr = {0};
	firstName = "";
	lastName = "";
}

Member::~Member() {
	
}

unsigned const char * GetiButtonAddr() {
	return ibuttonAddr;
}

std::string GetFirstName() {
	return firstName;
}

std::string GetLastName() {
	return lastName;
}

bool Member::SetiButtonAddr ( unsigned char * newAddr ) {
	bool result = false;

	if ( VerifyiButtonAddr( newAddr ) ) {
		for (int x = 0; x < IBUTTON_BYTES; x++) {
			ibuttonAddr[x] = newAddr[x];
		}

		result = true;
	}

	return result;
}

bool Member::SetFirstName ( std::string newFirstName ) {
	bool valid = false;
    if (sizeof(newFirstName) <= 30 && sizeof(newFirstName) > 0){
        firstName = newFirstName;
        valid = true;
	}
    else {
        valid = false;
    }
    return valid;
}

bool Member::SetLastName ( std::string newLastName ) {
	bool valid = false;
    if (sizeof(newLastName) <= 30 && sizeof(newLastName) > 0){
        lastName = newLastName;
        valid = true;
    }
    else {
        valid = false;
    }
}

// - Ian's note
// - Add these to the test harness when finished
//                      |
//                      |
//                      V

bool Member::CompareiButtonAddr( unsigned char * ibuttonAddr ) {
	bool result = true;

	// Before looking through the new address, make sure it is 
	// even valid first
	if ( VerifyiButtonAddr ( ibuttonAddr ) ) {

		// Check each byte for correctness until an incorrect byte is found
		for (int i = 0; (i < (sizeof ibuttonAddr) / (sizeof unsigned char)) && result; i++) {
			// If the byte is incorrect, the iButtons are not the same
			if ( this->ibuttonAddr[i] != ibuttonAddr[i] ) {
				result = false;
			}
		}
	}

	return result;
}

bool Member::Equals ( Member & otherMember ) {
	bool result = false;

	if ( this == &otherMember ) {
		// The memory locations are the same. No point in checking for anything else.
		result = true;
	}
	else {
		if ( firstName == otherMember.firstName &&
			lastName == otherMember.lastName &&
			CompareiButtonAddr(otherMember.GetiButtonAddr)
		   ) {
			result = true;
		}
	}

	return result;
}


bool Member::operator== ( Member & otherMember ) {
	return Equals(otherMember);
}

#endif
