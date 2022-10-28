#ifndef __LIBMYMATH_H
#define __LIBMYMATH_H

#include <graal_isolate.h>


#if defined(__cplusplus)
extern "C" {
#endif

int ceilingPowerOfTwo(graal_isolatethread_t*, int);

void vmLocatorSymbol(graal_isolatethread_t* thread);

#if defined(__cplusplus)
}
#endif
#endif
