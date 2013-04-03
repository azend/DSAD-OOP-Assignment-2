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
	firstName = newFirstName;
	
}

bool Member::SetLastName ( std::string newLastName ) {
	lastName = newLastName;
}

#endif
