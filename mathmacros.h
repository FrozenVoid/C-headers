#pragma once 
/* mathmacros.h
fixedpoint(func,guess) find a fixed point value(or closest guess) for func where f(x)==x
bound(x,min,max) bound variable by min/max which are returned if x is below/above
isinteger(x) return 1 if integer,0 otherwise
issigned(x) eturn 1 if signed type,0 otherwise
u64log2(x) return interger log2 value of uint64_t number
*/
#define u64log2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))
#define issigned(x) (((typeof(x))-1)<((typeof(x))0))
#define isinteger(x) ((typeof(x))1.1 == 1)
//branchless bound
#define bound(x,minbound,maxbound) (((x)*((x)>minbound)*((x)<maxbound))\
 +(((x)<minbound)*minbound)+(((x)>maxbound)*maxbound))

#define fixedpoint(func,guess) ({double diff=1e300,result=guess,current=guess;;\
while(1){result=func(current); \
double thisdiff=fabs(result-current);\
if(thisdiff>=diff){break;}\
diff=thisdiff;current=result;} ;result;})
