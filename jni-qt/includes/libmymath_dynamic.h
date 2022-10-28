#ifndef __LIBMYMATH_H
#define __LIBMYMATH_H

#include <graal_isolate_dynamic.h>


#if defined(__cplusplus)
extern "C" {
#endif

typedef int (*ceilingPowerOfTwo_fn_t)(graal_isolatethread_t*, int);

typedef void (*vmLocatorSymbol_fn_t)(graal_isolatethread_t* thread);

#if defined(__cplusplus)
}
#endif
#endif
