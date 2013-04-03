
#include "DoorBot.h"

int main(int argc, const char *argv[])
{
	DoorBot mrRoboto;
	
	if ( argc >= 2 ) {
		mrRoboto.SetDbPath(argv[1]);
	}

	mrRoboto.Setup();

	mrRoboto.Loop();

	return 0;
}

