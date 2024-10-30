#include "stdlib.h"
#include "stdio.h"

/*
 * ftoa.c
 *
 *  Created on: 18 de mai de 2022
 *      Author: Micro
 */

#ifndef FTOA_C_
#define FTOA_C_

char *ftoa(void)
{
    static char        buf[17];
    char *            cp = buf;
    unsigned long    l, rem;

extern float f;

    if(f < 0) {
        *cp++ = '-';
        f = -f;
    }
    l = (unsigned long)f;
    f -= (float)l;
    rem = (unsigned long)(f * 1e6);
    sprintf(cp, "%lu.%6.6lu", l, rem);
    return buf;
}

#endif /* FTOA_C_ */
