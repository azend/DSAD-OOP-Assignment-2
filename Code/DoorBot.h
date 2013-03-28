#ifndef _DOORBOT_H_
#define _DOORBOT_H_

/**
 * @file DoorBot.h
 *
 */

/*
 * @class DoorBot
 * @brief This class forms an object which manages the Diyode door entry system.
 *
 */
class DoorBot {
	private:
		MemberStore members;
		
	public:
		void Loop();
	
};

#endif
