/*
 * ultoa.c
 *
 *  Created on: 6 de jun de 2022
 *      Author: Micro
 */
#include	<stdlib.h>
#ifndef ULTOA_C_
#define ULTOA_C_

ultoa(char * buf, unsigned long val, int base)

{
	unsigned	long	v;
	char		c;

	v = val;
	do {
		v /= base;
		buf++;
	} while(v != 0);
	*buf-- = 0;
	do {
		c = val % base;
		val /= base;
		if(c >= 10)
			c += 'A'-'0'-10;
		c += '0';
		*buf-- = c;
	} while(val != 0);
	return buf;
}

#endif /* ULTOA_C_ */
