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

#define IBUTTON_BYTES 7 /**< The number of bytes in an iButton address */

/**
 * @class Member
 * @brief This class models basic properties of a member at Diyode.
 *
 */
class Member {
private:
	static const int kiButtonLength; /**< The number of bytes in an iButton address */
	static const int kFirstNameLength; /**< The maximum length in characters a members' first name can be */
	static const int kLastNameLength; /**< The maximum length in characters a members' last name can be */
	
	vector<unsigned char> ibuttonAddr; /**< The address of an iButton key code. In real life, it looks much like a MAC address */
	string firstName; /**< The first name of the member */
	string lastName; /**< The last name of the member */

	/**
	 * @brief Checks to see if an iButton code is valid.
	 * @details To meet this validation, the iButton keycode must be a vector that is IBUTTON_BYTES long.
	 * @param ibuttonAddr The address of an iButton key code.
	 * @return Returns true if the test passed and false if it does not.
	 * @see IBUTTON_BYTES
	 */
	static const bool VerifyiButtonAddr ( const vector<unsigned char> & ibuttonAddr );

	/**
	 * @brief Checks to see if a members' first name is valid.
	 * @details To pass validation, the passed in string must meet the following criteria:
	 * 	+ Must be a maximum of 30 characters long
	 * 	+ Must not include either a ';' character or a new line escape sequence
	 * @param firstName The first name of a member.
	 * @return Returns true if the test passes and false if it does not.
	 * @see GetFirstName
	 * @see SetFirstName
	 */
	static const bool VerifyFirstName ( const string & firstName );

	/**
	 * @brief Checks to see if a members' last name is valid.
	 * @details To pass validation, the passed in string must meet the following criteria:
	 * 	+ Must be a maximum of 30 characters long
	 * 	+ Must not include either a ';' character or a new line escape sequence
	 * @param firstName The last name of a member.
	 * @return Returns true if the test passes and false if it does not.
	 * @see GetLastName
	 * @see SetLastName
	 */
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
	const vector<unsigned char> GetiButtonAddr() const;

	/**
	* @brief Gets the iButton address of the member as a string
	* @return A stringified version of the iButton address
	*/
	const string GetiButtonAddrStr() const;
			
	/**
	 * @brief Gets the first name of the member.
	 *
	 * @return Returns the first name of the user as a string.
	 */
	const string GetFirstName() const;
	
	/**
	 * @brief Gets the last name of the member.
	 *
	 * @return Returns the last name of the user as a string.
	 */
	const string GetLastName() const;
	
	/* Mutators */
	
	/**
	 * @brief Set the iButton address of the member.
	 *
	 * This function relies on VerifyiButtonAddress to perform input validation before
	 * entering the data into the store.
	 *
	 * @param newAddr The new keycode for the member.
	 * @return Returns true if the keycode meets validation and was changed.
	 *
	 * @see VerifyiButtonAddr
	 * @see IBUTTON_BYTES
	 */
	const bool SetiButtonAddr ( const vector<unsigned char> & newiButtonAddr );    
    
	/**
	 * @brief Set the first name of the member.
	 *
	 * This function relies on VerifyFirstName to perform input validation before
	 * entering the data into the store.
	 *
	 * @param newFirstName The new first name of the member.
	 * @return Returns true if the name was changed and false if it was not.
	 *
	 * @see VerifyFirstName
	 */
	const bool SetFirstName ( const string & newFirstName );
	
	/**
	 * @brief Set the last name of the member.
	 *
	 * This function relies on VerifyLastName to perform input validation before
	 * entering the data into the store.
	 *
	 * @param newFirstName The new first name of the member.
	 * @return Returns true if the name was changed and false if it was not.
	 *
	 * @see VerifyLastName
	 */
	const bool SetLastName ( const string & newLastName );

	/**
	 * @brief Compares two member objects (this one and another) to see which is lesser.
	 * 
	 * This method is used for sorting within external containers. Sorting is determined
	 * by looking at the member iButton keys and comparing the bytes from left to right
	 * to see which is lesser.
	 *
	 * @param otherMember Another member to compare against.
	 * @return Returns true if *this is lesser than otherMember.
	 */
	const bool Less ( const Member & otherMember ) const;

	/**
	 * @brief Compares the current member object to an iButton address to see which is lesser.
	 * Aliases the Less which compares member objects.
	 * @return Returns true if *this is lesser than the address.
	 * @see Less
	 */
	const bool Less ( const vector<unsigned char> & otheriButtonAddress ) const;

	/**
	 * @brief Check if the member object passed in is the same as the current member object.
	 *
	 * @param member A member object to be compared.
	 * @return Returns true if the objects are the same and false if they are not.
	 */
	const bool Equals ( const Member & otherMember ) const;
	const bool Equals ( const vector<unsigned char> & otheriButtonAddress ) const;
	
	const bool operator< ( const Member & otherMember ) const;
	const bool operator< ( const vector<unsigned char> & otheriButtonAddress ) const;
	//friend const bool operator< ( const Member & lhsMember, const Member & rhsMember );
	//friend const bool operator< ( const vector<unsigned char> & ibuttonAddress, const Member & member);

	/**
	 * @brief Alias to Equals
	 * @see Equals
	 */
	bool operator== ( const Member & otherMember ) const;

	/**
	 * @brief Alias to Equals
	 * @see Equals
	 */
	bool operator== ( const vector<unsigned char> & otheriButtonAddress ) const;

	/**
	 * @brief Writes a serialzed member out to an output stream.
	 *
	 * @details Members will be written out the following format:
	 * 	1. 7 bytes seperated by colons to define the iButton address
	 * 	2. Field divider (;)
	 * 	3. The first name of the member
	 * 	4. Field divider (;)
	 * 	5. The last name of the member
	 * 	5. New line
	 *
	 * An example of the resulting string could be:
	 * 	00:1A:2B:3C:4D:5E:6F;Hugh;Man(\n)
	 * With the (\n) of course representing a new line
	 * @param os A writable ostream to write the member to.
	 * @param member The member object to write out.
	 * @return Returns the ostream object so that the << operator can be chained.
	 */
	friend ostream & operator<< (ostream & os, const Member & member);

	/** @brief Reads a serialized member out from an input stream.
	 *
	 * @details This method reads members out from an input stream using the same
	 * format as operator<< does.
	 *
	 * @param is An input stream to read the member from.
	 * @param member A member object to read the values into.
	 * @return Returns the input stream is for chaining
	 * @see operator<<
	 */
	friend istream & operator>> (istream & is, Member & member);
};

#endif

