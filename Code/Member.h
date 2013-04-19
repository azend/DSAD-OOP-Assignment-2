#ifndef _MEMBER_H_
#define _MEMBER_H_

/**
 *
 * @file Member.h
 *
 * @brief This file contains the Member class.
 *
 */

#include <iostream>

#define IBUTTON_BYTES 7 /**< The number of bytes in an iButton address */

/**
 * @class Member
 * @brief This class models basic properties of a member at Diyode.
 *
 */
class Member {
private:
    unsigned char ibuttonAddr[IBUTTON_BYTES]; /**< The address of an iButton key code. In real life, it looks much like a MAC address */
    std::string firstName; /**< The first name of the member */
    std::string lastName; /**< The last name of the member */
    /**
     * @brief Verifies that the iButton code is valid.
     *
     * @param ibuttonAddr The address of an iButton key code. It must be IBUTTON_BYTES bytes long.
     * @return Returns true if the test passed and false if it didn't
     * @see IBUTTON_BYTES
     */
    static bool VerifyiButtonAddr ( unsigned char * ibuttonAddr, int arraySize);
    
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
    unsigned char * GetiButtonAddr();
    
    /**
     * @brief Gets the first name of the member.
     *
     * @return Returns the first name of the user as a string.
     */
    std::string GetFirstName();
    
    /**
     * @brief Gets the last name of the member.
     *
     * @return Returns the last name of the user as a string.
     */
    std::string GetLastName();
    
    /* Mutators */
    
    /**
     * @brief Set the iButton address of the member.
     *
     * @param newAddr The new keycode for the member.
     * @return Returns true if the keycode is valid and false if it isn't.
     * @see IBUTTON_BYTES
     */
    bool SetiButtonAddr ( unsigned char * newAddr, int arraySize);
    
    /**
     * @brief Set the first name of the member.
     *
     * @param newFirstName The new first name of the member.
     * @return Returns true if the name is valid and false if it is not.
     */
    bool SetFirstName ( std::string newFirstName );
    
    /**
     * @brief Set the last name of the member.
     *
     * @param newLastName The new last name of the member.
     * @return Returns true if the name is valid and false if it is not.
     */
    bool SetLastName ( std::string newLastName );
    
    /**
     * @brief Check if the iButtonAddress is the same as the one of the current object.
     *
     * @param ibuttonAddr The iButton address to be compared with against the current object.
     * @return Returns true if the iButtons are the same and false if they are not.
     *
     * @see GetiButtonAddr
     * @see SetiButtonAddr
     */
    bool CompareiButtonAddr ( unsigned char * ibuttonAddr, int arraySize);
    
    /**
     * @brief Check if the member object passed in is the same as the current member object.
     *
     * @param member A member object to be compared.
     * @return Returns true if the objects are the same and false if they are not.
     */
    bool Equals ( Member & otherMember );
    
    /**
     * @brief Alias to Equals
     * @see Equals
     */
    bool operator== ( Member & otherMember );
};

#endif

