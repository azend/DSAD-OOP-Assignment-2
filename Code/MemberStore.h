#ifndef _MEMBERSTORE_H_
#define _MEMBERSTORE_H_

#include <map>

#include "Member.h"

class MemberStore : public map<unsigned char *, Member> {
public:

	// /**
	//  * @brief Creates a member storage object.
	//  *
	//  * @return A MemberStore object
	//  */
	// MemberStore ();

	// /**
	//  * @brief Destroys the member store.
	//  */
	// virtual ~MemberStore ();

	// /**
	//  * @brief Add a member to the member store.
	//  *
	//  * @param newMember A new member object to be copied into the store.
	//  */
	// AddMember ( Member newMember );

	// /**
	//  * @brief Removes a member with the same attributes as deleteMember
	//  * 
	//  * @param deleteMember A member object with attributes the same as the member in the store to be deleted.
	//  */
	// RemoveMember ( Member deleteMember );

	// /**
	//  * @brief Finds a member with the same keycode as the search query.
	//  *
	//  * @param keyCode The keycode to be searched for.
	//  */
	// FindMemberByiButton ( unsigned char * keyCode );

};

#endif
