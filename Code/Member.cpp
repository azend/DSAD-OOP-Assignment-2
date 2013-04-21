#ifndef _MEMBER_CPP_
#define _MEMBER_CPP_

#include "Member.h"

const int Member::kiButtonLength = 7;
const int Member::kFirstNameLength = 30;
const int Member::kLastNameLength = 30;

/*******************************************************************/
const bool Member::VerifyiButtonAddr ( const vector<unsigned char> & ibuttonAddr) {
	bool result = false;
	
	if ( ibuttonAddr.size() == kiButtonLength ) {
		result = true;
	}

	return result;
}

/*******************************************************************/

const bool Member::VerifyFirstName ( const string & firstName ) {
	bool result = false;

	if ( 
		firstName.size() <= kFirstNameLength && // Make sure the length is less than 30 chars
	       	firstName.find(";") == string::npos && // Make sure the string doesn't contain any ;
	  	firstName.find("\r") == string::npos && // or \r
	  	firstName.find("\n") == string::npos // or \n
	) {
		result = true;
	}
	
	return result;
}

/*******************************************************************/

const bool Member::VerifyLastName ( const string & lastName ) {
	bool result = false;

	if ( 
		lastName.size() <= kFirstNameLength && // Make sure the length is less than 30 chars
	       	lastName.find(";") == string::npos && // Make sure the string doesn't contain any ;
	  	lastName.find("\r") == string::npos && // or \r
	  	lastName.find("\n") == string::npos // or \n
	) {
		result = true;
	}
	
	return result;
}

/***********************************************************/

Member::Member() {

	for (int i = 0; i < kiButtonLength; i++) {
		ibuttonAddr.push_back(0);
	}

	firstName = "";
	lastName = "";

}

/*********************************************************/

Member::~Member() {
	// Nothing we need to do here really
}

/*********************************************************/

const vector<unsigned char> Member::GetiButtonAddr() const {
	return ibuttonAddr;
}

const string Member::GetiButtonAddrStr() const {
    string result;
    
    // Buffer of 1 byte written out in hex + null termination
    char buffer[3];
    
    for ( vector<unsigned char>::const_iterator it = ibuttonAddr.cbegin(); it != ibuttonAddr.cend(); it++ ) {
        
	// Use good ol' C strings to help us write out some hex
        sprintf(buffer, "%02X", *it);
        
        if ( it != --(ibuttonAddr.cend() ) ) {

            result += buffer;
            result += ":";
        }
        else {
            result += buffer;
        }
        
    }
    
    return result;
}
/**********************************************************/
const string Member::GetFirstName() const {
	return firstName;
}
/************************************************************/
const string Member::GetLastName() const {
	return lastName;
}
/***********************************************************/
const bool Member::SetiButtonAddr ( const vector<unsigned char> & newiButtonAddr ) {
	bool result = false;

	if ( VerifyiButtonAddr ( newiButtonAddr ) ) {
		ibuttonAddr = newiButtonAddr;

		result = true;
	}
	
	return result;
}
/**************************************************************/
const bool Member::SetFirstName ( const string & newFirstName ) {
	bool changed = false;

	if ( VerifyFirstName( newFirstName ) ) {
		firstName = newFirstName;
		changed = true;
	}
	
	return changed;
}
/*************************************************************/
const bool Member::SetLastName ( const string & newLastName ) {
	bool changed = false;

	if ( VerifyLastName ( newLastName ) ) {
		lastName = newLastName;
		changed = true;
	}
	
	return changed;
}

/**************************************************************************/
const bool Member::Less ( const Member & otherMember ) const {
	bool result = false;

	if ( this == &otherMember ) {
		// Objects point to the same place
		// Obviously these objects are the same and so the test will fail
	}
	else {
		vector<unsigned char>::const_iterator it = ibuttonAddr.begin();
		vector<unsigned char>::const_iterator otherIt = otherMember.ibuttonAddr.begin();
		
		// Check each byte sequentially until one is found which is less
		// than another
		while ( it != ibuttonAddr.end() ) {
			if ( *it < *otherIt ) {
				// The byte is lesser
				result = true;
				break;
			}
			else if ( *it > *otherIt ) {
				// The byte is greater
				break;
			}
			else {
				++it;
				++otherIt;
			}
		}
	}

	return result;
}
/**************************************************************************/
const bool Member::Less ( const vector<unsigned char> & otheriButtonAddress) const{
	Member tempMember;

	tempMember.SetiButtonAddr(otheriButtonAddress);

	return Less(tempMember);
}
/**************************************************************************/
const bool Member::Equals ( const Member & otherMember ) const {
	bool result = false;
	
	if ( this == &otherMember ) {
		// The memory locations are the same. No point in checking for anything else.
		result = true;
	}
	else {
		// If the first name, last name, and iButton addresses line up, they're the same
		if ( firstName == otherMember.firstName && lastName == otherMember.lastName && ibuttonAddr == otherMember.ibuttonAddr ) {
			result = true;
		}
	}
	
	return result;
}
/*****************************************************************************/
const bool Member::Equals ( const vector<unsigned char> & otheriButtonAddr ) const {
	bool result = false;

	if ( ibuttonAddr == otheriButtonAddr ) {
		result = true;
	}

	return result;
}
/*****************************************************************************/
const bool Member::operator< ( const Member & otherMember ) const {
	return Less(otherMember);
}

const bool Member::operator< ( const vector<unsigned char> & otheriButtonAddress ) const {
	return Less(otheriButtonAddress);
}

/*
const bool operator< ( const Member & lhsMember, const Member & rhsMember ){
    
    bool result = false;
    
	if ( &lhsMember == &rhsMember ) {
		// Objects point to the same place
		// Obviously these objects are the same and so the test will fail
	}
	else {
		vector<unsigned char>::const_iterator it = lhsMember.ibuttonAddr.begin();
		vector<unsigned char>::const_iterator otherIt = rhsMember.ibuttonAddr.begin();
		
		while ( it != lhsMember.ibuttonAddr.end() ) {
			if ( *it < *otherIt ) {
				result = true;
				break;
			}
			else if ( *it > *otherIt ) {
				break;
			}
			else {
				++it;
				++otherIt;
			}
		}
	}
    
    return result;
}
*/ 

/*
const bool operator< ( const vector<unsigned char> & ibuttonAddress, const Member & member) {
    Member tempMember;
    
	tempMember.SetiButtonAddr(ibuttonAddress);
    
    return tempMember < member;
}
*/
 
bool Member::operator== ( const Member & otherMember ) const {
	return Equals(otherMember);
}

bool Member::operator== ( const vector<unsigned char> & otheriButtonAddress ) const {
	return Equals(otheriButtonAddress);
}

ostream & operator<< ( ostream & os, const Member & member ) {
    
    for ( vector<unsigned char>::const_iterator it = member.ibuttonAddr.begin(); it != member.ibuttonAddr.end(); it++ ) {
        os << int(*it);
        
        if ( it != --(member.ibuttonAddr.end()) ) {
            os << ":";
        }
    }
    
    os << ";" << member.firstName << ";" << member.lastName << endl;
    
    return os;
}

istream & operator>> (istream & is, Member & member) {
    string buffer;
    getline(is, buffer);
    
    if ( buffer.empty() ) {
        cerr << "Record empty. Ignoring." << endl;
    }
    else {
	    // Check that the record meets a fairly strict regex
        smatch sm;
        if ( regex_match( buffer, sm, regex("^(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3});([ !\\w\\d]{0,30});([ -'!\\w\\d]{0,30})\r?\n?$") ) ) {

		// If it matchs the regex, the results must consist of the following values
		// 	1. The full string
		// 	1-7. Bytes in the iButton address
		// 	8. The first name of the member
		// 	9. The last name of the member

            vector<unsigned char> ibuttonAddr;
            
            
            for (int x = 1; x < 8; x++) {
                ibuttonAddr.push_back( (unsigned char) atoi( sm.str(x).c_str() ) );
            }
            
            member.SetiButtonAddr(ibuttonAddr);
            member.SetFirstName(sm.str(8));
            member.SetLastName(sm.str(9));
            
        }
        else {
            cerr << "Corrupt db record found parsing member records: \"" << buffer << "\"" << endl;
        }
    }
    
    
    
    return is;
}

#endif

