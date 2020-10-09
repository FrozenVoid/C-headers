#pragma once 
/* mathmacros.h
macros for quick function calls.
*/
#define u64log2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))
