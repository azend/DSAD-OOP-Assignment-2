#ifndef _MEMBERREADER_CPP_
#define _MEMBERREADER_CPP_

#include <iostream>
#include "MemberReader.h"


ifstream& MemberReader::operator>> ( Member& ) {
	Member steve;

	// Check that the stream is still open and everything is good
	if ( good() ) {
			
		std::string keyCode = "";
		std::string fullName = "";


	}

	return steve;
}


#endif
