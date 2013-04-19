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

	if ( firstName.size() <= kFirstNameLength ) {
		result = true;
	}
	
	return result;
}
/*******************************************************************/
const bool Member::VerifyLastName ( const string & lastName ) {
	bool result = false;

	if ( lastName.size() <= kLastNameLength ) {
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
/*
Member::operator= () {

}
*/
/*********************************************************/
const vector<unsigned char> Member::GetiButtonAddr() {
	return ibuttonAddr;
}
/**********************************************************/
const string Member::GetFirstName() {
	return firstName;
}
/************************************************************/
const string Member::GetLastName() {
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
const bool Member::Less ( const Member & otherMember ) {
	bool result = false;

	if ( this == &otherMember ) {
		// Objects point to the same place
		// Obviously these objects are the same and so the test will fail
	}
	else {
		vector<unsigned char>::const_iterator it = ibuttonAddr.begin();
		vector<unsigned char>::const_iterator otherIt = otherMember.ibuttonAddr.begin();
		
		while ( it != ibuttonAddr.end() ) {
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
/**************************************************************************/
const bool Member::Less ( const vector<unsigned char> & otheriButtonAddress) {
	Member tempMember;

	tempMember.SetiButtonAddr(otheriButtonAddress);

	return Less(tempMember);
}
/**************************************************************************/
const bool Member::Equals ( const Member & otherMember ) {
	bool result = false;
	
	if ( this == &otherMember ) {
		// The memory locations are the same. No point in checking for anything else.
		result = true;
	}
	else {
		if ( firstName == otherMember.firstName && lastName == otherMember.lastName && ibuttonAddr == otherMember.ibuttonAddr ) {
			result = true;
		}
	}
	
	return result;
}
/*****************************************************************************/
const bool Member::Equals ( const vector<unsigned char> & otheriButtonAddr ) {
	bool result = false;

	if ( ibuttonAddr == otheriButtonAddr ) {
		result = true;
	}

	return result;
}
/*****************************************************************************/
const bool Member::operator< ( const Member & otherMember ) {
	return Less(otherMember);
}

const bool Member::operator< ( const vector<unsigned char> & otheriButtonAddress ) {
	return Less(otheriButtonAddress);
}

const bool operator< ( const Member & lhsMember, const Member & rhsMember ) {
    
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

/*
const bool operator< ( const vector<unsigned char> & ibuttonAddress, const Member & member) {
    Member tempMember;
    
	tempMember.SetiButtonAddr(ibuttonAddress);
    
    return tempMember < member;
}
*/
 
bool Member::operator== ( const Member & otherMember ) {
	return Equals(otherMember);
}

bool Member::operator== ( const vector<unsigned char> & otheriButtonAddress ) {
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
    string numbuf;
    getline(is, buffer);
    
    smatch sm;
    if ( regex_match( buffer, sm, regex("^(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3});([!\\w\\d ]{0,30});([-'!\\w\\d ]{0,30})$") ) ) {
        
        vector<unsigned char> ibuttonAddr;
        
        //numbuf = sm[2];
        
        for (int x = 1; x < 8; x++) {
            ibuttonAddr.push_back( (unsigned char) atoi( sm.str(x).c_str() ) );
        }
        
        member.SetiButtonAddr(ibuttonAddr);
        member.SetFirstName(sm.str(8));
        member.SetLastName(sm.str(9));

    }
    else {
        cerr << "Parsing member record failed:" << endl;
        cerr << "\t\"" << buffer << "\"" << endl;
    }
    
    return is;
}

#endif

