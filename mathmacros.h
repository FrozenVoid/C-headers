#pragma once 
/* mathmacros.h
*/
#define u64log2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))
#define issigned(x) (((typeof(x))-1)<((typeof(x))0))
#define isinteger(x) ((typeof(x))1.1 == 1)
//branchless bound
#define bound(x,minbound,maxbound) (((x)*((x)>minbound)*((x)<maxbound))\
 +(((x)<minbound)*minbound)+(((x)>maxbound)*maxbound))
