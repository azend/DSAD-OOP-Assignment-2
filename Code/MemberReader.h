#ifndef _MEMBERREADER_H_
#define _MEMBERREADER_H_

#include <fstream>
#include <iostream>

#include "Member.h"

#define FIELD_DELIMITER ';' /**< The character to seperate between different fields in a database record. */

class MemberReader : public std::ifstream {
public:
	MemberReader();
	virtual ~MemberReader();
	ifstream& operator>> ( Member& );


private:
	/* data */
};

#endif
