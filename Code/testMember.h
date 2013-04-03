#ifndef _TESTMEMBER_H_
#define _TESTMEMBER_H_

#include <stdio.h>

#include "Member.h"

int main(void)
{
	unsigned char testAddr1[IBUTTON_BYTES] = { 1, 2, -127, 1024, 52, 6, 7 };
	unsigned char testAddr1[IBUTTON_BYTES + 1] = {0};
	unsigned char testAddr1[IBUTTON_BYTES - 1] = {0};
	unsigned char * testAddr4 = NULL;

	printf("Testing class Member:");
	
	printf("\tTesting default constructor... ");
	Member azend;
	
	
	return 0;
}
#endif

