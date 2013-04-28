#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

#define CLEARBUF() char ch; while ((ch = getchar()) != '\n' && ch != EOF);
#ifndef MAX
	#define MAX(a,b) ((a) > (b) ? a : b)
#endif
#ifndef MIN
	#define MIN(a,b) ((a) < (b) ? a : b)
#endif

#endif
/**/
