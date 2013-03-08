Proposal
========
Authors: Ian and Verdi

 + Diyode, the hackerspace in Guelph, ON, is looking for a new authentication system for allowing entry into the space.

 + The reason behind building this is that the current system in place is plagued with strange crashes and general instability.

 + We would like to build a new system on top of the Raspberry Pi to replace the current system using the concepts we've learned in class.

Basic Requirements
------------------

 + Recieve member list updates from an external server in the cloud

 + Communicate with iButton reader (over the OneWire protocol) to get key codes from people at the door

 + Let them in by unlocking the door with a simple circuit attached to the Raspberry Pi GPIO and controlled by our software

 + Keep a local cache of members in the event of network failure, etc.
