#ifndef _MEMBER_H_
#define _MEMBER_H_

/**
 *
 * @file Member.h
 *
 * @brief This file contains the Member class.
 *
 */

#include <regex>
#include <vector>
#include <iostream>
using namespace std;

/**
 * @class Member
 * @brief This class models basic properties of a member at Diyode.
 *
 */
class Member {
private:
	static const int kiButtonLength; /**< The number of bytes in an iButton address */
	static const int kFirstNameLength;
	static const int kLastNameLength;
	
	vector<unsigned char> ibuttonAddr; /**< The address of an iButton key code. In real life, it looks much like a MAC address */
	string firstName; /**< The first name of the member */
	string lastName; /**< The last name of the member */

	/**
	 * @brief Verifies that the iButton code is valid.
	 *
	 * @param ibuttonAddr The address of an iButton key code. It must be IBUTTON_BYTES bytes long.
	 * @return Returns true if the test passed and false if it didn't
	 * @see IBUTTON_BYTES
	 */
	static const bool VerifyiButtonAddr ( const vector<unsigned char> & ibuttonAddr );
	static const bool VerifyFirstName ( const string & firstName );
	static const bool VerifyLastName ( const string & lastName );
    
public:
	/* Constructors / Deconstructors */
	
	/**
	 * @brief Creates a member object with default properties. Objects instanciated using this method will have an iButton address of 00:00:00:00:00:00:00, a first name of "", and a last name of "".
	 */
	Member();
	
	/**
	 * @brief Destroys a member object
	 */
	~Member();
	
	/* Accessors */
	
	/**
	 * @brief Gets the iButton address of the member.
	 *
	 * @return Returns the iButton address of the member as an array IBUTTON_BYTES long.
	 * @see IBUTTON_BYTES
	 */
	const vector<unsigned char> GetiButtonAddr();
	
	/**
	 * @brief Gets the first name of the member.
	 *
	 * @return Returns the first name of the user as a string.
	 */
	const string GetFirstName();
	
	/**
	 * @brief Gets the last name of the member.
	 *
	 * @return Returns the last name of the user as a string.
	 */
	const string GetLastName();
	
	/* Mutators */
	
	/**
	 * @brief Set the iButton address of the member.
	 *
	 * @param newAddr The new keycode for the member.
	 * @return Returns true if the keycode is valid and false if it isn't.
	 * @see IBUTTON_BYTES
	 */
	const bool SetiButtonAddr ( const vector<unsigned char> & newiButtonAddr );
	
	/**
	 * @brief Set the first name of the member.
	 *
	 * @param newFirstName The new first name of the member.
	 * @return Returns true if the name is valid and false if it is not.
	 */
	const bool SetFirstName ( const string & newFirstName );
	
	/**
	 * @brief Set the last name of the member.
	 *
	 * @param newLastName The new last name of the member.
	 * @return Returns true if the name is valid and false if it is not.
	 */
	const bool SetLastName ( const string & newLastName );

	const bool Less ( const Member & otherMember );
	const bool Less ( const vector<unsigned char> & otheriButtonAddress );

	/**
	 * @brief Check if the member object passed in is the same as the current member object.
	 *
	 * @param member A member object to be compared.
	 * @return Returns true if the objects are the same and false if they are not.
	 */
	const bool Equals ( const Member & otherMember );
	const bool Equals ( const vector<unsigned char> & otheriButtonAddress );
	
	/**
	 * @brief Alias to Equals
	 * @see Equals
	 */
	const bool operator< ( const Member & otherMember );
	const bool operator< ( const vector<unsigned char> & otheriButtonAddress );
    friend const bool operator< ( const Member & lhsMember, const Member & rhsMember );
    friend const bool operator< ( const vector<unsigned char> & ibuttonAddress, const Member & member);

	bool operator== ( const Member & otherMember );
	bool operator== ( const vector<unsigned char> & otheriButtonAddress );
    
    friend ostream & operator<< (ostream & os, const Member & member);
    friend istream & operator>> (istream & is, Member & member);
};

#endif

