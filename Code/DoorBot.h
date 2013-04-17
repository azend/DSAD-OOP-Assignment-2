#ifndef _DOORBOT_H_
#define _DOORBOT_H_

/**
 * @file DoorBot.h
 * @brief This file contains the DoorBot class, a class designed to model the features of (semi-psychotic) door entry system.
 */
#include <set>
#include <string>
#include <fstream>

#include "Member.h"
#include "MemberReader.h"

#define DEFAULT_DB_PATH "db.txt" /**< The default file path for the file which stores members. */

/**
 * @class DoorBot
 * @brief This class forms an object which manages the Diyode door entry system.
 *
 */
class DoorBot {
	private:
		std::set<Member> members; /**< Holds currently registered members */
		std::string dbPath; /**< The file path to the current database */

		/**
		 * @brief Checks if the path to the database exists.
		 * @return Returns true if the path is valid and false if it is not.
		 */
		static bool ValidateDbPath ( std::string path );
		
	protected:

		/**
		 * @brief Loads in members from the database.
		 * @see MemberReader
		 */
		void LoadMembers(); //depricated
	
	public:
		/**
		 * @brief Constructs a DoorBot object using default values.
		 */
		DoorBot();

		/**
		 * @brief Destroys a perfectly good DoorBot object.
		 */
		~DoorBot();

		/**
		 * @brief Performs internal initialization functions.
		 *
		 * This function performs internal initialization functions such as loading members from the database.
		 * This is seperate from the constructor to allow changing of the members database file before it is read in.
		 */
		void Setup();

		/**
		 * @brief Loop forever while looking for new key codes and updating the database every few minutes.
		 */
		void Loop();

		/**
		 * @brief Get the path to the database.
		 * @return Returns the path to the database as a string
		 * @see DEFAULT_DB_PATH
		 * @see GetDbPath()
		 */
		std::string GetDbPath ();

		/**
		 * @brief Changes the database path to a new path.
		 * This must be run before Setup() as database path information becomes irrelavent if it has already been loaded.
		 * @see Setup()
		 */
		bool SetDbPath ( std::string newPath );
	
};

#endif
