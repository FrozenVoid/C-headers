#pragma once
#include "lambda.h"
/* mathmacros.h
numberof(str) convert string to number
hexnumberof(str) convert hex string to number

fixedpoint(func,guess) find a fixed point value(or closest guess) for func where f(x)==x
bound(x,min,max) bound variable by min/max which are returned if x is below/above
isinteger(x) return 1 if integer,0 otherwise
issigned(x) eturn 1 if signed type,0 otherwise
u64log2(x) return interger log2 value of uint64_t number
average(x,y) return average of x/y
averagedamp(func) return function that returns average of x/func(x)
tmin/tmax  min/max of two numbers
derivative  - lambda of derivative(function)
*/
//https://lemire.me/blog/2016/06/27/a-fast-alternative-to-the-modulo-reduction/
#define modxy(x,y) ((uint32_t)((((uint64_t) ((uint32_t)x) )*((uint64_t)y))>>32))

#define numberof(str) strtoll(str,NULL,10)
#define hexnumberof(str) strtoll(str,NULL,16)

#define tmin(x,y) ({typeof(x) tminx=x,tminy=y,res=tminy<tminx?tminy:tminx;      ;res;})
#define tmax(x,y) ({typeof(x) tminx=x,tminy=y,res=tminy>tminx?tminy:tminx;      ;res;})
#define tabs(x) ({typeof(x) res=x;res<0?-res:res;})

#define log2index(x)  (63 - __builtin_clzll((x)))
#define issigned(x) (((typeof(x))-1)<((typeof(x))0))
#define isinteger(x) ((typeof(x))1.1 == 1)
//branchless bound
#define bound(x,minbound,maxbound) (((x)*((x)>minbound)*((x)<maxbound))\
 +(((x)<minbound)*minbound)+(((x)>maxbound)*maxbound))

#define average(x,y) ({typeof(x) sum=(x)+(y); sum/2;})
#define averagedamp(func) lambda(double,(double val),return  average(val,func(val)))
#define derivative(func) lambda(double,(double x), const double dx=1e6*DBL_EPSILON;   return ((func(x+dx))-func(x))/dx   )
#define fixpointtranform(gfunc,transform,guess) fixedpoint(transform(gfunc),guess)

#define fixedpoint(func,guess) ({double diff=1e300,result=guess,current=guess;;\
while(1){result=func(current); \
double thisdiff=fabs(result-current);\
if(thisdiff>=diff){break;}\
diff=thisdiff;current=result;} ;current;})

#define newtontransform(gfunc) lambda(double,(double x),return x-( gfunc(x)/derivative(gfunc)(x)  ))
#define newtonmethod(gfunc,guess) fixedpoint(newtontransform(gfunc),guess)

#define intmin(x,y) (y ^ ((x ^ y) & -(x < y)))
#define intmax(x,y) (x ^ ((x ^ y) & -(x < y)))
