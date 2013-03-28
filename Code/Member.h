
#ifndef _MEMBER_H_
#define _MEMBER_H_

/**
 * 
 * @file Member.h
 *
 * @brief This file holds Member class.
 *
 */

#include <iostream>

#define IBUTTON_BYTES /**< The number of bytes in an iButton address */

/**
 *
 * @class Member
 * @brief This class models a member
 *
 */
class Member {

	private:
		unsigned char ibuttonAddr[IBUTTON_BYTES];
		std::string firstName;
		std::string lastName;

	public:
		/* Constructors / Deconstructors */
		Member();
		~Member();

		/* Accessors */
		unsigned char * GetiButtonAddr();
		std::string GetFirstName();
		std::string GetLastName();

		/* Mutators */
		void SetiButtonAddr ( unsigned char newAddr[IBUTTON_BYTES] );
		void SetFirstName ( std::string newFirstName );
		void SetLastName ( std::string newLastName );


};

#endif
